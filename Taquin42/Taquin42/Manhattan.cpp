#include <list>
#include "Manhattan.hpp"

Manhattan::Manhattan()
{
	std::cout << "*--------------------------------------*" << std::endl;
	std::cout << "*** This is Manhattan Implementation ***" << std::endl;
	std::cout << "*--------------------------------------*" << std::endl << std::endl;
	this->CurrentNodeName = 1;
	this->Direction[0] = '\0';
	this->EndTree = false;
}

Manhattan::~Manhattan()
{
	std::cout << "*-----------------------------------*" << std::endl;
	std::cout << "*** Manhattan Implementation Done ***" << std::endl;
	std::cout << "*-----------------------------------*" << std::endl;
}

void						Manhattan::Run(Puzzle& p)
{
	this->SearchNextPosZero(p);
}

void						Manhattan::NextNode()
{
	this->CurrentNodeName++;
}

void						Manhattan::SearchNextPosZero(Puzzle& p)
{
	sPositions ZeroNodePos;
	sPositions ZeroNodeDestinationPos(2,1);

	p.SearchCurrentNodePos(this->CurrentNodeName, this->CurrentNodePos);
	p.SearchCurrentNodePos(0, ZeroNodePos);
	p.GetSolutionGenerator()->SearchNodeGoalPos(this->CurrentNodeName, this->CurrentNodeDestinationPos);
	
	std::cout << "*CURRENT NODE NAME*					:\t#["  << this->CurrentNodeName << "]" << std::endl;
	std::cout << "*CURRENT NODE POSITIONS*				:\t"   << this->CurrentNodeName << "[" << CurrentNodePos.Node_px << ","     << CurrentNodePos.Node_py << "]" << std::endl;
	std::cout << "*CURRENT NODE DESTINATIONS POSITIONS*	\t\t:\t"   << this->CurrentNodeName << "[" << CurrentNodeDestinationPos.Node_px << "," << CurrentNodeDestinationPos.Node_py << "]" << std::endl;
	std::cout << "*NODE ZERO POSITIONS*					:\t0[" << ZeroNodePos.Node_px   << "," << ZeroNodePos.Node_py    << "]"     << std::endl;
	std::cout << "*NODE ZERO DESTINATIONS POSITIONS*	\t\t:\t0[2,1]" << std::endl;

	this->EndTree = false;
	std::list<std::string> l;
	std::list<std::string> t;
	l = this->Arbre(p.GetMap(), p.GetScale(), ZeroNodePos, ZeroNodeDestinationPos, t);
	std::cout << "Way found" << std::endl;
	std::cout << "* LIST MOUVEMENTS *" << std::endl;
	std::list<std::string>::iterator ita = this->ListMovement.begin();
	std::list<std::string>::iterator itd = this->ListMovement.end();
	std::cout << "Debut liste: " << std::endl;
	system("pause");
	for (; ita != itd; ++ita)
	{
		std::cout << "<"<< (*ita) << ">";
	}
	std::cout << std::endl;
	system("pause");
}

