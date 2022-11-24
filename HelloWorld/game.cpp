#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "game.h"


void SpawnBall() { 
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 60 }, 4, "ball"); 
	GameObject& ball = Play::GetGameObject(objectId);
	ball.velocity = normalize({ 1, -1 }) * ballSpeed;
	
};

void SetupScene() {
	for (int y = 5; y < DISPLAY_WIDTH / 20 ; y = y+(DISPLAY_WIDTH / 58)) {
		for (int x = 2; x < DISPLAY_WIDTH; x = x + (DISPLAY_WIDTH / 32)) {
			const int objectId = Play::CreateGameObject(ObjectType::TYPE_BRICK, { x, y }, 6, "brick");
		}
	}
}

void StepFrame(float f) {
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
	const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
	for (int balls : ballIds)
	{
		GameObject& ball = Play::GetGameObject(balls);

		bool leavingV = Play::IsLeavingDisplayArea(ball, Play::VERTICAL);
		bool leavingH = Play::IsLeavingDisplayArea(ball, Play::HORIZONTAL);

		if (leavingH == true)
			ball.velocity.x *= -1;

		if (leavingV == true)
			ball.velocity.y *= -1;




		Play::UpdateGameObject(ball);
		Play::DrawObject(ball);
	}
	for (int bricks : brickIds)
	{
		GameObject& brick = Play::GetGameObject(bricks);
		Play::UpdateGameObject(brick);
		Play::DrawObject(brick);
		for (int balls : ballIds) 
		{
			GameObject& ball = Play::GetGameObject(balls);
			bool destroyBrick = Play::IsColliding(ball, brick);

			if (destroyBrick == true)
			{
				ball.velocity.y = ball.velocity.y *-1;
				Play::DestroyGameObject(bricks);
			}
		}
	}
};

