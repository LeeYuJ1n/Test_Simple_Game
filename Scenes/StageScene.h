#pragma once

class StageScene : public Scene
{

public:
	StageScene();
	~StageScene();

	virtual void Update() override;
	virtual void Render() override;

	void Init();
	void PostRender();
	void Quit();

private:
	Quad* bg; // ¹è°æ
	Altar* altar;

	RectCollider* Tile1;
	RectCollider* Tile2;
	RectCollider* Tile3;
	RectCollider* Tile4;
	RectCollider* Tile5;
	RectCollider* Tile6;

	Destroyer* player;
};

