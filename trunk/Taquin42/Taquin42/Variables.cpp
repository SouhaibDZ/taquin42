#include "Variables.hpp"

sPositions::sPositions() : Node_px(0), Node_py(0)
{
}

sPositions::sPositions(int x, int y) : Node_px(x), Node_py(y)
{
}

bool								sPositions::operator !=(const sPositions& pos)
{
	return ((this->Node_px != pos.Node_px) || (this->Node_py != pos.Node_py));
}
