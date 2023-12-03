#pragma once
class DestroyerJumpAttack : public DestroyerAttack
{
public:
    DestroyerJumpAttack(Transform* target);
    ~DestroyerJumpAttack() = default;

    virtual void Update() override;

    virtual void Start() override;
private:
    virtual void DisableCollider() override;

private:
    float velocity = 0.0f;

    bool isFall = false;
};