#pragma once
#include "Actor.h"
class Bullet :
    public Actor {

private:
    float radius_;
    bool isShoot_;

private:
    void Move();
    bool CheckOutScreen();
    void OutOfScreen();

public:
    Bullet();
    void Init(Vec2f pos);
    void Update();
    void Draw();

    float GetSpeed()const;
    void SetSpeed(const float speed);

    const float GetRadius()const { return radius_; }

    bool GetIsShoot()const;
    void SetIsShoot(const bool isShoot);
};
