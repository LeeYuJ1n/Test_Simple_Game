#pragma once

class SceneManager : public Singleton<SceneManager>
{
private:
    friend class Singleton;

    SceneManager() = default;
    ~SceneManager();

public:

    void Update();
    void Render();
    void PostRender();

    // Register : ���
    void Register(string key, Scene* scene); //�Ű����� : ����� ���� (Ű�� ��)

    void ChangeScene(string key, bool init = true);
    //�� �ٲٱ�, �Ű������� ���� �̸�(Ű) �׸��� �ʱ�ȭ ����(�Է��� ������ �ʱ�ȭ ��)

private:

    //�� �̿��� �ڷᱸ�� = ��
    map<string, Scene*> scenes;

    Scene* curScene = nullptr;
};

