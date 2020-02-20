#ifndef INCLUDED_SEMAPHORE_H
#define INCLUDED_SEMAPHORE_H

#include "core/object.h"
#include "core/mutex.h"

namespace netr
{

class Semaphore : public Object
{
public:
                              Semaphore(unsigned int leastMaxValue, Object* parent = nullptr);

            void              aquire() noexcept;

            bool              try_aquire() noexcept;

            void              release();

private:
            Mutex             m_muxInternal;

            Mutex             m_muxLock;

   volatile unsigned int      m_value;

   const    unsigned int      m_leastMaxValue;
};

} // namespace

#endif