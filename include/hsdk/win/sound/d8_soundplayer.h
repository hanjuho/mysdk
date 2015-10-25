#pragma once



#include "d8_common.h"



namespace hsdk
{
	namespace sound
	{

		// ���� : 
		DLL_DECL_CLASS(Direct8_SoundPlayer)
		{
		public:

			// ���� : 
			CLASS_DECL_FUNC_T(void, clear)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC(setup)(
				_In_ const wchar_t * _directory);

			// ���� : 
			CLASS_DECL_FUNC(setup)(
				_In_ IDirectSoundBuffer * _soundBuffer);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_Volume)(
				_In_ long _volume);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_Distance)(
				_In_ float _minDistance,
				_In_ float _maxDistance);

			// ���� : 
			CLASS_DECL_FUNC_T(void, userSet_Translation)(
				_In_ const D3DXVECTOR3 & _position,
				_In_ const D3DXVECTOR3 & _velocity);

			// ���� : 
			CLASS_DECL_FUNC_T(void, play)(
				_In_ double _deltaTime);

		private:
			
			// ���� : 
			float my_Playtime = 0.0f;

			// ���� : 
			AutoRelease<IDirectSoundBuffer8> my_SoundPlayer;

			// ���� : 
			AutoRelease<IDirectSound3DBuffer8> my_Sound3DOption;

		};

	}
}