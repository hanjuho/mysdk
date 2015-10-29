#pragma once



#include "d3d10_common.h"
#include <map>



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		DECL_STRUCT(D3D10MY_BONE)
		{

			// ���� :
			std::wstring name;

			// ���� :
			unsigned int parent = -1;

			// ���� : sum of bone's children and length in bone's array
			unsigned int length = -1;

			// ���� :
			unsigned int id = -1;

			// ���� : 
			D3DXMATRIX mRelation = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f, };

			// ���� : 
			D3DXMATRIX mOwn = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f, };

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_BONE_KEYFRAME)
		{

			// ���� : 
			unsigned int boneID;

			// ���� : 
			aiAnimBehaviour preFrameMoveHint;

			// ���� : 
			aiAnimBehaviour postFrameMoveHint;

			// ���� : 
			std::vector<aiVectorKey> positionKeyFrame;

			// ���� : 
			std::vector<aiQuatKey> rotationKeyFrame;

			// ���� : 
			std::vector<aiVectorKey> scaleKeyFrame;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_ANIMATION)
		{

			// ���� : 
			unsigned int animID;

			// ���� : 
			std::wstring name;

			// ���� : �ִϸ��̼��� �����ϴ� �� ä��
			std::vector<D3D10MY_BONE_KEYFRAME> boneKeyFrames;

			// ���� :
			double tickPerSecond;

			// ���� : �ִϸ��̼� ���ӽð�
			double duration;

		};

		// ���� : 
		DECL_STRUCT(D3D10_Animation)
		{

			// ���� :
			std::map<std::wstring, unsigned int> bonePath;

			// ���� : 
			std::vector<D3D10MY_BONE> bones;

			// ���� :
			std::map<std::wstring, unsigned int> animationPath;

			// ���� :
			std::vector<D3D10MY_ANIMATION> animations;

		};

		// ���� :
		DECL_STRUCT(D3D10MY_KEYFRAME_RECORD)
		{

			// ���� :
			unsigned int boneID;

			// ���� : 
			unsigned int positionKey;

			// ���� : 
			unsigned int rotationKey;

			// ���� : 
			unsigned int scaleKey;

		};

		// ���� : 
		DECL_STRUCT(D3D10_Animation_Recorder)
		{

			// ���� : 
			unsigned int aniamtionID;

			//
			std::vector<D3DXMATRIX> pos;

			// ���� : 
			double time;

		};

		namespace animation
		{

			// ���� : 
			DLL_DECL_FUNC_T(void, animationClear)(
				_Out_ D3D10_Animation & _animation);
			
			// ���� : 
			DLL_DECL_FUNC_T(void, animationRecordClear)(
				_Out_ D3D10_Animation_Recorder & _recorder);

			/*
			���� : animation�� ����� �� �ִ� ��� ����.
			$ ���� : ���۸� ������ϱ� ������ create_Pos�� �����ϸ� animate_Pos�� ȣ��
			*/
			DLL_DECL_FUNC(create_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation,
				_In_ unsigned int _animationPos,
				_In_ double _time);

			// ���� : 
			DLL_DECL_FUNC_T(void, animate_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation);
			
			// ���� : 
			DLL_DECL_FUNC(trans_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation,
				_In_ unsigned int _animationPos);
			
			// ���� : 
			DLL_DECL_FUNC_T(void, reset_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation);
			
			// ���� :
			DLL_DECL_FUNC_T(D3DXMATRIX, compute_MatrixFromBoneKeyFrame)(
				_In_ const D3D10MY_BONE_KEYFRAME & _boneKeyframe,
				_In_ double _duration,
				_In_ double _time);

			// ���� :
			template<typename INPUT, typename OUTPUT> DECL_FUNC_T(OUTPUT, compute_VectorFromKeyFrame)(
				_In_ const std::vector<INPUT> & _keyFrame,
				_In_ aiAnimBehaviour _preFrameHint,
				_In_ aiAnimBehaviour _postFrameHint,
				_In_ double _duration,
				_In_ double _time);

			// ���� :
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