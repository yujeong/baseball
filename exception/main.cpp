#include <stdexcept>
#include <iostream>

int go(int a, int b)
{
	if (a < 0 || b < 0) {
		throw std::invalid_argument("a or b is negative");
	}
	return a + b;
};

int main()
{
	try
	{
		int result = go(10, 20);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid argument exception: " << e.what() << std::endl;
	}
}