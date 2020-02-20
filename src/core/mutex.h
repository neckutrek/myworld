#ifndef INCLUDED_MUTEX_H
#define INCLUDED_MUTEX_H

#include "core/object.h"

namespace netr
{

class Mutex : public Object
{
public:
                              Mutex(Object* parent = nullptr);

            void              lock() noexcept;

            bool              try_lock() noexcept;

            void              unlock() noexcept;

private:
   volatile unsigned int      m_locked;
};

} // namespace

#endif