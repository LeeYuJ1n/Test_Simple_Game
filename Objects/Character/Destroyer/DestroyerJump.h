#pragma once
class DestroyerJump : public Action
{
private:
    const float JUMP_POWER = 500.0f;

public:
    DestroyerJump(Transform* target);
    ~DestroyerJump() = default;

    virtual void Update() override;
    virtual void Start() override;

private:
    Transform* target;

    float velocity = 0.0f;
};