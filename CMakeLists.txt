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
        src/shape/Radial.cpp
        src/shape/Radial.h)
add_executable(cpplight ${SOURCE_FILES} src/main.cpp)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.55.5 COMPONENTS unit_test_framework)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(testcpplight test/test.cpp ${SOURCE_FILES})
    target_link_libraries(testcpplight ${Boost_LIBRARIES})
endif ()

find_package(OpenCV)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    add_definitions(-DHAVE_OPENCV)
    add_executable(cpplightocv src/cvmain.cpp ${SOURCE_FILES})
    target_link_libraries(cpplightocv ${OpenCV_LIBS})
    target_link_libraries(cpplight ${OpenCV_LIBS})
    target_link_libraries(testcpplight ${OpenCV_LIBS})
endif ()