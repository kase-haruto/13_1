#include "Character.h"

Character::Character() {
	gh_ = Novice::LoadTexture("white1x1.png");
}

void Character::VertexInit() {
	vertex_[LT] = { pos_.x - size_.x / 2.0f,pos_.y - size_.y / 2.0f };
	vertex_[RT] = { pos_.x + size_.x / 2.0f,pos_.y - size_.y / 2.0f };
	vertex_[LB] = { pos_.x - size_.x / 2.0f,pos_.y + size_.y / 2.0f };
	vertex_[RB] = { pos_.x + size_.x / 2.0f,pos_.y + size_.y / 2.0f };
}

void Character::Draw() {
	Novice::DrawQuad(
		static_cast<int>(vertex_[LT].x),
		static_cast<int>(vertex_[LT].y),
		static_cast<int>(vertex_[RT].x),
		static_cast<int>(vertex_[RT].y),
		static_cast<int>(vertex_[LB].x),
		static_cast<int>(vertex_[LB].y),
		static_cast<int>(vertex_[RB].x),
		static_cast<int>(vertex_[RB].y),
		0, 0, 1, 1,
		gh_, color_
	);
}