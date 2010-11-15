#include "FileLoader.h"

FileLoader::FileLoader()
{
	std::cout << "Parsing ...." << std::endl;
}

FileLoader::~FileLoader()
{
	std::cout << "Parsing  done :)" << std::endl;
}


void				FileLoader::LoadFile(const std::string & Filename)
{
	std::string		buf;
	std::string		tmp;

	this->OpenFile(Filename.c_str());
	while (std::getline(this->Infile, tmp))
		buf += tmp + "\n";
	std::cout << buf << std::endl;
}

void				FileLoader::OpenFile(const std::string & Filename)
{
	this->Infile.open(Filename.c_str());
	if (! (this->Infile.is_open()))
		std::cerr << Filename << " : No such file or directory" << std::endl;
	else
		std::cout << Filename << " : File opened successfully" << std::endl;
}

void				FileLoader::CloseFile(void)
{
	this->Infile.close();
}