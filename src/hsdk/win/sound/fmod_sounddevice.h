#pragma once



#include "fmod_common.h"



namespace hsdk
{
	namespace sound
	{

		///////////////////////////////////////////////////////////////////////////////
		// Class name: SoundClass
		///////////////////////////////////////////////////////////////////////////////
		DECL_CLASS(FMOD_SoundDevice)
		{

		public:

			// 설명 : 
			CLASS_DECL_FUNC(initialize)(
				_In_ void * _extraDriverdata = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, move)(
				_In_ const float * _postion);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, play)(
				_X_ void);

			/*
			설명 : 이미 불려진 음원은 버퍼에 저장되어 있음.
			$ 참고 : do not delete FMOD::Sound, FMOD::Channel
			*/
			CLASS_DECL_FUNC(load_WaveFile)(
				_Out_ FMOD::Sound ** _sound,
				_Out_ FMOD::Channel ** _controller,
				_In_ const wchar_t * _directory);

			// 설명 : 
			CLASS_DECL_FUNC_T(FMOD::System *, operator ->)(
				_X_ void);

		};

		// 설명 : Direct8Sound grobal variable
		extern FMOD_SoundDevice g_FMOD_SoundDevice;

	}
}