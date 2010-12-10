#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"
#include <sstream>
#include "Variables.hpp"

Puzzle::Puzzle(const std::string& Contents, Heuristics* Algo)
	: PuzzleMap(NULL), AlgoResolution(Algo), SolutionPlate(NULL)
{
	this->CreatePuzzle(Contents);
}

Puzzle::~Puzzle()
{
}

int**							Puzzle::GetMap(void) const
{
	return (this->PuzzleMap);
}

unsigned int					Puzzle::GetScale(void) const
{
	return (this->PuzzleScale);
}

const SolutionGenerator*		Puzzle::GetSolutionGenerator() const
{
	return (this->SolutionPlate);
}

void							Puzzle::SearchCurrentNodePos(int CurrentNodeName,
																	 sPositions& sPos) const
{
	unsigned int				i = 0;
	unsigned int				j = 0;
	bool						end = false;

	while (i < PuzzleScale && !end)
	{
		j = 0;
		while (j < PuzzleScale && !end)
		{
			if (PuzzleMap[i][j] == CurrentNodeName)
			{
				sPos.Node_px = j;
				sPos.Node_py = i;
			}
			++j;
		}
		++i;
	}
}

void									Puzzle::CreatePuzzle(const std::string & Contents)
{
	std::istringstream					in(Contents);

	int	pos = Contents.find_first_of('\n');
	this->PuzzleScale = this->CountScales(Contents.substr(0, pos));
	this->SolutionPlate	= new SolutionGenerator(this->PuzzleScale);
	this->PuzzleMap = new int*[this->PuzzleScale];

	for (unsigned int i = 0; i < this->PuzzleScale; ++i)
	{
		this->PuzzleMap[i] = new int[this->PuzzleScale];
		for(unsigned int j = 0; j < this->PuzzleScale; ++j)
		  in >> this->PuzzleMap[i][j];
	}
	// This part was put only for debug
	// It will be deleted at the end of project.
	std::cout << "2- File Map Content " << std::endl << std::endl;
	for (unsigned int i = 0; i < this->PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < this->PuzzleScale; ++j)
			std::cout << this->PuzzleMap[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "3- File Map Solution " << std::endl << std::endl;
	this->SolutionPlate->GenerateSolution();
	std::cout << std::endl << std::endl;
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


void										Puzzle::Resolve()
{
	this->AlgoResolution->Run(*this);
}

void										Puzzle::SwapNode(const sPositions& pos1, const sPositions& pos2)
{
	int										save = this->PuzzleMap[pos1.Node_py][pos1.Node_px];
	this->PuzzleMap[pos1.Node_py][pos1.Node_px] = this->PuzzleMap[pos2.Node_py][pos2.Node_px];
	this->PuzzleMap[pos2.Node_py][pos2.Node_px] = save;
	std::cout << "Node 1: " << this->PuzzleMap[pos1.Node_py][pos1.Node_px] << std::endl;
	std::cout << "Node 2: " << this->PuzzleMap[pos2.Node_py][pos2.Node_px] << std::endl;
}

std::ostream&					operator<<(std::ostream& o, const Puzzle& p)
{
	for (unsigned int i = 0; i < p.PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < p.PuzzleScale; ++j)
		{
			std::cout << p.PuzzleMap[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	return (o);
}