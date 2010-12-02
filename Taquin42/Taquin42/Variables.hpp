#ifndef _VARIABLES_HPP_
# define _VARIABLES_HPP_

struct						sPositions
{
	sPositions();
	sPositions(int x, int y);
	bool					operator!=(const sPositions&);

	unsigned int			Node_px;
	unsigned int			Node_py;
	bool					Block;
};

#endif // _VARIABLES_HPP_
