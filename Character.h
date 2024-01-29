#pragma once
#include "Actor.h"
class Character :
    public Actor {

protected:
    enum VertexNum {
        LT,RT,
        LB,RB
    };

    Vec2f vertex_[4];
    Vec2f size_;
    int hp_;
    int gh_;

protected:
    void VertexInit();

public:
    Character();
    virtual void Draw();

    Vec2f  GetLtVertex()const { return vertex_[LT]; }
    Vec2f  GetRtVertex()const { return vertex_[RT]; }
    Vec2f  GetLbVertex()const { return vertex_[LB]; }
    Vec2f  GetRbVertex()const { return vertex_[RB]; }

    void SetLtVertex(const Vec2f pos) { vertex_[LT] = pos; }
    void SetRtVertex(const Vec2f pos) { vertex_[RT] = pos; }
    void SetLbVertex(const Vec2f pos) { vertex_[LB] = pos; }
    void SetRbVertex(const Vec2f pos) { vertex_[RB] = pos; }

    const Vec2f GetSize()const { return size_; }

    const int GetHp()const { return hp_; }
    void SetHp(const int hp) { hp_ = hp; }
};

