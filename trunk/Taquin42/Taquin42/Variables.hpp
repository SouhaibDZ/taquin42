#ifndef _VARIABLES_HPP_
# define _VARIABLES_HPP_

struct			sPositions
{
	sPositions();
	sPositions(int x, int y);

	int			Node_px;
	int			Node_py;
};

struct			sGoalPositions
{
	int			GoalNode_px;
	int			GoalNode_py;
};

#endif // _VARIABLES_HPP_
