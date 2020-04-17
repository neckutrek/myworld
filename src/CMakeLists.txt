set(SOURCES_CORE
   core/lock_guard.cpp
   core/mutex.cpp
   core/object.cpp
   core/objectdb.cpp
   core/semaphore.cpp
   core/symbol.cpp)

set(SOURCES_MAIN
   main.cpp
   myvisitor.cpp
   myobject.cpp)
add_executable(main ${SOURCES_CORE} ${SOURCES_MAIN})
target_include_directories(main PRIVATE .)

set(SOURCES_MAIN2
   main2.cpp)
add_executable(main2 ${SOURCES_CORE} ${SOURCES_MAIN2})
target_include_directories(main2 PRIVATE .)

add_executable(test_mutex ${SOURCES_CORE} test/test_mutex.cpp)
target_include_directories(test_mutex PRIVATE .)

add_executable(test_semaphore ${SOURCES_CORE} test/test_semaphore.cpp)
target_include_directories(test_semaphore PRIVATE .)

add_executable(sort test/sorting_algorithms.cpp)
target_include_directories(sort PRIVATE .)