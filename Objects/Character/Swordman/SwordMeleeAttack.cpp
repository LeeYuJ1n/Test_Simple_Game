#include "Framework.h"

SwordMeleeAttack::SwordMeleeAttack(Transform* target)
    : Swordman_Attack("Attack.xml", target)
{
    clip->SetEvent(bind(&Swordman_Attack::End, this));

    power = 100.0f;

    attackCollider = new RectCollider(Vector2(50, 50));
    attackCollider->Pos().x = 30.0f;
    attackCollider->Pos().y = -30.0f;
    attackCollider->SetParent(target);


    clip->SetEvent(bind(&Swordman_Attack::EnableCollider, this), 1);
    clip->SetEvent(bind(&Swordman_Attack::DisableCollider, this), 5);
}