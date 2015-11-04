#pragma once



#include "common.h"
#include "actionlayer.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// ���� : 
			template<typename T = i_ActionLayer *> DECL_CLASS(i_ActionTable)
			{
			public:

				// �Ҹ���.
				CLASS_DECL_DESTRUCTOR(i_ActionTable)(void)
				{

				}

				// ���� :
				INTERFACE_DECL_FUNC_T(T, attack)(
					_In_ long _flag) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(T, suffer)(
					_In_ unsigned int _frequency,
					_In_ float _amount,
					_In_ long _flag) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(T, move)(
					_In_ float _x,
					_In_ float _y,
					_In_ long _flag) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(T, wait)(
					_In_ long _flag) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(T, effect)(
					_In_ unsigned int _effect,
					_In_ long _flag) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(T, recovery)(
					_In_ unsigned int _frequency,
					_In_ float _amount,
					_In_ long _flag) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(T, resurrect)(
					_In_ long _flag) = 0;

				// ���� :
				INTERFACE_DECL_FUNC_T(T, disappear)(
					_In_ long _flag) = 0;

			};

			// ���� : 
			typedef i_ActionTable<> i_ActionBase;

		}
	}
}