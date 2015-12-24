#pragma once



#include "interface/datatable.h"
#include "physics/bullet_engine.h"



namespace hsdk
{
	namespace game
	{

		// ���� : 
		DECL_CLASS(DataTable)
			: public i::i_DataTable
		{
		public:

			// ���� : 
			INTERFACE_DECL_FUNC_T(btRigidBody *, get_Body)(
				_X_ void)const;

			// ���� : 
			INTERFACE_DECL_FUNC_T(void, set_Body)(
				_In_ btRigidBody * _body);

		protected:

			// ���� : 
			btRigidBody * m_Body = nullptr;

		};

	}
}