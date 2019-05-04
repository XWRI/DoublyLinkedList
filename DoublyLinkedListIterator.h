//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"

template<typename T>
class DoublyLinkedList;

template<typename T>
class DoublyLinkedListIterator {
friend class DoublyLinkedList<T>;
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

protected:

	DoublyLinkedList<T>& doublyLinkedList;
	DoubleLinkedNode<T>* curNode;

  DoublyLinkedListIterator(DoublyLinkedList<T>& ItrDoublyLinkedList, DoubleLinkedNode<T>* ItrNode);

public:
  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig);
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  DoublyLinkedListIterator<T>& operator++(); //pre
  const DoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  DoublyLinkedListIterator<T>& operator--(); //pre
  const DoublyLinkedListIterator<T> operator--(int); //post

  //get a const reference to the value
  const T& operator*() const;

  //get a non const iterator
  T& operator*();

};

#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H


template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(DoublyLinkedList<T>& ItrDoublyLinkedList, DoubleLinkedNode<T>* ItrNode)
: doublyLinkedList(ItrDoublyLinkedList), curNode(ItrNode){}

template<typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(const DoublyLinkedListIterator &orig)
: doublyLinkedList(orig.doublyLinkedList), curNode(orig.curNode){}

template<typename T>
bool DoublyLinkedListIterator<T>::operator==(const DoublyLinkedListIterator<T> &rhs) const {
	if(&doublyLinkedList != &rhs.doublyLinkedList){
		return false;
	}
	else{
		return curNode == rhs.curNode;
	}
}

template<typename T>
bool DoublyLinkedListIterator<T>::operator!=(const DoublyLinkedListIterator<T> &rhs) const {
	return !(*this == rhs);
}

template<typename T>
DoublyLinkedListIterator<T>::operator bool() const {
	return curNode != nullptr;
}

template<typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator++() {

		curNode = curNode->next;
		return *this;

}

template<typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator++(int) {
	DoublyLinkedListIterator copy(*this);
	curNode = curNode->next;
	return copy;
}

template<typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator--() {

		curNode = curNode->previous;
		return *this;

}

template<typename T>
const DoublyLinkedListIterator<T> DoublyLinkedListIterator<T>::operator--(int) {
	DoublyLinkedListIterator copy(*this);
	curNode = curNode->previous;
	return copy;
}

template<typename T>
const T& DoublyLinkedListIterator<T>::operator*() const {
	return curNode->value;
}

template<typename T>
T& DoublyLinkedListIterator<T>::operator*() {
	return curNode->value;
}