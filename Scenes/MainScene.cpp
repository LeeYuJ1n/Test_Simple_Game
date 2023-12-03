#include "Framework.h"
#include "MainScene.h"

MainScene::MainScene()
{
	background = new Quad(L"Textures/background.png");
	background->Pos() = { CENTER_X, CENTER_Y };

	loadingBar = new ProgressBar(L"Textures/blackBar.png");
	loadingBar->SetPosition({ CENTER_X, CENTER_Y / 3 });

	button = new Button(L"Textures/Start.png");
	button->Pos() = { CENTER_X, CENTER_Y  / 3 };

	Init();
}

MainScene::~MainScene()
{
	delete background;
	delete loadingBar;
	delete button;
}

void MainScene::Update()
{
	if (timePassed < timeTotal) timePassed += DELTA;
	if (timePassed > timeTotal) timePassed = timeTotal;
	if (timePassed == timeTotal)
	{
		if (!button->Active()) button->Active() = true;
		if (loadingBar->Active()) loadingBar->Active() = false;
	}

	loadingBar->Scale() = { timePassed / timeTotal, 1 };
	loadingBar->Update();
	button->Update();
	background->Update();

	if (LoadComplete())
	{
		if (KEY_DOWN(VK_RETURN))
		{
			SceneManager::Get()->ChangeScene("Stage");
		}
	}
}

void MainScene::Render()
{
	background->Render();
	loadingBar->Render();
	button->Render();
}

void MainScene::PostRender()
{

}

void MainScene::Init()
{
	button->Active() = false; // ¹öÆ° ¼û±â±â
	loadingBar->Scale() = { 0, 1 };
	timePassed = 0;

	button->SetEvent(bind(GlobalEvent(), "LoadScene", "Stage"));
}

void MainScene::Quit()
{

}
