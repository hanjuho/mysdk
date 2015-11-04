#pragma once



#include "d8_common.h"
#include <vector>



namespace hsdk
{
	namespace sound
	{

		// 설명 : 
		DECL_CLASS(Direct8_SoundStreamPlayer)
		{

			// 설명 : 
			DECL_STRUCT(MY_SOUND)
			{

				// 설명 : 
				float playtime = 0.0f;

				// 설명 : 
				AutoRelease<IDirectSoundBuffer8> soundPlayer;

				// 설명 : 
				AutoRelease<IDirectSound3DBuffer8> sound3DOption;

			};

		public:

			// 설명 : 
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// 설명 :
			CLASS_DECL_FUNC(setup0)(
				_In_ unsigned int _numOfSound);

			// 설명 : 
			CLASS_DECL_FUNC(setup1_Sound)(
				_In_ unsigned int _indexOfSound,
				_In_ const wchar_t * _directory);

			// 설명 : 
			CLASS_DECL_FUNC(setup1_Sound)(
				_In_ unsigned int _indexOfSound,
				_In_ IDirectSoundBuffer * _soundBuffer);

			// 설명 : 
			CLASS_DECL_FUNC(userSet_PlayList)(
				_In_ unsigned int _count,
				_In_ unsigned int _start);

			// 설명 : 
			CLASS_DECL_FUNC(userSet_Volume)(
				_In_ unsigned int _indexOfSound,
				_In_ long _volume);

			// 설명 : 
			CLASS_DECL_FUNC(userSet_Distance)(
				_In_ unsigned int _indexOfSound,
				_In_ float _minDistance,
				_In_ float _maxDistance);

			// 설명 : 
			CLASS_DECL_FUNC(userSet_Translation)(
				_In_ unsigned int _indexOfSound,
				_In_ const D3DXVECTOR3 & _position,
				_In_ const D3DXVECTOR3 & _velocity);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, play)(
				_In_ double _deltaTime);

		private:

			// 설명 : 
			unsigned int my_PlayCount = 0;

			// 설명 : 
			unsigned int my_PlayStart = 0;

			// 설명 : 
			std::vector<MY_SOUND> my_SoundStream;

		};

	}
}