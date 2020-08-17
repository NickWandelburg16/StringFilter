#include "LinkedList.h"
#include<iostream>

LinkedList::LinkedList() : listSize{ 0 } {
    firstNode = nullptr;
    lastNode = nullptr;
}

void LinkedList::insert(std::string item)
{
    Node* temp = new Node{ item };
    if (firstNode == nullptr) {
        firstNode = temp;
        lastNode = temp;
    }
    else {
        temp->front = lastNode;
        lastNode->next = temp;
        lastNode = lastNode->next;
    }
    listSize++;
}

bool LinkedList::remove(std::string item)
{
    if (size() == 0) return false;
    Node* currentNode = firstNode;
    do {
        if (currentNode->item.compare(item) == 0) {
            if (currentNode == firstNode) {
                firstNode = nullptr;
            }
            else if (currentNode->next != nullptr) {
                currentNode->front->next = currentNode->next;
                currentNode->next->front = currentNode->front;
                currentNode = currentNode->next;
            }
            else {
                currentNode->front->next = nullptr;
            }
            delete currentNode;
            return true;
        }
    } while (currentNode->next != nullptr);
    return false;
}

bool LinkedList::contains(std::string item)
{
    if (size() == 0) return false;
    Node* currentNode = firstNode;
    do {
        if (currentNode->item.compare(item) == 0)
            return true;
        currentNode = currentNode->next;
    } while (currentNode != nullptr);
    return false;
}

int LinkedList::size() {
    return this->listSize;
}

void LinkedList::print()
{
    for (LinkedList::Iterator iterator = begin(); iterator != end(); iterator++) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;
}

LinkedList::Iterator LinkedList::begin()
{
    return Iterator(firstNode);
}

LinkedList::Iterator LinkedList::end()
{
    return Iterator(nullptr);
}
