#include "LinkedList.h"
#include<iostream>

LinkedList::LinkedList() : listSize{ 0 } {
    firstNode = nullptr;
    lastNode = nullptr;
}

LinkedList& LinkedList::operator+=(const LinkedList& n)
{
    for (LinkedList::Iterator iterator = n.begin(); iterator != n.end(); iterator++) {
        this->insert(*iterator);
    }
    return *this;
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
            if (currentNode->next != nullptr) {
                if (currentNode->front != nullptr) {
                    currentNode->next->front = currentNode->front;
                    currentNode->front->next = currentNode->next;
                }
                else {
                    currentNode = currentNode->next;
                }
            }
            else {
                if (currentNode->front != nullptr) {
                    currentNode->front->next = nullptr;
                    lastNode = currentNode->front;
                }
                else {
                    firstNode = nullptr;
                    lastNode = nullptr;
                }
            }
            listSize--;
            return true;
        }
        currentNode = currentNode->next;
    } while (currentNode != nullptr);
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

LinkedList::Iterator LinkedList::begin() const
{
    return Iterator(firstNode);
}

LinkedList::Iterator LinkedList::end() const
{
    return Iterator(nullptr);
}
