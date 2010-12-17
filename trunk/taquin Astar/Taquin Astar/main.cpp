#include <iostream>
#include <sstream>
#include <list>
#include <iterator>
#include <fstream>
#include "Extender.h"
#include "Puzzle.hpp"
#include "FileLoader.h"

int								main(int argc, char **argv)
{
	char Name = 'M';
	std::string taq = "TaquinA5_2.txt";
	if (argc == 3)
	{
		std::ifstream infile;
		infile.open(argv[2]);
		if (!infile.is_open())
		{
			std::cout << "Error: file <" << argv[2] << ">" << " not found" << std::endl; 
			return (-1);
		}
		infile.close();
		taq = argv[2];
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
		F.LoadFile(taq.c_str(), S);
		std::istringstream		In(S);
		P.SetAlgo(Name);
		Tab = P.CreatePuzzle(S);
		std::list<Puzzle>::iterator FirstPuzzle;
		OpenedList.push_back(P);
		while (fg != 0 && !OpenedList.empty())
		{
			FirstPuzzle = OpenedList.begin();
			fg = Resume(FirstPuzzle, OpenedList, ClosedList, timeEnd);
			ProcessUp(FirstPuzzle, OpenedList, ClosedList);
			ProcessDown(FirstPuzzle, OpenedList, ClosedList);
			ProcessRight(FirstPuzzle, OpenedList, ClosedList);
			ProcessLeft(FirstPuzzle, OpenedList, ClosedList);

			(*FirstPuzzle).ClearListTab();
			ClosedList.push_back(*FirstPuzzle);
			OpenedList.erase(FirstPuzzle);
		}
		if (fg != 0)
			std::cout << "NO SOLUTION FOR THIS TAQUIN!!!" << std::endl;
		std::cout << "CLOSED LIST NUMBER OF CONTENTS	: \t\t[" << ClosedList.size() << "]"<< std::endl;
		std::cout << "TIME ELAPSED			: \t\t[" << static_cast<double>(timeEnd - timeDeb) << "] ms." << std::endl;
		ShowNbMoves();
		std::cout << "Cleaning..." << std::endl;
		Clean(OpenedList, ClosedList);
		std::cout << "Clean done" << std::endl;
	}
	return (0);
}