#include "d3d10_mesh.h"



using namespace hsdk::direct3d;


//--------------------------------------------------------------------------------------
// D3D10_Mesh impl
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
IMPL_FUNC_T(void, hsdk::direct3d::mesh::meshClear)(
	_Out_ D3D10_Mesh * _mesh)
{
	_mesh->meshPath.clear();
	_mesh->materials.clear();
	_mesh->meshs.clear();
}
