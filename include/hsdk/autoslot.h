#pragma once



#include "../hsdk_common.h"
#include <vector>
#include <hash_map>



namespace hsdk
{

	/*
	���� : ��� Key�� ���ؼ� �ڵ����� ID�� �Ҵ��ϰ�, ID�� slot�� �����ϴ� index�� ��.
	$ ���� : V�� �������� �����Ǳ� ���Ѵٸ� V = AutoDelete Ȥ�� AutoRelease�� ����ϱ� ����.
	$ ���� : �� �� ���̶� �Ҵ�� Key�� slot��0 ������ �� ����.
	*/
	template <typename K, typename V> DECL_CLASS(AutoSlot) final
	{

		// ���� : AutoID�� Vector<T>�� �����ϱ� ���� friend ����.
		friend class AutoID;

		// ���� : �����ڰ� ȣ��� ������ 0���� ������ ID�� ������ ��ü.
		DECL_STRUCT(AutoID)
		{
			// ������.
			CLASS_DECL_CONSTRUCTOR(AutoID)(
				_In_ AutoSlot * _slot)
				: my_id(_slot->my_autoID++)
			{
				// ��ȿ�� �˻�.
				if (_slot->my_Buffer.size() !=
					_slot->my_Map.size())
				{
					throw HSDK_FAIL;
				}
				else
				{
					// ���� �뷮 ����.
					_slot->my_Buffer.emplace_back(V());
				}
			}

			const unsigned int my_id;

		};

	public:

		// ������.
		CLASS_DECL_CONSTRUCTOR(AutoSlot)(
			_X_ void)
			: my_autoID(0)
		{

		};

		// �Ҹ���.
		CLASS_DECL_WARN_DESTRUCTOR(AutoSlot)(
			_X_ void)
		{

		};

		// ���� : ������ ���� ��ȯ.
		CLASS_DECL_FUNC_T(unsigned int, size)(
			_X_ void)
		{
			return my_Buffer.size();
		}

		// ���� : ���� �ʱ�ȭ.
		CLASS_DECL_FUNC_T(void, clear)(
			_X_ void)
		{
			my_autoID = 0;
			my_Buffer.clear();
			my_Map.clear();
		}

		// ���� : << �����ڿ� ���� key�� index�� ��ȯ.
		CLASS_DECL_FUNC_T(unsigned int, operator <<)(
			_In_ K & _key)
		{
			std::hash_map<K, h_AutoID>::iterator _where;

			/*
			_key �ߺ� �˻�
			$ ���� 1 : ��� �����ڿ� �Ķ���Ͱ� ���ٸ� hash_map�� �ߺ� �˻��� �ʿ䰡 ����.
			$ ���� 2 : �Ʒ� ������ ���� hash_map::insert�� ������ ������ ��.
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
		���� : [] �����ڿ� ���� index�� V & �� ��ȯ.
		$ ���� : �Ҵ���� ���� index�� ����ϸ� ���� �߻�.
		$ ���� : V �� ���ӵ� �迭�� ���������.
		*/
		CLASS_DECL_FUNC_T(V &, operator [])(
			_In_ unsigned int index)
		{
			return my_Buffer[index];
		}

		// ���� : [] �����ڿ� ���� V & �� ��ȯ.
		CLASS_DECL_FUNC_T(V &, operator [])(
			_In_ K & _key)
		{
			return my_Buffer[this->operator<<(_key)];
		}

		// ! �����ڿ� ���� CONST std::vector<V> * �� ��ȯ.
		// $ ��� : CONST std::vector<V> * �� ������ ĳ�����Ͽ� ������ ���� ���, � ��쿡���� ġ������ ���� �߻�.
		CLASS_DECL_FUNC_T(const std::vector<V> *, operator !)(
			_X_ void)
		{
			return &my_Buffer;
		}

	private:

		// ���� Slot�� ID
		unsigned int my_autoID;

		// Key�� ������ ������ �ε����� �����ϴ� hash_map
		std::hash_map<K const, AutoID> my_Map;

		// ���� �����͸� �����ϴ� ����
		std::vector<V> my_Buffer;

	};

}