#pragma once
#include <vector>
#include <DirectXMath.h>

//This class contains the index triangles for any piece of geometry. For example
// A cube will hold a reference to a triangle list which will create a structure that will return
// It then returns the value to the object.

template<class T>
class IndexTriangleList
{
public:
	IndexTriangleList() = default;
	IndexTriangleList(std::vector<T> verts_in, std::vector<unsigned short> indices_in)
		:
		vertices(std::move(verts_in)),
		indices(std::move(indices_in))
	{
		assert(vertices.size() > 2);
		assert(indices.size() % 3 == 0);
	}
	void Transform(DirectX::FXMMATRIX matrix)
	{
		for (auto& v : vertices)
		{
			const DirectX::XMVECTOR pos = DirectX::XMLoadFloat3(&v.pos);
			DirectX::XMStoreFloat3(
				&v.pos,
				DirectX::XMVector3Transform(pos, matrix)
			);
		}
	}

public:
	//Vertex and indices
	std::vector<T> vertices;
	std::vector<unsigned short> indices;
};