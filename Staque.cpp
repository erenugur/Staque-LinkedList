#include <iostream>
#include "Staque.h"

//--- Definition of Staque constructor
Staque::Staque() {
    myFront = 0;
    myBack = 0;
}

//--- Definition of Staque copy constructor
Staque::Staque(const Staque& original) {
   myFront = 0;
   myBack = 0;
   if (!original.empty()) {
      myFront = myBack = new Staque::Node(original.front());
      Staque::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0) {
         myBack->next = new Staque::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Staque destructor
Staque::~Staque() { 
  Staque::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Staque & Staque::operator=(const Staque& rightHandSide) {
   if (this != &rightHandSide) {
      this->~Staque();                  
      if (rightHandSide.empty())
         myFront = myBack = 0;
      else {
         myFront = myBack = new Staque::Node(rightHandSide.front());
         Staque::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0) {
           myBack->next = new Staque::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Staque::empty() const { 
   return (myFront == 0); 
}

//--- Definition of front()
StaqueElement Staque::front() const {
   if (!empty()) {
      return (myFront->data);
   }
   else {
      cerr << "*** Queue is empty "
              " -- returning garbage ***\n";
      StaqueElement * temp = new(StaqueElement);  
      StaqueElement garbage = *temp;     // "Garbage" value
      delete temp;
      return garbage;
   }
}

//--- Definition of insert()
void Staque::insert(const StaqueElement & value) {
    if (value % 2 == 0) {
        myFront = new Staque::Node(value, myFront);
    }
    else if (value % 2 != 0) {
        Staque::NodePointer newptr = new Staque::Node(value);
        if (empty())
            myFront = myBack = newptr;
        else {
            myBack->next = newptr;
            myBack = newptr;
        }
    }
}

//--- Definition of removeEven()
void Staque::removeEven() {
   if (!empty()) {
      Staque::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
   }   
   else {
      cerr << "*** Stack is empty -- can't remove a value ***\n";
   }
}

//--- Definition of removeOdd()
void Staque::removeOdd() {
    Node* current = myFront;
    while ((current->next)->next != 0) {
        current = current->next;
    }

    delete current->next;
    current->next = 0;
}

//--- Definition of display()
void Staque::display(ostream & out) const {
   Staque::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next) {
        out << ptr->data << "  ";
   }
   out << endl;
}



