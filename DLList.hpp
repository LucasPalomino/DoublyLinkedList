#ifndef DLLIST_HPP
#define DLLIST_HPP

#include <iostream>
#include "NullNodeException.hpp"

// Class template for a doubly linked list.
// Note: In a class template definition, C++ will assume
//   any reference to the class is templated.
//   So, inside DLList writing DLList means DLList<T>
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

   // Test if current position is null.
   bool isCurNull() const
   {
      return cur == nullptr;
   }

   // Test if there is a previous element.
   bool hasPrev() const
   {
      return !isCurNull() && cur->prev != nullptr;
   }

   // Test if there is a next element.
   bool hasNext() const
   {
      return !isCurNull() && cur->next != nullptr;
   }

   // Move to the head of the list.
   // Return a reference to the invoking object.
   DLList & toHead()
   {
      cur = head;
      return *this;
   }

   // Move to the tail of the list.
   // Return a reference to the invoking object.
   DLList & toTail()
   {
      cur = tail;
      return *this;
   }

   // Move to the previous element.
   // Return a reference to the invoking object.
   DLList & toPrev();

   // Move to the next element.
   // Return a reference to the invoking object.
   DLList & toNext();

   // Get the data at the current position.
   // Throw a NullNodeException if the current position is null.
   T getData() const;

   // Set the data at the current position.
   // Throw a NullNodeException if the current position is null.
   // Return a reference to the invoking object.
   DLList & setData(const T & value);

   // Insert a new element before the current position
   // and move to this position.
   // If the current position is null and the list is not empty,
   // then the new element will not be inserted.
   // Return a reference to the invoking object.
   DLList & insertBefore(const T & data);

   // Insert a new element after the current position
   // and move to this position.
   // If the current position is null and the list is not empty,
   // then the new element will not be inserted.
   // Return a reference to the invoking object.
   DLList & insertAfter(const T & data);

   // Remove the element at the current position
   // and move to the next position.
   // Return a reference to the invoking object.
   DLList & removeToNext();

   // Remove the element at the current position
   // and move to the previous position.
   // Return a reference to the invoking object.
   DLList & removeToPrev();

   // Remove all elements in this list.
   // Return a reference to the invoking object.
   DLList & clear();

   // Test if the list is empty.
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
