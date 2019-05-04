//
// Created by mfbut on 2/13/2019.
//

#ifndef LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"

template<typename T>
class DoublyLinkedList;

template<typename T>
class ReverseDoublyLinkedListIterator {
 public:
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

  DoublyLinkedList<T>& doublyLinkedList;
  DoubleLinkedNode<T>* curNode;

  ReverseDoublyLinkedListIterator(DoublyLinkedList<T>& ItrdoublyLinkedList, DoubleLinkedNode<T>* ItrNode);

  //copy constructor
  ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const;

  //are the two iterators different?
  bool operator!=(ReverseDoublyLinkedListIterator<T>& rhs) const;

  //is the iterator safe to dereference?
  operator bool() const;

  //go to the next element
  ReverseDoublyLinkedListIterator<T>& operator++(); //pre
  const ReverseDoublyLinkedListIterator<T> operator++(int);//post

  //go to the previous element
  ReverseDoublyLinkedListIterator<T>& operator--(); //pre
  const ReverseDoublyLinkedListIterator<T> operator--(int);//post

  //get a const reference to the value
  const T& operator*() const;

  //get a non-const reference to the value
  T& operator*();

};

#endif //LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H

template<typename T>
ReverseDoublyLinkedListIterator<T>::ReverseDoublyLinkedListIterator(DoublyLinkedList<T> &ItrdoublyLinkedList, DoubleLinkedNode<T>* ItrNode)
: doublyLinkedList(ItrdoublyLinkedList), curNode(ItrNode){}

template<typename T>
ReverseDoublyLinkedListIterator<T>::ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator &orig)
	: doublyLinkedList(orig.doublyLinkedList),  curNode(orig.curNode){}

template<typename T>
bool ReverseDoublyLinkedListIterator<T>::operator==(const ReverseDoublyLinkedListIterator<T> &rhs) const {
	if(&doublyLinkedList != &rhs.doublyLinkedList){
		return false;
	}
	else{
		return curNode == rhs.curNode;
	}
}

template<typename T>
bool ReverseDoublyLinkedListIterator<T>::operator!=(ReverseDoublyLinkedListIterator<T>& rhs) const {
	return !(*this == rhs);
}

template<typename T>
ReverseDoublyLinkedListIterator<T>::operator bool() const {
	return curNode != nullptr;
}

template<typename T>
ReverseDoublyLinkedListIterator<T>& ReverseDoublyLinkedListIterator<T>::operator++() {

		curNode = curNode->previous;
		return *this;

}

template<typename T>
const ReverseDoublyLinkedListIterator<T> ReverseDoublyLinkedListIterator<T>::operator++(int) {
	ReverseDoublyLinkedListIterator copy(*this);
	curNode = curNode->previous;
	return copy;
}

template<typename T>
ReverseDoublyLinkedListIterator<T>& ReverseDoublyLinkedListIterator<T>::operator--() {

		curNode = curNode->next;
		return *this;

}

template<typename T>
const ReverseDoublyLinkedListIterator<T> ReverseDoublyLinkedListIterator<T>::operator--(int) {
	ReverseDoublyLinkedListIterator copy(*this);
	curNode = curNode->next;
	return copy;
}

template<typename T>
const T& ReverseDoublyLinkedListIterator<T>::operator*() const {
	return curNode->value;
}

template<typename T>
T& ReverseDoublyLinkedListIterator<T>::operator*() {
	return curNode->value;
}
