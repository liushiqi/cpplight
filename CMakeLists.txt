cmake_minimum_required(VERSION 3.9)
project(cpplight)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/utils/Shape.cpp
        src/utils/Shape.h
        src/utils/Point.cpp
        src/utils/Point.h
        src/shapes/Circle.cpp
        src/shapes/Circle.h
        src/utils/Scene.cpp
        src/utils/Scene.h
        src/utils/Vector.cpp
        src/utils/Vector.h
        src/shapes/HalfSpace.cpp
        src/shapes/HalfSpace.h
        src/utils/Shape.cpp
        src/shapes/UnionShape.cpp
        src/shapes/UnionShape.h
        src/shapes/IntersectShape.cpp
        src/shapes/IntersectShape.h
        src/shapes/SubtractShape.cpp
        src/shapes/SubtractShape.h
        src/shapes/Rectangle.cpp
        src/shapes/Rectangle.h
        src/utils/Radial.cpp
        src/utils/Radial.h)
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