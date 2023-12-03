#pragma once

class ProgressBar : public Transform
{
public:

    ProgressBar();
    ProgressBar(wstring file);
    ~ProgressBar();

    void Update();
    void Render();
    void PostRender() {}

    void SetPosition(Vector2 pos);

private:

    Quad* image;
    void Adjust();
};

