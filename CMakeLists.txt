cmake_minimum_required(VERSION 3.9)
project(cpplight)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/shape/Shape.cpp
        src/shape/Shape.h
        src/shape/Point.cpp
        src/shape/Point.h
        src/shape/Circle.cpp
        src/shape/Circle.h
        src/shape/Scene.cpp
        src/shape/Scene.h
        src/shape/Vector.cpp
        src/shape/Vector.h
        src/shape/HalfSpace.cpp
        src/shape/HalfSpace.h
        src/shape/Shape.cpp
        src/shape/UnionShape.cpp
        src/shape/UnionShape.h
        src/shape/IntersectShape.cpp
        src/shape/IntersectShape.h
        src/shape/SubtractShape.cpp
        src/shape/SubtractShape.h
        src/shape/Rectangle.cpp
        src/shape/Rectangle.h
        src/shape/Line.cpp
        src/shape/Line.h)
add_executable(cpplight ${SOURCE_FILES} src/main.cpp)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

add_executable(testcpplight test/test.cpp ${SOURCE_FILES})
find_package(Boost 1.55.5 REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(testcpplight ${Boost_LIBRARIES})