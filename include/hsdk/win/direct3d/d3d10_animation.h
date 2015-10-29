#pragma once



#include "d3d10_common.h"
#include <map>



namespace hsdk
{
	namespace direct3d
	{

		// 설명 : 
		DECL_STRUCT(D3D10MY_BONE)
		{

			// 설명 :
			std::wstring name;

			// 설명 :
			unsigned int parent = -1;

			// 설명 : sum of bone's children and length in bone's array
			unsigned int length = -1;

			// 설명 :
			unsigned int id = -1;

			// 설명 : 
			D3DXMATRIX mRelation = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f, };

			// 설명 : 
			D3DXMATRIX mOwn = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f, };

		};

		// 설명 : 
		DECL_STRUCT(D3D10MY_BONE_KEYFRAME)
		{

			// 설명 : 
			unsigned int boneID;

			// 설명 : 
			aiAnimBehaviour preFrameMoveHint;

			// 설명 : 
			aiAnimBehaviour postFrameMoveHint;

			// 설명 : 
			std::vector<aiVectorKey> positionKeyFrame;

			// 설명 : 
			std::vector<aiQuatKey> rotationKeyFrame;

			// 설명 : 
			std::vector<aiVectorKey> scaleKeyFrame;

		};

		// 설명 : 
		DECL_STRUCT(D3D10MY_ANIMATION)
		{

			// 설명 : 
			unsigned int animID;

			// 설명 : 
			std::wstring name;

			// 설명 : 애니메이션이 제어하는 뼈 채널
			std::vector<D3D10MY_BONE_KEYFRAME> boneKeyFrames;

			// 설명 :
			double tickPerSecond;

			// 설명 : 애니메이션 지속시간
			double duration;

		};

		// 설명 : 
		DECL_STRUCT(D3D10_Animation)
		{

			// 설명 :
			std::map<std::wstring, unsigned int> bonePath;

			// 설명 : 
			std::vector<D3D10MY_BONE> bones;

			// 설명 :
			std::map<std::wstring, unsigned int> animationPath;

			// 설명 :
			std::vector<D3D10MY_ANIMATION> animations;

		};

		// 설명 :
		DECL_STRUCT(D3D10MY_KEYFRAME_RECORD)
		{

			// 설명 :
			unsigned int boneID;

			// 설명 : 
			unsigned int positionKey;

			// 설명 : 
			unsigned int rotationKey;

			// 설명 : 
			unsigned int scaleKey;

		};

		// 설명 : 
		DECL_STRUCT(D3D10_Animation_Recorder)
		{

			// 설명 : 
			unsigned int aniamtionID;

			//
			std::vector<D3DXMATRIX> pos;

			// 설명 : 
			double time;

		};

		namespace animation
		{

			// 설명 : 
			DLL_DECL_FUNC_T(void, animationClear)(
				_Out_ D3D10_Animation & _animation);
			
			// 설명 : 
			DLL_DECL_FUNC_T(void, animationRecordClear)(
				_Out_ D3D10_Animation_Recorder & _recorder);

			/*
			설명 : animation을 재생할 수 있는 포즈를 생성.
			$ 참고 : 버퍼를 재생성하기 때문에 create_Pos가 성공하면 animate_Pos을 호출
			*/
			DLL_DECL_FUNC(create_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation,
				_In_ unsigned int _animationPos,
				_In_ double _time);

			// 설명 : 
			DLL_DECL_FUNC_T(void, animate_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation);
			
			// 설명 : 
			DLL_DECL_FUNC(trans_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation,
				_In_ unsigned int _animationPos);
			
			// 설명 : 
			DLL_DECL_FUNC_T(void, reset_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation);
			
			// 설명 :
			DLL_DECL_FUNC_T(D3DXMATRIX, compute_MatrixFromBoneKeyFrame)(
				_In_ const D3D10MY_BONE_KEYFRAME & _boneKeyframe,
				_In_ double _duration,
				_In_ double _time);

			// 설명 :
			template<typename INPUT, typename OUTPUT> DECL_FUNC_T(OUTPUT, compute_VectorFromKeyFrame)(
				_In_ const std::vector<INPUT> & _keyFrame,
				_In_ aiAnimBehaviour _preFrameHint,
				_In_ aiAnimBehaviour _postFrameHint,
				_In_ double _duration,
				_In_ double _time);

			// 설명 :
			DLL_DECL_FUNC_T(void, build_MeshBoneMatrix)(
				_Out_ D3DXMATRIX * _matrixbuffer,
				_In_ const unsigned int * _boneNodeBuffer,
				_In_ unsigned int _bufferSize,
				_In_ const D3D10_Animation & _animation,
				_In_ const D3D10_Animation_Recorder & _pos);

		}
	}
}



#include "d3d10_animation.inl"