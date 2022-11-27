#include "paddle.h"
#include "play.h"
void DrawPaddle() {
	Play::DrawRect({ px1,py1 }, { px2, py2 }, Play::cBlue, true);
}
void UpdatePaddle() {

}