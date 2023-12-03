#pragma once
class Swordman_Jump : public Action
{
private:
    const float JUMP_POWER = 500.0f;

public:
    Swordman_Jump(Transform* target);
    ~Swordman_Jump() = default;

    virtual void Update() override;
    virtual void Start() override;

private:
    Transform* target;

    float velocity = 0.0f;
};