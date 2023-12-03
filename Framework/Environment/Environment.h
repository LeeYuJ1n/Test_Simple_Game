#pragma once

class Environment : public Singleton<Environment>
{
private:
    friend class Singleton;

    Environment();
    ~Environment();

private:
    void CreateProjection();
    void CreateSamplerState();
    void CreateBlendState();
    void CreateRasterizerState(); // ������ȭ ���� �Լ�

public:
    // ���� ����, �߰� ���� ���� : �ܺο��� �� ��� �� ��ü�� �׶��׶� ������
    void SetAlphaBlend();
    void SetAdditiveBlend();

private:
    MatrixBuffer* projectionBuffer;

    ID3D11SamplerState* samplerState; // �ؽ�ó ���ø�(�⺻ ���)�� ���� ����
    ID3D11BlendState* blendState; // ���� (�� ��ó��)�� ���� ����

    ID3D11RasterizerState* rasterizerState; // �����Ͷ�����(���Ϳ� ���̴��� ����Ϳ� �ȼ��� �ٲ��ִ� ��)�� ���� ����
    // ������ ���� Ȯ���� ������ �� �ִ�
    // �����Ͷ���� ������ ������ ����� �ᱹ ����Ϳ� �ٷ� �����״ϱ�

    // 2��, 3�� ���� � ����� �߰� ���� ����(���� ���� ��)
    ID3D11BlendState* alphaBlendState; // ���� ���� ����
    ID3D11BlendState* additiveBlendState; // ������ �߰��� ��� ���� ����

    // �� ������ ���� ������ �߰��� �ؼ� �������� �ϳ��� ȭ�� ��� ������ ��ġ�� ���� ����
};