#include "Framework.h"

DestroyerRun::DestroyerRun(Transform* target)
    : Action("Textures/Destroyer/", "DRun.xml", true), target(target)
{
    
}

void DestroyerRun::Update()
{
    Control();

    target->Pos().x += velocity * MOVE_SPEED * DELTA;

    Action::Update();
}

void DestroyerRun::Control()
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

    // if (destroyer->charObject->L() <= )
    // {
    //     if (KEY_PRESS(VK_UP))
    //     {
    //         target->Pos().y += 0.5f;
    //     }
    // }
    
}