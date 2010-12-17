#include "Extender.h"

int		Resume(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList, clock_t& timeEnd)
{
	if ((*It).GetDistance() == 0)
	{
		timeEnd = clock();
		(*It).ShowMoves();
		std::cout << "TAQUIN SOLUTION FOUND!!! ;)" << std::endl << std::endl;
		std::cout << "OPENED LIST NUMBER OF CONTENTS	: \t\t[" << OpenedList.size() << "]"<< std::endl;
		std::cout << "NUMBER OF MOVES CROSSED		: \t\t[" << (*It).GetNbMoves() << "]" << std::endl;
	}
	return ((*It).GetDistance());
}

void	ProcessUp(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList)
{
	if ((*It).CanUp())
	{
		Puzzle	P(*It);
		P.ExecUp();
		AddInList(OpenedList, ClosedList, P, *It);
		NbMoves++;
	}
}

void	ProcessRight(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList)
{
	if ((*It).CanRight())
	{
		Puzzle	P(*It);
		P.ExecRight();
		AddInList(OpenedList, ClosedList, P, *It);
		NbMoves++;
	}
}


void	ProcessDown(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList)
{
	if ((*It).CanDown())
	{
		Puzzle	P(*It);
		P.ExecDown();
		AddInList(OpenedList, ClosedList, P, *It);
		NbMoves++;
	}
}

void	ProcessLeft(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList)
{
	if ((*It).CanLeft())
	{
		Puzzle	P(*It);
		P.ExecLeft();
		AddInList(OpenedList, ClosedList, P, *It);
		NbMoves++;
	}
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

void	AddInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle& P, Puzzle& Parent)
{
	if (IsInList(OpenedList, ClosedList, P) == true)
	{
		P.EraseMap();
		P.ClearListTab();
		return ;
	}
	short unsigned int d = P.GetDistance();
	std::list<Puzzle>::iterator it = OpenedList.begin();
	std::list<Puzzle>::iterator it_end = OpenedList.end();

	while (it != it_end && (*it).GetDistance() < d)
		++it;
	P.AddTab(Parent);
	OpenedList.insert(it, P);
}

void										ShowNbMoves(void)
{
	std::cout << "NUMBER OF MOVES			: \t\t[" << NbMoves << "] Moves." << std::endl;
}

void							DisplayLogo()
{
	std::cout << "___________                   .__           _____ ________  " << std::endl;
	std::cout << "\\__    ___/____    ________ __|__| ____    /  |  |\\_____  \\ " << std::endl;
	std::cout << "  |    |  \\__  \\  / ____/  |  \\  |/    \\  /   |  |_/  ____/ " << std::endl;
	std::cout << "  |    |   / __ \\< <_|  |  |  /  |   |  \\/    ^   /       \\ " << std::endl;
	std::cout << "  |____|  (____  /\\__   |____/|__|___|  /\\____   |\\_______ \\" << std::endl;
	std::cout << "               \\/    |__|             \\/      |__|        \\/" << std::endl;
}


void	Clean(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList)
{
	std::list<Puzzle>::iterator it;
	std::list<Puzzle>::iterator it_end = OpenedList.end();

	for (it = OpenedList.begin(); it != it_end; ++it)
	{
		(*it).EraseMap();
		(*it).ClearListTab();
	}

	it_end = ClosedList.end();
	for (it = ClosedList.begin(); it != it_end; ++it)
	{
		(*it).EraseMap();
		(*it).ClearListTab();
	}
}