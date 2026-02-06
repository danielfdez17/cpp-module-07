#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
	{
		Array<int> numbers(MAX_VAL);
		std::cout << YELLOW "numbers size: " << numbers.size() << std::endl;
		int* mirror = new int[MAX_VAL];
		// std::cout << mirror[0] << "\n";
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	{
		std::cout << YELLOW "My tests" RESET << std::endl;
		Array<int> myArray(5);
		Array<int> myCopy = myArray;
		Array<int> mirror(5);
		std::cout << YELLOW << "test\n";
		Array<int> mirrorCopy = mirror;
		int *a = new int();
		std::cout << a << "\n" << *a << "\n";
		delete a;
		for (int i = 0; i < 5; i++)
			std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
		for (int i = 0; i < 5; i++)
			mirrorCopy[i]++;
		for (int i = 0; i < 5; i++)
			std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << "mirrorCopy[" << i << "] = " << mirrorCopy[i] << std::endl;
		Array<int> negative(-1);
	}
	return 0;
}