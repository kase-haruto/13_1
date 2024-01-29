#pragma once
#include "Vec2.h"
#include"Novice.h"

class Actor {
protected:

	Vec2f pos_;
	float speed_;
	unsigned int color_;

public:
	Actor() {}

	virtual void Draw() = 0;

	const Vec2f GetPos()const { return pos_; }
	void SetPos(const Vec2f pos) { pos_ = pos; }

	float GetSpeed()const { return speed_; }
	void SetSpeed(const float speed) { speed_ = speed; }
};

