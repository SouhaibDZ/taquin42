#ifndef _EUCLIDEAN_HPP_
# define _EUCLIDEAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Variables.hpp"
#include <stdlib.h>
#include <math.h>

class					Euclidean
{
public:
  Euclidean();
  ~Euclidean();
  
private:
  Euclidean(const Euclidean &);
  Euclidean &				operator=(const Euclidean &);

public:
  inline double				Theory(const sPositions & NodePos,
				       	const sGoalPositions & GoalNodePos)
  {
 	double	dx = pow(static_cast<double>(NodePos.Node_px - GoalNodePos.GoalNode_px), 2);
 	double	dy = pow(static_cast<double>(NodePos.Node_py - GoalNodePos.GoalNode_py), 2);
  	return (sqrt(dx + dy));
  }
  
  inline bool				CanMove(sPositions CurrentNodePos,
						const int ** PuzzleMap)
  {
    return (true);
  }

public:
  virtual int				GetMovesNb(void) const;
  virtual const std::string &	GetStatesTime(void) const;
  virtual int				GetStatesSize(void) const;
  virtual int				GetTotalCosts(void) const;
  virtual const std::string &	GetOrderedSequence(void) const;

private:
  int					MovesNb;
  std::string				StatesTime;
  int					StatesSize;
  int					TotalCosts;
  std::string				OrderedSequence;
  int					PuzzleScale;
  sPositions				CurrentPos;
};

#endif //_EUCLIDEAN_HPP_
