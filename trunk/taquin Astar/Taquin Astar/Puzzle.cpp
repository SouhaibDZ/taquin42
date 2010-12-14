#include <iostream>
#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"
#include <sstream>

unsigned int	Puzzle::PuzzleScale = 0;
short unsigned int ** Puzzle::SolutionMap = NULL;

Puzzle::Puzzle()
{
}

Puzzle::~Puzzle(void)
{
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
		delete this->PuzzleMap[i];
	delete this->PuzzleMap;
}

Puzzle::Puzzle(const Puzzle & p)
{
	this->PuzzleMap = new unsigned short int*[Puzzle::PuzzleScale];
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		this->PuzzleMap[i] = new unsigned short int[Puzzle::PuzzleScale];
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
			this->PuzzleMap[i][j] = p.PuzzleMap[i][j];
			if (this->PuzzleMap[i][j] == 0)
			{
				x0 = j;
				y0 = i;
			}
		}
	}
	this->Distance = p.Distance;
}

Puzzle &								Puzzle::operator=(const Puzzle & as)
{
	if (this != &as)
    {
		this->PuzzleMap = as.PuzzleMap;
		this->Distance = as.Distance;
		this->x0 = as.x0;
		this->y0 = as.y0;
	}
	return (*this);
}

bool								Puzzle::operator==(const Puzzle & ass)
{
	short unsigned int i = 0;
	short unsigned int j = 0;
	bool ret = true;

	while (ret && i < Puzzle::PuzzleScale)
	{
		j = 0;
		while (ret && j < Puzzle::PuzzleScale)
		{
			if (this->PuzzleMap[i][j] != ass.PuzzleMap[i][j])
				ret = false;
			++j;
		}
		++i;
	}
	return (ret);
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
	SolutionGenerator					SG;

	int	pos = Contents.find_first_of('\n');
	Puzzle::PuzzleScale = this->CountScales(Contents.substr(0, pos));

	this->PuzzleMap = new short unsigned int*[Puzzle::PuzzleScale];

	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		this->PuzzleMap[i] = new short unsigned int[Puzzle::PuzzleScale];
		for(unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
		  in >> this->PuzzleMap[i][j];
		  if (this->PuzzleMap[i][j] == 0)
		  {
			x0 = j;
			y0 = i;
		  }
		}
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

	Puzzle::SolutionMap = SG.GenerateSolution(Puzzle::PuzzleScale);
	this->ManhattanDistance();
	return (this->PuzzleMap);
}

void										Puzzle::SearchPos(int& x, int& y, short unsigned int & Node)
{
	short unsigned int						i = 0;
	short unsigned int						j = 0;
	bool									Found = false;
	
	while (i < Puzzle::PuzzleScale && !(Found))
	{
		j = 0;
		while (j < Puzzle::PuzzleScale && !(Found))
		{
			short unsigned int toto = Puzzle::SolutionMap[i][j];
			if (Puzzle::SolutionMap[i][j] == Node)
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

void										Puzzle::ManhattanDistance()
{
	short unsigned int						D = 0;
	short unsigned int						CurrentNode;
	int x, y;

	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
			CurrentNode = this->PuzzleMap[i][j];
			this->SearchPos(x, y, CurrentNode);
			D += abs(j - x) + abs(i - y);
		}
	}
	//std::cout << "Manhattan Distance = " << D << std::endl;
	this->Distance = D;
}

void										Puzzle::AffPuzzle() const
{
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
			std::cout << this->PuzzleMap[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

bool										Puzzle::CanUp()
{
	return (this->y0 > 0);
}

bool										Puzzle::CanDown()
{
	return (this->y0 < Puzzle::PuzzleScale - 1);
}

bool										Puzzle::CanLeft()
{
	return (this->x0 > 0);
}

bool										Puzzle::CanRight()
{
	return (this->x0 < Puzzle::PuzzleScale - 1);
}

void										Puzzle::ExecUp()
{
	short unsigned int tmp = this->PuzzleMap[this->y0 - 1][this->x0];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0 - 1][this->x0] = 0;
	this->y0--;
	//std::cout << "Up : ";
	this->ManhattanDistance();

}

void										Puzzle::ExecDown()
{
	short unsigned int tmp = this->PuzzleMap[this->y0 + 1][this->x0];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0 + 1][this->x0] = 0;
	this->y0++;
	//std::cout << "Down : ";
	this->ManhattanDistance();
}

void										Puzzle::ExecLeft()
{
	short unsigned int tmp = this->PuzzleMap[this->y0][this->x0 - 1];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0][this->x0 - 1] = 0;
	this->x0--;
	//std::cout << "Left : ";
	this->ManhattanDistance();
}

void										Puzzle::ExecRight()
{
	short unsigned int tmp = this->PuzzleMap[this->y0][this->x0 + 1];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0][this->x0 + 1] = 0;
	this->x0++;
	//std::cout << "Right : ";
	this->ManhattanDistance();
}

short unsigned int							Puzzle::GetManhattanDistance()
{
	return (this->Distance);
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

void										Puzzle::AffSolution() const
{
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
			std::cout << Puzzle::SolutionMap[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}