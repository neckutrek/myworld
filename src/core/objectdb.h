#ifndef INCLUDED_OBJECT_DATABASE_H
#define INCLUDED_OBJECT_DATABASE_H

#include "core/symbol.h"
#include "core/object.h"

#include <unordered_map>

namespace netr
{
   
//using Symbol = std::string;

class ObjectDB : public Object
{
public:
   ~ObjectDB();

   /**
    * Must be called only once, ownership of the database data is returned to callee.
    * NOTE: Callee is responsible for 
    */
   static ObjectDB* createObjectDatabase();

   static ObjectDB* getObjectDatabase();

   void addObject(Object* object, const Symbol& id);
   void addObject(Object* object, Symbol&& id);

   Object* getObject(const Symbol& id) const;

private:
   ObjectDB();

   std::unordered_map<Symbol, Object*> m_map;

};

} // namespace netr

#endif