#include "SolutionGenerator.hpp"
#include <iostream>

SolutionGenerator::SolutionGenerator()
{
	std::cout << "\tSolution Generating ....." << std::endl;
	this->X_min = 0;
	this->X_max = 0;
	this->X_cur = 0;
	this->Y_min = 0;
	this->Y_max = 0;
	this->Y_cur = 0;
	this->Num = 1;
}

SolutionGenerator::~SolutionGenerator() {}

void				SolutionGenerator::FillTop()
{
	if (this->Num == this->Limit)
		this->Num = 0;
	while (this->X_cur < this->X_max)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->X_cur++;
		this->Num++;
	}
	this->X_cur--;
	this->X_max--;
	this->Y_cur++;
}

void				SolutionGenerator::FillRight()
{
	if (this->Num == this->Limit)
		this->Num = 0;
	while (this->Y_cur < this->Y_max)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->Y_cur++;
		this->Num++;
	}
	this->Y_cur--;
	this->Y_max--;
	this->X_cur--;
}

void				SolutionGenerator::FillBottom()
{
	if (this->Num == this->Limit)
		this->Num = 0;
	while (this->X_cur > this->X_min - 1)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->X_cur--;
		this->Num++;
	}
	this->X_cur++;
	this->X_min++;
	this->Y_cur--;
}

void				SolutionGenerator::FillLeft()
{
	if (this->Num == this->Limit)
		this->Num = 0;
	while (this->Y_cur > this->Y_min)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->Y_cur--;
		this->Num++;
	}
	this->Y_cur++;
	this->Y_min++;
	this->X_cur++;
}

short unsigned int** 				SolutionGenerator::GenerateSolution(unsigned int Scale)
{
	if (Scale > 100)
	{
		std::cerr << "The taquin is too big" << std::endl;
		return (NULL);
	}
	this->X_max = Scale;
	this->Y_max = Scale;
	this->Limit = Scale * Scale;
	this->Witness = new short unsigned int*[Scale];
	for (unsigned int i = 0; i < Scale; i++)
		this->Witness[i] = new short unsigned int[Scale];
	while (this->X_min <= this->X_max && this->Y_min <= this->Y_max)
	{
		this->FillTop();
		this->FillRight();
		this->FillBottom();
		this->FillLeft();
	}
	return (this->Witness);
}
