///////////////////////////////////////////////////////////////////////////////
// Filename: soundclass.h
///////////////////////////////////////////////////////////////////////////////
#pragma once


/////////////
// LINKING //
/////////////
#pragma comment(lib, "dsound.lib")


//////////////
// INCLUDES //
//////////////
#include "../../../hsdk_common.h"
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>



namespace hsdk
{
	namespace sound
	{

		// 설명 : 
		DLL_DECL_CLASS(Direct8_SoundPlayer)
		{

		public:

			// 설명 :
			CLASS_DECL_FUNC(initialize)(
				_In_ unsigned int _numOfSound);

		};
		
	}
}