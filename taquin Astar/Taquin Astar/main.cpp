#include <iostream>
#include <sstream>
#include <list>
#include <iterator>
#include "Extender.h"
#include "Puzzle.hpp"
#include "FileLoader.h"

int								main(int argc, char **argv)
{
	{
		clock_t timeDeb, timeEnd;
		FileLoader				F;
		std::string				S;
		Puzzle					P;
		SolutionGenerator		SG;
		short unsigned int**	Tab;
		std::list<Puzzle>		OpenedList;
		std::list<Puzzle>		ClosedList;
		int x = 0, y = 0, fg = -42;

		timeDeb = clock();
		DisplayLogo();
		F.LoadFile("TaquinA3_2.txt", S);
		std::istringstream		In(S);
		P.SetAlgo('E');
		Tab = P.CreatePuzzle(S);
		std::list<Puzzle>::iterator FirstPuzzle;
		OpenedList.push_back(P);
		while (fg != 0 && !OpenedList.empty())
		{
			FirstPuzzle = OpenedList.begin();
			fg = Resume(FirstPuzzle, OpenedList, ClosedList);
			ProcessUp(FirstPuzzle, OpenedList, ClosedList);
			ProcessDown(FirstPuzzle, OpenedList, ClosedList);
			ProcessRight(FirstPuzzle, OpenedList, ClosedList);
			ProcessLeft(FirstPuzzle, OpenedList, ClosedList);
			ClosedList.push_back(*FirstPuzzle);
			OpenedList.erase(FirstPuzzle);
		}
		timeEnd = clock();
		std::cout << "TIME ELAPSED			: \t\t [" << static_cast<double>(timeEnd - timeDeb) << "] ms." << std::endl;
		ShowNbMoves();
		system("pause");
	}
	system("pause");
	return (0);
}