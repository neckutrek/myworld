#include "myvisitor.h"
#include "myobject.h"

MyVisitor::MyVisitor(Object* parent)
: Object(parent)
{}

void MyVisitor::visit(Object* other)
{
   if (auto o = dynamic_cast<MyObject*>(other))
   {
      o->f();
   }
}