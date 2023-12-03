#pragma once

class DestroyerRun : public Action
{
public:
    DestroyerRun(Transform* target);
    ~DestroyerRun() = default;

    virtual void Update() override;

private:
    void Control();

private:
    Transform* target;
    float velocity = 0.0f;
};