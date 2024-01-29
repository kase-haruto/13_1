#include "Bullet.h"

Bullet::Bullet() {
	radius_ = 15.0f;
}

void Bullet::Init(Vec2f pos) {
	pos_ = pos;
	speed_ = 12.0f;
	color_ = 0xff0000ff;
	isShoot_ = true;
}

void Bullet::Move() {
	pos_.y -= speed_;
}

bool Bullet::CheckOutScreen() {
	/*============================
		画面外に出たかの判定*/

	bool isOut;

	if (pos_.x - radius_ > 1280.0f || pos_.x + radius_ < 0.0f) {
		isOut = true;
	} else if (pos_.y - radius_ > 720.0f || pos_.y + radius_ < 0.0f) {
		isOut = true;
	} else {
		isOut = false;
	}

	return isOut;
}

void Bullet::OutOfScreen() {
	//画面外に出たらフラグを下す
	if (this->CheckOutScreen()) {
		isShoot_ = false;
	}
}

void Bullet::Update() {
	if (isShoot_) {
		this->Move();
		this->OutOfScreen();
	}
}

void Bullet::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f, color_,
		kFillModeSolid
	);
}



float Bullet::GetSpeed()const { return speed_; }
void Bullet::SetSpeed(const float speed) { speed_ = speed; }

bool Bullet::GetIsShoot()const { return isShoot_; }
void Bullet::SetIsShoot(const bool isShoot) { isShoot_ = isShoot; }