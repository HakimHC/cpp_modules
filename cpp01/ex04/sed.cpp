#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

#include "sed.hpp"

str replace(str original, str src, str dest)
{
	if (src.empty())
		return original;
	size_t i = 0;
	while ((i = original.find(src, i)) != std::string::npos) {
		original = original.substr(0, i) + dest + original.substr(i + src.length());
		i += dest.length();
	}
	return original;
}

void sed(str path, str src, str dest)
{
	std::ifstream infile;
	std::ofstream outfile;

	infile.open(path.c_str());
	if (!infile.is_open()) {
		std::cout << "fatal: can't open infile" << std::endl;
		return;
	}

	outfile.open(path.append(".replace").c_str());
	if (!outfile.is_open()) {
		std::cout << "fatal: can't open outfile" << std::endl;
		return;
	}

	str buffer;
	while (std::getline(infile, buffer)) {
		outfile << replace(buffer, src, dest) << std::endl;
	}
	infile.close();
	outfile.close();
}
