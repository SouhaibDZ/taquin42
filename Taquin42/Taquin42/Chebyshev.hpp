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
  inline int				Max(int d1, int d2)
  {
  	return ((d1 > d2) ? d1 : d2); 
  }
  
  inline int				Theory(const sPositions  	& NodePos,
				       	const sPositions	& GoalNodePos)
  {
  	int				dx = abs(NodePos.Node_px - GoalNodePos.Node_px);
  	int				dy = abs(NodePos.Node_py - GoalNodePos.Node_py);
  	
	return (Max (dx, dy));
  }
  
  inline bool				CanMove(sPositions CurrentNodePos,
						const int ** PuzzleMap)
  {
    return (true);
  }

private:
  int					PuzzleScale;
  sPositions				CurrentPos;
};

#endif //_CHEBYSHEV_HPP_
