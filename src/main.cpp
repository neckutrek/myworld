/**
 * CPP PROJECT TEMPLATE
 */

#include <iostream>

#include "myvisitor.h"
#include "myobject.h"
#include "core/objectdb.h"

int main(int argc, char** argv)
{
   MyVisitor* v = new MyVisitor;
   MyObject* o1 = new MyObject;
   MyObject* o2 = new MyObject;

   o2->addObserver(o1);

   netr::ObjectDB* db = netr::ObjectDB::createObjectDatabase();
   db->addObject(o1, "First");
   db->addObject(o2, "Second");

   db->getObject("First")->accept(v);
   if (auto obj2 = dynamic_cast<MyObject*>(db->getObject("Second")))
   {
      obj2->doSomething();
   }


   delete db;
   return 0;
}