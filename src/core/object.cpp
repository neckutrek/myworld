#include "core/object.h"

Object::Object(Object* parent)
: m_parent(parent)
{

}

Object::~Object()
{
}

void Object::accept(Object* visitor)
{
   visitor->visit(this);
}

void Object::visit(Object* other)
{
   //no op
}

void Object::addObserver(Object* observer)
{
   if (!observer)
   {
      return;
   }

   auto iter = std::find(m_observers.begin(), m_observers.end(), observer);
   if (iter != m_observers.end())
   {
      return;
   }

   m_observers.push_front(observer);
}

void Object::removeObserver(Object* observer)
{
   m_observers.remove_if( 
      [&observer](Object* o) -> bool { return o == observer; }
   );
}

void Object::stateChanged(Object* argument, Object* aspect)
{
   for (auto& observer : m_observers)
   {
      observer->notify(aspect, argument);
   }
}

void Object::notify(Object* argument, Object* aspect)
{
   // no op
}