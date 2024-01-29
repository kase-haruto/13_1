#include "Enemy.h"

bool Enemy::isAlive_;


Enemy::Enemy(Vec2f pos, unsigned int color) {
	gh_ = Novice::LoadTexture("white1x1.png");
	speed_ = 8.0f;
	size_ = { 64.0f,64.0f };
	color_ = color;
	spawnCount_ = 120;
	this->Init(pos);
	Character::VertexInit();
}

void Enemy::Spawn(Vec2f pos) {
	spawnCount_--;
	if (spawnCount_ <= 0) {
		this->Init(pos);
	}
}

void Enemy::Init(Vec2f pos) {
	spawnCount_ = 120;
	pos_ = pos;
	isAlive_ = true;
	hp_ = 10;
}

void Enemy::Move() {
	pos_.x += speed_;
	Character::VertexInit();
}

void Enemy::ExitScreen() {
	float radius = size_.x / 2.0f;
	if (pos_.x + radius >= 1280.0f || pos_.x <= radius) {
		speed_ *= -1;
	}
}

void Enemy::Update() {
	if (isAlive_) {
		this->Move();
		this->ExitScreen();
		if (hp_ < 0) {
			isAlive_ = false;
		}
	} else {
		this->Spawn(pos_);
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Character::Draw();
	}
}