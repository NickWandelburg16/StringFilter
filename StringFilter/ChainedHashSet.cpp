#include "ChainedHashSet.h"
#include "HashSet.h"
#include <vector>
#include <string>

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
	LinkedList allElements{};
	for (int i = 0; i < hashSet.size(); i++) {
		LinkedList linkedList = hashSet.at(i);
		if (linkedList.size() == 0) continue;
		allElements += linkedList;
	}
	return allElements;
}

void ChainedHashSet::insert(std::string key)
{
	int index = hashFunction(key);
	hashSet.at(index).insert(key);
	itemsCount++;
	updateLoadFactor();
}

bool ChainedHashSet::remove(std::string key)
{
	int index = hashFunction(key);
	if (hashSet.at(index).remove(key)) {
		itemsCount--;
		updateLoadFactor();
		return true;
	}
	return false;
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
		for (LinkedList::Iterator iterator = linkedList.begin(); iterator != linkedList.end(); iterator++) {
			std::string item = *iterator;
			int index = hashFunction(item);
			tempHashSet.at(index).insert(item);
		}
	}
	hashSet = tempHashSet;
	updateLoadFactor();
}