#include <iostream>
#include "FileLoader.h"
#include <sstream>
#include "Puzzle.hpp"
#include <list>

void	AddInList(std::list<Puzzle>&, Puzzle&);

int main()
{
	FileLoader				F;
	std::string				S;
	Puzzle					P;
	SolutionGenerator		SG;
	short unsigned int**	Tab;
	std::list<Puzzle>		OpenedList;
	std::list<Puzzle>		ClosedList;

	F.LoadFile("TaquinA4.txt", S);
	std::istringstream		In(S);
	Tab = P.CreatePuzzle(S);
	int x, y = 0;
	short unsigned int node = 10;
	std::string Dir;
	//std::cout << "Node Possibilities : " << node << " "<< P.LookDirection(Tab, x, y, node, Dir) << std::endl;
	P.CreatePossiblities(Tab, x, y, node, Dir);
	std::cout << std::endl;
	OpenedList.push_back(P);
	if (!OpenedList.empty())
	{
		std::list<Puzzle>::iterator it = OpenedList.begin();
		if (P.CanUp())
		{
			Puzzle PUp(P); // on cree la copie du puzzle
			PUp.ExecUp(); //on decale le 0 vers le haut
			AddInList(OpenedList, PUp);
		}
		if (P.CanDown())
		{
			Puzzle PDown(P);
			PDown.ExecDown();
			AddInList(OpenedList, PDown);
		}
		if (P.CanLeft())
		{
			Puzzle PLeft(P);
			PLeft.ExecLeft();
			AddInList(OpenedList, PLeft);
		}
		if (P.CanRight())
		{
			Puzzle PRight(P);
			PRight.ExecRight();
			AddInList(OpenedList, PRight);
		}
			
		// transfer du premiere element de la liste open
		// vers la fin de la liste closed
		ClosedList.push_back(*it);
		OpenedList.erase(it);

		//Debug
		std::list<Puzzle>::iterator it2 = OpenedList.begin();
		std::list<Puzzle>::iterator it2_end = OpenedList.end();
		std::cout << std::endl << "Opened List:" << std::endl;
		while (it2 != it2_end)
		{
			std::cout << (*it2).GetManhattanDistance() << ",";
			++it2;
		}
		std::cout << std::endl;
	}

	return (0);
}


void	AddInList(std::list<Puzzle>& OpenedList, Puzzle& P)
{
	short unsigned int d = P.GetManhattanDistance();
	std::list<Puzzle>::iterator it = OpenedList.begin();
	std::list<Puzzle>::iterator it_end = OpenedList.end();

	while (it != it_end && (*it).GetManhattanDistance() < d)
		++it;
	OpenedList.insert(it, P);
}