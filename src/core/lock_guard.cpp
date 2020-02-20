#include "core/lock_guard.h"
#include "core/mutex.h"

namespace netr
{

LockGuard::LockGuard(Object* parent)
: Object(parent)
{
   m_mutex.lock();
}

LockGuard::~LockGuard()
{
   m_mutex.unlock();
}


} // namespace netr