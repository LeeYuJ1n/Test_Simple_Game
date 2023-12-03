#pragma once

class Button : public Quad
{
protected:
    enum State
    {
        NONE,
        DOWN, UP,
        OVER,
    };

public:

    Button(wstring file);
    Button(Vector2 size);
    ~Button();

    void Update();
    void Render();

    RectCollider* GetCollider() { return collider; }

private:
    RectCollider* collider;

    State state = NONE;

    bool isDownCheck = false;

    Event event = nullptr;
    ParamEvent paramEvent = nullptr;

    void* object;

public:
    void SetEvent(Event event) { this->event = event; }
    void SetParamEvent(ParamEvent event) { this->paramEvent = event; }
    void SetObejct(void* object) { this->object = object; }
};