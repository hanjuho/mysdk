#pragma once



#include "component.h"
#include <hash_map>


namespace hsdk
{
	namespace frame
	{

		enum LAYOUT_SPACE
		{

		};

		// Ό³Έν :
		DECL_INTERFACE(Layout)
		{

			INTERFACE_DECL_FUNC_T(void, set_Space)(
				_In_ float _value) = 0;
			
			INTERFACE_DECL_FUNC_T(void, get_Space)(
				_In_ float _value) = 0;
			

		};

	}
}