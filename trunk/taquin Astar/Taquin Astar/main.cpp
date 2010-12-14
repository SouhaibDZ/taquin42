#include <iostream>
#include <sstream>
#include <list>
#include <iterator>
#include "Extender.h"
#include "Puzzle.hpp"
#include "FileLoader.h"

void	DisplayLogo()
{
	std::cout << "___________                   .__           _____ ________  " << std::endl;
	std::cout << "\\__    ___/____    ________ __|__| ____    /  |  |\\_____  \\ " << std::endl;
	std::cout << "  |    |  \\__  \\  / ____/  |  \\  |/    \\  /   |  |_/  ____/ " << std::endl;
	std::cout << "  |    |   / __ \\< <_|  |  |  /  |   |  \\/    ^   /       \\ " << std::endl;
	std::cout << "  |____|  (____  /\\__   |____/|__|___|  /\\____   |\\_______ \\" << std::endl;
	std::cout << "               \\/    |__|             \\/      |__|        \\/" << std::endl;
}

int main()
{
	{
		clock_t timeDeb, timeEnd;
		FileLoader				F;
		std::string				S;
		Puzzle					P;
		SolutionGenerator		SG;
		short unsigned int**	Tab;
		std::string				Tmp("Begin");
		std::list<Puzzle>		OpenedList;
		std::list<Puzzle>		ClosedList;
		int x = 0, y = 0;

		timeDeb = clock();
		DisplayLogo();
		F.LoadFile("TaquinA4.txt", S);
		std::istringstream		In(S);
		Tab = P.CreatePuzzle(S);
		std::list<Puzzle>::iterator FirstPuzzle;
		//P.SetTime(Tmp);
		OpenedList.push_back(P);
		for (int i = 0; i < 120000; ++i)
		{
			if (!OpenedList.empty())
			{
				FirstPuzzle = OpenedList.begin();
				Resume(FirstPuzzle, OpenedList, ClosedList, i);
				ProcessUp(FirstPuzzle, OpenedList, ClosedList);
				ProcessDown(FirstPuzzle, OpenedList, ClosedList);
				ProcessRight(FirstPuzzle, OpenedList, ClosedList);
				ProcessLeft(FirstPuzzle, OpenedList, ClosedList);
				ClosedList.push_back(*FirstPuzzle);
				OpenedList.erase(FirstPuzzle);
			}
		}
		Tmp = "End";
		timeEnd = clock();
		//P.SetTime(Tmp);
		//P.TimeCounter();
		std::cout << "TIME ELAPSED			: \t\t [" << static_cast<double>(timeEnd - timeDeb) << "] ms." << std::endl;
		ShowNbMoves();
		system("pause");
	}
	system("pause");
	return (0);
}