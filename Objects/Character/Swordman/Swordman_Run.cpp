#include "Framework.h"

Swordman_Run::Swordman_Run(Transform* target)
    : Action("Textures/Swordman/", "Run.xml", true), target(target)
{
}

void Swordman_Run::Update()
{
    Control();

    target->Pos().x += velocity * MOVE_SPEED * DELTA;

    Action::Update();
}

void Swordman_Run::Control()
{
    if (KEY_PRESS(VK_RIGHT))
    {
        velocity = 1.0f;
        target->Rot().y = 0;
    }

    if (KEY_PRESS(VK_LEFT))
    {
        velocity = -1.0f;
        target->Rot().y = XM_PI;
    }
}
