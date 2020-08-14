#include <iostream>
#include "ChainedHashSet.h"

int main()
{
	ChainedHashSet chainedHashSet{};
	std::cout << chainedHashSet.getSize() << " " << chainedHashSet.getLoadFactor() << std::endl;
	chainedHashSet.insert("abc");
	std::cout << chainedHashSet.getSize() << " " << chainedHashSet.getLoadFactor() << std::endl;
}