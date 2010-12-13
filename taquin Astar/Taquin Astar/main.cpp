#include <iostream>
#include "FileLoader.h"
#include <sstream>
#include "Puzzle.hpp"
#include <list>

int main()
{
	FileLoader				F;
	std::string				S;
	Puzzle					P;
	SolutionGenerator		SG;
	short unsigned int**	Tab;
	std::list<Puzzle>		OpenedList;
	std::list<Puzzle>		ClosedList;

	F.LoadFile("TaquinA5.txt", S);
	std::istringstream		In(S);
	Tab = P.CreatePuzzle(S);

	std::cout << std::endl;
	OpenedList.push_back(P);
	std::list<Puzzle>::iterator it = OpenedList.begin();
	if (P.CanUp())
	{
		Puzzle PUp(P); // on cree la copie du puzzle
		PUp.ExecUp(); //on decale le 0 vers le haut
	}
	if (P.CanDown())
	{
		Puzzle PDown(P);
		PDown.ExecDown();
		;
	}
	if (P.CanLeft())
	{
		Puzzle PLeft(P);
		PLeft.ExecLeft();
		;
	}
	if (P.CanRight())
	{
		Puzzle PRight(P);
		PRight.ExecRight();
		;
	}
	// transfer du premiere element de la liste open
	// vers la fin de la liste closed
	ClosedList.push_back(*it);
	OpenedList.erase(it);
	

	return (0);
}