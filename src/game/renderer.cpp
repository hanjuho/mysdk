#include "renderer.h"



using namespace hsdk;
using namespace game;


//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Renderer, void, initialize)(
	_X_ void)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Renderer, void, update)(
	_X_ void)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Renderer, void, render)(
	_X_ void)
{

}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Renderer, void, link_DataTable)(
	_Ref_ i::i_DataTable * _datatable)
{
	m_Datatable = _datatable;
}
