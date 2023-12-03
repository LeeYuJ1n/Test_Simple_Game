#pragma once

class Environment : public Singleton<Environment>
{
private:
    friend class Singleton;

    Environment();
    ~Environment();

private:
    void CreateProjection();
    void CreateSamplerState();
    void CreateBlendState();
    void CreateRasterizerState(); // 레스터화 생성 함수

public:
    // 알파 블랜드, 추가 블랜드 설정 : 외부에서 꼭 써야 할 개체만 그때그때 쓰도록
    void SetAlphaBlend();
    void SetAdditiveBlend();

private:
    MatrixBuffer* projectionBuffer;

    ID3D11SamplerState* samplerState; // 텍스처 샘플링(기본 출력)에 대한 설정
    ID3D11BlendState* blendState; // 블랜드 (색 재처리)에 대한 설정

    ID3D11RasterizerState* rasterizerState; // 레스터라이즈(벡터와 셰이더를 모니터용 픽셀로 바꿔주는 일)에 대한 설정
    // 일종의 최종 확인을 시켜줄 수 있다
    // 래스터라이즈가 끝나면 나오는 결과는 결국 모니터에 바로 나올테니까

    // 2차, 3차 블랜드 등에 사용할 추가 블랜드 상태(알파 설정 등)
    ID3D11BlendState* alphaBlendState; // 알파 적용 목적
    ID3D11BlendState* additiveBlendState; // 색등이 추가될 경우 적용 목적

    // 위 변수에 각각 설정을 추가로 해서 마지막에 하나로 화소 출력 정보를 합치는 것이 목적
};