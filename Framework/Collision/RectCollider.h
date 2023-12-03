#pragma once

// ��Ʈ �ݶ��̴� : �ݶ��̴� Ŭ������ �޾Ƽ� �簢���� �ٸ� ������ ������ ���� ����Ϸ��� Ŭ����

class RectCollider : public Collider
{
public:

    // ������� �ε�ģ �� ���̾��� ���, �ش� ���� �簢���� ������ �Ǻ��ϱ� ���� ����� ����ü
    struct ObbDesc // O : ��, BB : �簢���� ��Ÿ���� ��ȣ�� ���� �� �ϳ�, AA, BB, CC��..., Desc : descript, ����, �ظ�, �м�
    {
        Vector2 position;
        Vector2 axis[2];
        Vector2 halfSize;
    };

public:
    RectCollider(Vector2 size);
    ~RectCollider() = default;

    // �ݶ��̴��� �ִ� �߻��Լ��� ���⼭ �������̵�
    virtual bool IsPointCollision(Vector2 point) override;
    virtual bool IsRectCollision(RectCollider* rect, Vector2* overlap) override;
    virtual bool IsCircleCollision(CircleCollider* circle) override;

    //�� �ݶ��̴�(�簢���� �ݶ��̴� = �ڱ⵵ �簢��) ����
    Vector2 Size() { return size * GlobalScale(); }
    Vector2 Half() { return Size() * 0.5f; }

    Vector2 LeftTop();
    Vector2 LeftBottom();
    Vector2 RightTop();
    Vector2 RightBottom();

    float L();
    float R();
    float T();
    float B();

    ObbDesc GetObb();

private:

    //��ü���� ����� ���� ���� �浹 �Ǻ� �Լ�

    //AABB : AA��� �簢���� BB��� �簢���� ���� ���, OBB : �� O�� �簢�� BB�� ���� ���
    bool IsAABB(RectCollider* rect, Vector2* overlap);
    bool IsOBB(RectCollider* rect);

    // ���� ���� ������ ��ġ�� ���� ������ ������ ����°�?
    bool IsSeperate(Vector2 sperateAxis, ObbDesc box1, ObbDesc box2);

private:
    Vector2 size;

    ObbDesc obbDesc;
};