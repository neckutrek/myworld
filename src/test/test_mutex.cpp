#include <iostream>
#include <thread>

#include "core/mutex.h"

netr::Mutex m;

void f(const std::string& str)
{
   while (true)
   {
      if (m.try_lock())
      {
         std::cout << str;
         std::cout << str;
         std::cout << str;
         std::cout << str;
         std::cout << str << "\n" << std::flush;
         m.unlock();
      }
   }
}

int main(int argc, char* argv[])
{
   std::thread t1(f, "f");
   std::thread t2(f, "g");

   t1.join();
   t2.join();

   return 0;
}