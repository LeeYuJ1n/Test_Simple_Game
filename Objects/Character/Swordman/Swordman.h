#pragma once
class Swordman : public GameObject
{
private:
    enum ActionType
    {
        IDLE = 0,
        RUN,
        JUMP,
        ATTACK = 10,
        JUMP_ATTACK,
        DEAD
    };

    static Swordman* instance;

public:
    Swordman();
    ~Swordman();

    void Update();
    void Render();

    // bool IsLeft() { return this->Rot().y == XM_PI; }

    static Swordman* Get()
    {
        if (instance == nullptr)
        {
            instance = new Swordman();
        }

        return instance;
    }

private:
    void Control();

    void Move();
    void Jump();
    void Attack();

    void SetIdle();

    void SetAction(ActionType type);

    void SetActionCode(int typeCode);

    void CreateActions();

private:
    map<ActionType, Action*> actions;

    ActionType curAction = IDLE;

    Texture* secondLayer;

    IntValueBuffer* intBuffer;
    FloatValueBuffer* floatBuffer;

    RectCollider* bossRect;
};