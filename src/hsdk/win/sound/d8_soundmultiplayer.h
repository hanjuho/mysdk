#pragma once



#include "d8_common.h"
#include <vector>



namespace hsdk
{
	namespace sound
	{

		// ���� : 
		DECL_CLASS(Direct8_SoundStreamPlayer)
		{

			// ���� : 
			DECL_STRUCT(MY_SOUND)
			{

				// ���� : 
				float playtime = 0.0f;

				// ���� : 
				AutoRelease<IDirectSoundBuffer8> soundPlayer;

				// ���� : 
				AutoRelease<IDirectSound3DBuffer8> sound3DOption;

			};

		public:

			// ���� : 
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// ���� :
			CLASS_DECL_FUNC(setup0)(
				_In_ unsigned int _numOfSound);

			// ���� : 
			CLASS_DECL_FUNC(setup1_Sound)(
				_In_ unsigned int _indexOfSound,
				_In_ const wchar_t * _directory);

			// ���� : 
			CLASS_DECL_FUNC(setup1_Sound)(
				_In_ unsigned int _indexOfSound,
				_In_ IDirectSoundBuffer * _soundBuffer);

			// ���� : 
			CLASS_DECL_FUNC(userSet_PlayList)(
				_In_ unsigned int _count,
				_In_ unsigned int _start);

			// ���� : 
			CLASS_DECL_FUNC(userSet_Volume)(
				_In_ unsigned int _indexOfSound,
				_In_ long _volume);

			// ���� : 
			CLASS_DECL_FUNC(userSet_Distance)(
				_In_ unsigned int _indexOfSound,
				_In_ float _minDistance,
				_In_ float _maxDistance);

			// ���� : 
			CLASS_DECL_FUNC(userSet_Translation)(
				_In_ unsigned int _indexOfSound,
				_In_ const D3DXVECTOR3 & _position,
				_In_ const D3DXVECTOR3 & _velocity);

			// ���� : 
			CLASS_DECL_FUNC_T(void, play)(
				_In_ double _deltaTime);

		private:

			// ���� : 
			unsigned int my_PlayCount = 0;

			// ���� : 
			unsigned int my_PlayStart = 0;

			// ���� : 
			std::vector<MY_SOUND> my_SoundStream;

		};

	}
}