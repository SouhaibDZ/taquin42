#ifndef _SOLUTIONGENERATOR_H_
#define _SOLUTIONGENERATOR_H_

class SolutionGenerator
{
public:
	SolutionGenerator();
	~SolutionGenerator();

private:
	SolutionGenerator&	operator=(SolutionGenerator const&);
	SolutionGenerator(SolutionGenerator const&);

public:
	void				GenerateSolution(const int PuzzleScale);
	void				FillTop();
	void				FillRight();
	void				FillBottom();
	void				FillLeft();

private:
	int					X_min, X_max, X_cur;
	int					Y_min, Y_max, Y_cur;
	int					Num;
	int					**Witness;

};

#endif /* _SOLUTIONGENERATOR_H_ */
