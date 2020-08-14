#include <vector>
#include <string>
#include "ChainedHashSet.h"
#include "HashSet.h"

ChainedHashSet::ChainedHashSet(int initSize) : HashSet(initSize)
{
	hashSet = std::vector<std::vector<std::string>>(size);
}

int ChainedHashSet::getSize()
{
	return size;
}

std::vector<std::string> ChainedHashSet::getAllElements()
{
	//TODO
	return std::vector<std::string>();
}

void ChainedHashSet::insert(std::string key)
{
	int index = hashFunction(key);
	hashSet.at(index).push_back(key);
	itemsCount++;
	updateLoadFactor();
}

bool ChainedHashSet::remove(std::string key)
{
	bool removed = false;
	int itemPos = 0;
	int index = hashFunction(key);
	for (std::string item : hashSet.at(index)) {
		if (item.compare(key) == 0) {
			hashSet.at(index).erase(hashSet.at(index).begin() + itemPos);
			removed = true;
			itemsCount--;
			updateLoadFactor();
			break;
		}
		itemPos++;
	}
	return removed;
}

bool ChainedHashSet::contains(std::string key)
{
	//TODO
	return false;
}

void ChainedHashSet::resize()
{
	//TODO
}