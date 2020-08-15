#pragma once
#include <vector>
#include <string>
#include <cmath>
#include "LinkedList.h"

class HashSet
{
public:
	HashSet(int size) : size{ size }, itemsCount{ 0 }, loadFactor{ 0.0f }, K{ 0.75 }{}

	int hashFunction(std::string key) {
		int hash = 0; 
		for (size_t i = 0; i < key.length(); i++)
		{
			hash = (hash + static_cast<int>(key.at(i) * std::pow(R, i)));
			hash %= size;
		}
		return hash;
	}

	int getItemCount() {
		return itemsCount;
	}

	float getLoadFactor()
	{
		return loadFactor;
	}

	virtual int getSize() = 0; 
	virtual LinkedList getAllElements() = 0;
	virtual void insert(std::string) = 0; 
	virtual bool remove(std::string) = 0;
	virtual bool contains(std::string) = 0;

protected:
	int size;
	int itemsCount;
	float loadFactor;
	const float K;

	void updateLoadFactor() {
		loadFactor = static_cast<float>(itemsCount) / size;
		if (loadFactor >= K) 
			resize();
	}

	virtual void resize() = 0;

private:
	const int R = 31;
};
