#include "multicontainer.h"


//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_CONSTRUCTOR(hsdk::frame::MultiContainer<INDEX>, MultiContainer)(
	_In_ PARENT_RELATION _relation)
	: Container(_relation)
{

}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_DESTRUCTOR(hsdk::frame::MultiContainer<INDEX>, MultiContainer)(void)
{
	for (unsigned int index = 0; index < INDEX; ++index)
	{
		m_Container = m_Buffer[index];
		Container::clear();
	}
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, void, select_Buffer)(
	_In_ unsigned int _index,
	_In_ bool _store)
{
	if (!(_index < INDEX) || _index == m_CurrentBuffer)
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
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, unsigned int, get_CurrentBuffer)(
	_X_ void)
{
	return m_CurrentBuffer;
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, void, reset)(
	_X_ void)
{
	for (unsigned int index = 0; index < INDEX; ++index)
	{
		m_Container = m_Buffer[index];
		Container::clear();
	}
	m_CurrentBuffer = 0;

	m_Layout.~AutoDelete();
	m_Graphics = Graphics();
}

//--------------------------------------------------------------------------------------
template<unsigned int INDEX> CLASS_IMPL_FUNC_T(hsdk::frame::MultiContainer<INDEX>, void, clear)(
	_X_ void)
{
	Container::clear();
	m_Buffer[m_CurrentBuffer].clear();
}