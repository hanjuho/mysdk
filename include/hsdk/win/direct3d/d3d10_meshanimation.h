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
			unsigned int parentID = -1;

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
		DECL_STRUCT(D3D10MY_ANIMATION_BONE_KEYFRAME)
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
			std::wstring name;

			// 설명 : 애니메이션이 제어하는 뼈 채널
			std::vector<D3D10MY_ANIMATION_BONE_KEYFRAME> boneFrames;

			// 설명 :
			double tickPerSecond;

			// 설명 : 애니메이션 지속시간
			double secDuration;

		};

		// 설명 :
		DECL_STRUCT(D3D10MY_KEYFRAME_RECORD)
		{

			// 설명 :
			unsigned int bone_id;

			// 설명 : 
			unsigned int position_key;

			// 설명 : 
			unsigned int rotation_key;

			// 설명 : 
			unsigned int scale_key;

		};

		// 설명 : 
		DECL_STRUCT(D3D10MY_ANIMATIONPOS_RECORD)
		{

			// 설명 : 
			unsigned int aniamtion;

			// 설명 : 
			double time;

			// 설명 : 
			std::vector<D3D10MY_KEYFRAME_RECORD> keyframe;

			//
			std::vector<D3DXMATRIX> pos;

		};

		// 설명 : 
		DLL_DECL_CLASS(D3D10_MeshAnimation)
		{

		public:

			// 설명 : 
			DECL_FUNC_T(void, clear)(
				_X_ void);

			// 설명 :
			DECL_FUNC(setup0)(
				_In_ unsigned int _numOfBones,
				_In_ unsigned int _numOfAnimation);

			/*
			설명 : 뼈대는 다음과 같은 규칙을 따라 기입해야 한다(이 객체에서 Bone's Node는 배열로 구성된다).
			$ 1. 계층 구조로 이루어진 뼈대를 중위 순회의 순서로 정렬.
			$ 2. 뼈대의 정보를 정렬된 순서대로 파라미터에 기입.
			$ 3. _lengthOfBone 파라미터는 현재 노드에서 종단 노드 까지의 모든 자식 노드 개수
			(직계 후손의 노드 개수가 아님).
			$ 4. _matrix 파라미터는 직계 부모 노드로부터 상대적 행렬 변위.
			*/
			DECL_FUNC(setup1_BoneNode)(
				_In_ unsigned int _indexOfBone,
				_In_ unsigned int _parentID,
				_In_ unsigned int _lengthOfBone,
				_In_ const wchar_t * _nameOfBone,
				_In_ const float * _matrix);

			// 설명 : 
			DECL_FUNC(setup1_Animation)(
				_In_ unsigned int _indexOfAnimation,
				_In_ const wchar_t * _nameOfAnimation,
				_In_ unsigned int _numOfAnimateBones,
				_In_ double _tickPerSecond,
				_In_ double _secondOfDuration);

			/*
			설명 : 굉장히 이례적인 데이터 삽입, 구조가 복잡해서 하나 하나 넣을 수 없음.
			$ 참고 1 : 뼈에 대한 지식 없이 수정하지 않길 바람.
			*/
			DECL_FUNC_T(D3D10MY_ANIMATION_BONE_KEYFRAME *, setup2_AnimationBoneKeyFrame)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _channelOfAnimateBone);

			// 설명 : 
			DECL_FUNC(userSet_AnimationBoneKey)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _channelOfAnimateBone,
				_In_ unsigned int _indexfAnimateKey,
				_In_ unsigned int _keyType,
				_In_ const float * _value);

			/*
			설명 : setup bone matrix.
			$ 참고 : _matrix parameter is bone's own matrix.
			*/
			DECL_FUNC(userSet_BoneMatrix)(
				_In_ unsigned int _indexOfBone,
				_In_ const float * _matrix);

			// 설명 :
			DECL_FUNC_T(unsigned int, get_NumOfBones)(
				_X_ void)const;

			// 설명 :
			DECL_FUNC_T(unsigned int, get_NumOfAnimations)(
				_X_ void)const;

			// 설명 :
			DECL_FUNC_T(const D3D10MY_BONE *, find_BoneFromName)(
				_In_ const wchar_t * _nameOfBone)const;

			// 설명 :
			DECL_FUNC_T(const D3D10MY_BONE *, find_BoneFromID)(
				_In_  unsigned int _id)const;

			// 설명 :
			DECL_FUNC_T(unsigned int, find_BoneIDFromName)(
				_In_ const wchar_t * _nameOfBone)const;

			// 설명 :
			DECL_FUNC_T(const D3D10MY_ANIMATION *, fine_AnimationFromName)(
				_In_ const wchar_t * _nameOfAnimation)const;

			// 설명 :
			DECL_FUNC_T(const D3D10MY_ANIMATION *, fine_AnimationFromID)(
				_In_  unsigned int _id)const;

			// 설명 :
			DECL_FUNC_T(unsigned int, fine_AnimationIDFromName)(
				_In_ const wchar_t * _nameOfAnimation)const;

			// 설명 :
			DECL_FUNC_T(const D3D10MY_ANIMATION_BONE_KEYFRAME &, get_BoneKeyFrame)(
				_In_ unsigned int _indexOfAnimation,
				_In_ unsigned int _channelOfAnimateBone)const;

			// 설명 :
			DECL_FUNC_T(void, create_Pos)(
				_Out_ D3D10MY_ANIMATIONPOS_RECORD & _pos,
				_In_ unsigned int _indexOfAnimation,
				_In_ double _time);

			// 설명 :
			DECL_FUNC_T(void, trans_Pos)(
				_Out_ D3D10MY_ANIMATIONPOS_RECORD & _pos,
				_In_ double _elapsedTime);

		private:

			// 설명 :
			std::map<std::wstring, unsigned int> my_BoneOfNames;

			// 설명 : 
			std::vector<D3D10MY_BONE> my_Bones;

			// 설명 :
			std::map<std::wstring, unsigned int> my_AnimationOfNames;

			// 설명 :
			std::vector<D3D10MY_ANIMATION> my_Animation;

		};

	}
}