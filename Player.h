#pragma once
#include "Character.h"
#include"Bullet.h"
#include<vector>
#include<memory>

class Player final :
	public Character {

	bool isAlive_ = true;

	std::vector<std::unique_ptr<Bullet>> bullets_;

private:
	void Move(char* keys);
	void Shoot(char* keys, char* preKeys);
	void InitializeBullets();
	void DeleteInactive(); //使用していない弾の配列の削除

public:
	Player();
	~Player();



	void Init();
	void Update(char* keys, char* preKeys);
	void Draw()override;

	
	std::vector<std::unique_ptr<Bullet>>& GetBullets() {
		return bullets_;
	}
};