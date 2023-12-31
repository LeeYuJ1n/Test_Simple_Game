#pragma once
class Font : public Singleton<Font>
{
	// 글자를 나타내기 전에 글자의 정보를 저장하는 수단으로 만든 클래스
private:
	friend class Singleton;

	Font();
	~Font();

public:

	// 정해진 자료구조에 폰트 관리 정보를 넣고 빼는 것만 목적이니까 업데이트, 렌더는 일단 생략

	// 렌더는 틱으로 돌아가는 렌더보다는 호출을 통해서 글자를 출력하는 걸로 (cpp의 cout, winAPI의 TextOut 같은 걸 의도)

	// 업데이트, 렌더 보다는 오히려 텍스처처럼 정보를 넣고 빼거나 세팅하는 것이 더 중요할 것

	// 폰트에 들어가야 할 정보를 넣기

	// 브러시 (글자의 색), 글자의 정보를 넣기
	void AddColor(string key, float r, float g, float b, float a = 1);

	void AddStyle(string key, wstring font, float size = 18.0f,// 일반적으로 더 많이 쓰이는 이름(스타일)을 써서 함수 명명
		DWRITE_FONT_WEIGHT weight = DWRITE_FONT_WEIGHT_NORMAL, // 글자의 굵기 처리, 기본값은 없음(보통)
		DWRITE_FONT_STYLE style = DWRITE_FONT_STYLE_NORMAL, // 글자의 스타일 처리, 기본값은 없음
		DWRITE_FONT_STRETCH stretch = DWRITE_FONT_STRETCH_NORMAL); // 글자의 장평자간 등의 추가 글꼴정보, 기본값은 없음
	
	// 브러시, 글자 정보 세팅하기
	void SetColor(string key);
	void SetStyle(string key);

	// 디바이스에 접근하기
	ID2D1DeviceContext* GetDC() { return context; }

	// 텍스트 출력 선언
	void RenderText(string text, Float2 pos, Float2 size = Float2()); // 일반 문자열
	void RenderText(wstring text, Float2 pos, Float2 size = Float2()); // 범용 문자열

private:
	// 폰트에 실제로 들어갈 정보들

	// dwrite를 통한 글자 출력의 준비물들
	// 다이렉트 x에서 제공하는 클래스와 구조체 자료들을 쓰는 거라서, 암기보다는 필요할 때 검색하는 편이 효율적

	ID2D1Factory1* factory; // 정보 집합
	IDWriteFactory* writeFactory; // 쓰기 정보 집합

	ID2D1Device* device; // 출력 정보
	ID2D1DeviceContext* context; // 가상화된 출력 대상 정보

	ID2D1Bitmap1* targetBitmap; // 출력하기 위한 비트맵 : 다이렉트x에서는 글자도 그림인 것

	// 위까지는 비트맵을 받아서 출력하기 위한 변수, 아래로는 스타일 지정

	map<string, ID2D1SolidColorBrush*> brushes; // 브러시를 사용한 맵
	map<string, IDWriteTextFormat*> formats; // 글자의 정보를 사용한 맵

	ID2D1SolidColorBrush* curBrush; // 현재 세팅된 브러시
	IDWriteTextFormat* curFormat; // 현재 세팅된 글자의 정보

};

