#include "Framework.h"

Transform::Transform()
{
    world = XMMatrixIdentity(); // ������� �����
}

void Transform::UpdateWorld() // ���⼭�� ���� = �ڱ� ���� = �ڱ��� ����
{
    // ũ��, ȸ��, ��ġ ���� ��ķ� ���
    S = XMMatrixScaling(localScale.x, localScale.y, 1.0f);
    //z�ุ�� �ƴ� 3��ȸ�� (��ġ, ���, �Ѹ�) ���� �Լ��� ȣ��
    // ��ġ = x ȸ��, �յ� ���Ʒ��� ������
    // ��� = y ȸ��, �¿�� ���ۺ���
    // �Ѹ� = z ȸ��, �Һ��ϵ��� ��û��û
    R = XMMatrixRotationRollPitchYaw(localRotation.x,
        localRotation.y, localRotation.z);
    T = XMMatrixTranslation(localPosition.x, localPosition.y, 0.0f);

    // ���� ������ ����ġ�� �翬�� (�ʿ��ϸ� ���� ��ġ�� ������ �ٲ� �� �ִ�)
    P = XMMatrixTranslation(pivot.x, pivot.y, 0.0f);
    IP = XMMatrixInverse(nullptr, P);

    //������ ����� ����� ��� �����ؼ� ���忡 ����
    world = IP * S * R * T * P;

    // ���⼭���� ������ �����, ������� ��� ������ �ۿ��� �̿��ϰų� �� �� �ֵ��� �� ��

    // "�� Ʈ�������� �ٸ� Ʈ�������� �پ����� ���, �� Ʈ���������� ���� ������ �����Ѵ�"
    if (parent)
        world *= parent->world;

    // ���� ����� ���ؼ� (Store : ����, Ȥ�� "Ȯ��")
    XMStoreFloat4x4(&matWorld, world);
    right = Vector2(matWorld._11, matWorld._12); //���� ������ "������" (�� ���ص��� ���� ��� � ���δ�)
    up = Vector2(matWorld._21, matWorld._22);    //���� ������ "����"

    //�ܺη� ���̱� ���� ������ ������
    XMVECTOR outS, outR, outT;
    XMMatrixDecompose(&outS, &outR, &outT, world);

    Float2 tempPos, tempScale;
    XMStoreFloat2(&tempPos, outT);
    XMStoreFloat2(&tempScale, outT);

    //�۷ι� ���忡 ����� ������ �̿��ؼ� "��ü ȭ�� ���� ��ġ"�� ���Ѵ�
    globalPosition = tempPos;
    globalScale = tempScale;
}

void Transform::RenderUI()
{
    // ImGUI�� ����ؼ� Ʈ�������� ���� ��� (���� ���� ��, ��ȸ�� ������ ���캸��)

    ImGui::Text(tag.c_str());

    string temp = tag + "_Pos";
    ImGui::DragFloat2(temp.c_str(), (float*)&localPosition, 1.0f);

    temp = tag + "_Rot";
    Float3 rot;
    rot.x = XMConvertToDegrees(localRotation.x);
    rot.y = XMConvertToDegrees(localRotation.y);
    rot.z = XMConvertToDegrees(localRotation.z);

    ImGui::DragFloat3(temp.c_str(), (float*)&rot, 1.0f, -180, 180);

    localRotation.x = XMConvertToRadians(rot.x);
    localRotation.y = XMConvertToRadians(rot.y);
    localRotation.z = XMConvertToRadians(rot.z);

    temp = tag + "_Scale";
    ImGui::DragFloat2(temp.c_str(), (float*)&localScale, 0.1f);
}
