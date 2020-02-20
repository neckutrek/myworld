#ifndef INCLUDED_SYMBOL_H
#define INCLUDED_SYMBOL_H

#include <string>

#include "core/object.h"

#include <functional>

namespace netr
{

class Symbol : public Object
{
public:
                              Symbol(const std::string& string);

                              Symbol(const char* string);

            bool              operator==(const Symbol& other) const;

private:

   friend struct std::hash<Symbol>;

            void              rehash();

            std::string       m_name;

            std::size_t       m_hash;

};

} // namespace netr

template<> struct std::hash<netr::Symbol>
{
   std::size_t operator()(const netr::Symbol& s) const noexcept
   {
      return s.m_hash;
   }
};

#endif
