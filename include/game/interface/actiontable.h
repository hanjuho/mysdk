#pragma once



#include "common.h"
#include "actionlayer.h"



namespace hsdk
{
	namespace game
	{
		namespace i
		{

			// 설명 : 
			template<typename T = i_ActionLayer *> DECL_CLASS(i_ActionTable)
			{
			public:

				// 소멸자.
				CLASS_DECL_DESTRUCTOR(i_ActionTable)(void)
				{

				}

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, attack)(
					/* [r] */ long _flag) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, suffer)(
					/* [r] */ unsigned int _frequency,
					/* [r] */ float _amount,
					/* [r] */ long _flag) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, move)(
					/* [r] */ float _x,
					/* [r] */ float _y,
					/* [r] */ long _flag) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, wait)(
					/* [r] */ long _flag) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, effect)(
					/* [r] */ unsigned int _effect,
					/* [r] */ long _flag) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, recovery)(
					/* [r] */ unsigned int _frequency,
					/* [r] */ float _amount,
					/* [r] */ long _flag) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, resurrect)(
					/* [r] */ long _flag) = 0;

				// 설명 :
				INTERFACE_DECL_FUNC_T(T, disappear)(
					/* [r] */ long _flag) = 0;

			};

			// 설명 : 
			typedef i_ActionTable<> i_ActionBase;

		}
	}
}