#pragma once



#include "d3d10_common.h"
#include <map>



namespace hsdk
{
	namespace direct3d
	{

		// ���� : 
		enum D3D10MY_FRAME_HINT
		{
			// ���� : The value from the default node transformation is taken
			FRAME_HINT_DEFAULT = 0x0,

			// ���� : The nearest key value is used without interpolation
			FRAME_HINT_CONSTANT = 0x1,

			/*
			���� : The value of the nearest two keys is linearly
			extrapolated for the current time value.
			*/
			FRAME_HINT_LINEAR = 0x2,

			/*
			���� : The animation is repeated.
			If the animation key go from n to m and the current	time is t,
			use the value at (t-n) % (|m-n|).
			*/
			FRAME_HINT_REPEAT = 0x3

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_BONE)
		{

			// ���� :
			std::wstring name;

			// ���� :
			unsigned int parentID = -1;

			// ���� : The sum number of bone's children and the length in bone's array
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
		DECL_STRUCT(D3D10MY_ANIMATION_KEY)
		{

			// ���� : 
			D3DXVECTOR3 position;

			// ���� : 
			D3DXVECTOR3 rotation;

			// ���� : 
			D3DXVECTOR3 scaling;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_ANIMATION_BONE_KEYFRAME)
		{

			// ���� : 
			unsigned int boneID;

			// ���� : 
			D3D10MY_FRAME_HINT frameHint;

			// ���� : 
			std::vector<D3D10MY_ANIMATION_KEY> keyFrame;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_ANIMATION)
		{

			// ���� : 
			std::wstring name;

			// ���� : 
			std::vector<D3D10MY_ANIMATION_BONE_KEYFRAME> boneFrames;

			// ���� : 
			double tickPerSecond;

			// ���� : 
			double secDuration;

		};

		// ���� : 
		DLL_DECL_CLASS(D3D10_MeshAnimation)
		{

		public:

			// ���� : 
			DECL_FUNC_T(void, clear)(
				_X_ void);

			// ���� :
			DECL_FUNC(setup0)(
				_In_ unsigned int _numOfBones,
				_In_ unsigned int _numOfAnimation);

			/*
			���� : ����� ������ ���� ��Ģ�� ���� �����ؾ� �Ѵ�(�� ��ü���� Bone's Node�� �迭�� �����ȴ�).
			$ 1. ���� ������ �̷���� ���븦 ���� ��ȸ�� ������ ����.
			$ 2. ������ ������ ���ĵ� ������� �Ķ���Ϳ� ����.
			$ 3. _lengthOfBone �Ķ���ʹ� ���� ��忡�� ���� ��� ������ ��� �ڽ� ��� ����
			(���� �ļ��� ��� ������ �ƴ�).
			$ 4. _matrix �Ķ���ʹ� ���� �θ� ���κ��� ����� ��� ����.
			*/
			DECL_FUNC(setup1_BoneNode)(
				_In_ unsigned int _indexOfBone,
				_In_ unsigned int _parentID,
				_In_ unsigned int _lengthOfBone,
				_In_ const wchar_t * _nameOfBone,
				_In_ const float * _matrix);

			// ���� : 
			DECL_FUNC(setup1_Animation)(
				_In_ unsigned int _indexOfAnimation,
				_In_ const wchar_t * _nameOfAnimation,
				_In_ unsigned int _numOfAnimateBones,
				_In_ double _tickPerSecond,
				_In_ double _secondOfDuration);

			// ���� : 
			DECL_FUNC(setup2_AnimationBoneKeyFrame)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _indexOfAnimateBones,
				_In_ unsigned int _boneID,
				_In_ unsigned int _numOfAnimateFrameKeys,
				_In_ const D3DXVECTOR3 * _postionStream,
				_In_ const D3DXVECTOR3 * _rotationStream,
				_In_ const D3DXVECTOR3 * _scalingStream,
				_In_ D3D10MY_FRAME_HINT _frameHin1t);

			// ���� : 
			DECL_FUNC(userSet_AnimationBoneKey)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _indexOfAnimateBones,
				_In_ unsigned int _indexfAnimateKey,
				_In_ const D3DXVECTOR3 & _postionStream,
				_In_ const D3DXVECTOR3 & _rotationStream,
				_In_ const D3DXVECTOR3 & _scalingStream);

			/*
			���� : setup bone matrix.
			$ ���� : _matrix parameter is bone's own matrix.
			*/
			DECL_FUNC(userSet_BoneMatrix)(
				_In_ unsigned int _indexOfBone,
				_In_ const float * _matrix);

			// ���� :
			DECL_FUNC_T(unsigned int, get_NumOfBones)(
				_X_ void)const;

			// ���� :
			DECL_FUNC_T(const D3D10MY_BONE *, find_BoneFromName)(
				_In_ const wchar_t * _nameOfBone)const;

			// ���� :
			DECL_FUNC_T(const D3D10MY_BONE *, find_BoneFromID)(
				_In_  unsigned int _id)const;

			// ���� :
			DECL_FUNC_T(unsigned int, find_BoneIDFromName)(
				_In_ const wchar_t * _nameOfBone)const;

			// ���� :
			DECL_FUNC_T(void, transbone)(
				_Out_ D3DXMATRIX * _matrixbuffer,
				_Out_ unsigned int _numOfMatrixs,
				_Out_ const D3DXMATRIX _form);

		private:

			// ���� :
			std::map<std::wstring, unsigned int> my_BoneOfNames;

			// ���� : 
			std::vector<D3D10MY_BONE> my_Bones;

			// ���� :
			std::map<std::wstring, unsigned int> my_AnimationOfNames;

			// ���� :
			std::vector<D3D10MY_ANIMATION> my_Animation;

		};

	}
}