#include "Dijkstra.hpp"

Dijkstra::Dijkstra()
{
  std::cout << " *** Dijkstra implementation ***" << std::endl;
}

Dijkstra::~Dijkstra()
{
    std::cout << " *** Dijkstra implementation Done ***" << std::endl;
}

int			Dijkstra::GetMovesNb(void) const
{
  return (this->MovesNb);
}

std::string &		Dijkstra::GetStatesTime(void) const
{
  return (this->StatesTime);
}

int			Dijkstra::GetStatesSize(void) const
{
  return (this->StatesSize);
}

int			Dijkstra::GetTotalCosts(void) const
{
  return (this->TotalCosts);
}

std::string &		Dijkstra::GetOrderedSequence(void) const
{
    return (this->OrderedSequence);
}
