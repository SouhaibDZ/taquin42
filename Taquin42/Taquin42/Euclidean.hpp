#ifndef _EUCLIDEAN_HPP_
# define _EUCLIDEAN_HPP_

#include <iostream>
#include <string>
#include <vector>

class				Euclidean
{
public:
  Euclidean();
  ~Euclidean();
  
private:
  Euclidean(const Euclidean &);
  Euclidean &			operator=(const Euclidean &);

public:
  inline int			Theory(int Node_px, int Node_py);
  inline const sPositions &	GetCurrentPos(int CurrentNodeName);
  inline bool			CanMove(sPositions CurrentNodePos, const std::vector< std::vector <int> > & PuzzleMap);

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

#endif //_EUCLIDEAN_HPP_
