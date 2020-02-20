#include "core/semaphore.h"
#include "core/lock_guard.h"

namespace netr
{

Semaphore::Semaphore(unsigned int leastMaxValue, Object* parent)
: Object(parent),
  m_leastMaxValue(leastMaxValue)
{}

void Semaphore::aquire() noexcept
{
   LockGuard lg;

   if (m_value < m_leastMaxValue)
   {
      ++m_value;
      if (m_value >= m_leastMaxValue)
      {
         m_muxLock.lock();
      }
   }
}

bool Semaphore::try_aquire() noexcept
{
   LockGuard lg;

   ++m_value;
   if (m_value >= m_leastMaxValue)
   {
      m_value = m_leastMaxValue;
      m_muxLock.lock();
      return false;
   }

   return true;
}

void Semaphore::release()
{
   LockGuard lg;

   --m_value;
   m_muxLock.unlock();
}

} // namespace