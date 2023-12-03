#pragma once
class Destroyer : public GameObject
{
private:
    enum ActionType
    {
        IDLE = 0,
        RUN,
        JUMP,
        ATTACK = 10,
        JUMP_ATTACK,
        CHARGE,
        JUMP_CHARGE,
        DEAD
    };

    static Destroyer* instance;

public:
    Destroyer();
    ~Destroyer();

    void Update();
    void Render();

    RectCollider* destroyerArea;

    static Destroyer* Get()
    {
        if (instance == nullptr)
        {
            instance = new Destroyer();
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
};