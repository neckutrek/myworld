#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "core/semaphore.h"

const unsigned int MAXCOUNT = 10;
netr::Semaphore s(MAXCOUNT);
volatile int c = 0;

void f(bool randomval)
{
   while (true)
   {
      if (s.try_aquire())
      {
         if (randomval)
         {
            ++c;
         }
         else
         {
            --c;
         }
         std::cout << c << std::endl;
      }
   }
}

int main(int argc, char* argv[])
{
   srand(time(0));

   std::vector<std::thread> threads;
   for (int i=0; i<10; ++i)
   {
      bool rndval = i%2;
      auto& iter = threads.emplace_back(f, rndval );
      iter.join();
   }

   return 0;
}