#include "Framework.h"

Altar::Altar()
{
	// 보스
	altar = new Quad(L"Textures/BossAltar.png");
	altar->Scale() = { 1.5f, 1.5f };
	altar->Pos() = { 1110, 90 };
	altar->UpdateWorld();

	interactObject1 = new RectCollider(Vector2(130, 70));
	interactObject1->Pos() = { 1110, 90 };
	interactObject1->UpdateWorld();

	TARGET->Scale() = { 1.5f, 1.5f };
	PLAYER->Scale() = { 0.7f, 0.7f };
}

Altar::~Altar()
{
	delete altar;
	delete interactObject1;
}

void Altar::Update()
{
	PLAYER->Update();
	interactObject1->Update();

	if (interactObject1->L() <= PLAYER->destroyerArea->R() ||
		interactObject1->R() <= PLAYER->destroyerArea->L())
	{
		if (KEY_DOWN('E'))
		{
			TARGET->Pos() = { 1110, 150 };
			TARGET->Update();
			swordMan_Active = true;
		}
	}
}

void Altar::Render()
{
	altar->Render();
	PLAYER->Render();
	interactObject1->Render();

	if (swordMan_Active)
	{
		TARGET->Render();
	}
	if (!swordMan_Active)
	{
		// TODO : 나중에 필요하면 코드 추가
	}
}