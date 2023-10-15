#ifndef DLLIST_HPP
#define DLLIST_HPP

#include <iostream>
#include "NullNodeException.hpp"

// Class template for a doubly linked list.
template <class T>
class DLList
{
private:
   // Structure containing the data and
   // pointers to the next and previous nodes.
   struct Node
   {
      T data;
      Node * prev;
      Node * next;

      Node(const T & theData, Node * prevNode = nullptr,
	   Node * nextNode = nullptr)
	 : data{theData}, prev{prevNode}, next{nextNode}
      {}
   };

   Node * head; // pointer to head of list
   Node * tail; // pointer to tail of list
   Node * cur;  // pointer to current position in list

public:
   DLList() : head{}, tail{}, cur{}
   {}

   ~DLList();

   // Tests if current position is null.
   bool isCurNull() const
   {
      return cur == nullptr;
   }

   // Tests if there is a previous element.
   bool hasPrev() const
   {
      return !isCurNull() && cur->prev != nullptr;
   }

   // Tests if there is a next element.
   bool hasNext() const
   {
      return !isCurNull() && cur->next != nullptr;
   }

   // Moves to the head of the list.
   // Returns a reference to the invoking object.
   DLList & toHead()
   {
      cur = head;
      return *this;
   }

   // Moves to the tail of the list.
   // Returns a reference to the invoking object.
   DLList & toTail()
   {
      cur = tail;
      return *this;
   }

   // Moves to the previous element.
   // Returns a reference to the invoking object.
   DLList & toPrev();

   // Moves to the next element.
   // Returns a reference to the invoking object.
   DLList & toNext();

   // Gets the data at the current position.
   // Throws a NullNodeException if the current position is null.
   T getData() const;

   // Sets the data at the current position.
   // Throws a NullNodeException if the current position is null.
   // Returns a reference to the invoking object.
   DLList & setData(const T & value);

   // Inserts a new element before the current position
   // and moves to this position.
   // If the current position is null and the list is not empty,
   // then the new element will not be inserted.
   // Returns a reference to the invoking object.
   DLList & insertBefore(const T & data);

   // Inserts a new element after the current position
   // and moves to this position.
   // If the current position is null and the list is not empty,
   // then the new element will not be inserted.
   // Returns a reference to the invoking object.
   DLList & insertAfter(const T & data);

   // Removes the element at the current position
   // and moves to the next position.
   // Returns a reference to the invoking object.
   DLList & removeToNext();

   // Removes the element at the current position
   // and moves to the previous position.
   // Returns a reference to the invoking object.
   DLList & removeToPrev();

   // Removes all elements in this list.
   // Returns a reference to the invoking object.
   DLList & clear();

   // Tests if the list is empty.
   bool isEmpty() const
   {
      return head == nullptr;
   }

private:
   std::ostream & print(std::ostream & os) const;

public:
   // Allows us to print a DLList object to a std::ostream object
   friend std::ostream & operator<<(std::ostream & os, const DLList & l)
   {
      return l.print(os);
   }
};

#endif
