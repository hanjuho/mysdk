#pragma once



#include "common.h"
#include "d8_soundplayer.h"
#include "d8_soundmultiplayer.h"



namespace hsdk
{
	namespace sound
	{

		///////////////////////////////////////////////////////////////////////////////
		// Class name: SoundClass
		///////////////////////////////////////////////////////////////////////////////
		DLL_DECL_CLASS(Direct8_SoundFactory)
		{

		public:

			// ���� : 
			CLASS_DECL_FUNC(initialize)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, destroy)(
				_X_ void);

			/*
			���� : �̹� �ҷ��� ������ ���ۿ� ����Ǿ� ����.
			if will call this function, you must call Addref() when Second Paramiter is AutoRelease.
			*/
			CLASS_DECL_FUNC(load_WaveFile)(
				_In_ const wchar_t * _directory,
				_Out_ IDirectSoundBuffer8 ** _d8Sound);

			// ���� : 
			CLASS_DECL_FUNC(create_SoundPlayer)(
				_Out_ Direct8_SoundStreamPlayer & _player,
				_In_ const wchar_t ** _directorys,
				_In_ unsigned int _numOfDirectorys);

		};

		// ���� : Direct8Sound grobal variable
		extern HSDK_DLL Direct8_SoundFactory g_Direct8_SoundFactory;

	}
}