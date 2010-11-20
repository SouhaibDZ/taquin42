#ifndef _SOLUTIONGENERATOR_H_
#define _SOLUTIONGENERATOR_H_

class SolutionGenerator
{
public:
	SolutionGenerator(const int Scale = 100);
	~SolutionGenerator();

private:
	SolutionGenerator&	operator=(SolutionGenerator const&);
	SolutionGenerator(SolutionGenerator const&);

private:
	 void				DisplaySolution()const;

public:
	void				FillTop();
	void				FillRight();
	void				FillBottom();
	void				FillLeft();
	bool				GenerateSolution();

private:
	int					X_min, X_max, X_cur;
	int					Y_min, Y_max, Y_cur;
	int					Num;
	int					**Witness;
	int					PuzzleScale;
};

#endif /* _SOLUTIONGENERATOR_H_ */
