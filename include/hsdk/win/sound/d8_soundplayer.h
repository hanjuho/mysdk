#pragma once



#include "d8_common.h"



namespace hsdk
{
	namespace sound
	{

		// 설명 : 
		DLL_DECL_CLASS(Direct8_SoundPlayer)
		{
		public:

			// 설명 : 
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC(setup)(
				_In_ const wchar_t * _directory);

			// 설명 : 
			CLASS_DECL_FUNC(setup)(
				_In_ IDirectSoundBuffer * _soundBuffer);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_Volume)(
				_In_ long _volume);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_Distance)(
				_In_ float _minDistance,
				_In_ float _maxDistance);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, userSet_Translation)(
				_In_ const D3DXVECTOR3 & _position,
				_In_ const D3DXVECTOR3 & _velocity);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, play)(
				_In_ double _deltaTime);

		private:
			
			// 설명 : 
			float my_Playtime = 0.0f;

			// 설명 : 
			AutoRelease<IDirectSoundBuffer8> my_SoundPlayer;

			// 설명 : 
			AutoRelease<IDirectSound3DBuffer8> my_Sound3DOption;

		};

	}
}