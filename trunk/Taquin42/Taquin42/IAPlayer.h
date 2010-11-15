#ifndef __IAPLAYER_H__
#define __IAPLAYER_H__

#include <iostream>
#include <string>

class						IAPlayer
{
public:
	IAPlayer();
	~IAPlayer();

private:
	IAPlayer(const IAPlayer &);
	IAPlayer &				operator=(const IAPlayer &);

public:
	int						GetMovesNb(void) const;
	const std::string &		GetStatesTime(void) const;
	int						GetStatesSize(void) const;
	int						GetTotalCosts(void) const;
	const std::string &		GetOrderedSequence(void) const;

private:
	int						MovesNb;
	std::string				StatesTime;
	int						StatesSize;
	int						TotalCosts;
	std::string				OrderedSequence;
};

#endif //__IAPLAYER_H__