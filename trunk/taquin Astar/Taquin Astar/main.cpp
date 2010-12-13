#include <iostream>
#include "FileLoader.h"
#include <sstream>
#include "Puzzle.hpp"
#include <list>
#include <iterator>

void	AddInList(std::list<Puzzle>&, std::list<Puzzle>&, Puzzle&);

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

	int x = 0, y = 0;
	short unsigned int node = 10;
	std::string Dir;
	std::list<Puzzle>::iterator FirstPuzzle;
	//std::cout << "Node Possibilities : " << node << " "<< P.LookDirection(Tab, x, y, node, Dir) << std::endl;
//P.CreatePossiblities(Tab, x, y, node, Dir);
	std::cout << std::endl;
	OpenedList.push_back(P);
	for (int i = 0; i < 120000; ++i)
	{
		if (!OpenedList.empty())
		{
			FirstPuzzle = OpenedList.begin();
			if ((*FirstPuzzle).GetManhattanDistance() == 0)
			{
				std::cout << "R�sultat trouv� au bout de " << i + 1 << " iterations" << std::endl; 
				std::cout << "Size Opened: " << OpenedList.size() << std::endl;
				std::cout << "Size Closed: " << ClosedList.size() << std::endl;
				(*FirstPuzzle).ManhattanDistance();
				(*FirstPuzzle).AffPuzzle();
				system("pause");
			}
			if ((*FirstPuzzle).CanUp())
			{
				Puzzle PUp((*FirstPuzzle)); // on cree la copie du puzzle
				PUp.ExecUp(); //on decale le 0 vers le haut
				AddInList(OpenedList, ClosedList, PUp);
			}
			if ((*FirstPuzzle).CanDown())
			{
				Puzzle PDown((*FirstPuzzle));
				PDown.ExecDown();
				AddInList(OpenedList, ClosedList, PDown);
			}
			if ((*FirstPuzzle).CanLeft())
			{
				Puzzle PLeft((*FirstPuzzle));
				PLeft.ExecLeft();
				AddInList(OpenedList, ClosedList, PLeft);
			}
			if ((*FirstPuzzle).CanRight())
			{
				Puzzle PRight((*FirstPuzzle));
				PRight.ExecRight();
				AddInList(OpenedList, ClosedList, PRight);
			}
				
			// transfer du premiere element de la liste open
			// vers la fin de la liste closed
			ClosedList.push_back(*FirstPuzzle);
			OpenedList.erase(FirstPuzzle);

			//Debug
			/*std::list<Puzzle>::iterator it2 = OpenedList.begin();
			std::list<Puzzle>::iterator it2_end = OpenedList.end();
			std::cout << std::endl << "Opened List:" << std::endl;
			while (it2 != it2_end)
			{
				std::cout << (*it2).GetManhattanDistance() << ",";
				++it2;
			}
			std::cout << std::endl;*/
		}
	}
	return (0);
}

bool	IsInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle & P)
{
	std::list<Puzzle>::iterator	itob = OpenedList.begin();
	std::list<Puzzle>::iterator	itoe = OpenedList.end();
	std::list<Puzzle>::iterator	itcb = ClosedList.begin();
	std::list<Puzzle>::iterator	itce = ClosedList.end();	
	for (; itob != itoe; ++itob)
	{	
		if ((*itob) == P)
			return (true);
	}
	for (; itcb != itce; ++itcb)
	{	
		if ((*itcb) == P)
			return (true);
	}
	return (false);
}

void	AddInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle& P)
{
	if (IsInList(OpenedList, ClosedList, P) == true)
		return ;
	short unsigned int d = P.GetManhattanDistance();
	std::list<Puzzle>::iterator it = OpenedList.begin();
	std::list<Puzzle>::iterator it_end = OpenedList.end();

	while (it != it_end && (*it).GetManhattanDistance() < d)
		++it;
	OpenedList.insert(it, P);
}