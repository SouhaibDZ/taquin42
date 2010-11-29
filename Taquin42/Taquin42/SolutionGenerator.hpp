#ifndef _SOLUTIONGENERATOR_HPP_
#define _SOLUTIONGENERATOR_HPP_
#include "Variables.hpp"

class 					SolutionGenerator
{
public:
	SolutionGenerator(unsigned int Scale = 100);
	~SolutionGenerator();

private:
	SolutionGenerator&	operator=(SolutionGenerator const&);
	SolutionGenerator(SolutionGenerator const&);

private:
	 void				DisplaySolution() const;

private:
	void				FillTop();
	void				FillRight();
	void				FillBottom();
	void				FillLeft();

public:
	bool				GenerateSolution();
	void				SearchNodeGoalPos(int CurrentNodeName, sPositions& pos) const;

private:
	int					X_min, X_max, X_cur;
	int					Y_min, Y_max, Y_cur;
	int					Num;
	int					**Witness;
	unsigned int		PuzzleScale;
};

#endif /* _SOLUTIONGENERATOR_HPP_ */
 
