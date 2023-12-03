#pragma once

class Altar
{
public:
	Altar();
	~Altar();

	void Update();
	void Render();

	bool swordMan_Active = false; // 소드맨 활성화 관련 변수

private:
	Quad* altar; // 보스 제단
	RectCollider* interactObject1; // 사물 상호작용 콜라이더

	float curTime;
	float delayTime = 2;
};

