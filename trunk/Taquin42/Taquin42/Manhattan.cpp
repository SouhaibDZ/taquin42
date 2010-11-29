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
//		arbre();
		//to check the 4 possibilities
	}
}
/*
void arbre()
{
// Compute Manhattan distance from the closest cases
// Next, choose way and sort this choose
	
	damn(); 3
	up(); 4
	left(); 4 
	right(); 5
}

void up()
{
	//stocker le chemin ds une liste
	arbre();
}*/

void						Manhattan::showDirection()
{

}

void						Manhattan::MoveZeroToPosDestination()
{

}