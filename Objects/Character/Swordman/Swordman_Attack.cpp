#include "Framework.h"

Swordman_Attack::Swordman_Attack(string file, Transform* target)
    : Action("Textures/Swordman/", file, false), target(target)
{
}

Swordman_Attack::~Swordman_Attack()
{
    delete attackCollider;
}

void Swordman_Attack::Render()
{
    Action::Render();

    attackCollider->Render();
}

void Swordman_Attack::End()
{
    event();
}

void Swordman_Attack::EnableCollider()
{
    attackCollider->UpdateWorld();
    attackCollider->SetActive(true);
}

void Swordman_Attack::DisableCollider()
{
    attackCollider->SetActive(false);
}