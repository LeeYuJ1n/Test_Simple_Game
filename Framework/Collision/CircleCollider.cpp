#include "Framework.h"

//�� �浹�� �����ϱ� ���� �ݶ��̴�

CircleCollider::CircleCollider(float radius)
    : radius(radius)
{
    type = Type::CIRCLE;

    vertices.reserve(VERTEX_COUNT + 1);

    //������ ���� ���ư��鼭 64���� �����

    float theta = XM_2PI / VERTEX_COUNT; // ������ ���� ���� ���� 360���� ������ ������ ����
    for (UINT i = 0; i <= VERTEX_COUNT; i++)
    {
        float x = cos(theta * i) * radius; //���������� ���ư��鼭 ���ؽ� xy�� ���Ѵ�
        float y = sin(theta * i) * radius;

        vertices.emplace_back(x, y);
    }

    vertexBuffer = new VertexBuffer(vertices.data(),
        sizeof(VertexPos), vertices.size());
}

bool CircleCollider::IsPointCollision(Vector2 point)
{
    float distance = Distance(point, GlobalPos());

    return distance < Radius();
}

bool CircleCollider::IsRectCollision(RectCollider* rect, Vector2* overlap)
{
    return rect->IsCircleCollision(this);
    //winAPI�� ����������, ��/�簢 �浹�� �׳� �簢 �ʿ� �Լ��� ���ѱ��
}

//������ �浹�� �׳� ������ ���� �պ��� �Ÿ��� �ָ� �浹 �ƴ�
bool CircleCollider::IsCircleCollision(CircleCollider* circle)
{
    float distance = Distance(circle->GlobalPos(), GlobalPos());

    return distance < Radius() + circle->Radius();
}
