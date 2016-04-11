#pragma once

#include "sphere.h"
#include "texture.h"
#include "common.h"

class glBall : public glSphere
{
public:
	glBall(float R) : glSphere(R, "textures\\ball.bmp"){};
	~glBall();
private:

};

