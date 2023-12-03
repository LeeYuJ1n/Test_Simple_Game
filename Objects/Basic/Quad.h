#pragma once
class Quad : public GameObject
{
public:
    Quad(Vector2 size, Vector2 pos = Vector2());
    Quad(wstring file, Vector2 pos = Vector2());

    Quad(bool useTrim, wstring file, Vector2 startUV = Vector2(), Vector2 endUV = Vector2(1, 1));

    ~Quad();

    virtual void Render() override;

    void SetTexture(wstring file);

    Vector2 Half() { return size * 0.5f; }

    Float4& GetColor() { return colorBuffer->Get(); }

    Vector2 GetSize() { return size; }

private:
    void CreateMesh(Vector2 size, Vector2 pos); //<-"»ç°¢Çü" »ý¼ºÀ» »©³Â´Ù
    void CreateMesh(Vector2 size, Vector2 startUV, Vector2 endUV);

protected:

    Texture* texture = nullptr;

    Vector2 size;

    ColorBuffer* colorBuffer;
};
