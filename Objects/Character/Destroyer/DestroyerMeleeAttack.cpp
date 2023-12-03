#include "Framework.h"

DestroyerMeleeAttack::DestroyerMeleeAttack(Transform* target)
    : DestroyerAttack("DAttack.xml", target)
{
    clip->SetEvent(bind(&DestroyerAttack::End, this));

    power = 100.0f;

    attackCollider = new RectCollider(Vector2(50, 50));
    attackCollider->Pos().x = 30.0f;
    attackCollider->Pos().y = -30.0f;
    attackCollider->SetParent(target);

    clip->SetEvent(bind(&DestroyerAttack::EnableCollider, this), 0);
    clip->SetEvent(bind(&DestroyerAttack::DisableCollider, this), 3);
}