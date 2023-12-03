#pragma once
class DestroyerCharge : public Action
{
public:
    DestroyerCharge(string file, Transform* target);
    ~DestroyerCharge();

    virtual void Render() override;
    virtual void End() override;

    virtual void EnableCollider();
    virtual void DisableCollider();

protected:
    Transform* target;
    float power = 0.0f;

    Collider* chargeCollider;
};