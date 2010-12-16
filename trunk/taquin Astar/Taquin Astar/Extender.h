#ifndef _EXTENDER_H_
# define _EXTENDER_H_

#include <iostream>
#include "Puzzle.hpp"
#include <list>
#include <iterator>

static int NbMoves;

int		Resume(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
void	ProcessUp(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
void	ProcessRight(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
void	ProcessDown(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
void	ProcessLeft(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
bool	IsInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle & P);
void	AddInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle& P, Puzzle& Parent);
void	ShowNbMoves(void);
void	ChooseAlgo(const char Name,  std::list<Puzzle>::iterator & It);
void	DisplayLogo();

#endif //_EXTENDER_H_