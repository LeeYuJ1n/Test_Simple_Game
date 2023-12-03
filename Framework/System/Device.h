#pragma once

class Device : public Singleton<Device>
{
private:
    friend class Singleton;

    Device();
    ~Device();

public:
    void Clear();
    void Present();

    ID3D11Device* GetDevice() { return device; }
    ID3D11DeviceContext* GetDeviceContext() { return deviceContext; }

    // ���� ȣ���ϱ�(���� ȭ�� ������ �����ϱ�) = ����ü�� ����
    IDXGISwapChain* GetSwapChain() { return swapChain; }

private:
    ID3D11Device* device;
    ID3D11DeviceContext* deviceContext;
    
    IDXGISwapChain* swapChain;
    ID3D11RenderTargetView* renderTargetView;
};