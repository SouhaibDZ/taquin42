#ifndef _CHEBYSHEV_HPP_
# define _CHEBYSHEV_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Variables.hpp"
#include <stdlib.h>

class					Chebyshev
{
public:
  Chebyshev();
  ~Chebyshev();
  
private:
  Chebyshev(const Chebyshev &);
  Chebyshev &				operator=(const Chebyshev &);

public:
  inline int				Theory(const sPositions  	& NodePos,
				       	const sGoalPositions	& GoalNodePos)
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

#endif //_CHEBYSHEV_HPP_
