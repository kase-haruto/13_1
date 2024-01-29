#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#include<math.h>

const char kWindowTitle[] = "LC1B_";


bool CheckEnemy2Bullet(const std::vector<std::unique_ptr<Bullet>>& bullets, Vec2f pos, Vec2f size) {
	Vec2f enemyPos = pos;
	float enemyRadius = size.x / 2.0f;
	float distance;
	bool isHit = false;

	for (auto& bullet : bullets) {
		distance = sqrtf(powf(bullet->GetPos().x - enemyPos.x, 2) + powf(bullet->GetPos().y - enemyPos.y, 2));

		if (distance <= enemyRadius + bullet->GetRadius()) {
			isHit = true;
			bullet->SetIsShoot(false);
		}
	}
	return isHit;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player();

	Enemy* enemyA = new Enemy(Vec2f{ 800.0f,300.0f }, 0x565656ff);
	Enemy* enemyB = new Enemy(Vec2f{ 400.0f,300.0f }, 0xc5c5c5ff);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys, preKeys);
		enemyA->Update();
		enemyB->Update();

		/*-------------------------------------
			当たり判定
		-------------------------------------*/
		if (CheckEnemy2Bullet(player->GetBullets(), enemyA->GetPos(), enemyA->GetSize())) {
			// 当たっている場合、敵のHPを減らす
			enemyA->SetHp(enemyA->GetHp() - 1);
		}

		if (CheckEnemy2Bullet(player->GetBullets(), enemyB->GetPos(), enemyB->GetSize())) {
			// 当たっている場合、敵のHPを減らす
			enemyB->SetHp(enemyB->GetHp() - 1);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		enemyA->Draw();
		enemyB->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemyA;
	delete enemyB;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
