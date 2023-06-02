#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

typedef std::string str;

str replace(str original, str src, str dest)
{
	size_t i = original.find(src);
	if (i == std::string::npos)
		return original;
	return original.substr(0, i) + dest + original.substr(i + dest.length());
}

void sed(const char* path, str src, str dest)
{
	std::ifstream infile;
	/* std::ofstream outfile; */

	infile.open(path);
	if (!infile.is_open()) {
		std::cout << "fatal: can't open infile" << std::endl;
		exit(1);
	}

	/* outfile.open(path); */
	/* if (!outfile.is_open()) { */
	/* 	std::cout << "fatal: can't open outfile" << std::endl; */
	/* 	exit(1); */
	/* } */

	str buffer;
	while (std::getline(infile, buffer)) {
		std::cout << replace(buffer, src, dest) << std::endl;
	}
}

int main(int _, char **argv) {
	sed(argv[1], argv[2], argv[3]);
}
