#ifndef INCLUDED_LOCK_GUARD_H
#define INCLUDED_LOCK_GUARD_H

#include "core/object.h"
#include "core/mutex.h"

namespace netr
{

class LockGuard : public Object
{
public:
                              LockGuard(Object* parent = nullptr);
                              ~LockGuard();

private:
            Mutex             m_mutex;
};

} // namespace

#endif