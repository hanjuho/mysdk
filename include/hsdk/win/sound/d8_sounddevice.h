#pragma once



#include "d8_common.h"
#include "d8_soundplayer.h"
#include "d8_soundmultiplayer.h"



namespace hsdk
{
	namespace sound
	{

		///////////////////////////////////////////////////////////////////////////////
		// Class name: SoundClass
		///////////////////////////////////////////////////////////////////////////////
		DLL_DECL_CLASS(Direct8_SoundDevice)
		{

		public:

			// ���� : 
			CLASS_DECL_FUNC(initialize)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			// ���� :
			CLASS_DECL_FUNC_T(void, flush)(
				_X_ void);
			
			/*
			���� : �̹� �ҷ��� ������ ���ۿ� ����Ǿ� ����.
			if will call this function, you must call Addref() when Second Paramiter is AutoRelease.
			*/
			CLASS_DECL_FUNC(load_WaveFile)(
				_In_ const wchar_t * _directory,
				_Out_ IDirectSoundBuffer ** _soundBuffer);

			// ���� : 
			CLASS_DECL_FUNC(create_SoundPlayer)(
				_Out_ Direct8_SoundStreamPlayer & _player,
				_In_ const wchar_t ** _directorys,
				_In_ unsigned int _numOfDirectorys);

			// ���� :
			CLASS_DECL_FUNC_T(IDirectSound8 *, get_Device)(
				_X_ void);

			// ���� :
			CLASS_DECL_FUNC_T(IDirectSoundBuffer *, get_PrimaryBuffer)(
				_X_ void);

			// ���� :
			CLASS_DECL_FUNC_T(IDirectSound3DListener8 *, get_SoundListener)(
				_X_ void);

		};

		// ���� : Direct8Sound grobal variable
		extern HSDK_DLL Direct8_SoundDevice g_Direct8_SoundDevice;

	}
}