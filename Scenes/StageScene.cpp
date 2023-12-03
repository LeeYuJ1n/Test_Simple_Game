#include "Framework.h"
#include "StageScene.h"

StageScene::StageScene()
{
	// ¹è°æ
	bg = new Quad(L"Textures/TileMap.png");
	bg->Pos() = { CENTER_X, CENTER_Y };
	bg->Scale() = { 1, 1.03f };

	altar = new Altar();

	Tile1 = new RectCollider(Vector2(103, 115));
	Tile1->Pos() = { 52, 365 };
	Tile1->UpdateWorld();

	Tile2 = new RectCollider(Vector2(337, 117));
	Tile2->Pos() = { 444, 365 };
	Tile2->UpdateWorld();

	Tile3 = new RectCollider(Vector2(280, 115));
	Tile3->Pos() = { 1140, 365 };
	Tile3->UpdateWorld();

	Tile4 = new RectCollider(Vector2(329, 230));
	Tile4->Pos() = { 165, 115 };
	Tile4->UpdateWorld();

	Tile5 = new RectCollider(Vector2(845, 55));
	Tile5->Pos() = { 752, 28 };
	Tile5->UpdateWorld();

	Tile6 = new RectCollider(Vector2(105, 229));
	Tile6->Pos() = { 1227, 115 };
	Tile6->UpdateWorld();
}

StageScene::~StageScene()
{
	delete bg;
	delete altar;
}

void StageScene::Update()
{
	bg->Update();
	altar->Update();
}

void StageScene::Render()
{
	bg->Render();
	altar->Render();

	Tile1->Render();
	Tile2->Render();
	Tile3->Render();
	Tile4->Render();
	Tile5->Render();
	Tile6->Render();
}

void StageScene::Init()
{
}

void StageScene::PostRender()
{
}

void StageScene::Quit()
{
}
