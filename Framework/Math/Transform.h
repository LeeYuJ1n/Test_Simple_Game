#pragma once

class Transform
{
public:
    Transform();
    ~Transform() = default;

    void UpdateWorld();
    void RenderUI();

    // Ʈ�������� ��� ������ �ٱ����� �� �� �ֵ��� �ϴ� ���͵�

    // ������� ���� ������ ����ȭ�ؼ� ��ȯ�ϴ� �Լ�
    // ����ȭ : ������ ũ�� ������ ��ȿȭ�ϴ� ���, ����� ���� ������ �����
    Vector2 Right() { return right.GetNormalized(); }
    Vector2 Up() { return up.GetNormalized(); }

    // ������� ��ü ���迡���� ��ġ�� ũ�� (������ ���� ���� ������ ���� �Ǵϱ�)
    Vector2 GlobalPos() { return globalPosition; }
    Vector2 GlobalScale() { return globalScale; }

    // Ʈ�������� �θ�(��ӵ� ���� Ʈ������ ���ϱ�)
    // *������ �ʿ���°�? -> ������ �� Ŭ�������� ���� ���� �����ϸ� �Ǵϱ�...
    void SetParent(Transform* transform) { parent = transform; }
    void SetPivot(Vector2 pivot) { this->pivot = pivot; } //�൵ �ʿ��ϸ� ���ϱ�

    // Ȱ��ȭ
    bool& Active() { return isActive; }
    void SetActive(bool value) { isActive = value; } // ���ͱ��� �����

    // ������� Ʈ������ ���� ����
    // ���� �ִ� �Լ��� ����, ���⼭�� ���
    // �� ���� ���̴� Ʈ�������� �ٸ� Ʈ�������� �ڽ��� �� (�ٸ� ���� �θ��� ��) �߻�
    // ���� ��� ��ũ�� ��ž�� ���, ���� ��ġ�� ��ũ�� ��ġ. ������ ��� ��ġ��? ��ũ �ٷ� ��(=�������� �ʾ���)
    Vector2& Pos() { return localPosition; }
    Float3& Rot() { return localRotation; }
    Vector2& Scale() { return localScale; }

protected:
    string tag;

    // ��� ��ġ, ��� ȸ��, ��� ũ��
    Vector2 localPosition;
    Float3 localRotation = { 0, 0, 0 };
    Vector2 localScale = { 1, 1 };

    bool isActive = true;    

    Matrix world;

    Transform* parent = nullptr; // Ʈ�������� ���� ����� �ٸ� Ʈ�������� ���� ��� �ش� Ʈ�������� ������

private:

    Matrix S, R, T;
    Matrix P, IP;
    Vector2 pivot; //�� ����

    Vector2 right, up; //������, �� ������ ����ų ����
    Vector2 globalPosition, globalScale; //�۷ι� ���� (��� �繰�� ���̴� ��) ������ ��ġ, ũ�� ����

    XMFLOAT4X4 matWorld;
    
};