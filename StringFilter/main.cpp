#include <iostream>
#include "ChainedHashSet.h"

int main()
{
	ChainedHashSet chainedHashSet{};
	std::cout << chainedHashSet.getSize() << " " << chainedHashSet.getItemCount() << " " << chainedHashSet.getLoadFactor() << std::endl;
	for (int i = 0; i <= 15; i++)
		chainedHashSet.insert("abc");
	std::cout << chainedHashSet.getSize() << " " << chainedHashSet.getItemCount() << " " << chainedHashSet.getLoadFactor() << std::endl;
	chainedHashSet.remove("abc");
	std::cout << chainedHashSet.getSize() << " " << chainedHashSet.getItemCount() << " " << chainedHashSet.getLoadFactor() << std::endl;
}