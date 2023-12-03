#pragma once

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void Update();
    void Render();

private:
    void Create();
    void Delete();

    // �ӽ� �� ������ �Է�
    void DebugInput();

    void ChangeScene(Scene* dest, bool toInit);

private:
    Scene* scene;

    // ���� �ϳ��� �ƴ� ���:

    // �ʿ��� ���� �ε��ص� ��
    // -> �Ŵ������� ������ ���� scene ������ �ּҸ� �����ָ� �ȴ�

    Scene* sceneData1;
    Scene* sceneData2;

    // �ε� �� ���

    Scene* loadingScene;
};