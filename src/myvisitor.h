#ifndef INCLUDED_MYVISITOR_H
#define INCLUDED_MYVISITOR_H

#include "core/object.h"

class MyVisitor : public Object
{
public:
   MyVisitor(Object* parent = nullptr);

protected:
   void visit(Object* other);

};

#endif