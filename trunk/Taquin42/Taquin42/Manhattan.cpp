#include <map>
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

void					Manhattan::Arbre(int ** Map, unsigned int Size, sPositions NodePos, sPositions& DestinationPos)
{
	std::map<void (Manhattan::*)(), int>		dep;
	int											distance;

	void	(Manhattan::*prout)();
	prout = &Manhattan::left;

	if (NodePos.Node_px > 0) //left
	{
		distance = this->Theory(sPositions(NodePos.Node_px - 1, NodePos.Node_py), DestinationPos);
		std::cout << "Left Distance : " << distance << std::endl;
		//dep[&Manhattan::left] = distance;
		//dep[*prout] = distance;
	}
	if (NodePos.Node_px < Size - 1) //right
	{
		distance = this->Theory(sPositions(NodePos.Node_px + 1, NodePos.Node_py), DestinationPos);
		std::cout << "Right  Distance : " << distance << std::endl;
	}
	if (NodePos.Node_py > 0) //up
	{
		distance = this->Theory(sPositions(NodePos.Node_px, NodePos.Node_py - 1), DestinationPos);
		std::cout << "Up  Distance : " << distance << std::endl;
	}
	if (NodePos.Node_py < Size - 1) //down
	{
		distance = this->Theory(sPositions(NodePos.Node_px, NodePos.Node_py + 1), DestinationPos);
		std::cout << "Down  Distance : " << distance << std::endl;
	}
	system("pause");
// Compute Manhattan distance from the closest cases
// Next, choose way and sort this choose
	/*
	damn(); 3
	up(); 4
	left(); 4 
	right(); 5*/
}

void						Manhattan::up()
{
	//stocker le chemin ds une liste
	//arbre();
}

void						Manhattan::down()
{
	//stocker le chemin ds une liste
	//arbre();
}

void						Manhattan::left()
{
	//stocker le chemin ds une liste
	//arbre();
}

void						Manhattan::right()
{
	//stocker le chemin ds une liste
	//arbre();
}

void						Manhattan::showDirection()
{

}

void						Manhattan::MoveZeroToPosDestination()
{

}