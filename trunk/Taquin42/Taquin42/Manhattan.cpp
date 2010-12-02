#include <list>
#include "Manhattan.hpp"

Manhattan::Manhattan()
{
  std::cout << " *** Manhattan implementation ***" << std::endl;
  this->CurrentNodeName = 1;
  this->Direction[0] = '\0';
}

Manhattan::~Manhattan()
{
    std::cout << " *** Manhattan implementation Done ***" << std::endl;
}

void						Manhattan::Run(Puzzle& p)
{
	SearchNextPosZero(p);
}

void						Manhattan::NextNode()
{
	this->CurrentNodeName++;
}

void						Manhattan::SearchNextPosZero(Puzzle& p)
{
	sPositions CurrentNodePos;
	sPositions ZeroNodePos;
	sPositions CurrentNodeDestinationPos;
	sPositions ZeroNodeDestinationPos(2,1);

	p.SearchCurrentNodePos(this->CurrentNodeName, CurrentNodePos);
	p.SearchCurrentNodePos(0, ZeroNodePos);
	p.GetSolutionGenerator()->SearchNodeGoalPos(this->CurrentNodeName, CurrentNodeDestinationPos);
	
	std::cout << "CurrentNodeName : " << this->CurrentNodeName << "(" << CurrentNodePos.Node_px << "," << CurrentNodePos.Node_py << ")" << std::endl;
	std::cout << "NodeName : 0(" << ZeroNodePos.Node_px << "," << ZeroNodePos.Node_py << ")" << std::endl;
	std::cout << "Destination of current node : " << "(" << CurrentNodeDestinationPos.Node_px << "," << CurrentNodeDestinationPos.Node_py << ")" << std::endl;

	while (CurrentNodePos != CurrentNodeDestinationPos)
	{
		//distance of Manhattan
		//4 possible directions
		this->Arbre(p.GetMap(), p.GetScale(), ZeroNodePos, ZeroNodeDestinationPos);
		//to check the 4 possibilities
	}
}


void									Manhattan::Arbre(int ** Map, unsigned int Size, sPositions NodePos, sPositions& DestinationPos)
{
	std::list<ManhattanMoves>			dep;
	int									distance;

	if (NodePos.Node_px > 0) //left
	{
		distance = this->Theory(sPositions(NodePos.Node_px - 1, NodePos.Node_py), DestinationPos);
		std::cout << "Left Distance : " << distance << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Left, distance));
	}
	if (NodePos.Node_px < Size - 1) //right
	{
		distance = this->Theory(sPositions(NodePos.Node_px + 1, NodePos.Node_py), DestinationPos);
		std::cout << "Right  Distance : " << distance << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Right, distance));
	}
	if (NodePos.Node_py > 0) //up
	{
		distance = this->Theory(sPositions(NodePos.Node_px, NodePos.Node_py - 1), DestinationPos);
		std::cout << "Up  Distance : " << distance << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Up, distance));
	}
	if (NodePos.Node_py < Size - 1) //down
	{
		distance = this->Theory(sPositions(NodePos.Node_px, NodePos.Node_py + 1), DestinationPos);
		std::cout << "Down  Distance : " << distance << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Down, distance));
	}
	this->SortList(dep);
	std::list<ManhattanMoves>::iterator itb = dep.begin();
	std::list<ManhattanMoves>::iterator ite = dep.end();
	std::cout << "===== the list sorted ======"<< std::endl;
	for (; itb != ite; ++itb)
	{
		std::cout << (*itb).NbMove << "-" ;
		(this->*(*itb).Meth)(NodePos, DestinationPos, Map, Size);
	}
	std::cout << std::endl;
	system("pause");
// Compute Manhattan distance from the closest cases
// Next, choose way and sort this choose
	/*
	damn(); 3
	up(); 4
	left(); 4 
	right(); 5*/
}

void						Manhattan::Up(sPositions Pos, sPositions& DestinationsPos,
							      int** Map, int Size)
{
	sPositions					NewZeroPos = Pos;
	NewZeroPos.Node_py--;
	this->ListMovement.push_back("Up");
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos);
}

void						Manhattan::Down(sPositions Pos, sPositions& DestinationsPos,
								int** Map, int Size)
{
	sPositions					NewZeroPos = Pos;
	NewZeroPos.Node_py++;
	this->ListMovement.push_back("Down");
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos);
}

void						Manhattan::Left(sPositions Pos, sPositions& DestinationsPos,
								int** Map, int Size)
{
	sPositions					NewZeroPos = Pos;
	NewZeroPos.Node_px--;
	this->ListMovement.push_back("Left");
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos);
}

void						Manhattan::Right(sPositions Pos, sPositions& DestinationsPos,
								 int** Map, int Size)
{
	sPositions					NewZeroPos = Pos;
	NewZeroPos.Node_px++;
	this->ListMovement.push_back("Right");
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos);
	//Pos = NewZeroPos;
}

void						Manhattan::MoveZeroToPosDestination()
{

}

void						Manhattan::SortList(std::list<ManhattanMoves> & ListToSort) const
{
	std::list<ManhattanMoves>			ListSorted;
	std::list<ManhattanMoves>::iterator BackUpIt;
	int									Min;


	while (! ListToSort.empty())
	{
		std::list<ManhattanMoves>::iterator	itb = ListToSort.begin();
		std::list<ManhattanMoves>::iterator	ite = ListToSort.end();
		Min = (*itb).NbMove;
		BackUpIt = itb;
		for (; itb != ite; ++itb)
		{
			if ((*itb).NbMove < Min)
			{
				Min = (*itb).NbMove;
				BackUpIt = itb;
			}
		}
		ListSorted.push_back(*BackUpIt);
		ListToSort.erase(BackUpIt);
	}
	ListToSort = ListSorted;
}
