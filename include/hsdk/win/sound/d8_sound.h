#pragma once



#include "common.h"



namespace hsdk
{
	namespace sound
	{

		///////////////////////////////////////////////////////////////////////////////
		// Class name: SoundClass
		///////////////////////////////////////////////////////////////////////////////
		DLL_DECL_CLASS(Direct8Sound)
		{

		public:

			// 설명 : 
			CLASS_DECL_FUNC(initialize)(
				_In_ HWND _hwnd);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC(load_WaveFile)(
				_Out_ IDirectSoundBuffer8** _d8Sound,
				_In_ const wchar_t * _directory,
				_Out_ IDirectSound3DBuffer8 ** _d8Sound3D);

		};

		// 설명 : 
		extern HSDK_DLL Direct8Sound g_Direct8_Sound;

	}
}