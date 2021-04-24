#include "renderer.h"

ofBoxPrimitive renderer::render(std::vector < std::vector < std::vector<int> >> &e)
{
	ofBoxPrimitive lastnode;
	for (size_t i = 0 ; i <e.size() - 1; i++)
	{
		for (size_t j = 0; j < e[i].size(); j++)
		{
			for (size_t z = 0; z < e[i][j].size(); z++)
			{
				if (e[i][j][z])
				{
					ofDrawBox(dx * j, dy * z, 1 * dz * i, dx, dy, dz);
				}
			}
		}
	}
	lastnode = ofBoxPrimitive(dx, dy, dz);
	if(smth > 40)
	lastnode.setPosition(dx *(e[0].size() )/2, dy * e[0][0].size() /2, 1 * dz * (e.size() - 40));
	else
	{
		smth++;
		lastnode.setPosition(dx * (e[0].size()) / 2, dy * e[0][0].size() / 2, 1 * dz * (e.size() - smth));
	}
	return lastnode;

}

void renderer::render_2d(std::vector < std::vector<int> >& e)
{

		for (size_t j = 0; j < e.size(); j++)
		{
			for (size_t z = 0; z < e[j].size(); z++)
			{
				if (e[j][z])
					ofDrawBox(dx * j, dy * z,0, dx, dy,dz);
			}
		}
}

