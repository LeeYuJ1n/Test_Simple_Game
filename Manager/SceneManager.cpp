#include "Framework.h"

SceneManager::~SceneManager()
{
    //�ʿ� �ִ� ��� �� �����
    for (pair<string, Scene*> scene : scenes)
    {
        delete scene.second;
    }
}

void SceneManager::Update()
{
    if (curScene == nullptr) return;

    curScene->Update();
}

void SceneManager::Render()
{
    if (curScene == nullptr) return;

    curScene->Render();
}

void SceneManager::PostRender()
{
    if (curScene == nullptr) return;

    curScene->PostRender();
}


void SceneManager::Register(string key, Scene* scene)
{
    //�ߺ���� ����
    if (scenes.count(key) > 0) return;

    scenes[key] = scene; // �̷��Ե� ���̸� �߰� ����
}

void SceneManager::ChangeScene(string key, bool init)
{
    if (scenes.count(key) == 0) return; //��� ���� ������ ����
    if (scenes[key] == curScene) return; //���� ����� �� ����̾ ����
    if (curScene != nullptr && init) {} //�ʱ�ȭ ����� �޾��� ���, ���⿡ �߰� �ڵ�

    curScene = scenes[key]; // �Ű������� ���� ������� �ٲٱ� (���� ������Ʈ���� ��� ��ü)

    if (init) curScene->Init(); //�ʱ�ȭ ���ΰ� true�� ��� �ʱ�ȭ���� ����
}