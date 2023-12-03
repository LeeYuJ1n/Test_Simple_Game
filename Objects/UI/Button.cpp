#include "Framework.h"

Button::Button(wstring file)
    : Quad(file)
{
    collider = new RectCollider(size);
    collider->SetParent(this);
}

Button::Button(Vector2 size)
    : Quad(size)
{
    collider = new RectCollider(size);
    collider->SetParent(this);
}

Button::~Button()
{
    delete collider;
}

void Button::Update()
{
    if (!isActive) return;

    if (collider->IsPointCollision(mousePos))
    {
        if (KEY_DOWN(VK_LBUTTON))
            isDownCheck = true;

        if (KEY_PRESS(VK_LBUTTON)) state = DOWN;
        else state = OVER;

        if (isDownCheck && KEY_UP(VK_LBUTTON))
        {
            if (event != nullptr) event();
            if (paramEvent != nullptr) paramEvent(object);

            isDownCheck = false;
        }
    }
    else
    {
        state = NONE;

        if (KEY_UP(VK_LBUTTON))
            isDownCheck = false;
    }

    switch(state)
    {
    case Button::NONE:
        localScale = { 1.1f, 1.1f };
        break;
    case Button::DOWN:
        localScale = { 1.1f, 1.1f };
        break;
    case Button::OVER:
        localScale = { 1.2f, 1.2f };
        break;
    }

    Quad::Update();
    collider->Update();
}

void Button::Render()
{
    if (!isActive) return;

    Quad::Render();
    collider->Render();
}