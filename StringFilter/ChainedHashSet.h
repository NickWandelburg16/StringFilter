#pragma once
#include <vector>
#include "HashSet.h"
#include "LinkedList.h"

class ChainedHashSet : public HashSet
{
public:
	ChainedHashSet(int size = 20);
	int getSize() override;
	LinkedList getAllElements() override;
	void insert(std::string) override;
	bool remove(std::string) override;
	bool contains(std::string) override;

private:
	std::vector<LinkedList> hashSet;
	void resize() override;
};
