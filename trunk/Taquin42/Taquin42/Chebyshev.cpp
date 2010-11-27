#include "Chebyshev.hpp"

Chebyshev::Chebyshev()
{
  std::cout << " *** Chebyshev implementation ***" << std::endl;
}

Chebyshev::~Chebyshev()
{
    std::cout << " *** Chebyshev implementation Done ***" << std::endl;
}

int				Chebyshev::GetMovesNb(void) const
{
  return (this->MovesNb);
}

const std::string &		Chebyshev::GetStatesTime(void) const
{
  return (this->StatesTime);
}

int				Chebyshev::GetStatesSize(void) const
{
  return (this->StatesSize);
}

int				Chebyshev::GetTotalCosts(void) const
{
  return (this->TotalCosts);
}

const std::string &		Chebyshev::GetOrderedSequence(void) const
{
    return (this->OrderedSequence);
}
