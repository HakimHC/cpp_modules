#include <cstdlib>
#include <fstream>

#include "sed.hpp"

int main() {

	std::ofstream ftest1;

	ftest1.open("test1");
	if (!ftest1.is_open()) {
		std::cerr << "fatal: can't open test1 file" << std::endl;
		return 1;
	}
	// this test is a very basic test, 3 lines of simple, non-tricky text
	std::cout << "test 1: change letter 'o' to letter 'a'" << std::endl;
	ftest1 << "hello" << std::endl;
	ftest1 << "omar" << std::endl;
	ftest1 << "olek" << std::endl;
	std::string cmd = "./sed test1 o a";
	system(cmd.c_str());
	system("diff test1 test1.replace");

	std::cout << "test 2: empty string" << std::endl;
	cmd = "./sed test1 \"\" o";
	system(cmd.c_str());
	system("diff test1 test1.replace");

	std::cout << "no difference" << std::endl;

	ftest1.close();
	std::remove("test1");
	std::remove("test1.replace");

	std::cout << "test 3: wrong files (no crash)" << std::endl;
	system("./sed foo bar baz");

	std::cout << "test 4: wrong arguments (no crash)" << std::endl;
	system("./sed");
	system("./sed Makefile");
	system("./sed 1 2");
	system("./sed 1 2 3 4");

}
