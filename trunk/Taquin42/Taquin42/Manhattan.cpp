#include "Manhattan.hpp"

Manhattan::Manhattan()
{
  std::cout << " *** Manhattan implementation ***" << std::endl;
  this->CurrentNodeName = 1;
  this->Direction[0] = '\0';
}

Manhattan::~Manhattan()
{
    std::cout << " *** Manhattan implementation Done ***" << std::endl;
}

void						Manhattan::Run(Puzzle& p)
{
	SearchNextPosZero(p);
}

void						Manhattan::NextNode()
{
	this->CurrentNodeName++;
}

void						Manhattan::SearchNextPosZero(Puzzle& p)
{
	sPositions CurrentNodePos;
	sPositions ZeroNodePos;

	p.ProcessCurrentNodePos(this->CurrentNodeName, CurrentNodePos);

	std::cout << "NodeName: " << this->CurrentNodeName << "(" << CurrentNodePos.Node_px << "," << CurrentNodePos.Node_py << ")" << std::endl;
}

void						Manhattan::showDirection()
{

}

void						Manhattan::MoveZeroToPosDestination()
{

}