#ifndef _EXTENDER_H_
# define _EXTENDER_H_

#include <iostream>
#include "Puzzle.hpp"
#include <list>
#include <iterator>

static int NbMoves;

void	Resume(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList, int &);
void	ProcessUp(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
void	ProcessRight(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
void	ProcessDown(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
void	ProcessLeft(std::list<Puzzle>::iterator & It, std::list<Puzzle> & OpenedList,
				  std::list<Puzzle> & ClosedList);
bool	IsInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle & P);
void	AddInList(std::list<Puzzle>& OpenedList, std::list<Puzzle>& ClosedList, Puzzle& P);
void	ShowNbMoves(void);

#endif //_EXTENDER_H_