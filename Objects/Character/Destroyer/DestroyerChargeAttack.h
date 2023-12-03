#pragma once
class DestroyerChargeAttack : public DestroyerCharge
{
public:
    DestroyerChargeAttack(Transform* target);
    ~DestroyerChargeAttack() = default;
};