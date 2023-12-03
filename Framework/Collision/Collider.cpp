#include "Framework.h"

// ���� ���� ��ħ�� ��쿡 ��� �����Ϸ��°��� ���ϴ� Ŭ����

Collider::Collider()
{
    // ��ħ �� ��ü�� �Ǻ��Ϸ��� �������ٴ� �� �Ǻ��� ����� �ð�ȭ�ϱ� ���ؼ�
    vertexShader = Shader::AddVS(L"VertexPos.hlsl");
    pixelShader = Shader::AddPS(L"PixelPos.hlsl");

    // �Ǻ��� ���� �������� �޾ƿ��� (ũ��, ��ġ, ȸ��)
    worldBuffer = new MatrixBuffer();

    // �ٽ� �ð�ȭ
    colorBuffer = new ColorBuffer();
    colorBuffer->Get() = { 0, 1, 0, 1 };
}

Collider::~Collider()
{
    delete vertexBuffer;

    delete colorBuffer;
    delete worldBuffer;
}

void Collider::Update()
{
    Transform::UpdateWorld();

    // �ݶ��̴� Ȱ��ȭ ���� ��� 2. �θ� Ʈ�������� Ȱ��ȭ ������ �޾Ƽ� Update �� �ٷ� �ݿ�
    // -> ��Ģȭ, �� ����, ��, ��� �߽��ڵ忡 �����ؼ� �߸� ¥�� �� ���� ����
    // �̷��� �θ� Ʈ�������� Ȱ��ȭ ������ �ٸ� ��ɿ����� �� ���, �Ʒ� �ڵ� �� ������
    // Tranform Ŭ���� ������ �Ű��ִ� ���� �� ���� ���� �ִ�! (��ũ�� ��ž)
    if (parent != nullptr) isActive = parent->Active();
    if (!isActive) return;


}

void Collider::Render()
{
    if (!isActive) return;

    // �Ǻ� ����� �ð�ȭ�ϱ� ���� ���� ������, ���۸� ��� ���

    worldBuffer->Set(world);
    worldBuffer->SetVS(0);
    colorBuffer->SetPS(0);

    vertexBuffer->Set(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    vertexShader->Set();
    pixelShader->Set();

    DC->Draw(vertices.size(), 0);
}

bool Collider::IsCollision(Collider* collider)
{
    // ���ƴ°�? �� �Ǻ�

    if (!Active()) return false;
    if (!collider->Active()) return false;

    // �ε�ģ ��ü�� Ÿ���� �Ǻ��ؼ� �ش� Ŭ������ �纯ȯ�ϰ� ���� �Լ��� ȣ��

    switch (collider->type)
    {
    case Collider::Type::RECT:
        return IsRectCollision((RectCollider*)collider);
    case Collider::Type::CIRCLE:
        return IsCircleCollision((CircleCollider*)collider);
    }

    return false;
}
