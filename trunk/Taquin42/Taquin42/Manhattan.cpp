#include "Manhattan.hpp"

Manhattan::Manhattan()
{
  std::cout << " *** Manhattan implementation ***" << std::endl;
}

Manhattan::~Manhattan()
{
    std::cout << " *** Manhattan implementation Done ***" << std::endl;
}

int			Manhattan::GetMovesNb(void) const
{
  return (this->MovesNb);
}

std::string &		Manhattan::GetStatesTime(void) const
{
  return (this->StatesTime);
}

int			Manhattan::GetStatesSize(void) const
{
  return (this->StatesSize);
}

int			Manhattan::GetTotalCosts(void) const
{
  return (this->TotalCosts);
}

std::string &		Manhattan::GetOrderedSequence(void) const
{
    return (this->OrderedSequence);
}
