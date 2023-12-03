#include "Framework.h"

DestroyerChargeAttack::DestroyerChargeAttack(Transform* target)
    : DestroyerCharge("DShot.xml", target)
{
    clip->SetEvent(bind(&DestroyerCharge::End, this));

    power = 100.0f;

    chargeCollider = new RectCollider(Vector2(80, 50));
    chargeCollider->Pos().x = 30.0f;
    chargeCollider->Pos().y = -30.0f;
    chargeCollider->SetParent(target);

    clip->SetEvent(bind(&DestroyerCharge::EnableCollider, this), 0);
    clip->SetEvent(bind(&DestroyerCharge::DisableCollider, this), 7);
}