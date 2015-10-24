///////////////////////////////////////////////////////////////////////////////
// Filename: soundclass.h
///////////////////////////////////////////////////////////////////////////////
#pragma once


/////////////
// LINKING //
/////////////
#pragma comment(lib, "dsound.lib")


//////////////
// INCLUDES //
//////////////
#include "../../../hsdk_common.h"
#include "../../autorelease.h"
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>



namespace hsdk
{
	namespace sound
	{

		// ���� : 
		DECL_STRUCT(Direct8Sound_WAVEHEADERTYPE)
		{

			// ���� : 
			char chunkId[4];

			// ���� : 
			unsigned long chunkSize;

			// ���� : 
			char format[4];

			// ���� : 
			char subChunkId[4];

			// ���� : 
			unsigned long subChunkSize;

			// ���� : 
			unsigned short audioFormat;

			// ���� : 
			unsigned short numChannels;

			// ���� : 
			unsigned long sampleRate;

			// ���� : 
			unsigned long bytesPerSecond;

			// ���� : 
			unsigned short blockAlign;

			// ���� : 
			unsigned short bitsPerSample;

			// ���� : 
			char dataChunkId[4];

			// ���� : 
			unsigned long dataSize;

		};

		// ���� : 
		DECL_STRUCT(Direct8MY_SOUND)
		{

			// ���� : 
			Direct8Sound_WAVEHEADERTYPE soundHeader;
			
			// ���� :
			AutoRelease<IDirectSoundBuffer8> d8Sound;

			// ���� : 
			AutoRelease<IDirectSound3DBuffer8> d8Sound3D;

		};

	}
}