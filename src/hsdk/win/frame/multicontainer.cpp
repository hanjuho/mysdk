#include "multicontainer.h"



using namespace hsdk::frame;


//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_DESTRUCTOR(MultiContainer<INDEX>, MultiContainer)(void)
{
	for (unsigned int index = 0; index < INDEX; ++index)
	{
		m_Container = m_Buffer[_index];
		Container::clear();
	}
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(MultiContainer<INDEX>, void, select_Buffer)(
	_In_ unsigned int _index,
	_In_ bool _store)
{
	if (_index < INDEX || _index == m_CurrentBuffer)
	{
		return;
	}

	if (_store)
	{
		m_Buffer[m_CurrentBuffer] = m_Container;

		m_Container.clear();
		m_Container = m_Buffer[_index];
	}
	else
	{
		Container::clear();
		m_Container = m_Buffer[_index];
	}

	m_CurrentBuffer = _index;
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(MultiContainer<INDEX>, void, clear)(
	_X_ void)
{
	Container::clear();
	m_Buffer[m_CurrentBuffer].clear();
}