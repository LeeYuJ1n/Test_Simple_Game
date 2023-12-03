#pragma once

struct Vector2
{
    float x = 0.0f;
    float y = 0.0f;

    Vector2() = default;
    Vector2(float x, float y) : x(x), y(y) {};
    Vector2(POINT point) : x(point.x), y(point.y) {};
    Vector2(Float2 point) : x(point.x), y(point.y) {};

    Vector2 operator+(const Vector2& value) const
    {
        return Vector2(x + value.x, y + value.y);
    }
    Vector2 operator-(const Vector2& value) const
    {
        return Vector2(x - value.x, y - value.y);
    }
    Vector2 operator*(const Vector2& value) const
    {
        return Vector2(x * value.x, y * value.y);
    }
    Vector2 operator/(const Vector2& value) const
    {
        return Vector2(x / value.x, y / value.y);
    }
    Vector2 operator*(const float& value) const
    {
        return Vector2(x * value, y * value);
    }
    Vector2 operator/(const float& value) const
    {
        return Vector2(x / value, y / value);
    }

    void operator+=(const Vector2& value)
    {
        x += value.x;
        y += value.y;
    }
    void operator-=(const Vector2& value)
    {
        x -= value.x;
        y -= value.y;
    }
    void operator*=(const float& value)
    {
        x *= value;
        y *= value;
    }
    void operator/=(const float& value)
    {
        x /= value;
        y /= value;
    }

    float Length() const
    {
        return sqrt(x * x + y * y);
    }

    void Normalize()
    {
        float length = Length();

        x /= length;
        y /= length;
    }

    Vector2 GetNormalized() const
    {
        float length = Length();

        return Vector2(x / length, y / length);        
    }

    float Angle() const
    {
        return atan2(y, x);
    }


    //���Ϳ� ����� ����� �߰�����
    
    // �Լ� �������̵��� �ٸ� ���� : �� ������ ��� �߿����� ���� ��������... �����ڸ� �������̵��ϴ� ��
    // -> ������ �������̵�
    Vector2 operator* (const Matrix& value) const
    {
        Float2 coord(x, y); //x�� y��� ����� ���Ǵ� Float2 ����
        // ��Ģ���꿡�� int result ����� �� result�� return �ߴ� �Ͱ� ���� ���

        XMVECTOR tmp = XMLoadFloat2(&coord); //���̷�Ʈx�� ���ͷ� ��ȯ

        tmp = XMVector2TransformCoord(tmp, value); // ��Ŀ��� ���Ͱ� ���� ��ǥ���� �ٽ� ���ͷ� �ǵ��

        //coord�� tmp ������ ��ݿ�
        XMStoreFloat2(&coord, tmp);

        return coord; //�ش� Float2�� ������ Vector2�� �ٽ� ��ȯ
    }

    // ���� �迡... ���������ڵ�?
    void operator*= (const Matrix& value)
    {
        Float2 coord(x, y);
        XMVECTOR tmp = XMLoadFloat2(&coord);
        tmp = XMVector2TransformCoord(tmp, value);

        XMStoreFloat2(&coord, tmp);

        //���ǰ� ��������� x, y ��ġ(���� �� ����)�� �� ���(���� ���) �Ҵ�
        x = coord.x;
        y = coord.y;
    }


    // ����(�������� ������ ��)�� ����(�� ���� ������ ���ڷ� ǥ���� ��, ����) �ۼ�

    // ����
    // ��� ���Ͷ�� �Ѵ� (���� �ִ� ����ȭ�� �򰥸��� �� �ȴ�)
    Vector2 Normal()
    {
        return Vector2(-y, x); //x�� ��ǥ�� y�� ����, y�� ��ǥ�� �������� x�� ����
    }

    //����(����)
    float Dot(Vector2 input) const
    {
        return (x * input.x) + (y * input.y);

        // ������ �ﰢ�Լ� Ȥ�� ��Ľ��� �̿��� ���ϱ� ����� ���;� ������...
        // ���̷�Ʈ x������ ������ ����� �Ǿ�� �� ���⺤�Ͱ� ����ȭ�� �̹� �Ǿ� �ִ�
        // = ���̰� 1, x y ��ǥ�� �̹� �ﰢ�Լ����� �ڻ��� ���ο� �����ϴ� ��ǥ�� �Ǿ� �ִ�
        // �׷��� ������ input�� �̸� ����ȭ�� �صθ� ���ϴ� �������� �ڵ����� ������ ���� �κб��� ����� ������
    }
};