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

std::string ChainedHashSet::remove(std::string key)
{
	//TODO
	return std::string();
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