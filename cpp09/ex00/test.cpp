#include <sstream>
#include <iostream>
#include <string>
#include <strstream>

int main() {
	std::string s = "1.3abc";

	std::stringstream ss;
	ss << s;

	float n;

	ss >> n;

	std::cout << n << std::endl;
}
