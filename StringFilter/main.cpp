#include <iostream>
#include "ChainedHashSet.h"

void print(ChainedHashSet chainedHashSet) {
	std::cout << "Size: \t" << chainedHashSet.getSize() << "\t Item count: \t" << chainedHashSet.getItemCount() 
		<< "\tLoadFactor: \t" << chainedHashSet.getLoadFactor() << std::endl;
}

int main()
{
	ChainedHashSet chainedHashSet{};
	print(chainedHashSet);
	for (int i = 0; i <= 15; i++)
		chainedHashSet.insert("abc");
	print(chainedHashSet);
	chainedHashSet.remove("abc");
	print(chainedHashSet);
}