#pragma once
class Swordman_JumpAttack : public Swordman_Attack
{
public:
    Swordman_JumpAttack(Transform* target);
    ~Swordman_JumpAttack() = default;

    virtual void Update() override;

    virtual void Start() override;
private:
    virtual void DisableCollider() override;

private:
    float velocity = 0.0f;

    bool isFall = false;
};

