#pragma once



#include "../hsdk_common.h"
#include <vector>
#include <hash_map>



namespace hsdk
{

	/*
	설명 : 모든 Key에 대해서 자동으로 ID를 할당하고, ID는 slot에 접근하는 index가 됨.
	$ 참고 : V가 동적으로 생성되길 원한다면 V = AutoDelete 혹은 AutoRelease를 사용하길 권장.
	$ 주의 : 단 한 번이라도 할당된 Key와 slot은0 제거할 수 없음.
	*/
	template <typename K, typename V> DECL_CLASS(AutoSlot) final
	{

		// 설명 : AutoID가 Vector<T>에 접근하기 위한 friend 선언.
		friend class AutoID;

		// 설명 : 생성자가 호출될 때마다 0부터 증가된 ID를 가지는 객체.
		DECL_STRUCT(AutoID)
		{
			// 생성자.
			CLASS_DECL_CONSTRUCTOR(AutoID)(
				_In_ AutoSlot * _slot)
				: my_id(_slot->my_autoID++)
			{
				// 유효성 검사.
				if (_slot->my_Buffer.size() !=
					_slot->my_Map.size())
				{
					throw HSDK_FAIL;
				}
				else
				{
					// 버퍼 용량 증가.
					_slot->my_Buffer.emplace_back(V());
				}
			}

			const unsigned int my_id;

		};

	public:

		// 생성자.
		CLASS_DECL_CONSTRUCTOR(AutoSlot)(
			_X_ void)
			: my_autoID(0)
		{

		};

		// 소멸자.
		CLASS_DECL_WARN_DESTRUCTOR(AutoSlot)(
			_X_ void)
		{

		};

		// 설명 : 슬롯의 개수 반환.
		CLASS_DECL_FUNC_T(unsigned int, size)(
			_X_ void)
		{
			return my_Buffer.size();
		}

		// 설명 : 슬롯 초기화.
		CLASS_DECL_FUNC_T(void, clear)(
			_X_ void)
		{
			my_autoID = 0;
			my_Buffer.clear();
			my_Map.clear();
		}

		// 설명 : << 연산자에 대해 key의 index를 반환.
		CLASS_DECL_FUNC_T(unsigned int, operator <<)(
			_In_ K & _key)
		{
			std::hash_map<K, h_AutoID>::iterator _where;

			/*
			_key 중복 검사
			$ 참고 1 : 사실 생성자에 파라미터가 없다면 hash_map은 중복 검사할 필요가 없음.
			$ 참고 2 : 아래 구문은 실제 hash_map::insert의 내용을 복사한 것.
			*/
			if ((_where = my_Map.lower_bound(_key)) == my_Map.end())
			{
				_where = my_Map.insert(
					/* pair<type1, type2>(x, y)*/
					std::pair<std::hash_map<K, h_AutoID>::key_type, std::hash_map<K, h_AutoID>::mapped_type>(
					std::move(_key), std::hash_map<K, h_AutoID>::mapped_type(this))).first;
			}

			return (_where->second).my_id;
		}

		/*
		설명 : [] 연산자에 대해 index의 V & 를 반환.
		$ 주의 : 할당되지 않은 index를 사용하면 예외 발생.
		$ 참고 : V 는 연속된 배열로 만들어졌음.
		*/
		CLASS_DECL_FUNC_T(V &, operator [])(
			_In_ unsigned int index)
		{
			return my_Buffer[index];
		}

		// 설명 : [] 연산자에 대해 V & 를 반환.
		CLASS_DECL_FUNC_T(V &, operator [])(
			_In_ K & _key)
		{
			return my_Buffer[this->operator<<(_key)];
		}

		// ! 연산자에 대해 CONST std::vector<V> * 를 반환.
		// $ 경고 : CONST std::vector<V> * 를 강제로 캐스팅하여 수정을 가할 경우, 어떤 경우에서든 치명적인 에러 발생.
		CLASS_DECL_FUNC_T(const std::vector<V> *, operator !)(
			_X_ void)
		{
			return &my_Buffer;
		}

	private:

		// 다음 Slot의 ID
		unsigned int my_autoID;

		// Key와 연관된 버퍼의 인덱스를 저장하는 hash_map
		std::hash_map<K const, AutoID> my_Map;

		// 실제 데이터를 저장하는 버퍼
		std::vector<V> my_Buffer;

	};

}