#ifndef INCLUDED_OBJECT_H
#define INCLUDED_OBJECT_H

#include <forward_list>

class Object
{
public:
   Object(Object* parent = nullptr);
   
   virtual ~Object();

   void accept(Object* visitor);

   void addObserver(Object* observer);

   void removeObserver(Object* observer);

protected:
   virtual void visit(Object* object);

   void stateChanged(Object* argument = nullptr, Object* aspect = nullptr);

   virtual void notify(Object* argument = nullptr, Object* aspect = nullptr);

private:
   Object* m_parent;

   std::forward_list<Object*> m_observers;

};

#endif