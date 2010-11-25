#ifndef _MANHATTAN_HPP_
# define _MANHATTAN_HPP_

#include <iostream>
#include <string>
#include <vector>

class				Manhattan
{
public:
  Manhattan();
  ~Manhattan();
  
private:
  Manhattan(const Manhattan &);
  Manhattan &			operator=(const Manhattan &);

public:
  inline int			Theory(const sPostions & NodePos, const sPostions & GoalNodePos)
  {
    return ();
  }
  
  inline const sPositions &	GetCurrentPos(int CurrentNodeName);
  inline bool			CanMove(sPositions CurrentNodePos,
					const std::vector< std::vector <int> > & PuzzleMap);

public:
  virtual int			GetMovesNb(void) const;
  virtual std::string &		GetStatesTime(void) const;
  virtual int			GetStatesSize(void) const;
  virtual int			GetTotalCosts(void) const;
  virtual std::string &		GetOrderedSequence(void) const;

public:
  int				MovesNb;
  std::string			StatesTime;
  int				StatesSize;
  int				TotalCosts;
  std::string			OrderedSequence;
};

#endif //_MANHATTAN_HPP_
