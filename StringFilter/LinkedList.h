#pragma once
#include <string>

class LinkedList 
{
public:
	LinkedList();
    LinkedList& operator+=(const LinkedList& n);
	void insert(std::string item);
	bool remove(std::string item);
	bool contains(std::string item);
	int size();
    void print();
	class Iterator;
	Iterator begin() const;
	Iterator end() const;

    class Node {
    public:
        std::string item;
        Node* front;
        Node* next;

        Node(std::string item) {
            this->item = item;
            this->front = NULL;
            this->next = NULL;
        }
    };

    class Iterator {
    public:
        Iterator(const Node* node) : currentNode(node) { }

        Iterator& operator=(Node* node)
        {
            this->currentNode = node;
            return *this;
        }

        Iterator& operator++()
        {
            if (currentNode)
                currentNode = currentNode->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++* this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator)
        {
            return currentNode != iterator.currentNode;
        }

        std::string operator*()
        {
            return currentNode->item;
        }

    private:
        const Node* currentNode;
    };

private: 
	int listSize;

	Node* firstNode;
	Node* lastNode;
};
