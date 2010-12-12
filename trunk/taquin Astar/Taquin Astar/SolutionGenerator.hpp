#ifndef _SOLUTIONGENERATOR_HPP_
#define _SOLUTIONGENERATOR_HPP_

class 					SolutionGenerator
{
public:
	SolutionGenerator();
	~SolutionGenerator();

private:
	SolutionGenerator&	operator=(SolutionGenerator const&);
	SolutionGenerator(SolutionGenerator const&);

private:
	void				FillTop();
	void				FillRight();
	void				FillBottom();
	void				FillLeft();

public:
	short unsigned int **	GenerateSolution(unsigned int Scale = 100);

private:
	int					X_min, X_max, X_cur;
	int					Y_min, Y_max, Y_cur;
	int					Num;
	short unsigned int		**Witness;
	unsigned int		PuzzleScale;
};

#endif /* _SOLUTIONGENERATOR_HPP_ */
 
