#include "Puzzle.hpp"
#include "SolutionGenerator.hpp"
#include <sstream>
#include "Variables.hpp"

Puzzle::Puzzle(const std::string& Contents, Heuristics* Algo) : PuzzleMap(NULL), AlgoResolution(Algo), SolutionPlate(NULL)
{
	this->CreatePuzzle(Contents);
}

Puzzle::~Puzzle()
{
}

void									Puzzle::Resolve()
{
	this->AlgoResolution->Run(*this);
}

void									Puzzle::CreatePuzzle(const std::string & Contents)
{
	std::istringstream						in(Contents);

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
	for (unsigned int i = 0; i < this->PuzzleScale; ++i)
	{
		for (unsigned int j = 0; j < this->PuzzleScale; ++j)
			std::cout << this->PuzzleMap[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << "Puzzle Loaded successfully :)" << std::endl << std::endl;
	std::cout << "##### Solution #####" << std::endl << std::endl;
	this->SolutionPlate->GenerateSolution();
}

void									Puzzle::SearchCurrentNodePos(int CurrentNodeName, sPositions& sPos) const
{
	unsigned int i = 0;
	unsigned int j = 0;
	bool		 end = false;

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

int**							Puzzle::GetMap(void) const
{
	return (this->PuzzleMap);
}

const SolutionGenerator*		Puzzle::GetSolutionGenerator() const
{
	return (this->SolutionPlate);
}