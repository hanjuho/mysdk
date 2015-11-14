#pragma once



#include "d3d10_common.h"
#include <map>



namespace hsdk
{
	namespace direct3d
	{

		// ���� : one bone data
		DECL_STRUCT(D3D10MY_BONE)
		{

			// ���� : bone's name
			std::wstring name;

			// ���� : parent id
			unsigned int parent = -1;

			// ���� : sum of bone's children and length in bone's array
			unsigned int length = -1;

			// ���� : my id
			unsigned int boneNumber = -1;

			// ���� : to itself matrix from parent
			D3DXMATRIX mRelation = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f, };

			// ���� : offset matrix
			D3DXMATRIX mOwn = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f, };

		};

		// ���� : it is bone's keyframe buffer and member of D3D10MY_ANIMATION.
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

		// ���� : it's animation data and member of D3D10_Animation.
		DECL_STRUCT(D3D10MY_ANIMATION)
		{

			// ���� : 
			unsigned int animNumber;

			// ���� : 
			std::wstring name;

			// ���� :
			std::vector<D3D10MY_BONE_KEYFRAME> boneKeyFrames;

			// ���� :
			double tickPerSecond;

			// ���� : �ִϸ��̼� ���ӽð�
			double duration;

		};

		// ���� : it's bone, animation buffer that made from d3d10factory.
		DECL_STRUCT(D3D10_Animation)
		{

			// ���� : find bone dispather
			std::map<std::wstring, unsigned int> bonePath;

			// ���� : 
			std::vector<D3D10MY_BONE> bones;

			// ���� : find animation dispather
			std::map<std::wstring, unsigned int> animationPath;

			// ���� :
			std::vector<D3D10MY_ANIMATION> animations;

		};

		// ���� : no use
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

		// ���� : it's The buffer that records bone keyframe matrices in time.
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
			DECL_FUNC_T(void, animationClear)(
				_Out_ D3D10_Animation & _animation);
			
			// ���� : 
			DECL_FUNC_T(void, animationRecordClear)(
				_Out_ D3D10_Animation_Recorder & _recorder);

			/*
			���� : animation�� ����� �� �ִ� ��� ����.
			$ ���� : ���۸� ������ϱ� ������ create_Pos�� �����ϸ� animate_Pos�� ȣ��
			*/
			DECL_FUNC(build_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation,
				_In_ unsigned int _animationPos,
				_In_ double _time);

			// ���� : 
			DECL_FUNC_T(void, animate_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation);
			
			// ���� : 
			DECL_FUNC(trans_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation,
				_In_ unsigned int _animationPos);
			
			// ���� : 
			DECL_FUNC_T(void, reset_Pos)(
				_Out_ D3D10_Animation_Recorder & _pos,
				_In_ const D3D10_Animation & _animation);
			
			// ���� :
			DECL_FUNC_T(D3DXMATRIX, compute_MatrixFromBoneKeyFrame)(
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
			DECL_FUNC_T(void, build_MeshBoneMatrix)(
				_Out_ D3DXMATRIX * _matrixbuffer,
				_In_ const unsigned int * _boneNodeBuffer,
				_In_ unsigned int _bufferSize,
				_In_ const D3D10_Animation & _animation,
				_In_ const D3D10_Animation_Recorder & _pos);

		}
	}
}



#include "d3d10_animation.inl"