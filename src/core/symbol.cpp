#include "core/symbol.h"

#include <functional>

Symbol::Symbol(const std::string& string)
: m_name(string)
{
   rehash();
}

Symbol::Symbol(const char* string)
: m_name(string)
{
   rehash();
}

bool Symbol::operator==(const Symbol& other) const
{
   return m_hash == other.m_hash;
}

void Symbol::rehash()
{
   m_hash = std::hash<std::string>{}( m_name );
}
