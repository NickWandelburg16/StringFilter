#pragma once
#include <vector>
#include "HashSet.h"

class ChainedHashSet : public HashSet
{
public:
	ChainedHashSet(int size = 20);
	int getSize() override;
	std::vector<std::string> getAllElements() override;
	void insert(std::string) override;
	bool remove(std::string) override;
	bool contains(std::string) override;

private:
	std::vector<std::vector<std::string>> hashSet;

	void resize() override;
};
