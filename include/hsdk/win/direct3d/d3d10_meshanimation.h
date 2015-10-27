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
			unsigned int parentID = -1;

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
		DECL_STRUCT(D3D10MY_ANIMATION_BONE_KEYFRAME)
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
			std::wstring name;

			// ���� : �ִϸ��̼��� �����ϴ� �� ä��
			std::vector<D3D10MY_ANIMATION_BONE_KEYFRAME> boneFrames;

			// ���� :
			double tickPerSecond;

			// ���� : �ִϸ��̼� ���ӽð�
			double secDuration;

		};

		// ���� :
		DECL_STRUCT(D3D10MY_KEYFRAME_RECORD)
		{

			// ���� :
			unsigned int bone_id;

			// ���� : 
			unsigned int position_key;

			// ���� : 
			unsigned int rotation_key;

			// ���� : 
			unsigned int scale_key;

		};

		// ���� : 
		DECL_STRUCT(D3D10MY_ANIMATIONPOS_RECORD)
		{

			// ���� : 
			unsigned int aniamtion;

			// ���� : 
			double time;

			// ���� : 
			std::vector<D3D10MY_KEYFRAME_RECORD> keyframe;

			//
			std::vector<D3DXMATRIX> pos;

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

			/*
			���� : ������ �̷����� ������ ����, ������ �����ؼ� �ϳ� �ϳ� ���� �� ����.
			$ ���� 1 : ���� ���� ���� ���� �������� �ʱ� �ٶ�.
			*/
			DECL_FUNC_T(D3D10MY_ANIMATION_BONE_KEYFRAME *, setup2_AnimationBoneKeyFrame)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _channelOfAnimateBone);

			// ���� : 
			DECL_FUNC(userSet_AnimationBoneKey)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _channelOfAnimateBone,
				_In_ unsigned int _indexfAnimateKey,
				_In_ unsigned int _keyType,
				_In_ const float * _value);

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
			DECL_FUNC_T(unsigned int, get_NumOfAnimations)(
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
			DECL_FUNC_T(const D3D10MY_ANIMATION *, fine_AnimationFromName)(
				_In_ const wchar_t * _nameOfAnimation)const;

			// ���� :
			DECL_FUNC_T(const D3D10MY_ANIMATION *, fine_AnimationFromID)(
				_In_  unsigned int _id)const;

			// ���� :
			DECL_FUNC_T(unsigned int, fine_AnimationIDFromName)(
				_In_ const wchar_t * _nameOfAnimation)const;

			// ���� :
			DECL_FUNC_T(const D3D10MY_ANIMATION_BONE_KEYFRAME &, get_BoneKeyFrame)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _channelOfAnimateBone)const;

			// ���� :
			DECL_FUNC_T(void, create_Pos)(
				_Out_ D3D10MY_ANIMATIONPOS_RECORD & _pos,
				_In_ unsigned int _indexOfAnimation,
				_In_ double _time);

			// ���� :
			DECL_FUNC_T(void, trans_Pos)(
				_Out_ D3D10MY_ANIMATIONPOS_RECORD & _pos,
				_In_ double _elapsedTime);

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