
#ifndef _HEURISTICS_HPP_
# define _HEURISTICS_HPP_

#include <iostream>
#include <string>
#include <vector>

class				Heuristics
{
public:
  Heuristics();
  ~Heuristics();
  
private:
  Heuristics(const Heuristics &);
  Heuristics &		operator=(const Heuristics &);

public:
  inline int			Theory(int Node_px, int Node_py);
  inline bool			CanMove(sPositions CurrentNodePos,
  				const int ** PuzzleMap);

public:
  virtual int			GetMovesNb(void) const;
  virtual std::string &	GetStatesTime(void) const;
  virtual int			GetStatesSize(void) const;
  virtual int			GetTotalCosts(void) const;
  virtual std::string &	GetOrderedSequence(void) const;

public:
  int				MovesNb;
  std::string			StatesTime;
  int				StatesSize;
  int				TotalCosts;
  std::string			OrderedSequence;
};

#endif //_HEURISTICS_HPP_
