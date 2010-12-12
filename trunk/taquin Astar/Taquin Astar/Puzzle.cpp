#include <iostream>
#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"
#include <sstream>

unsigned int	Puzzle::PuzzleScale = 0;
short unsigned int ** Puzzle::SolutionMap = NULL;
Puzzle::Puzzle()
{
}

Puzzle::~Puzzle()
{
}

unsigned int					Puzzle::GetScale(void)
{
	return (Puzzle::PuzzleScale);
}

short unsigned int**			Puzzle::GetSolutionGenerator()
{
	if (Puzzle::SolutionMap == NULL)
		return NULL;
	return (Puzzle::SolutionMap);
}

short unsigned int**					Puzzle::CreatePuzzle(const std::string & Contents)
{
	std::istringstream					in(Contents);

	int	pos = Contents.find_first_of('\n');
	Puzzle::PuzzleScale = this->CountScales(Contents.substr(0, pos));

	this->PuzzleMap = new short unsigned int*[Puzzle::PuzzleScale];

	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		this->PuzzleMap[i] = new short unsigned int[Puzzle::PuzzleScale];
		for(unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		  in >> this->PuzzleMap[i][j];
	}
	std::cout << "2- File Map Content " << std::endl << std::endl;
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
			std::cout << this->PuzzleMap[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "3- File Map Solution " << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	return (this->PuzzleMap);
}

void										Puzzle::SearchPos(short unsigned int** SolutionMap, int& x, int& y, short unsigned int & Node)
{
	short unsigned int						i = 0;
	short unsigned int						j = 0;
	bool									Found = false;
	
	while (i < Puzzle::PuzzleScale && !(Found))
	{
		j = 0;
		while (j < Puzzle::PuzzleScale && !(Found))
		{
			short unsigned int toto = SolutionMap[i][j];
			if (SolutionMap[i][j] == Node)
			{
				Found = true;
				x = i;
				y = j;
			}
			++j;
		}
		++i;
	}
}

short unsigned int							Puzzle::ManhattanDistance(short unsigned int ** SolutionMap)
{
	short unsigned int						Distance = 0;
	short unsigned int						CurrentNode;
	int x, y;

	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
			CurrentNode = this->PuzzleMap[i][j];
			SearchPos(SolutionMap, x, y, CurrentNode);
			Distance += abs(j - x) + abs(i - y);
		}
	}
	return (Distance);
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
