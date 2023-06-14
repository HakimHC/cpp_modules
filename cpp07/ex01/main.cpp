#include <cstddef>
#include <iostream>

#include "iter.hpp"

class Test {
	private:
		int _age;
	public:
		Test();
		static void sayHello(Test&);
};

Test::Test()
	:_age(1)
{

	std::cout << "constructor called" << std::endl;
}

void Test::sayHello(Test& a) {
	std::cout << "Hello!! I am " << a._age << " years old" << std::endl;
}

void	incr(int& n) {
	++n;
}

int main() {
	int arr[4] = {1, 2, 3, 4};
	int i;

	std::cout << "=======================================================================" << std::endl;
	std::cout << "Lets start with a simple test, array of 4 integers => foreach increment" << std::endl;
	std::cout << "=======================================================================" << std::endl;
	for (i = 0; i < 4; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	iter(arr, 4, &incr);

	for (i = 0; i < 4; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	std::cout << "=======================================================================" << std::endl;
	std::cout << "Now lets do something that is also quite generic, pass a null pointer" << std::endl;
	std::cout << "=======================================================================" << std::endl;

	iter((int*)NULL, 100, &incr);

	std::cout << "(no crash)" << std::endl;

	std::cout << "=======================================================================" << std::endl;
	std::cout << "Now, just for fun, lets create an array of instances of the Test class" << std::endl;
	std::cout << "=======================================================================" << std::endl;

	Test *t = new Test[5];
	iter(t, 5, &(t[i].sayHello));

}
