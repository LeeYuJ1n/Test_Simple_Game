#include "Framework.h"

DestroyerAttack::DestroyerAttack(string file, Transform* target)
    : Action("Textures/Destroyer/", file, false), target(target)
{
}

DestroyerAttack::~DestroyerAttack()
{
    delete attackCollider;
}

void DestroyerAttack::Render()
{
    Action::Render();

    attackCollider->Render();
}

void DestroyerAttack::End()
{
    event();
}

void DestroyerAttack::EnableCollider()
{
    attackCollider->UpdateWorld();
    attackCollider->SetActive(true);
}

void DestroyerAttack::DisableCollider()
{
    attackCollider->SetActive(false);
}