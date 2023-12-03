#include "Framework.h"

#include "Scenes/MainScene.h"
#include "Scenes/StageScene.h"

GameManager::GameManager()
{
    Create();

    //로딩 씬 만들어서 scene에 할당
    loadingScene = new MainScene();
    scene = loadingScene;

    //씬 매니저로 써보기

    //씬 등록
    SceneManager::Get()->Register("Main", new MainScene());
    SceneManager::Get()->Register("Stage", new StageScene());

    //씬 중 하나로 전환
    SceneManager::Get()->ChangeScene("Stage");
}

GameManager::~GameManager()
{
    delete scene;

    Delete();
}

void GameManager::Update()
{
    DebugInput();

    Keyboard::Get()->Update();
    Timer::Get()->Update();

    SceneManager::Get()->Update();
}

void GameManager::Render()
{
    Device::Get()->Clear();

    SceneManager::Get()->Render();

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    string fps = "FPS : " + to_string(Timer::Get()->GetFPS());
    ImGui::Text(fps.c_str());

    ImGui::Render();
    // ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData()); imgui 출력

    Device::Get()->Present();
}

void GameManager::Create()
{
    Keyboard::Get();
    Timer::Get();
    Device::Get();
    Environment::Get();

    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hWnd);
    ImGui_ImplDX11_Init(DEVICE, DC);
}

void GameManager::Delete()
{
    Keyboard::Delete();
    Timer::Delete();
    Device::Delete();
    Shader::Delete();
    Texture::Delete();
    Environment::Delete();
    Audio::Delete();

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();

    ImGui::DestroyContext();
}

void GameManager::DebugInput()
{
    
}

void GameManager::ChangeScene(Scene* dest, bool toInit)
{
    scene = dest;
    if (toInit) scene->Init();
}