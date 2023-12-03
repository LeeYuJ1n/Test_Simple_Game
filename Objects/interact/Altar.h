#pragma once

class Altar
{
public:
	Altar();
	~Altar();

	void Update();
	void Render();

	bool swordMan_Active = false; // �ҵ�� Ȱ��ȭ ���� ����

private:
	Quad* altar; // ���� ����
	RectCollider* interactObject1; // �繰 ��ȣ�ۿ� �ݶ��̴�

	float curTime;
	float delayTime = 2;
};

