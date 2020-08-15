#include <vector>
#include <string>
#include "ChainedHashSet.h"
#include "HashSet.h"

ChainedHashSet::ChainedHashSet(int initSize) : HashSet(initSize)
{
	hashSet = std::vector<LinkedList>(size);
}

int ChainedHashSet::getSize()
{
	return size;
}

LinkedList ChainedHashSet::getAllElements()
{
	//TODO
	return LinkedList{};
}

void ChainedHashSet::insert(std::string key)
{
	int index = hashFunction(key);
	hashSet.at(index).insert(key);
	itemsCount++;
	updateLoadFactor();
	hashSet.at(index).print();
}

bool ChainedHashSet::remove(std::string key)
{
	int index = hashFunction(key);
	itemsCount--;
	updateLoadFactor();
	return hashSet.at(index).remove(key);
}

bool ChainedHashSet::contains(std::string key)
{
	int index = hashFunction(key);
	return hashSet.at(index).contains(key);
}

void ChainedHashSet::resize()
{
	size *= 2;
	std::vector<LinkedList> tempHashSet = std::vector<LinkedList>(size);
	for (int i = 0; i < hashSet.size(); i++) {
		LinkedList linkedList = hashSet.at(i);
		if (linkedList.size() == 0) continue;
		hashSet.at(i).print();
		for (LinkedList::Iterator iterator = linkedList.begin(); iterator != linkedList.end(); iterator++) {
			std::string item = *iterator;
			int index = hashFunction(item);
			tempHashSet.at(index).insert(item);
		}
		hashSet = tempHashSet;
	}
}