std::list<std::string>		Manhattan::Arbre(int ** Map, unsigned int Size,
											 sPositions NodePos, sPositions& DestinationPos, std::list<std::string> l)
{
	std::list<ManhattanMoves>			dep;
	int									distance;
	sPositions							tmpPos;


	if (this->EndTree)
		return l;
	std::cout << std::endl;
	std::cout << "\t\t*-------------------------*" << std::endl;
	std::cout << "\t\t*Distances Processing ....*" << std::endl;
	std::cout << "\t\t*-------------------------*" << std::endl << std::endl;

	tmpPos = sPositions(NodePos.Node_px - 1, NodePos.Node_py);
	if (NodePos.Node_px > 0 && (tmpPos != this->CurrentNodePos) && (tmpPos != this->ZeroPreviousPos))			//left
	{
		distance = this->Theory(tmpPos, DestinationPos);
		if (distance == 0)
		{
			l.push_back("Left");
			this->EndTree = true;
			this->ListMovement = l;
			return l;
		}
		std::cout << "*LEFT  DISTANCE  <-to-> ZERO DESTINATIONS*	\t:\t[" << distance << "]" << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Left, distance));
	}
	tmpPos = sPositions(NodePos.Node_px + 1, NodePos.Node_py);
	if (NodePos.Node_px < Size - 1 && (tmpPos != this->CurrentNodePos) && (tmpPos != this->ZeroPreviousPos)) 	//right
	{
		distance = this->Theory(tmpPos, DestinationPos);
		if (distance == 0)
		{
			l.push_back("Right");
			this->EndTree = true;
			this->ListMovement = l;
			return l;
		}
		std::cout << "*RIGHT DISTANCE  <-to-> ZERO DESTINATIONS*	\t:\t[" << distance << "]" << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Right, distance));
	}
	std::cout << "PreviousZeroPos (" << this->ZeroPreviousPos.Node_px << "," << this->ZeroPreviousPos.Node_py << ")" << std::endl;
	std::cout << "ZeroPos (" << NodePos.Node_px << "," << NodePos.Node_py << ")" << std::endl;

	system("pause");
	tmpPos = sPositions(NodePos.Node_px, NodePos.Node_py - 1);
	if (NodePos.Node_py > 0 && (tmpPos != this->CurrentNodePos) && (tmpPos != this->ZeroPreviousPos))			//up
	{
		distance = this->Theory(tmpPos, DestinationPos);
		if (distance == 0)
		{
			l.push_back("Up");
			this->EndTree = true;
			this->ListMovement = l;
			return l;
		}
		std::cout << "*UP    DISTANCE  <-to-> ZERO DESTINATIONS*	\t:\t[" << distance << "]" << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Up, distance));
	}
	tmpPos = sPositions(NodePos.Node_px, NodePos.Node_py + 1);
	if (NodePos.Node_py < Size - 1 && (tmpPos != this->CurrentNodePos) && (tmpPos != this->ZeroPreviousPos))		//down
	{
		distance = this->Theory(tmpPos, DestinationPos);
		if (distance == 0)
		{
			l.push_back("Down");
			this->EndTree = true;
			this->ListMovement = l;
			return l;
		}
		std::cout << "*DOWN  DISTANCE  <-to-> ZERO DESTINATIONS*	\t:\t[" << distance << "]" << std::endl;
		dep.push_back(ManhattanMoves(&Manhattan::Down, distance));
	}
	this->SortList(dep);
	std::cout << "===== The List is sorted ======"<< std::endl;
	std::list<ManhattanMoves>::iterator itb = dep.begin();
	std::list<ManhattanMoves>::iterator ite = dep.end();
	//system("pause");
	std::cout << "* LIST CONTENTS *"<< std::endl;
	for (; itb != ite; ++itb)
	{
		std::cout << "<"<< (*itb).NbMove << ">";
		(this->*(*itb).Meth)(NodePos, DestinationPos, Map, Size, l);
	}
	std::cout << std::endl;
// Compute Manhattan distance from the closest cases
// Next, choose way and sort this choose
	/*
	damn(); 3
	up(); 4
	left(); 4 
	right(); 5*/
	return l;
}

void						Manhattan::Up(sPositions Pos, sPositions& DestinationsPos,
										  int** Map, int Size, std::list<std::string> l)
{
	sPositions				NewZeroPos = Pos;
	NewZeroPos.Node_py--;
	l.push_back("Up");
	this->ZeroPreviousPos = Pos;
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos, l);
}

void						Manhattan::Down(sPositions Pos, sPositions& DestinationsPos,
								int** Map, int Size, std::list<std::string> l)
{
	sPositions				NewZeroPos = Pos;
	NewZeroPos.Node_py++;
	l.push_back("Down");
	this->ZeroPreviousPos = Pos;
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos, l);
}

void						Manhattan::Left(sPositions Pos, sPositions& DestinationsPos,
								int** Map, int Size, std::list<std::string> l)
{
	sPositions					NewZeroPos = Pos;
	NewZeroPos.Node_px--;
	l.push_back("Left");
	this->ZeroPreviousPos = Pos;
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos, l);
}

void						Manhattan::Right(sPositions Pos, sPositions& DestinationsPos,
								 int** Map, int Size, std::list<std::string> l)
{
	sPositions					NewZeroPos = Pos;
	NewZeroPos.Node_px++;
	l.push_back("Right");
	this->ZeroPreviousPos = Pos;
	this->Arbre(Map, Size, NewZeroPos, DestinationsPos, l);
}

void						Manhattan::MoveZeroToPosDestination(std::list<std::string> ListMovement)
{
	std::list<std::string>::iterator	itb = ListMovement.begin();
	std::list<std::string>::iterator	ite = ListMovement.end();

	for (; itb != ite; ++itb)
	{
		;
	}
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
