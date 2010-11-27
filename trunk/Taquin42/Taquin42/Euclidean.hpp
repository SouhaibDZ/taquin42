#ifndef _EUCLIDEAN_HPP_
# define _EUCLIDEAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Variables.hpp"

class				Euclidean
{
public:
  Euclidean();
  ~Euclidean();
  
private:
  Euclidean(const Euclidean &);
  Euclidean &			operator=(const Euclidean &);

public:
  inline int			Theory(const sPostions & NodePos,
				       const sPostions & GoalNodePos)
  {
    return (abs(NodePos->Node_px - GoalNodePos->GoalNode_px) +
	    abs(NodePos->Node_py - GoalNodePos->GoalNode_py));
  }
  
  inline bool			CanMove(sPositions CurrentNodePos,
					const int ** PuzzleMap)
  {
    return (true);
  }

public:
  virtual int			GetMovesNb(void) const;
  virtual std::string &	GetStatesTime(void) const;
  virtual int			GetStatesSize(void) const;
  virtual int			GetTotalCosts(void) const;
  virtual std::string &	GetOrderedSequence(void) const;

private:
  int				MovesNb;
  std::string			StatesTime;
  int				StatesSize;
  int				TotalCosts;
  std::string			OrderedSequence;
  int				PuzzleScale;
  sPositions			CurrentPos;
};

#endif //_EUCLIDEAN_HPP_
