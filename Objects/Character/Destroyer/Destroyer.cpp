#include "Framework.h"

Destroyer* Destroyer::instance = nullptr;

Destroyer::Destroyer()
{
    // Pos() = { 80, 470 };
    Pos() = { 1000, 102 };

    destroyerArea = new RectCollider(Vector2(55, 80));
    destroyerArea->Pos() = { 0, -25 };
    destroyerArea->SetParent(this);

    CreateActions();
    actions[curAction]->Start();

    Observer::Get()->AddIntParamEvent("Skill", bind(&Destroyer::SetActionCode, this, placeholders::_1));

    SetPixelShader(L"Ninja.hlsl"); // ¿Ü°û¼±
    
    secondLayer = Texture::Add(L"Textures/outline.png"); // ¿Ü°û¼± »ö

    intBuffer = new IntValueBuffer();
    floatBuffer = new FloatValueBuffer();
}

Destroyer::~Destroyer()
{
    for (pair<ActionType, Action*> action : actions)
        delete action.second;
}

void Destroyer::Update()
{
    Control();

    actions[curAction]->Update();
    UpdateWorld();

    destroyerArea->UpdateWorld();
}

void Destroyer::Render()
{
    secondLayer->PSSet(1);

    intBuffer->SetPS(1);
    floatBuffer->SetPS(2);

    Vector2 frameSize = actions[curAction]->GetClip()->GetCurFrame()->GetSize();
    floatBuffer->Get()[0] = frameSize.x;
    floatBuffer->Get()[1] = frameSize.y;

    SetRender();

    actions[curAction]->Render();

    destroyerArea->Render();
}

void Destroyer::Control()
{
    Move();
    Jump();
    Attack();
}

void Destroyer::Move()
{
    if (curAction == JUMP) return;
    if (curAction >= ATTACK) return;

    bool isMove = false;

    isMove |= KEY_PRESS(VK_RIGHT);
    isMove |= KEY_PRESS(VK_LEFT);
    // isMove |= KEY_PRESS(VK_UP);

    isMove ? SetAction(RUN) : SetAction(IDLE);
}

void Destroyer::Jump()
{
    if (curAction >= ATTACK) return;

    if (KEY_DOWN(VK_SPACE))
        SetAction(JUMP);
}

void Destroyer::Attack()
{
    if (curAction >= ATTACK) return;

    if (KEY_DOWN('A'))
    {
        if (curAction == JUMP)
        {
            SetAction(JUMP_ATTACK);
        }
        else
        {
            SetAction(ATTACK);
        }
    }

    if (KEY_DOWN('S'))
    {
        SetAction(CHARGE);
    }
}

void Destroyer::SetIdle()
{
    SetAction(IDLE);
}

void Destroyer::SetAction(ActionType type)
{
    if (curAction == type) return;

    curAction = type;
    actions[type]->Start();
}

void Destroyer::SetActionCode(int typeCode)
{
    if (curAction == (ActionType)typeCode) return;

    curAction = (ActionType)typeCode;
    actions[(ActionType)typeCode]->Start();
}

void Destroyer::CreateActions()
{
    actions[IDLE] = new Action("Textures/Destroyer/", "DIdle.xml", true);
    actions[RUN] = new DestroyerRun(this);
    actions[JUMP] = new DestroyerJump(this);
    actions[JUMP]->SetEvent(bind(&Destroyer::SetIdle, this));

    actions[ATTACK] = new DestroyerMeleeAttack(this);
    actions[ATTACK]->SetEvent(bind(&Destroyer::SetIdle, this));
    actions[JUMP_ATTACK] = new DestroyerJumpAttack(this);
    actions[JUMP_ATTACK]->SetEvent(bind(&Destroyer::SetIdle, this));
    actions[CHARGE] = new DestroyerChargeAttack(this);
    actions[CHARGE]->SetEvent(bind(&Destroyer::SetIdle, this));
    actions[JUMP_CHARGE] = new DestroyerJumpCharge(this);
    actions[JUMP_CHARGE]->SetEvent(bind(&Destroyer::SetIdle, this));
}