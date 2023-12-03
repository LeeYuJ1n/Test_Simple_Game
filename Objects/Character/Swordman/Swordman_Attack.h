#pragma once
class Swordman_Attack : public Action
{
public:
    Swordman_Attack(string file, Transform* target);
    ~Swordman_Attack();

    virtual void Render() override;
    virtual void End() override;

    virtual void EnableCollider();
    virtual void DisableCollider();

protected:
    Transform* target;
    float power = 0.0f;

    Collider* attackCollider;
};