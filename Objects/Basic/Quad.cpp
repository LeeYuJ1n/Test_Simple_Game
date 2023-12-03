#include "Framework.h"

Quad::Quad(Vector2 size, Vector2 pos)
{
    CreateMesh(size, pos);
}

Quad::Quad(wstring file, Vector2 pos)
{
    SetTexture(file);             //�׸� ���Ͽ��� �ؽ�ó�� �ް�
    size = texture->GetSize();    //������ �������� ũ�⸦ ���ϰ�
    CreateMesh(size, pos);        //�ؽ�ó�� �°� �޽ø� ������
}

Quad::Quad(bool useTrim, wstring file, Vector2 startUV, Vector2 endUV)
{
    SetTexture(file);
    size = (endUV - startUV) * texture->GetSize(); // ���� ũ��(����) ��ŭ�� �ؽ�ó�� ���ϱ�
    CreateMesh(size, startUV, endUV);

    colorBuffer = new ColorBuffer();
}


//�ؽ�ó ���� (���߿� �ܻ� �޽ÿ��� �ؽ�ó�� ���� �� �ֵ��� �Ϸ���)
void Quad::SetTexture(wstring file)
{
    texture = Texture::Add(file);
}

Quad::~Quad()
{

}

void Quad::Render()
{
    if (colorBuffer != nullptr)
    {
        colorBuffer->SetPS(0);
    }
    //�ؽ�ó�� �ȼ� ���̴��� ����
    texture->PSSet();

    //�⺻ : ���ӿ�����Ʈ ���
    // - ��ӵ� Ŭ������ �⺻������ �θ�� ���� �Լ� ������ ������
    //   �׷��� �ʿ信 ���� �θ��� �Լ��� �������̵� ���� ���
    //   �θ��� �Լ� ����� �����ϱ� ���ؼ�, "�θ� Ŭ������ �Լ�"��
    //   ��Ȯ�� �����ؼ� ���� ȣ���� ���� �ִ�
    GameObject::Render(); // <-������ ���� �Լ�����, ���ӿ�����Ʈ�� ���� �Լ��� ���� ȣ�� ����
}

void Quad::CreateMesh(Vector2 size, Vector2 pos)
{
    //�簢���� �簢�����μ� �����ϱ� ���� ���¸� ���⼭ �����
    // ó�� ����� ���� "���ؽ� �ε��� �����"���� �� ������
    // ���̷�Ʈx ȯ�濡���� "�޽� ����(�����)"�̶�� �θ��� ��

    float left = pos.x - size.x * 0.5f;
    float right = pos.x + size.x * 0.5f;
    float top = pos.y + size.y * 0.5f;
    float bottom = pos.y - size.y * 0.5f;

    vertices.emplace_back(left, top, 0, 0);
    vertices.emplace_back(right, top, 1, 0);
    vertices.emplace_back(left, bottom, 0, 1);
    vertices.emplace_back(right, bottom, 1, 1);

    indices = { 0, 1, 2, 2, 1, 3 };

    vertexBuffer = new VertexBuffer(vertices.data(), sizeof(Vertex), vertices.size());
    indexBuffer = new IndexBuffer(indices.data(), indices.size());
}

void Quad::CreateMesh(Vector2 size, Vector2 startUV, Vector2 endUV)
{
    float left = -size.x * 0.5f;
    float right = size.x * 0.5f;
    float top = size.y * 0.5f;
    float bottom = -size.y * 0.5f;

    vertices.emplace_back(left, top, startUV.x, startUV.y);
    vertices.emplace_back(right, top, endUV.x, startUV.y);
    vertices.emplace_back(left, bottom, startUV.x, endUV.y);
    vertices.emplace_back(right, bottom, endUV.x, endUV.y);

    indices = { 0, 1, 2, 2, 1, 3 };

    vertexBuffer = new VertexBuffer(vertices.data(), sizeof(Vertex), vertices.size());
    indexBuffer = new IndexBuffer(indices.data(), indices.size());
}