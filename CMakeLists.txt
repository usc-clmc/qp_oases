cmake_minimum_required(VERSION 2.8.3)
project(qp_oases)

find_package(catkin REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE}")
add_definitions(-D__NO_COPYRIGHT__ -D__SUPPRESSANYOUTPUT__)

include_directories(include)

add_library(${PROJECT_NAME}
  src/BLASReplacement.cpp
  src/Bounds.cpp
  src/Constraints.cpp
  src/Flipper.cpp
  src/Indexlist.cpp
  src/LAPACKReplacement.cpp
  src/Matrices.cpp
  src/MessageHandling.cpp
  src/Options.cpp
  src/QProblemB.cpp
  src/QProblem.cpp
  src/SQProblem.cpp
  src/SubjectTo.cpp
  src/Utils.cpp
)

