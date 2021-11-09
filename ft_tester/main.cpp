#include "includes/main.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "please write as argument the type of container to test : vector, stack, map or all" << std::endl;
		return 0;
	}
	std::string arg = av[1];
	if (arg == "vector")
		vector_test();
	
	return 0;
}