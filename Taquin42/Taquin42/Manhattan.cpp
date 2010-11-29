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
