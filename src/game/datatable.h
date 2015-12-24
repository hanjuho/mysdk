#pragma once



#include "interface/datatable.h"
#include "physics/bullet_engine.h"



namespace hsdk
{
	namespace game
	{

		// 설명 : 
		DECL_CLASS(DataTable)
			: public i::i_DataTable
		{
		public:

			// 설명 : 
			INTERFACE_DECL_FUNC_T(btRigidBody *, get_Body)(
				_X_ void)const;

			// 설명 : 
			INTERFACE_DECL_FUNC_T(void, set_Body)(
				_In_ btRigidBody * _body);

		protected:

			// 설명 : 
			btRigidBody * m_Body = nullptr;

		};

	}
}