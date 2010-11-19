#include "Puzzle.h"
#include <sstream>

Puzzle::Puzzle()
{
}

Puzzle::~Puzzle()
{
}

void										Puzzle::CreatePuzzle(const std::string & Contents)
{
	std::istringstream						in(Contents);
	int										tmp;
	int										pos = Contents.find_first_of('\n');
	unsigned int							scale = this->CountScales(Contents.substr(0, pos));
	
	for (unsigned int i = 0; i < scale; ++i)
	{
		std::vector<int> line;
		for(unsigned int j = 0; j < scale; ++j)
		{
		  in >> tmp;
		  line.push_back(tmp);
		}
		this->PuzzleMap.push_back(line);
	}
	// This part was put only for debug
	// It will be deleted at the end of project.
	for (unsigned int i = 0; i < scale; ++i)
	{
		for (unsigned int j = 0; j < scale; ++j)
			std::cout << this->PuzzleMap[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "Puzzle Loaded successfully :)" << std::endl;
}

unsigned int								Puzzle::CountScales(const std::string & Contents) const
{
	unsigned int							max = Contents.size();
	unsigned int							ret = 0;
	char									prev = '0';

	for (unsigned int i = 0; i < max; ++i)
	{
		if (prev != ' ' && Contents.at(i) == ' ')
			ret++;
		prev = Contents.at(i);
	}
	return (ret + 1);
}

const std::vector<std::vector <int> > &		Puzzle::GetMap(void) const
{
	return (this->PuzzleMap);
}

bool									Puzzle::GenerateSolution(const int PuzzleScale)
{
  if (PuzzleScale > 100)
  {
	std::cerr << "The taquin is too big" << std::endl;
	return (false);
  }
  else
    {
		int num = 1;
		int x_min, x_max, x_cur;
		int y_min, y_max, y_cur;

		x_max = y_max = PuzzleScale;
		x_min = y_min = 0;
		x_cur = y_cur = 0;

		int** tab;
		tab = new int*[PuzzleScale];
		for (int i = 0; i < PuzzleScale; i++)
			tab[i] = new int[PuzzleScale];

		while (x_min <= x_max && y_min <= y_max)
		{
			while (x_cur < x_max)
			{
				tab[x_cur][y_cur] = num;
				x_cur++;
				num++;
			}
			// x_cur 
			x_cur--;
			x_max--;
			y_cur++;
			while (y_cur < y_max)
			{
				tab[x_cur][y_cur] = num;
				y_cur++;
				num++;
			}
			y_cur--;
			y_max--;
			x_cur--;
			while (x_cur > x_min - 1)
			{
				tab[x_cur][y_cur] = num;
				x_cur--;
				num++;
			}
			x_cur++;
			x_min++;
			y_cur--;
			while (y_cur > y_min)
			{
				tab[x_cur][y_cur] = num;
				y_cur--;
				num++;
			}
			y_cur++;
			y_min++;
			x_cur++;
		}
		for (int i = 0; i < PuzzleScale; ++i)
		{
			for (int j = 0; j < PuzzleScale; ++j)
			{
				if (tab[i][j] == PuzzleScale * PuzzleScale)
					tab[i][j] = 0;
				std::cout << tab[j][i] << "\t";
			}
			std::cout << std::endl;
		}
    }
  return (true);
}
