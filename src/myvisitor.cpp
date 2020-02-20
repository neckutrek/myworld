#include "myvisitor.h"
#include "myobject.h"

MyVisitor::MyVisitor(netr::Object* parent)
: netr::Object(parent)
{}

void MyVisitor::visit(netr::Object* other)
{
   if (auto o = dynamic_cast<MyObject*>(other))
   {
      o->f();
   }
}