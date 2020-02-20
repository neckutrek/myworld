#include "myobject.h"

#include <iostream>

MyObject::MyObject(netr::Object* parent)
: netr::Object(parent)
{}

void MyObject::notify(netr::Object* aspect, netr::Object* argument)
{
   std::cout << "I can see that\n";
}