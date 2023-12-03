#include "Framework.h"

//�׸��� �޾ƿͼ� �ؽ�ó(DX���� ���� ���� �غ� �ڷ�)�� ����� ����
//DX�� �������̽��� ���Ƽ� �ܼ� �ϱ��� �ʿ亸�ٴ� �帧�� ���δ� ���� ����

unordered_map<wstring, Texture*> Texture::textures;

Texture::Texture(ID3D11ShaderResourceView* srv, ScratchImage& image, wstring file)
    : srv(srv), image(move(image)), file(file)
{
}

Texture::~Texture()
{
    srv->Release();
}

void Texture::PSSet(UINT slot)
{
    DC->PSSetShaderResources(slot, 1, &srv);
}

//��API���� �־��� �ؽ�ó �߰� �Լ� : �ڵ��� ���� ö�ڰ� �ٲ���� ������ ��API�� ���� ����
Texture* Texture::Add(wstring file)
{
    if (textures.count(file) > 0)
        return textures[file];

    //�߿��� �� ���⼭ �� �� (�׸��� ������ ���Ͽ��� �����ϰ�, ���̴��� ������ �� �� �ִ� ���� ����)
    ScratchImage image;
    LoadFromWICFile(file.c_str(), WIC_FLAGS_NONE, nullptr, image);

    ID3D11ShaderResourceView* srv;

    //���̴��� ���ҽ� ���� ����
    CreateShaderResourceView(DEVICE, image.GetImages(), image.GetImageCount(),
        image.GetMetadata(), &srv);

    //�ؽ�ó ����
    textures[file] = new Texture(srv, image, file);

    return textures[file];
}

void Texture::Delete()
{
    for (pair<wstring, Texture*> texture : textures)
        delete texture.second;
}
