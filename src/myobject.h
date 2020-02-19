#ifndef INCLUDED_MYOBJECT_H
#define INCLUDED_MYOBJECT_H

#include "core/object.h"

#include <iostream>

class MyObject : public Object
{
public:
   MyObject(Object* parent = nullptr);

   void notify(Object* aspect, Object* argument);

   inline void f() {
      std::cout << "it works!\n";
   }

   inline void doSomething() {
      std::cout << "I do something\n";
      stateChanged();
   }
};

#endif