#pragma once
#include<vector>
#include"renderer.h"
#include"ofMain.h"
#include<fstream>
#include<string>
class grawzyc
{
	std::vector<std::vector<std::vector<int>>> render_pos;
	std::vector<std::vector<std::vector<int>>> positions;
	std::shared_ptr<renderer> _render;
	std::string filename;
	std::ofstream file;
	double rng;
	int suma(int _c, int i, int j);
public:
	grawzyc(){}
	grawzyc(int x, int y,double prob)
	{
		rng = prob;
		filename = "c" + std::to_string(x) + "x" + std::to_string(y)+"p"+std::to_string(prob);
		positions.push_back(std::vector<std::vector<int>>{0});
		positions.push_back(std::vector<std::vector<int>>{0});
		file = std::ofstream(filename);
		for (int i = 0; i < x; i++)
		{
			std::vector<int> pos_y;
			for (int j = 0; j < y; j++)
			{
				pos_y.push_back(abs(ofRandomf())<prob);
			}
			positions[0].push_back(pos_y);
			positions[1].push_back(pos_y);
		}

	}
	void write(int _c)
	{

		double alive = 0;
		for (size_t i = 0; i < positions[_c].size(); i++)
		{
			for (size_t j = 0; j < positions[_c][i].size(); j++)
			{
				if (positions[_c][i][j])
				{
					alive++;
				}
			}
		}
		double g = alive / (double)(positions[_c][0].size() + positions[_c].size());
		if (file.is_open())
		{
			file << g;
			file << " \n";
		}
	}
	void reset()
	{
		for (size_t i = 0; i < positions[0].size(); i++)
		{
			for (size_t j = 0; j < positions[0][i].size(); j++)
			{
				positions[0][i][j] = abs(ofRandomf()) < rng;
			}
		}

	}
	void calc_life_non(int _c);
	void set_renderer(std::shared_ptr<renderer> rend) { _render = rend; }
	void render3d(int _c) {
		render_pos.push_back(positions[_c]);
		_render->render(render_pos);
	}
	void render3dnew(int _c)
	{
		render_pos.push_back(positions[_c]);
	}
	ofBoxPrimitive render3dfresh(int _c)
	{
		return _render->render(render_pos);
	}
	void render(int _c) { _render->render_2d(positions[_c]);
}
};

