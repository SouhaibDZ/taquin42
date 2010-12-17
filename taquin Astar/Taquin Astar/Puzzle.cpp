#include <iostream>
#include <sstream>
#include <math.h>
#include <fstream>
#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"


unsigned int			Puzzle::PuzzleScale = 0;
short unsigned int **	Puzzle::SolutionMap = NULL;

Puzzle::Puzzle()
{

}

Puzzle::~Puzzle()
{
}

Puzzle::Puzzle(const Puzzle & p)
{
	this->meth = p.meth;
	this->ListTab = p.ListTab;
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
	Puzzle::SolutionMap = SG.GenerateSolution(Puzzle::PuzzleScale);
	(this->*meth)();
	return (this->PuzzleMap);
}

unsigned int					Puzzle::GetScale(void)
{
	return (Puzzle::PuzzleScale);
}

short unsigned int**						Puzzle::GetSolutionGenerator()
{
	if (Puzzle::SolutionMap == NULL)
		return NULL;
	return (Puzzle::SolutionMap);
}

bool										Puzzle::CanUp() const
{
	return (this->y0 > 0);
}

bool										Puzzle::CanDown() const
{
	return (this->y0 < Puzzle::PuzzleScale - 1);
}

bool										Puzzle::CanLeft() const
{
	return (this->x0 > 0);
}

bool										Puzzle::CanRight() const
{
	return (this->x0 < Puzzle::PuzzleScale - 1);
}

void										Puzzle::ExecUp()
{
	short unsigned int tmp = this->PuzzleMap[this->y0 - 1][this->x0];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0 - 1][this->x0] = 0;
	this->y0--;
	(this->*meth)();

}

void										Puzzle::ExecDown()
{
	short unsigned int tmp = this->PuzzleMap[this->y0 + 1][this->x0];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0 + 1][this->x0] = 0;
	this->y0++;
	(this->*meth)();
}

void										Puzzle::ExecLeft()
{
	short unsigned int tmp = this->PuzzleMap[this->y0][this->x0 - 1];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0][this->x0 - 1] = 0;
	this->x0--;
	(this->*meth)();
}

void										Puzzle::ExecRight()
{
	short unsigned int tmp = this->PuzzleMap[this->y0][this->x0 + 1];
	this->PuzzleMap[this->y0][this->x0] = tmp;
	this->PuzzleMap[this->y0][this->x0 + 1] = 0;
	this->x0++;
	(this->*meth)();
}

short unsigned int							Puzzle::GetDistance() const
{
	return (this->Distance);
}

void										Puzzle::AffPuzzle() const
{
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
			std::cout << this->PuzzleMap[i][j] << "\t";
		std::cout << std::endl;
	}
}

void										Puzzle::AffSolution() const
{
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
			std::cout << Puzzle::SolutionMap[i][j] << "\t";
		std::cout << std::endl;
	}
}
void										Puzzle::DeletePuzzle()
{
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
		delete this->PuzzleMap[i];
	delete this->PuzzleMap;
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
			D += abs(static_cast<int>(j - x)) + abs(static_cast<int>(i - y));
		}
	}
	this->Distance = D;
}

void										Puzzle::ChebyshevDistance()
{
	short unsigned int						D = 0;
	short unsigned int						CurrentNode;
	int										x, y;
	double									dx, dy;

	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
			CurrentNode = this->PuzzleMap[i][j];
			this->SearchPos(x, y, CurrentNode);
			dx = pow(static_cast<double>(i - x), 2);
 			dy = pow(static_cast<double>(j - y), 2);
			D += static_cast<short unsigned int>(sqrt(dx + dy));
		}
	}
	this->Distance = D;
}

int											Max(int d1, int d2)
{
	return ((d1 > d2) ? d1 : d2);
}

void										Puzzle::EuclideanDistance()
{
	short unsigned int						D = 0;
	short unsigned int						CurrentNode;
	int										x, y, dx, dy;

	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < Puzzle::PuzzleScale; ++j)
		{
			CurrentNode = this->PuzzleMap[i][j];
			this->SearchPos(x, y, CurrentNode);
			dx = abs(static_cast<int>(i - x));
			dy = abs(static_cast<int>(j - y));
			D += static_cast<short unsigned int>(Max(dx, dy));
		}
	}
	this->Distance = D;
}

void										Puzzle::AddTab(Puzzle& P)
{
	this->ListTab.push_back(P.PuzzleMap);
}

void										Puzzle::ClearListTab()
{
	this->ListTab.clear();
}

void										Puzzle::ShowMoves() const
{
	/*
	std::list<short unsigned int **>::const_iterator it;
	std::list<short unsigned int **>::const_iterator it_end = this->ListTab.end();
	unsigned int i, j;

	for (it = this->ListTab.begin(); it != it_end; ++it)
	{
		for (i = 0; i < Puzzle::PuzzleScale; ++i)
		{
			for (j = 0; j < Puzzle::PuzzleScale; ++j)
				std::cout << (*it)[i][j] << "\t";
			std::cout << std::endl;
		}
		std::cout << std::endl << "--------------------------------------------" << std::endl;
	}
	this->AffPuzzle();
	*/

	std::filebuf fb;
	fb.open ("out.txt",std::ios::out);
	std::ostream os(&fb);

	std::list<short unsigned int **>::const_iterator it;
	std::list<short unsigned int **>::const_iterator it_end = this->ListTab.end();
	unsigned int i, j;

	for (it = this->ListTab.begin(); it != it_end; ++it)
	{
		os << "--------------------------------" << std::endl;
		for (i = 0; i < Puzzle::PuzzleScale; ++i)
		{
			for (j = 0; j < Puzzle::PuzzleScale; ++j)
				os << (*it)[i][j] << "\t";
			os << std::endl;
		}
	}
	this->AffPuzzle();
}

void										Puzzle::SetAlgo(const char Name)
{
	if (Name == 'C')
		this->meth = &Puzzle::ChebyshevDistance;
	else if (Name == 'E')
		this->meth = &Puzzle::EuclideanDistance;
	else
		this->meth = &Puzzle::ManhattanDistance;
}

void									Puzzle::EraseMap()
{
	if (this->PuzzleMap == NULL)
		return ;
	for (unsigned int i = 0; i < Puzzle::PuzzleScale; ++i)
		delete[] this->PuzzleMap[i];
	delete this->PuzzleMap;
}


short unsigned int						Puzzle::GetNbMoves() const
{
	return (this->ListTab.size() + 1);
}
