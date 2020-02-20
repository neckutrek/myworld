set(SOURCES_CORE
   core/lock_guard.cpp
   core/mutex.cpp
   core/object.cpp
   core/objectdb.cpp
   core/semaphore.cpp
   core/symbol.cpp)

# project main
project(main)
set(SOURCES_MAIN
   main.cpp
   myvisitor.cpp
   myobject.cpp)
add_executable(main ${SOURCES_CORE} ${SOURCES_MAIN})
target_include_directories(main PRIVATE .)

# project test_mutex
project(test_mutex)
add_executable(test_mutex ${SOURCES_CORE} test/test_mutex.cpp)
target_include_directories(test_mutex PRIVATE .)

# project test_semaphore
project(test_semaphore)
set(CMAKE_CXX_FLAGS "-std=c++17 -O0 -ggdb")
add_executable(test_semaphore ${SOURCES_CORE} test/test_semaphore.cpp)
target_include_directories(test_semaphore PRIVATE .)