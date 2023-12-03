#include "Framework.h"

ProgressBar::ProgressBar()
{
    image = new Quad(L"Textures/blackBar.png");
    Adjust();
}

ProgressBar::ProgressBar(wstring file)
{
    image = new Quad(file);
    Adjust();
}

ProgressBar::~ProgressBar()
{
    delete image;
}

void ProgressBar::Update()
{
    Transform::UpdateWorld();
    image->Update();
}

void ProgressBar::Render()
{
    image->Render();
}

void ProgressBar::Adjust()
{
    image->SetParent(this);
    image->Pos() = { image->Half().x, 0 };
}

void ProgressBar::SetPosition(Vector2 pos)
{
    localPosition = { pos.x - image->Half().x, pos.y };
}