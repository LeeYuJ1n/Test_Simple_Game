#pragma once

class MatrixBuffer : public ConstBuffer
{
public:
    MatrixBuffer() : ConstBuffer(&matrix, sizeof(Matrix))
    {
        matrix = XMMatrixIdentity();
    }

    void Set(Matrix value)
    {
        matrix = XMMatrixTranspose(value);
    }

private:
    Matrix matrix;
};

// ���� ��Ÿ���� ������ �޸𸮿� �����ϱ� ���� ���� //��� ��� �� ��
class ColorBuffer : public ConstBuffer
{
public:
    ColorBuffer() : ConstBuffer(&color, sizeof(Float4))
    {
        color = { 1, 1, 1, 1 };
    }

    void Set(Float4 color)
    {
        this->color = color;
    }

    Float4& Get() { return color; }

private:
    Float4 color = { 1, 1, 1, 1 }; // �����ʱ�ȭ, Ȯ�λ��
};

// ������ ���� ���� �����
class IntValueBuffer : public ConstBuffer
{
public:
    IntValueBuffer() : ConstBuffer(values, sizeof(int) * 4) {}
    int* Get() { return values; }

private:
    int values[4] = { };
};

// �Ҽ��� ���� ���� �����
class FloatValueBuffer : public ConstBuffer
{
public:
    FloatValueBuffer() : ConstBuffer(values, sizeof(float) * 4) {}
    float* Get() { return values; }

private:
    float values[4] = { };
};