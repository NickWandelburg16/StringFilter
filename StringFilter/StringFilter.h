#pragma once
#include "ChainedHashSet.h"
#include <string>

class StringFilter
{
private:
	ChainedHashSet uniqueItems, dublicateItems;
public:
	void add(std::string);
	void remove(std::string);
	void print();
};

