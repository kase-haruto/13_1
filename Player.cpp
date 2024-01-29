#include "Player.h"
Player::Player() {
	gh_ = Novice::LoadTexture("white1x1.png");
	pos_ = { 1280.0f / 2.0f,720.0f / 1.5f };
	speed_ = 8.0f;
	size_ = { 64.0f,64.0f };
	color_ = 0xffffffff;
	this->Init();
	this->InitializeBullets();
}

Player::~Player() {
	
}

void Player::InitializeBullets() {
	bullets_.push_back(std::make_unique<Bullet>());
}

void Player::Init() {
	isAlive_ = true;//フラグのリセット
	hp_ = 10;
}

void Player::Move(char* keys) {

	if (keys[DIK_A]) {
		pos_.x -= speed_;
	} else if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	if (keys[DIK_W]) {
		pos_.y -= speed_;
	} else if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	//各頂点の更新
	Character::VertexInit();
}

void Player::DeleteInactive() {
	// 使用していない配列の削除
	if (!bullets_.empty()) {
		auto isInactive = [](const std::unique_ptr<Bullet>& bullet) {
			return !bullet->GetIsShoot();
		};

		bullets_.erase(std::remove_if(bullets_.begin(), bullets_.end(), isInactive), bullets_.end());
	}
}

void Player::Shoot(char* keys, char* preKeys) {

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		bullets_.push_back(std::make_unique<Bullet>());
		bullets_.back()->Init(this->pos_);
	}

	for (auto& bullet : bullets_) {
		bullet->Update();
	}
	this->DeleteInactive();
}

void Player::Update(char* keys, char* preKeys) {
	if (isAlive_) {
		this->Move(keys);
		this->Shoot(keys, preKeys);
	} else {
		this->Init();
	}
}

void Player::Draw() {
	if (isAlive_) {
		Character::Draw();
	}

	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
}