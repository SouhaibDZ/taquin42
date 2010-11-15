#include <iostream>
#include <string>

class				FileLoader
{
public:
	FileLoader();
	~FileLoader();

private:
	FileLoader(const FileLoader &);
	FileLoader &	operator=(const FileLoader &);

};