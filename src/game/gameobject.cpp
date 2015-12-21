#include "gameobject.h"



using namespace hsdk;
using namespace game;


//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, update)(
	_X_ void)
{
	act_ActionLayers();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, render)(
	_X_ void)
{
	m_Renderer->render();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, set_Datatalbe)(
	/* [set] */ i::i_DataTable * _datatable)
{
	m_DataTable = _datatable;
	if (_datatable && m_ActionBase)
	{
		m_ActionBase->link_DataTable(_datatable);
	}

	if (_datatable && m_Renderer)
	{
		m_Renderer->link_DataTable(_datatable);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, set_Controller)(
	/* [set] */ Controller * _controller)
{
	m_Controller = _controller;
	if (_controller && m_ActionBase)
	{
		m_Controller->link_ActionBase(m_ActionBase);
		m_Controller->link_ActionListener(this);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, set_ActionBase)(
	/* [set] */ ActionBase * _actionbase)
{
	m_ActionBase = _actionbase;
	if (_actionbase && m_DataTable)
	{
		m_ActionBase->link_DataTable(m_DataTable);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, set_Renderer)(
	/* [set] */ Renderer * _renderer)
{
	m_Renderer = _renderer;
	if (_renderer && m_DataTable)
	{
		m_Renderer->link_DataTable(m_DataTable);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, i::i_DataTable *, get_Datatalbe)(
	_X_ void)const
{
	return m_DataTable;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, i::i_Controller *, get_Controller)(
	_X_ void)const
{
	return m_Controller;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, i::i_ActionBase *, get_ActionBase)(
	_X_ void)const
{
	return m_ActionBase;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, i::i_Renderer *, get_Renderer)(
	_X_ void)const
{
	return m_Renderer;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, listen_Action)(
	_Ref_ i::i_ActionLayer * _actionlayer)
{
	unsigned int p = _actionlayer->priority();
	if (p)
	{		
		if (p < my_Action->priority())
		{
			//
			_actionlayer->initialize();
			my_Action = _actionlayer;

			//
			m_Renderer->initialize();
		}
	}
	else
	{
		//
		_actionlayer->initialize();
		my_Effects.push_back(_actionlayer);
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(GameObject, void, act_ActionLayers)(
	_X_ void)
{
	std::list<i::i_ActionLayer *>::iterator begin = my_Effects.begin();
	std::list<i::i_ActionLayer *>::iterator end = my_Effects.begin();

	while (begin != end)
	{
		IF_FALSE((*begin)->act())
		{
			begin = my_Effects.erase(begin);
			continue;
		}

		++begin;
	}

	if (nullptr == my_Action || my_Action->act())
	{
		m_Controller->wait(0);
	}
}