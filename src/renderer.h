#pragma once
#include <vector>
#include "ofMain.h"
class renderer
{
	float dx;
	float dy;
	float dz;
	int smth = 0;
public:
	renderer(float d_x,float d_y,float d_z)
	{
		dx = d_x;
		dy = d_y;
		dz = d_z;
	}
	ofBoxPrimitive render(std::vector<std::vector<std::vector<int>>>& e);
	void render_2d(std::vector < std::vector<int> >& e);
};

