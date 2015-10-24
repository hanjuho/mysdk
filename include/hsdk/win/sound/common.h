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

		// 설명 : 
		DECL_STRUCT(Direct8Sound_WAVEHEADERTYPE)
		{

			// 설명 : 
			char chunkId[4];

			// 설명 : 
			unsigned long chunkSize;

			// 설명 : 
			char format[4];

			// 설명 : 
			char subChunkId[4];

			// 설명 : 
			unsigned long subChunkSize;

			// 설명 : 
			unsigned short audioFormat;

			// 설명 : 
			unsigned short numChannels;

			// 설명 : 
			unsigned long sampleRate;

			// 설명 : 
			unsigned long bytesPerSecond;

			// 설명 : 
			unsigned short blockAlign;

			// 설명 : 
			unsigned short bitsPerSample;

			// 설명 : 
			char dataChunkId[4];

			// 설명 : 
			unsigned long dataSize;

		};

		// 설명 : 
		DECL_STRUCT(Direct8MY_SOUND)
		{

			// 설명 : 
			Direct8Sound_WAVEHEADERTYPE soundHeader;
			
			// 설명 :
			AutoRelease<IDirectSoundBuffer8> d8Sound;

			// 설명 : 
			AutoRelease<IDirectSound3DBuffer8> d8Sound3D;

		};

	}
}