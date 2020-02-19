#include "MyObject.h"

#include <iostream>

MyObject::MyObject(Object* parent)
: Object(parent) 
{}

void MyObject::notify(Object* aspect, Object* argument)
{
   std::cout << "I can see that\n";
}