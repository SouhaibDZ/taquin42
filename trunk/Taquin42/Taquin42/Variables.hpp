#ifndef _VARIABLES_HPP_
# define _VARIABLES_HPP_

#include <list>
#include <iostream>
#include <string>

class						Manhattan;

struct						sPositions
{
	sPositions();
	sPositions(int x, int y);
	bool					operator!=(const sPositions&);

	unsigned int			Node_px;
	unsigned int			Node_py;
	bool					Block;
};

struct						ManhattanMoves
{
	ManhattanMoves();
	ManhattanMoves(void (Manhattan::*)(sPositions Pos, sPositions& DestinationsPos, int** Map, std::list<std::string>), int);

	void					(Manhattan::*Meth)(sPositions Pos, sPositions& DestinationsPos, int** Map, std::list<std::string>);
	int						NbMove;
};

#endif // _VARIABLES_HPP_
