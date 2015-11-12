#include "multicontainer.h"


//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_CONSTRUCTOR(hsdk::frame::MultiContainer<INDEX>, MultiContainer)(
	_In_ PARENT_RELATION _relation)
	: Container(_relation)
{

}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_DESTRUCTOR(hsdk::frame::MultiContainer<INDEX>, MultiContainer)(void)
{
	reset();
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, void, select_Buffer)(
	_In_ unsigned int _index,
	_In_ bool _store)
{
	if (!(_index < INDEX) || _index == m_CurrentBuffer)
	{
		return;
	}

	if (_store)
	{
		m_Buffer[m_CurrentBuffer] = m_Container;

		m_Container.clear();
		m_Container = m_Buffer[_index];
	}
	else
	{
		clear_Component();
		m_Container = m_Buffer[_index];
	}

	m_CurrentBuffer = _index;
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, unsigned int, get_CurrentBuffer)(
	_X_ void)
{
	return m_CurrentBuffer;
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, void, clear_Component)(
	_X_ void)
{
	Container::clear_Component();
	m_Buffer[m_CurrentBuffer].clear();
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, void, reset)(
	_X_ void)
{
	// 임시 버퍼를 클리어
	for (unsigned int index = 0; index < INDEX; ++index)
	{
		// 임시 버퍼 선택
		m_CurrentBuffer = index;
		m_Container = m_Buffer[index];

		// 임시 버퍼 클리어
		clear_Component();
	}

	m_CurrentBuffer = 0;
	Component::reset();
	m_Layout.~AutoDelete();
}