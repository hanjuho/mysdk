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

			// ���� : 
			CLASS_DECL_FUNC(initialize)(
				_In_ void * _extraDriverdata = nullptr);

			// ���� : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, move)(
				_In_ const float * _postion);

			// ���� : 
			CLASS_DECL_FUNC_T(void, play)(
				_X_ void);

			/*
			���� : �̹� �ҷ��� ������ ���ۿ� ����Ǿ� ����.
			$ ���� : do not delete FMOD::Sound, FMOD::Channel
			*/
			CLASS_DECL_FUNC(load_WaveFile)(
				_Out_ FMOD::Sound ** _sound,
				_Out_ FMOD::Channel ** _controller,
				_In_ const wchar_t * _directory);

			// ���� : 
			CLASS_DECL_FUNC_T(FMOD::System *, operator ->)(
				_X_ void);

		};

		// ���� : Direct8Sound grobal variable
		extern FMOD_SoundDevice g_FMOD_SoundDevice;

	}
}