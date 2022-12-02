#include "paddle.h"
#include "play.h"
void DrawPaddle(const Paddle& paddle) {
	Play::DrawRect( {paddle.px1 , paddle.py1}, { paddle.px1 + paddle.width , paddle.py2}, Play::cCyan, true);
	
}

void UpdatePaddle() {
	float oldpos = paddle.px1;
	if (Play::KeyDown(VK_LEFT))
	{
		paddle.px1 -= paddle.velocity;
	}

}