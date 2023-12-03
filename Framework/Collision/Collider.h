#pragma once

// ��API���� �츮�� ��� "��ġ�� �Ǻ��Ѵ�"�� ����� DX 2D�� �������� ��

// ���� ��� : �ݶ��̴� ����
// DX���� ��ü�� ��ġ�� �˾ƺ��� ������ �Լ��� �ֱ� �ϴ�
// -> �׷��� 3D��. (DX 2D��� �ϴ� ������ ȯ���� ���� ������)

// 2D���� ������ ���� ������ ��, �ش� �����͸� Ȯ���ϱ� ���ؼ���
// �ʿ������� "������ ���ƴ�"��� ����� ���� ������ �ʿ䰡 �ִ�

class Collider : public Transform
{
protected:
    enum class Type //�浹�� ������ Ÿ��
    {
        RECT, CIRCLE
    };

public:
    Collider();
    ~Collider();

    void Update();

    void Render(); //�ݶ��̴� ���� ����

    bool IsCollision(Collider* collider); //�ε��ƴ°�?

    // ���� / ��Ʈ�� / ��Ŭ�� ���ϰ� �ε��ƴ°�?
    // ���⼭�� �Ʒ� �Լ����� �߻� �Լ��� ������� �ִ�
    virtual bool IsPointCollision(Vector2 point) = 0;
    virtual bool IsRectCollision(class RectCollider* rect, Vector2* overlap = nullptr) = 0;
    virtual bool IsCircleCollision(class CircleCollider* circle) = 0;

    // �� ���ϱ�
    Float4& GetColor() { return colorBuffer->Get(); }

protected:
    Type type;

    // ������ ������ (��Ʈ���� �ƴϴ�) �޸𸮿� ����ϱ� ���� (��ϵ� �޸𸮸� �ޱ� ����) ����
    // -> winAPI�� ���� ������ DX������ �ٽ� �ޱ�
    VertexBuffer* vertexBuffer;
    vector<VertexPos> vertices;

private:

    //���̴� : ������
    VertexShader* vertexShader;
    PixelShader* pixelShader;

    //��ġ ũ�� ȸ���� ����
    MatrixBuffer* worldBuffer;
    ColorBuffer* colorBuffer;
};