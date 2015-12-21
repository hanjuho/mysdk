#include "rendertargetcontainer.h"
#include "../direct3d/d3d10_renderer.h"
#include "../framework.h"


//--------------------------------------------------------------------------------------
template<typename CONTAINER> CLASS_IMPL_CONSTRUCTOR(hsdk::frame::RenderTargetContainer<CONTAINER>, RenderTargetContainer)(
	_In_ PARENT_RELATION _relation)
	: CONTAINER(_relation)
{
	m_Graphics.bgColor.w = 0.0f;
}

//--------------------------------------------------------------------------------------
template<typename CONTAINER> CLASS_IMPL_DESTRUCTOR(hsdk::frame::RenderTargetContainer<CONTAINER>, RenderTargetContainer)(void)
{
	reset();
}

//--------------------------------------------------------------------------------------
template<typename CONTAINER> CLASS_IMPL_FUNC_T(hsdk::frame::RenderTargetContainer<CONTAINER>, void, render)(
	_X_ void)
{
	if (is_Visible())
	{
		if (m_Render)
		{
			IF_SUCCEEDED(my_RenderTarget.begin(m_Graphics.bgColor))
			{
				direct3d::g_D3D10_Renderer.set_MatrixWorldViewProj(&direct3d::g_D3D10_identityMatrix);
				direct3d::g_D3D10_Renderer.set_ScalarPSTime(1.0f);
				if (m_Graphics.refTexture)
				{
					direct3d::g_D3D10_Renderer.set_ScalarVSFlag(0);
					direct3d::g_D3D10_Renderer.set_ScalarPSFlag(direct3d::PS_TEXTURE_0 | direct3d::PS_CALLFUNCTION_0 | direct3d::PS_TEXMATRIX_0);
					direct3d::g_D3D10_Renderer.render_UITexture(
						m_Graphics.refTexture,
						&m_Graphics.mTexcoord);
				}
				else
				{
					direct3d::g_D3D10_Renderer.set_ScalarVSFlag(0);
					direct3d::g_D3D10_Renderer.set_ScalarPSFlag(direct3d::PS_MARERIAL_0 | direct3d::PS_CALLFUNCTION_0);
					direct3d::g_D3D10_Renderer.render_UIRectangle(
						&m_Graphics.bgColor);
				}

				my_RenderTarget.viewport();

				auto begin = m_Container.begin();
				auto end = m_Container.end();
				while (begin != end)
				{
					(*begin)->render();
					++begin;
				}

				my_RenderTarget.end();
			}

			m_Render = FALSE;
		}

		direct3d::g_D3D10_Renderer.set_MatrixWorldViewProj(&m_Position);
		direct3d::g_D3D10_Renderer.set_ScalarVSFlag(0);
		direct3d::g_D3D10_Renderer.set_ScalarPSFlag(direct3d::PS_TEXTURE_0);
		direct3d::g_D3D10_Renderer.render_UITexture(
			my_RenderTarget.get_View(), &direct3d::g_D3D10_identityMatrix);
	}
}

//--------------------------------------------------------------------------------------
template<typename CONTAINER> CLASS_IMPL_FUNC_T(hsdk::frame::RenderTargetContainer<CONTAINER>, void, reform)(
	_X_ void)
{
	CONTAINER::reform();

	my_RenderTarget.initialize(
		(unsigned int)get_W(),
		(unsigned int)get_H());
}

//--------------------------------------------------------------------------------------
template<typename CONTAINER> CLASS_IMPL_FUNC_T(hsdk::frame::RenderTargetContainer<CONTAINER>, void, redraw)(
	_X_ void)
{
	CONTAINER::redraw();
	m_Render = TRUE;
}

//--------------------------------------------------------------------------------------
template<typename CONTAINER> CLASS_IMPL_FUNC_T(hsdk::frame::RenderTargetContainer<CONTAINER>, void, reset)(
	_X_ void)
{
	CONTAINER::reset();
	my_RenderTarget = direct3d::D3D10_RenderTarget();
}