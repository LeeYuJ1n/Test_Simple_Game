#pragma once

class Scene
{
public:
    virtual ~Scene() = default;

    virtual void Update() = 0;    

    virtual void Render() = 0;
    virtual void PostRender() = 0;

    //�Ʒ��� ���� ������ ���� ���θ� �ְ���� �� �ʿ��� �Լ� 2��
    virtual void Init() = 0; // Initiate : �ʱ�ȭ, Ȥ�� ����(Start)
    virtual void Quit() = 0; // Quit : ���� (End)
};