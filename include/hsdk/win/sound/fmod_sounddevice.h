#pragma once



#include "fmod_common.h"



namespace hsdk
{
	namespace sound
	{

		///////////////////////////////////////////////////////////////////////////////
		// Class name: SoundClass
		///////////////////////////////////////////////////////////////////////////////
		DLL_DECL_CLASS(FMOD_SoundDevice)
		{

		public:

			// ���� : 
			CLASS_DECL_FUNC(initialize)(
				_In_ void * _extraDriverdata = nullptr);

			// ���� : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			/*
			���� : �̹� �ҷ��� ������ ���ۿ� ����Ǿ� ����.
			$ ���� : do not delete FMOD::Sound
			*/
			CLASS_DECL_FUNC(load_WaveFile)(
				_In_ const wchar_t * _directory,
				_Out_ FMOD::Sound ** _sound,
				_Out_opt_ FMOD_CREATESOUNDEXINFO * info = nullptr);

			// ���� : 
			CLASS_DECL_FUNC_T(FMOD::System *, operator ->)(
				_X_ void);

		};

		// ���� : Direct8Sound grobal variable
		extern HSDK_DLL FMOD_SoundDevice g_FMOD_SoundDevice;

	}
}