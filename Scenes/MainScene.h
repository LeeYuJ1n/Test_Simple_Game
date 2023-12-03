#pragma once
class MainScene : public Scene
{
public:
	MainScene();
	~MainScene();

	void Update();
	void Render();

	void PostRender();
	void Init();
	void Quit();

	bool LoadComplete() { return ((timePassed / timeTotal) >= 1); }
private:

	Quad* background;

	ProgressBar* loadingBar;
	Button* button;

	float timePassed;
	float timeTotal = 2;

};

