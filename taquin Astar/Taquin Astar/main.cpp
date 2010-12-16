#include <iostream>
#include <sstream>
#include <list>
#include <iterator>
#include "Extender.h"
#include "Puzzle.hpp"
#include "FileLoader.h"

int								main(int argc, char **argv)
{
	char Name = 'E';
	if (argc == 2)
		//Name = argv[1][0];
	{
		FileLoader				F;
		std::string				S;
		Puzzle					P;
		SolutionGenerator		SG;
		short unsigned int**	Tab;
		clock_t					timeDeb, timeEnd;
		std::list<Puzzle>		OpenedList, ClosedList;
		int x = 0, y = 0, fg = -42;

		timeDeb = clock();
		DisplayLogo();
		F.LoadFile("TaquinA5_2.txt", S);
		std::istringstream		In(S);
		P.SetAlgo(Name);
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

			(*FirstPuzzle).ClearListTab();
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