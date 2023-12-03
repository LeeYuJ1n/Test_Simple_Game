#pragma once
class Swordman_Run : public Action
{
public:
    Swordman_Run(Transform* target);
    ~Swordman_Run() = default;

    virtual void Update() override;

    void SetTarget(Destroyer* target) { this->target = target; }

private:
    void Control();

private:
    Transform* target;
    float velocity = 0.0f;

    //Destroyer* target = nullptr;
};