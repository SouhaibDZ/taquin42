#include "Extender.h"

int		Resume(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList)
{
	if ((*It).GetDistance() == 0)
	{
		std::cout << "OPENED LIST NUMBER OF CONTENTS	: \t\t[" << OpenedList.size() << "]"<< std::endl;
		std::cout << "CLOSED LIST NUMBER OF CONTENTS	: \t\t[" << ClosedList.size() << "]"<< std::endl;
		std::cout << std::endl;
		//(*It).Show();
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
		AddInList(OpenedList, ClosedList, P);
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
		AddInList(OpenedList, ClosedList, P);
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
		AddInList(OpenedList, ClosedList, P);
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
		AddInList(OpenedList, ClosedList, P);
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

void	AddInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle& P)
{
	if (IsInList(OpenedList, ClosedList, P) == true)
		return ;
	short unsigned int d = P.GetDistance();
	std::list<Puzzle>::iterator it = OpenedList.begin();
	std::list<Puzzle>::iterator it_end = OpenedList.end();

	while (it != it_end && (*it).GetDistance() < d)
		++it;
	OpenedList.insert(it, P);
}

void										ShowNbMoves(void)
{
	std::cout << "NUMBER OF MOVES			: \t\t [" << NbMoves << "] Moves." << std::endl;
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
