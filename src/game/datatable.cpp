#include "datatable.h"



using namespace hsdk;
using namespace game;


//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(DataTable, btRigidBody *, get_Body)(
	_X_ void)const
{
	return m_Body;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(DataTable, void, set_Body)(
	_In_ btRigidBody * _body)
{
	m_Body = _body;
}