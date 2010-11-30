#ifndef _MANHATTAN_HPP_
# define _MANHATTAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Variables.hpp"
#include "Heuristics.hpp"

class					Manhattan : public Heuristics
{
public:
  Manhattan();
  ~Manhattan();
  
private:
  Manhattan(const Manhattan &);
  Manhattan &				operator=(const Manhattan &);

public:
  inline int				Theory(const sPositions & NodePos,
				       	const sGoalPositions & GoalNodePos)
  {
    return (abs(NodePos.Node_px - GoalNodePos.GoalNode_px) +
	    abs(NodePos.Node_py - GoalNodePos.GoalNode_py));
  }
  
  inline bool				CanMove(sPositions CurrentNodePos,
						const int ** PuzzleMap)
  {
    return (true);
  }

public:
  void						Run(Puzzle&);

private:
  void						NextNode(); // Go to the next node
  void						SearchNextPosZero(Puzzle&); // find destination of zero
  void						showDirection();
  void						MoveZeroToPosDestination();
  void						Arbre(int**, unsigned int, sPositions);

private:
  int						PuzzleScale;
  sPositions				CurrentPos;
  sPositions				PosZeroDestination;
  char						Direction[5];
  int						CurrentNodeName;
};

#endif //_MANHATTAN_HPP_
