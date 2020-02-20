#include "core/mutex.h"

#include <thread>

namespace netr
{

Mutex::Mutex(Object* parent)
: Object(parent)
{}

void Mutex::lock() noexcept
{
   while (m_locked)
   {
      std::this_thread::yield();
   }
   __sync_lock_test_and_set(&m_locked, 1);
   return;
}

bool Mutex::try_lock() noexcept
{
   if (!__sync_lock_test_and_set(&m_locked, 1))
   {
      return true;
   }
   return false;
}

void Mutex::unlock() noexcept
{
   __sync_lock_test_and_set(&m_locked, 0);
}

} // namespace netr