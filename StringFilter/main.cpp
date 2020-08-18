#include <iostream>
#include "ChainedHashSet.h"
#include "StringFilter.h"

void print(ChainedHashSet chainedHashSet) {
	std::cout << "Size: \t" << chainedHashSet.getSize() << "\t Item count: \t" << chainedHashSet.getItemCount() 
		<< "\tLoadFactor: \t" << chainedHashSet.getLoadFactor() << std::endl;
}

int main()
{
	std::cout << "HashSet:\n" << std::endl;

	ChainedHashSet chainedHashSet{};
	print(chainedHashSet);
	for (int i = 0; i <= 15; i++)
		chainedHashSet.insert("abc");
	print(chainedHashSet);
	chainedHashSet.remove("abc");
	print(chainedHashSet);

	std::cout << "\nStringFilter:\n" << std::endl;

	StringFilter stringFilter{};
	stringFilter.add("abc");
	stringFilter.add("abc");
	stringFilter.add("def");
	stringFilter.add("ghi");
	stringFilter.print();
	stringFilter.remove("abc");
	stringFilter.print();
}