#include "d8_soundmultiplayer.h"
#include "d8_sounddevice.h"



using namespace hsdk::sound;


//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Direct8_SoundStreamPlayer, void, clear)(
	_X_ void)
{
	my_PlayCount = 0;
	my_PlayStart = 0;
	my_SoundStream.clear();
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Direct8_SoundStreamPlayer, setup0)(
	_In_ unsigned int _numOfSound)
{
	if (my_SoundStream.size())
	{
		return E_ACCESSDENIED;
	}

	my_SoundStream.resize(_numOfSound);

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Direct8_SoundStreamPlayer, setup1_Sound)(
	_In_ unsigned int _indexOfSound,
	_In_ const wchar_t * _directory)
{
	IF_FALSE(_indexOfSound < my_SoundStream.size())
	{
		return E_INVALIDARG;
	}

	HRESULT hr;

	IDirectSoundBuffer * sound;
	IF_SUCCEEDED(hr = g_Direct8_SoundDevice.load_WaveFile(
		_directory,
		&sound))
	{

		// MY_SOUND�� AutoRelease �̱� ������ setup�� �����ߴٸ� Addref�� ȣ���ؾ� ������
		// setup1_Sound���� �װ��� ó����.

		return setup1_Sound(_indexOfSound, sound);
	}
	else
	{
		return hr;
	}
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Direct8_SoundStreamPlayer, setup1_Sound)(
	_In_ unsigned int _indexOfSound,
	_In_ IDirectSoundBuffer * _soundBuffer)
{
	IF_FALSE(_indexOfSound < my_SoundStream.size())
	{
		return E_INVALIDARG;
	}

	HRESULT hr;

	// Test the buffer format against the direct sound 8 interface and create the secondary buffer.
	AutoRelease<IDirectSoundBuffer8> soundPlayer;
	IF_FAILED(_soundBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&soundPlayer))
	{
		return false;
	}

	// Get the 3D interface to the secondary sound buffer.
	AutoRelease<IDirectSound3DBuffer8> sound3DOption;
	IF_FAILED(hr = soundPlayer->QueryInterface(IID_IDirectSound3DBuffer8, (void**)&sound3DOption))
	{
		return hr;
	}

	MY_SOUND & sound = my_SoundStream[_indexOfSound];
	sound.soundPlayer = soundPlayer;
	sound.sound3DOption = sound3DOption;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Direct8_SoundStreamPlayer, userSet_PlayList)(
	_In_ unsigned int _count,
	_In_ unsigned int _start)
{
	IF_FALSE((_start + _count) < my_SoundStream.size())
	{
		return E_INVALIDARG;
	}

	my_PlayCount = _count;
	my_PlayStart = _start;

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Direct8_SoundStreamPlayer, userSet_Volume)(
	_In_ unsigned int _indexOfSound,
	_In_ long _volume)
{
	IF_FALSE(_indexOfSound < my_SoundStream.size())
	{
		return E_INVALIDARG;
	}

	return my_SoundStream[_indexOfSound].soundPlayer->SetVolume(_volume);
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Direct8_SoundStreamPlayer, userSet_Distance)(
	_In_ unsigned int _indexOfSound,
	_In_ float _minDistance,
	_In_ float _maxDistance)
{
	IF_FALSE(_indexOfSound < my_SoundStream.size())
	{
		return E_INVALIDARG;
	}

	IDirectSound3DBuffer8 * pointer = my_SoundStream[_indexOfSound].sound3DOption;
	pointer->SetMinDistance(_minDistance, DS3D_DEFERRED);
	pointer->SetMaxDistance(_maxDistance, DS3D_DEFERRED);

	return S_OK;
}


//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC(Direct8_SoundStreamPlayer, userSet_Translation)(
	_In_ unsigned int _indexOfSound,
	_In_ const D3DXVECTOR3 & _position,
	_In_ const D3DXVECTOR3 & _velocity)
{
	IF_FALSE(_indexOfSound < my_SoundStream.size())
	{
		return E_INVALIDARG;
	}

	IDirectSound3DBuffer8 * pointer = my_SoundStream[_indexOfSound].sound3DOption;
	pointer->SetPosition(_position[0], _position[1], _position[2], DS3D_DEFERRED);
	pointer->SetVelocity(_velocity[0], _velocity[1], _velocity[2], DS3D_DEFERRED);

	return S_OK;
}

//--------------------------------------------------------------------------------------
CLASS_IMPL_FUNC_T(Direct8_SoundStreamPlayer, void, play)(
	_In_ double _deltaTime)
{
	MY_SOUND * sounds = &my_SoundStream[0];
	unsigned int size = my_SoundStream.size();

	for (unsigned int index = 0; index < my_PlayCount; ++index)
	{
		MY_SOUND & sound = sounds[my_PlayStart + index];


	}
}