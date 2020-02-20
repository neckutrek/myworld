#ifndef INCLUDED_MYVISITOR_H
#define INCLUDED_MYVISITOR_H

#include "core/object.h"

class MyVisitor : public netr::Object
{
public:
   MyVisitor(netr::Object* parent = nullptr);

protected:
   void visit(netr::Object* other);

};

#endif