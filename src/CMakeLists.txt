project(main)

set(SOURCES
   core/object.cpp
   core/symbol.cpp
   core/objectdb.cpp
   main.cpp
   myvisitor.cpp
   myobject.cpp)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE .)