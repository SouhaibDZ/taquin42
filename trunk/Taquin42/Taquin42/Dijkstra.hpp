#ifndef _DIJKSTRA_HPP_
# define _DIJKSTRA_HPP_

#include <iostream>
#include <string>
#include <vector>

class				Dijkstra
{
public:
  Dijkstra();
  ~Dijkstra();
  
private:
  Dijkstra(const Dijkstra &);
  Dijkstra &			operator=(const Dijkstra &);

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

#endif //_DIJKSTRA_HPP_
