#ifndef _MANHATTAN_HPP_
# define _MANHATTAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <list>
#include "Variables.hpp"
#include "Heuristics.hpp"

class						Manhattan : public Heuristics
{
public:
  Manhattan();
  ~Manhattan();
  
private:
  Manhattan(const Manhattan &);
  Manhattan &				operator=(const Manhattan &);

public:
  inline int				Theory(const sPositions & NodePos,
				       			const sPositions & GoalNodePos)
  {
	  return (abs(NodePos.Node_px - GoalNodePos.Node_px) +
		  abs(NodePos.Node_py - GoalNodePos.Node_py));
  }
  
  inline bool				CanMove(sPositions CurrentNodePos,
								const int ** PuzzleMap)
  {
    return (true);
  }

public:
  void						Run(Puzzle&);

private:
  void						NextNode();					// Go to the next node
  void						SearchNextPosZero(Puzzle&); // find destination of zero
  void						MoveZeroToPosDestination(std::list<std::string>);
  void						Arbre(int**, unsigned int, sPositions, sPositions&, std::list<std::string>);
  void						Up(sPositions Pos, sPositions& DestinationsPos, int** Map, int size, std::list<std::string>);
  void						Down(sPositions Pos, sPositions& DestinationsPos, int** Map, int size, std::list<std::string>);
  void						Left(sPositions Pos, sPositions& DestinationsPos, int** Map, int size, std::list<std::string>);
  void						Right(sPositions Pos, sPositions& DestinationsPos, int** Map, int size, std::list<std::string>);
  void						SortList(std::list<ManhattanMoves> &) const;

private:
	bool					LeftBranches(sPositions & NodePos, sPositions & DestinationPos,
											sPositions & TmpPos, std::list<std::string> & MovesList, std::list<ManhattanMoves> & Dep);
	bool					RightBranches(sPositions & NodePos, sPositions & DestinationPos, sPositions & TmpPos,
											std::list<std::string> & MovesList, std::list<ManhattanMoves> & Dep, unsigned int Size);
	bool					UpBranches(sPositions & NodePos, sPositions & DestinationPos,
											sPositions & TmpPos, std::list<std::string> & MovesList, std::list<ManhattanMoves> & Dep);
	bool					DownBranches(sPositions & NodePos, sPositions & DestinationPos, sPositions & TmpPos,
											std::list<std::string> & MovesList, std::list<ManhattanMoves> & Dep, unsigned int Size);
	void					moveZeroNode(sPositions& ZeroNodePos, const std::string& Direction, Puzzle& p);

private:
  int						PuzzleScale;
  sPositions				CurrentNodePos;
  sPositions				CurrentNodeDestinationPos;
  char						Direction[5];
  int						CurrentNodeName;
  std::list<std::string>	ListMovement;
  bool						EndTree;
  sPositions				ZeroPreviousPos;
};

#endif //_MANHATTAN_HPP_
