#pragma once
class DestroyerMeleeAttack : public DestroyerAttack
{
public:
    DestroyerMeleeAttack(Transform* target);
    ~DestroyerMeleeAttack() = default;
};