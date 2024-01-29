#pragma once
#include "Character.h"
class Enemy final :
	public Character {

private:
	static bool isAlive_;
	int spawnCount_;

private:
	void ExitScreen();
	void Move();
	void Spawn(Vec2f pos);


public:
	Enemy(Vec2f pos,unsigned int color);
	void Init(Vec2f pos);
	void Update();
	void Draw();

	int GetHp()const { return hp_; }
};

