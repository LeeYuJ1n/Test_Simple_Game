#include "Framework.h"

DestroyerJumpAttack::DestroyerJumpAttack(Transform* target)
    : DestroyerAttack("DAttack.xml", target)
{
    power = 100.0f;

    attackCollider = new RectCollider(Vector2(50, 50));
    attackCollider->Pos().x = 30.0f;
    attackCollider->Pos().y = -30.0f;
    attackCollider->SetParent(target);


    clip->SetEvent(bind(&DestroyerAttack::EnableCollider, this), 1);
    clip->SetEvent(bind(&DestroyerJumpAttack::DisableCollider, this), 3);
}

void DestroyerJumpAttack::Update()
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

void DestroyerJumpAttack::Start()
{
    Action::Start();

    velocity = 0.0f;

}

void DestroyerJumpAttack::DisableCollider()
{
    DestroyerAttack::DisableCollider();

    isFall = true;
}