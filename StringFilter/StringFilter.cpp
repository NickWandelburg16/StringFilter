#include "StringFilter.h"
#include <iostream>

void StringFilter::add(std::string key)
{
	if (!uniqueItems.contains(key) && !dublicateItems.contains(key))
		uniqueItems.insert(key);
	else {
		uniqueItems.remove(key);
		dublicateItems.insert(key);
	}
}

void StringFilter::remove(std::string key)
{
	if(!uniqueItems.remove(key));
		dublicateItems.remove(key);
}

void StringFilter::print()
{
	LinkedList uniqueItemLinkedList = uniqueItems.getAllElements();
	std::cout << "Unique Items: "; uniqueItemLinkedList.print();
	
	LinkedList dublicateItemLinkedList = dublicateItems.getAllElements();
	std::cout << "Dublicate Items: ";  dublicateItemLinkedList.print();

	std::cout << std::endl;
}
