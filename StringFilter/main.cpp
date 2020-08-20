#include <iostream>
#include "ChainedHashSet.h"
#include "StringFilter.h"
#include "LinkedList.h"

void print(ChainedHashSet chainedHashSet) {
	std::cout << "Size: \t" << chainedHashSet.getSize() << "\t Item count: \t" << chainedHashSet.getItemCount() 
		<< "\tLoadFactor: \t" << chainedHashSet.getLoadFactor() << std::endl;
}

int main()
{
	/* Tests:

	std::cout << "\nLinkedList:\n" << std::endl;

	LinkedList linkedList{};
	linkedList.insert("abc");
	linkedList.insert("def");
	linkedList.insert("ghi");
	linkedList.remove("jkl");
	linkedList.remove("def");
	linkedList.remove("ghi");
	linkedList.remove("abc");
	linkedList.insert("abc");

	std::cout << "HashSet:\n" << std::endl;

	ChainedHashSet chainedHashSet{};
	print(chainedHashSet);
	for (int i = 0; i <= 15; i++)
		chainedHashSet.insert("abc");
	print(chainedHashSet);
	chainedHashSet.remove("abc");
	print(chainedHashSet);

	*/

	std::cout << "\nStringFilter:\n" << std::endl;

	StringFilter stringFilter{};
	std::cout << "Add \'abc\':\n";
	stringFilter.add("abc");
	stringFilter.print();
	std::cout << "Add \'abc\' again (dublicate):\n";
	stringFilter.add("abc");
	stringFilter.print();
	std::cout << "Add \'def\' and \'ghi\':\n";
	stringFilter.add("def");
	stringFilter.add("ghi");
	stringFilter.print();
	std::cout << "Remove \'abc\':\n";
	stringFilter.remove("abc");
	stringFilter.print();
}