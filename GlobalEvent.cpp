#include "Framework.h"

void GlobalEvent::operator()(string keyword)
{
    // ����� �� Ȯ�� �ε�

    if (keyword == "Start")
    {
        //�� �Ŵ��� �̱����� ���� ����� �� ȣ��
        SceneManager::Get()->ChangeScene("PlaneScene");
    }
}

void GlobalEvent::operator()(string keyword, string args)
{
    // �� �ε��� �ϴµ� ������ ������ �ޱ�

    if (keyword == "LoadScene")
    {
        SceneManager::Get()->ChangeScene(args);
    }
}
