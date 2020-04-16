#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <functional>

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& vec) {
   for (auto& t : vec) os << t << ", ";
   os << "\n";
   return os;
}

template <typename T>
class AbstractSort {
public:
   virtual void sort(std::vector<T>&) = 0;

   bool isSorted(const std::vector<T>& vec)
   {
      return std::is_sorted(vec.begin(), vec.end());
   }
};

template <typename T>
class InsertionSort : public AbstractSort<T>
{
public:
   void sort(std::vector<T>& vec) override
   {
      if (vec.size() < 2) {
         return;
      }

      typename std::vector<T>::iterator top = vec.begin();
      top++;
      while (top != vec.end()) {
         typename std::vector<T>::iterator m = top;
         typename std::vector<T>::iterator n = top;
         m--;
         while (*m > *n)
         {
            std::iter_swap(m, n);
            m--;
            n--;
         }
         top++;
      }
   }
};

template <typename T>
class QuickSort : public AbstractSort<T>
{
public:
   void sort(std::vector<T>& vec) override
   {
      if (vec.size() < 2) {
         return;
      }

      innerSort(vec, 0, vec.size());
   }

private:
   void innerSort(
      std::vector<T>& vec,
      unsigned int begin,
      unsigned int end)
   {
      if (end < begin + 2)
      {
         return;
      }
      else if (end == begin + 2)
      {
         if (vec[begin] > vec[end-1]) {
            std::swap(vec[begin], vec[end-1]);
         }
      }

      unsigned int i=begin;
      unsigned int j=end-2;
      while (j != i)
      {
         while (i != j && vec[i] <= vec[end-1]) ++i;
         while (j != i && vec[j] >= vec[end-1]) --j;
         if (i != j) {
            std::swap(vec[i], vec[j]);
         }
      }

      if (vec[i] > vec[end-1]) {
         std::swap(vec[i], vec[end-1]);
      }
      innerSort(vec, begin, i+1);
      innerSort(vec, i+1, end);
   }
};

template <typename T>
class HeapSort : public AbstractSort<T>
{
public:
   void sort(std::vector<T>& vec) override
   {
      heapify(vec);
      std::cout << std::is_heap(vec.begin(), vec.end()) << "\n";
   }

private:
   void heapify(std::vector<T>& vec)
   {
      std::cout << "sta " << vec;

      if (vec.size() < 2)
      {
         return;
      }

      auto getLeftChild = [](int parent){
         return 2 * parent + 1;
      };

      std::function<void(int,int,int)> swapAndSiftDown;
      swapAndSiftDown = [&vec, &swapAndSiftDown, &getLeftChild](
         int current, int leftChild, int rightChild) -> void
         {
            // if right child is outside vector
            if ( getLeftChild(current)+1 >= vec.size()) {
               if (vec[getLeftChild(current)] > vec[current]) {
                  std::swap(vec[getLeftChild(current)], vec[current]);
                  std::cout << "pre " << vec;
               }
               return;
            }

            int maxChild = (
               vec[leftChild] > vec[rightChild] ?
               leftChild :
               rightChild );

            if (vec[maxChild] > vec[current]) {
               std::swap(vec[maxChild], vec[current]);
               std::cout << "nor " << vec;
               swapAndSiftDown(maxChild, getLeftChild(maxChild), getLeftChild(maxChild)+1);
            }
         };

      int current = (vec.size()-2) / 2; // get binary-tree parent of last element

      for (; current >= 0; --current)
      {
         swapAndSiftDown(current, getLeftChild(current), getLeftChild(current)+1);
      }
   }
};

int main() {
   using DataT = int;
   //std::vector<DataT> vec = {5, 4, 2, 3, 1, 7, 5, 7, 2};
   std::vector<DataT> vec = {1,2,3,4,5,6,7,8,9,10};
/*
   std::random_device dev;
   std::mt19937 rng(dev());
   std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1'000'000);
   for (int i=0; i<1'000'000; ++i)
   {
      vec.push_back( dist(rng) );
   }
*/
   std::unique_ptr< AbstractSort<DataT> > sorter( new HeapSort<DataT>() );
   sorter->sort(vec);
   std::cout << sorter->isSorted(vec);

   return 0;
}