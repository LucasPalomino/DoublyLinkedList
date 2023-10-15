#ifndef DLLIST_CPP
#define DLLIST_CPP

#include "DLList.hpp"

// Move to the previous element.
// Return a reference to the invoking object.
template <class T>
DLList<T> & DLList<T>::toPrev()
{
   if (!isCurNull()) cur = cur->prev;

   return *this;
}

// TODO: write the definition of function DLList<T>::toNext().
//   This function points cur to the next element (this is done if
//   cur is not nullptr) and returns a reference to the invoking object.
//   The purpose of returning a reference to the invoking object is to
//   allow chaining of method call in a single statement. For example:
//      DLList<int> l;
//      l.toNext().toNext().toNext();
//   In a non-static member function, the keyword this is a pointer
//   to the invoking object. We can return a reference to the
//   invoking object by returning *this.
//   Move to the next element.
//   Return a reference to the invoking object.

template <class T>
DLList<T> & DLList<T>::toNext()
{
   if(!isCurNull()) cur = cur->next;
   
   return *this;
}


// Get the data at the current position.
// Throw a NullNodeException if the current position is null.
template <class T>
T DLList<T>::getData() const
{
   if (isCurNull()) throw NullNodeException{};

   return cur->data;
}

// TODO: write the definition of function
//   DLList<T>::setData(const T & value).
//   This function sets the data of the current node (the node cur
//   points to) to the parameter value.
//   If isCurNull() is true, then throw a NullNodeException instead
//   of setting the current node data.
//   A NullNodeException can be thrown with: throw NullNodeException{};
//   Return a reference to the invoking object.

template <class T>
DLList<T> & DLList<T>::setData(const T & value)
{
   if (isCurNull()) throw NullNodeException{};

   cur->data=value;

   return *this;
}

// TODO: write the definition of function
//   DLList<T>::insertBefore(const T & data).
//   This function inserts a new node (whose data is equal to parameter data)
//   before the current position and moves to this new node.
//   If the current position is null (i.e., isCurNull() is true) and the
//   list is not empty (i.e., !isEmpty() is true), then the new element will
//   not be inserted.
//   Return a reference to the invoking object.
//   Hint: the new node should be created on the heap.

template <class T>
DLList<T> & DLList<T>::insertBefore(const T & data)
{
   if(!(isEmpty()) && cur == nullptr) return *this;

   Node * newNode = new Node(data, cur->prev, cur);

   if(!(isEmpty()))
   {
      newNode->prev = cur->prev;
      newNode->next = cur;
   }

   if(cur == nullptr)
   {
      head = newNode;
      tail = newNode;
   }
   else
   {
      cur->prev = newNode;
      
      if(newNode->prev != nullptr)
      {
	 newNode->prev->next = newNode;
      }
      else head = newNode;
   }

   cur = newNode;

   return *this;
   
}
   
// TODO: write the definition of function
//   DLList<T>::insertAfter(const T & data).
//   This function inserts a new node (whose data is equal to parameter data)
//   after the current position and moves to this new node.
//   If the current position is null (i.e., isCurNull() is true) and the
//   list is not empty (i.e., !isEmpty() is true), then the new element will
//   not be inserted.
//   Return a reference to the invoking object.
//   Hint: the new node should be created on the heap.

template <class T>
DLList<T> & DLList<T>::insertAfter(const T & data)
{
   if(!(isEmpty()) && cur == nullptr) return *this;

   Node * newNode = new Node(data);

   if(!(isEmpty()))
   {
      newNode->prev = cur;
      newNode->next = cur->next;
   }

   if(cur == nullptr)
   {
      head = newNode;
      tail = newNode;
   }
   else
   {
      cur->next = newNode;
      
      if(newNode->next != nullptr)
      {
	 newNode->next->prev = newNode;
      }
      else tail = newNode;
   }

   cur = newNode;

   return *this;
}

// TODO: write the definition of function DLList<T>::removeToNext().
//   This function removes the node at the current position
//   and move to the next node (this is done if the current node
//   is not nullptr).
//   Return a reference to the invoking object.
//   Hint: this method should call delete to delete the current node.

template <class T>
DLList<T> & DLList<T>::removeToNext()
{
   if(cur == nullptr) return *this;

   Node * delNode = cur;

   cur = cur->next;

   if(cur != nullptr)
   {
      cur->prev = delNode->prev;

      if(delNode->prev !=nullptr)
      {
	 delNode->prev->next = cur;
      }
   }

   if(head == delNode) head = cur;
   if(tail == delNode) tail = delNode->prev;

   delete delNode;

   return *this;
}

// TODO: add the definition of function DLList<T>::removeToPrev().
//   This function removes the node at the current position
//   and move to the previous node (as long as cur is not nullptr).
//   Return a reference to the invoking object.
//   Hint: this method should call delete to delete the current node.

template <class T>
DLList<T> & DLList<T>::removeToPrev()
{
   if(cur == nullptr) return *this;

   Node * delNode = cur;

   cur = cur->prev;

   if(cur != nullptr)
   {
      cur->next = delNode->next;

      if(delNode->next !=nullptr)
      {
	 delNode->next->prev = cur;
      }
   }

   if(head == delNode) head = delNode->next;
   if(tail == delNode) tail = cur;

   delete delNode;

   return *this;
}

// TODO: add the definition of function DLList<T>::clear().
//   This method removes all nodes from the linked list.
//   Return a reference to the invoking object.

template <class T>
DLList<T> & DLList<T>::clear()
{
   toHead();

   while(!isCurNull()) removeToNext();

   return *this;
}

// TODO: add the definition of the destructor DLList<T>::~DLList().
//   This should remove all nodes from the linked list.

template <class T>
DLList<T>::~DLList()
{
   clear();
}


// Print the linked list to an std::ostream object.
// * indicates where the current position is.
template <class T>
std::ostream & DLList<T>::print(std::ostream & os) const
{
   os << "[";

   if (!isEmpty())
   {
      Node * p = head;

      while (true)
      {
	 if (p == cur) os << "*";

	 os << p->data;
	 p = p->next;

	 if (p == nullptr) break;

	 os << ", ";
      }
   }

   return os << "]";
}

#endif
