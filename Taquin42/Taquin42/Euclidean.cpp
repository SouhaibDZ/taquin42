#include "Euclidean.hpp"

Euclidean::Euclidean()
{
  std::cout << " *** Euclidean implementation ***" << std::endl;
}

Euclidean::~Euclidean()
{
    std::cout << " *** Euclidean implementation Done ***" << std::endl;
}

int				Euclidean::GetMovesNb(void) const
{
  return (this->MovesNb);
}

const std::string &		Euclidean::GetStatesTime(void) const
{
  return (this->StatesTime);
}

int				Euclidean::GetStatesSize(void) const
{
  return (this->StatesSize);
}

int				Euclidean::GetTotalCosts(void) const
{
  return (this->TotalCosts);
}

const std::string &		Euclidean::GetOrderedSequence(void) const
{
    return (this->OrderedSequence);
}
