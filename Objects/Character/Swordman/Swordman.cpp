#include "Framework.h"

Swordman* Swordman::instance = nullptr;

Swordman::Swordman()
{
    Pos() = { CENTER_X, CENTER_Y };

    CreateActions();
    actions[curAction]->Start();

    Observer::Get()->AddIntParamEvent("Skill", bind(&Swordman::SetActionCode, this, placeholders::_1));

    SetPixelShader(L"Ninja.hlsl"); // ¿Ü°û¼±
    
    secondLayer = Texture::Add(L"Textures/outline.png"); // ¿Ü°û¼± »ö

    intBuffer = new IntValueBuffer();
    floatBuffer = new FloatValueBuffer();

    bossRect = new RectCollider(Vector2(80, 70));
    bossRect->Pos() = { 0, -30 };
    bossRect->SetParent(this);

    
}

Swordman::~Swordman()
{
    for (pair<ActionType, Action*> action : actions)
        delete action.second;
}

void Swordman::Update()
{
    Control();

    actions[curAction]->Update();
    UpdateWorld();

    bossRect->Update();
}

void Swordman::Render()
{
    secondLayer->PSSet(1);

    intBuffer->SetPS(1);
    floatBuffer->SetPS(2);

    Vector2 frameSize = actions[curAction]->GetClip()->GetCurFrame()->GetSize();
    floatBuffer->Get()[0] = frameSize.x;
    floatBuffer->Get()[1] = frameSize.y;

    SetRender();

    actions[curAction]->Render();

    bossRect->Render();
}

void Swordman::Control()
{
    Move();
    Jump();
    Attack();
}

void Swordman::Move()
{
    if (curAction == JUMP) return;
    if (curAction >= ATTACK) return;

    bool isMove = false;

    isMove |= KEY_PRESS(VK_RIGHT);
    isMove |= KEY_PRESS(VK_LEFT);

    isMove ? SetAction(RUN) : SetAction(IDLE);
}

void Swordman::Jump()
{
    if (curAction >= ATTACK) return;

    if (KEY_DOWN(VK_UP))
        SetAction(JUMP);
}

void Swordman::Attack()
{
    SetAction(ATTACK);
}

void Swordman::SetIdle()
{
    SetAction(IDLE);
}

void Swordman::SetAction(ActionType type)
{
    if (curAction == type) return;

    curAction = type;
    actions[type]->Start();
}

void Swordman::SetActionCode(int typeCode)
{
    if (curAction == (ActionType)typeCode) return;

    curAction = (ActionType)typeCode;
    actions[(ActionType)typeCode]->Start();
}

void Swordman::CreateActions()
{
    actions[IDLE] = new Action("Textures/Swordman/", "Idle.xml", true);
    actions[RUN] = new Swordman_Run(this);
    actions[JUMP] = new Swordman_Jump(this);
    actions[JUMP]->SetEvent(bind(&Swordman::SetIdle, this));

    actions[ATTACK] = new SwordMeleeAttack(this);
    actions[ATTACK]->SetEvent(bind(&Swordman::SetIdle, this));
    actions[JUMP_ATTACK] = new Swordman_JumpAttack(this);
    actions[JUMP_ATTACK]->SetEvent(bind(&Swordman::SetIdle, this));
}