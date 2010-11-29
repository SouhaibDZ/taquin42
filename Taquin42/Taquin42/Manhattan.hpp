#ifndef _MANHATTAN_HPP_
# define _MANHATTAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Variables.hpp"
#include <stdlib.h>

class					Manhattan
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

  // Go to the next node
  void NextNode();

  // find destination of zero
  void SearchNextPosZero();

  void showDirection();

  void MoveZeroToPosDestination();

private:
  int					PuzzleScale;
  sPositions			CurrentPos;
  sPositions			PosZeroDestination;
  char					Direction[5];
  int					CurrentNodeName;
};

#endif //_MANHATTAN_HPP_
