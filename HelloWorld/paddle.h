#pragma once
#include"constants.h"

struct Paddle
{
	int const width = 70;
	int px1 = 200;
	int py1 = 310;
	int py2 = 320;
	int velocity = 5;
};
static Paddle paddle;


void DrawPaddle(const Paddle& paddle);
void UpdatePaddle();