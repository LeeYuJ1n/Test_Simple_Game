#pragma once
class DestroyerAttack : public Action
{
public:
    DestroyerAttack(string file, Transform* target);
    ~DestroyerAttack();

    virtual void Render() override;
    virtual void End() override;

    virtual void EnableCollider();
    virtual void DisableCollider();

protected:
    Transform* target;
    float power = 0.0f;

    Collider* attackCollider;
};