#include "container.h"
#include "inputeventhelper.h"



using namespace hsdk::frame;


//--------------------------------------------------------------------------------------
CLASS_IMPL_CONSTRUCTOR(Container, Container)(
	_In_ PARENT_RELATION _relation)
	: Component(_relation)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_DESTRUCTOR(Container, Container)(void)
{
	reset();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, void, set_Layout)(
	_In_ hsdk::i::frame::i_Layout * _layout)
{
	m_Layout = _layout;
	if (m_Layout)
	{
		m_Layout->resize(get_W(), get_H());
		m_Layout->reset();
		reform();
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, hsdk::i::frame::i_Layout *, get_Layout)(
	_X_ void)
{
	return m_Layout;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Container, add_Component)(
	_In_ i_Component * _component,
	_In_ hsdk::i::frame::LAYOUT_COMPOSITION _composition)
{
	// �θ� �ִٸ� �Ʒ� ������ ġ������
	if (_component->parent())
	{
		return E_INVALIDARG;
	}

	// is - a ���� ����
	Component * component;
	component = (Component *)(_component);
	IF_FALSE(component)
	{
		return E_INVALIDARG;
	}

	if (m_Layout)
	{
		HRESULT hr;
		IF_FAILED(hr = m_Layout->link_Form(
			component->my_Rectangle,
			_composition))
		{
			return hr;
		}
	}

	// �θ���� �߰�
	component->my_Parent = this;
	component->m_Composition = _composition;

	// �����̳ʿ� �߰�
	m_Container.push_back(component);

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Container, remove_Component)(
	_In_ i_Component * _component)
{
	// �θ� ���ٸ� �Ʒ� ������ �ǹ̰� ����
	IF_INVALID(_component->parent())
	{
		return E_INVALIDARG;
	}

	auto iter = std::find(m_Container.begin(), m_Container.end(), _component);
	if (iter == m_Container.end())
	{
		auto begin = m_Container.begin();
		auto end = m_Container.end();
		while (begin != end)
		{
			IF_SUCCEEDED((*begin)->remove_Component(_component))
			{
				return S_OK;
			}

			++begin;
		}

		return E_INVALIDARG;
	}
	else
	{
		// ���ԵǾ� �ִٴ� ���� is - a ���谡 Ȯ���ϴٴ� ���� ��Ÿ��
		Component * component = (Component *)(_component);

		// �θ���� ����
		component->my_Parent = nullptr;

		// �����̳ʿ��� ����
		m_Container.erase(iter);
	}

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Container, contain_Component)(
	_In_ i_Component * _component)const
{
	// �θ� ���ٸ� �Ʒ� ������ �ǹ̰� ����
	IF_INVALID(_component->parent())
	{
		return E_INVALIDARG;
	}

	auto iter = std::find(m_Container.begin(), m_Container.end(), _component);
	if (iter == m_Container.end())
	{
		auto begin = m_Container.begin();
		auto end = m_Container.end();
		while (begin != end)
		{
			IF_SUCCEEDED((*begin)->contain_Component(_component))
			{
				return S_FALSE;
			}

			++begin;
		}
	}
	else
	{
		return S_OK;
	}

	return E_INVALIDARG;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Container, get_Component)(
	_Out_ i_Component * (&_component),
	_In_ unsigned int _id)const
{
	// �θ� ���ٸ� �Ʒ� ������ �ǹ̰� ����
	IF_INVALID(_component->parent())
	{
		return E_INVALIDARG;
	}

	auto begin = m_Container.begin();
	auto end = m_Container.end();
	while (begin != end)
	{
		if ((*begin)->my_id == _id)
		{
			_component = (*begin);
			return S_OK;
		}
		else
		{
			IF_SUCCEEDED((*begin)->get_Component(_component, _id))
			{
				return S_OK;
			}
		}

		++begin;
	}

	return E_INVALIDARG;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, void, clear_Component)(
	_X_ void)
{
	auto begin = m_Container.begin();
	auto end = m_Container.end();
	while (begin != end)
	{
		DEL_POINTER(*begin);
		++begin;
	}

	m_Container.clear();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, bool, event_chain)(
	_In_ hsdk::i::frame::i_inputEventHelper * _eventhelper)
{
	if (_eventhelper->chain(this))
	{
		auto begin = m_Container.begin();
		auto end = m_Container.end();
		while (begin != end)
		{
			if ((*begin)->event_chain(_eventhelper))
			{
				break;
			}

			++begin;
		}

		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, void, update)(
	_X_ void)
{
	auto begin = m_Container.begin();
	auto end = m_Container.end();
	while (begin != end)
	{
		(*begin)->update();
		++begin;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, void, render)(
	_X_ void)
{
	if (is_Visible())
	{
		Component::render();

		auto begin = m_Container.begin();
		auto end = m_Container.end();
		while (begin != end)
		{
			(*begin)->render();
			++begin;
		}
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, void, reform)(
	_X_ void)
{
	Component::reform();

	auto begin = m_Container.begin();
	auto end = m_Container.end();

	if (m_Layout)
	{
		m_Layout->resize(get_W(), get_H());
		m_Layout->reset();

		while (begin != end)
		{
			Component * compo = (*begin);
			m_Layout->link_Form(
				compo->my_Rectangle,
				compo->m_Composition);

			++begin;
		}
	}

	begin = m_Container.begin();
	while (begin != end)
	{
		(*begin)->reform();
		++begin;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, void, redraw)(
	_X_ void)
{
	auto begin = m_Container.begin();
	auto end = m_Container.end();
	while (begin != end)
	{
		(*begin)->redraw();
		++begin;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Container, void, reset)(
	_X_ void)
{
	clear_Component();
	Component::reset();
	m_Layout.~AutoDelete();
}