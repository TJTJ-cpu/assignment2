#pragma once
#include"constants.h"

struct Paddle
{
	float px1 = 250;
	float py1 = 300;
	float px2 = 350;
	float py2 = 310;
};

void DrawPaddle();
void UpdatePaddle();