#include "Framework.h"

DestroyerJumpCharge::DestroyerJumpCharge(Transform* target)
    : DestroyerCharge("DShot.xml", target)
{
    power = 100.0f;

    chargeCollider = new RectCollider(Vector2(50, 50));
    chargeCollider->Pos().x = 30.0f;
    chargeCollider->Pos().y = -30.0f;
    chargeCollider->SetParent(target);


    clip->SetEvent(bind(&DestroyerCharge::EnableCollider, this), 0);
    clip->SetEvent(bind(&DestroyerJumpCharge::DisableCollider, this), 7);
}

void DestroyerJumpCharge::Update()
{
    Action::Update();

    if (isFall)
    {
        velocity -= GRAVITY * DELTA;

        target->Pos().y += velocity * DELTA;

        if (KEY_PRESS(VK_RIGHT))
        {
            target->Pos().x += MOVE_SPEED * DELTA;
            target->Rot().y = 0;
        }

        if (KEY_PRESS(VK_LEFT))
        {
            target->Pos().x -= MOVE_SPEED * DELTA;
            target->Rot().y = XM_PI;
        }

        if (target->Pos().y < FLOOR_HEIGHT)
        {
            target->Pos().y = FLOOR_HEIGHT;
            velocity = 0.0f;

            event();
        }
    }
}

void DestroyerJumpCharge::Start()
{
    Action::Start();

    velocity = 0.0f;

}

void DestroyerJumpCharge::DisableCollider()
{
    DestroyerCharge::DisableCollider();

    isFall = true;
}