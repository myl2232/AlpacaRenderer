#include "Mesh.h"

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

Mesh* Mesh::CreateTrangle()
{
	Mesh* mesh = new Mesh();
	Vector3 v1(-1, -1, 0); Color c1(1.0f, 0, 0, 1.0f);
	Vector3 v2(1, -1, 0); Color c2(0, 1.0f, 0, 1.0f);
	Vector3 v3(0, 0, 0); Color c3(0, 0, 1.0f, 1.0f);
	Vertex p1(v1, c1, 0, 0);
	Vertex p2(v2, c2, 0, 1);
	Vertex p3(v3, c3, 1, 1);
	
	mesh->vertexBuffer.push_back(p1);
	mesh->vertexBuffer.push_back(p2);
	mesh->vertexBuffer.push_back(p3);

	int indexArray[] = { 0, 1, 2 };
	//����ֱ��תvector https://blog.csdn.net/sagittarius_warrior/article/details/54089242
	std::vector<int> index(indexArray, indexArray + sizeof(indexArray) / sizeof(int));
	mesh->indexBuffer = index;
	return mesh;
}

Mesh* Mesh::CreatePlane()
{
	Mesh* mesh = new Mesh();
	Vector3 v1(-1,  1, 0); Color c1(1.0f, 0, 0, 1.0f);
	Vector3 v2( 1,  1, 0); Color c2(0, 1.0f, 0, 1.0f);
	Vector3 v3( 1, -1, 0); Color c3(0, 0, 1.0f, 1.0f);
	Vector3 v4(-1, -1, 0); Color c4(1.0f, 0, 0, 1.0f);
	Vertex p1(v1, c1, 0, 0);
	Vertex p2(v2, c2, 1, 0);
	Vertex p3(v3, c3, 1, 1);
	Vertex p4(v4, c4, 0, 1);

	mesh->vertexBuffer.push_back(p1);
	mesh->vertexBuffer.push_back(p2);
	mesh->vertexBuffer.push_back(p3);
	mesh->vertexBuffer.push_back(p4);

	int indexArray[] = { 0, 1, 2, 0, 2, 3};
	//����ֱ��תvector https://blog.csdn.net/sagittarius_warrior/article/details/54089242
	std::vector<int> index(indexArray, indexArray + sizeof(indexArray) / sizeof(int));
	mesh->indexBuffer = index;
	return mesh;
}

Mesh* Mesh::CreateCube()
{
	return NULL;
}

void Mesh::DrawElement(ApcDevice* device)
{
	for (int i = 0; i < indexBuffer.size(); i = i + 3)
	{
		Vertex p1 = vertexBuffer[indexBuffer[i]];
		Vertex p2 = vertexBuffer[indexBuffer[i + 1]];
		Vertex p3 = vertexBuffer[indexBuffer[i + 2]];
		device->DrawPrimitive(p1, p2, p3);
	}
}