//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
    friend class DoublyLinkedListIterator<T>;

 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator = DoublyLinkedListIterator<T>/*put the type of your iterator here*/;
  using const_iterator = ConstDoublyLinkedListIterator<T>/*put the type of your const iterator here*/;
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>/*put the type of your reverse iterator here*/;
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>/*put the type of your const reverse iterator here*/;

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);

  //create an empty DoublyLinkedList
  DoublyLinkedList();

  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();
  void clearImpl(DoubleLinkedNode<T>* node);

  //get a reference to the front element in the list
  const T& front() const;
  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);


private:
  Node_Ptr head;
  Node_Ptr tail;
  int len;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T> &values)
  : DoublyLinkedList<T>() {
    len = 0;
    for (auto itr = values.crbegin(); itr != values.crend(); ++itr) {
    push_front(*itr);
    }
    head->previous = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(): head(nullptr), tail(nullptr), len(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  clear();
}
template<typename T>
void DoublyLinkedList<T>::clear() {
  clearImpl(head);
  head = nullptr;
  tail = nullptr;
  len = 0;
}

template<typename T>
void DoublyLinkedList<T>::clearImpl(DoubleLinkedNode<T> *node) {
  if(node == nullptr){
    return;
  }else{
    clearImpl(node->next);
    delete node;
  }
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
  T& ref = (T&)*head;
  return ref;
}

template<typename T>
T& DoublyLinkedList<T>::front() {
  T& ref = (T&)*head;
  return ref;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
  T& ref = (T&)*tail;
  return ref;
}

template<typename T>
T& DoublyLinkedList<T>::back() {
  T& ref = (T&)*tail;
  return ref;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
  Node_Ptr curHead = head;
  head = new DoubleLinkedNode<T>(value, nullptr, curHead);

  len++;

  if(curHead == nullptr){
    tail = head;
  }else{
    curHead->previous = head;
  }
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T &value) {
  Node_Ptr  curTail = tail;
  tail = new DoubleLinkedNode<T>(value, curTail, nullptr);

  len++;

  if(curTail == nullptr){
    head = tail;
  }else{
    curTail->next = tail;
  }
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
  return (head == nullptr && tail == nullptr && len == 0);
}

template<typename T>
int DoublyLinkedList<T>::size() const {
  return len;
}


template<typename T>
ConstDoublyLinkedListIterator<T> DoublyLinkedList<T>::begin() const {
	return ConstDoublyLinkedListIterator<T>(*this, this->head);
}

template<typename T>
ConstDoublyLinkedListIterator<T> DoublyLinkedList<T>::end() const {
	return ConstDoublyLinkedListIterator<T>(*this, nullptr);
}

template<typename T>
DoublyLinkedListIterator<T> DoublyLinkedList<T>::begin() {
  return DoublyLinkedListIterator<T>(*this, this->head);
}

template<typename T>
DoublyLinkedListIterator<T> DoublyLinkedList<T>::end() {
  return DoublyLinkedListIterator<T>(*this, nullptr);
}

template<typename T>
ConstReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::crbegin() const {
  return ConstReverseDoublyLinkedListIterator<T>(*this, this->tail);
}

template<typename T>
ConstReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::crend() const {
  return ConstReverseDoublyLinkedListIterator<T>(*this, nullptr);
}

template<typename T>
ReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rbegin() {
  return ReverseDoublyLinkedListIterator<T>(*this, this->tail);
}

template<typename T>
ReverseDoublyLinkedListIterator<T> DoublyLinkedList<T>::rend() {
  return ReverseDoublyLinkedListIterator<T>(*this, nullptr);
}

template<typename T>
void DoublyLinkedList<T>::insert(DoublyLinkedList::iterator &position, const T &value) {
  if(position.curNode == nullptr){
    if(this->empty()){
      head = tail = new DoubleLinkedNode<T>(value, nullptr, nullptr);
      len = 1;
    }
    else{
      position.curNode = tail;
      tail = new DoubleLinkedNode<T>(value, position.curNode, nullptr);
      position.curNode->next = tail;
      len++;
    }
  }
  else if(position.curNode == head){
    push_front(value);
  }
  else{
    Node_Ptr temp = nullptr;
    temp = position.curNode->previous;
    position.curNode->previous = new DoubleLinkedNode<T>(value, temp, position.curNode);
    temp->next = position.curNode->previous;
    len++;
  }
}

template<typename T>
void DoublyLinkedList<T>::erase(DoublyLinkedList::iterator &position) {
  if(position.curNode == nullptr){
      return;
  }
  else if (head != tail) {
    if (position.curNode == head) {
      head = position.curNode->next;
      head->previous = position.curNode->previous;
      head->next = position.curNode->next->next;
      delete position.curNode;
      position.curNode = nullptr;

      if (head == nullptr) {
        tail = nullptr;
        len = 0;
      } else {
        len--;
      }
    } else if (position.curNode == tail) {
      tail = position.curNode->previous;
      tail->next = position.curNode->next;
      tail->previous = position.curNode->previous->previous;
      delete position.curNode;
      position.curNode = nullptr;
      len--;
    } else {
      position.curNode->previous->next = position.curNode->next;
      position.curNode->next->previous = position.curNode->previous;
      delete position.curNode;
      position.curNode = nullptr;
      len--;
    }
  }
  else if(head == tail){
    head = tail = nullptr;
    len = 0;
  }
}


//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList){

  for (const auto& val :doublyLinkedList) {
    out << val << ' ';
  }
  return out;
}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList){

  T input;
  in >> input;
  doublyLinkedList.push_back(input);

  return doublyLinkedList;
}



#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
