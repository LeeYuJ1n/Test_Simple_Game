#pragma once
class DestroyerJumpCharge : public DestroyerCharge
{
public:
    DestroyerJumpCharge(Transform* target);
    ~DestroyerJumpCharge() = default;

    virtual void Update() override;

    virtual void Start() override;
private:
    virtual void DisableCollider() override;

private:
    float velocity = 0.0f;

    bool isFall = false;
};

