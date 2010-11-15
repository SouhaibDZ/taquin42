#include "IAPlayer.h"

IAPlayer::IAPlayer()
{
	this->MovesNb = 0;
	this->StatesTime = "";
	this->StatesSize = 0;
	this->TotalCosts = 0;
	this->OrderedSequence = "";
}

IAPlayer::~IAPlayer()
{
}

int						IAPlayer::GetMovesNb(void) const
{
	return (this->MovesNb);
}

const std::string &		IAPlayer::GetStatesTime(void) const
{
	return (this->StatesTime);
}

int						IAPlayer::GetStatesSize(void) const
{
	return (this->StatesSize);
}

int						IAPlayer::GetTotalCosts(void) const
{
	return (this->TotalCosts);
}

const std::string &		IAPlayer::GetOrderedSequence(void) const
{
	return (this->OrderedSequence);
}