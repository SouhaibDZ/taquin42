
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
  inline int			GetMovesNb(void) const
  {
	return (this->MovesNb);
  }

  inline const std::string &	GetStatesTime(void) const
  {
	return (this->StatesTime);
  }

  inline int			GetStatesSize(void) const
  {
	return (this->StatesSize);
  }

  inline int			GetTotalCosts(void) const
  {
	return (this->TotalCosts);
  }

  inline const std::string &	GetOrderedSequence(void) const
  {
	return (this->OrderedSequence);
  }

public:
  int				MovesNb;
  std::string			StatesTime;
  int				StatesSize;
  int				TotalCosts;
  std::string			OrderedSequence;
};

#endif //_HEURISTICS_HPP_
