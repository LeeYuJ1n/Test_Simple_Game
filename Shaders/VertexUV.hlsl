// ���ؽ� "UV" ���̴�

// �⺻�����δ� ���ؽ� ���̴��� ���°� ���� ����
// ���� : SV (���ؽ��� ���� ���� ����) ��� UV��� �ڷḦ ����Ѵ�

// UV : �ؽ�ó�� ��� ��ǥ�� ��Ī�Ѵ� (=�ؽ�ó�� Ʈ������ó�� �ڱ⸸�� ��ǥ ������ ���� �ִ�)

// ���� �� ��ü������.... �ؽ�ó �� ���α׷��ֿ��� ���̴� �ΰ� �ð� ���� ��ǥ���

// ���������δ� xyz 3���� ���ϸ� ������ ������, ���� ������ ��� �������� ǥ���� �ٸ��ٴ� ���� ��Ȯ�� �ϱ� ���ؼ� (�ǵ��� ����)

// �ڱ���� ����ϴ� ���� �̸��� u v w ��� ����Ѵ�. �׷��� UV ��ǥ��

// �������ڸ�, ���� ���л��� ��������...

// x y z : �Ϲ����� ��
// u v w : �ؽ��͸� ���� UV��ǥ

cbuffer WorldBuffer : register(b0)
{
    matrix world;
}

cbuffer ProjectionBuffer : register(b2)
{
    matrix projection;
}

struct VertexInput
{
    float4 pos : POSITION;
    float2 uv : UV;
};

struct VertexOutput
{
    float4 pos : SV_POSITION;
    float2 uv : UV;
};

VertexOutput VS(VertexInput input)
{
    VertexOutput output;
    output.pos = mul(input.pos, world);
    output.pos = mul(output.pos, projection);
    output.uv = input.uv;
	
    return output;
}