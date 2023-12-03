#pragma once
class Font : public Singleton<Font>
{
	// ���ڸ� ��Ÿ���� ���� ������ ������ �����ϴ� �������� ���� Ŭ����
private:
	friend class Singleton;

	Font();
	~Font();

public:

	// ������ �ڷᱸ���� ��Ʈ ���� ������ �ְ� ���� �͸� �����̴ϱ� ������Ʈ, ������ �ϴ� ����

	// ������ ƽ���� ���ư��� �������ٴ� ȣ���� ���ؼ� ���ڸ� ����ϴ� �ɷ� (cpp�� cout, winAPI�� TextOut ���� �� �ǵ�)

	// ������Ʈ, ���� ���ٴ� ������ �ؽ�óó�� ������ �ְ� ���ų� �����ϴ� ���� �� �߿��� ��

	// ��Ʈ�� ���� �� ������ �ֱ�

	// �귯�� (������ ��), ������ ������ �ֱ�
	void AddColor(string key, float r, float g, float b, float a = 1);

	void AddStyle(string key, wstring font, float size = 18.0f,// �Ϲ������� �� ���� ���̴� �̸�(��Ÿ��)�� �Ἥ �Լ� ���
		DWRITE_FONT_WEIGHT weight = DWRITE_FONT_WEIGHT_NORMAL, // ������ ���� ó��, �⺻���� ����(����)
		DWRITE_FONT_STYLE style = DWRITE_FONT_STYLE_NORMAL, // ������ ��Ÿ�� ó��, �⺻���� ����
		DWRITE_FONT_STRETCH stretch = DWRITE_FONT_STRETCH_NORMAL); // ������ �����ڰ� ���� �߰� �۲�����, �⺻���� ����
	
	// �귯��, ���� ���� �����ϱ�
	void SetColor(string key);
	void SetStyle(string key);

	// ����̽��� �����ϱ�
	ID2D1DeviceContext* GetDC() { return context; }

	// �ؽ�Ʈ ��� ����
	void RenderText(string text, Float2 pos, Float2 size = Float2()); // �Ϲ� ���ڿ�
	void RenderText(wstring text, Float2 pos, Float2 size = Float2()); // ���� ���ڿ�

private:
	// ��Ʈ�� ������ �� ������

	// dwrite�� ���� ���� ����� �غ񹰵�
	// ���̷�Ʈ x���� �����ϴ� Ŭ������ ����ü �ڷ���� ���� �Ŷ�, �ϱ⺸�ٴ� �ʿ��� �� �˻��ϴ� ���� ȿ����

	ID2D1Factory1* factory; // ���� ����
	IDWriteFactory* writeFactory; // ���� ���� ����

	ID2D1Device* device; // ��� ����
	ID2D1DeviceContext* context; // ����ȭ�� ��� ��� ����

	ID2D1Bitmap1* targetBitmap; // ����ϱ� ���� ��Ʈ�� : ���̷�Ʈx������ ���ڵ� �׸��� ��

	// �������� ��Ʈ���� �޾Ƽ� ����ϱ� ���� ����, �Ʒ��δ� ��Ÿ�� ����

	map<string, ID2D1SolidColorBrush*> brushes; // �귯�ø� ����� ��
	map<string, IDWriteTextFormat*> formats; // ������ ������ ����� ��

	ID2D1SolidColorBrush* curBrush; // ���� ���õ� �귯��
	IDWriteTextFormat* curFormat; // ���� ���õ� ������ ����

};

