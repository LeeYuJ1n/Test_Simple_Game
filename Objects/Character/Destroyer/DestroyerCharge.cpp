#include "Framework.h"

DestroyerCharge::DestroyerCharge(string file, Transform* target)
	: Action("Textures/Destroyer/", file, false), target(target)
{
}

DestroyerCharge::~DestroyerCharge()
{
	delete chargeCollider;
}

void DestroyerCharge::Render()
{
	Action::Render();

	chargeCollider->Render();
}

void DestroyerCharge::End()
{
	event();
}

void DestroyerCharge::EnableCollider()
{
	chargeCollider->UpdateWorld();
	chargeCollider->SetActive(true);
}

void DestroyerCharge::DisableCollider()
{
	chargeCollider->SetActive(false);
}