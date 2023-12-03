#pragma once

// �� ����(���̴�)�� ���ؼ� ������ ���̱��� ���� �����������

class FrameBuffer : public ConstBuffer
{
private:
	struct Data
	{
		Vector2 maxFrame;
		Vector2 curFrame;
	};
	Data data;

public:
	FrameBuffer() : ConstBuffer(&data, sizeof(Data)) {}

	void SetMaxFrame(Vector2 maxFrame) { this->data.maxFrame = maxFrame; }

	Vector2& GetCurFrame() { return this->data.curFrame; }
};

