#include "grawzyc.h"

int grawzyc::suma(int _c, int i, int j)
{

	size_t p, l, g, d;
		if (i < positions[_c].size() - 1)
		{
			p = i + 1;
		}
		else
		{
			p = 0;
		}

		if (i > 0)
		{
			l = i - 1;
		}
		else
		{
			l = positions[_c].size() - 1;
		}
		if (j < positions[_c][i].size() - 1)
		{
			g = j +1;
		}
		else
		{
			g = 0;
		}
		if (j > 0)
		{
			d = j - 1;
		}
		else
		{
			d = 0;
		}
	return positions[_c][p][g] + positions[_c][p][d] + positions[_c][p][j]+positions[_c][l][g] + positions[_c][l][d]+ 
		  positions[_c][l][j]+positions[_c][i][g]+positions[_c][i][d];
}

void grawzyc::calc_life_non(int _c)
{
	int i_size = positions[_c].size();
	int j_size = positions[_c][0].size();
	int i = 0;
#pragma omp parallel for private(i)
	for (i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			int suma = this->suma(_c, i, j);

			if (positions[_c][i][j] && (suma == 2 || suma == 3))
			{
				positions[1 - _c][i][j] = 1;
			}
			else if (!positions[_c][i][j] && suma == 3)
			{
				positions[1-_c][i][j] = 1;
			}
			/*else if (positions[_c][i][j] && suma != 2 && suma != 3)
			{
				positions[1-_c][i][j] = 0;
			}*/
			else
			{
				positions[1 - _c][i][j] = 0;
			}
		}
	}
}
