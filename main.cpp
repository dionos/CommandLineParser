#include <iostream>

int version();
void test();

int main(int argc, char *argv[]) {

	std::cout << "Hello world" << std::endl;
	std::cout << "Version = " << version()<< std::endl;
	test();
	return 0;
}
