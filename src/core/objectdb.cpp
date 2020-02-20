#include "core/objectdb.h"

#include <cassert>

namespace netr
{

static ObjectDB* s_objectDB = nullptr;

ObjectDB::ObjectDB()
{}

ObjectDB::~ObjectDB()
{}

ObjectDB* ObjectDB::createObjectDatabase()
{
   assert(!s_objectDB); // ObjectDB::createObjectDatabase has been called more than once!

   s_objectDB = new ObjectDB;

   return s_objectDB;
}

ObjectDB* ObjectDB::getObjectDatabase()
{
   assert(s_objectDB); // ObjectDB::createObjectDatabase has not been called!

   return s_objectDB;
}

void ObjectDB::addObject(Object* object, const Symbol& id)
{
   m_map[id] = object;
}

void ObjectDB::addObject(Object* object, Symbol&& id)
{
   m_map[id] = object;
}

Object* ObjectDB::getObject(const Symbol& id) const
{
   auto iter = m_map.find(id);
   if (iter != m_map.end())
   {
      return iter->second;
   }
   return nullptr;
}

} // namespace netr