cmake_minimum_required(VERSION 3.0.0)

project(DicomClassifier VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Define sources
file(GLOB_RECURSE SOURCES_FILES
    "DicomClassifier/*.cpp"
    "DicomClassifier/*.cxx"
)

file(GLOB_RECURSE METRICS_SOURCES_FILES
    "metrics/*.cpp"
)

file(GLOB_RECURSE PREPROCESSING_SOURCES_FILES
    "preprocessing/*.cpp"
)

# Define headers
file(GLOB_RECURSE HEADERS_FILES
    "*.h"
    "*.hpp"
)

# Set sources
add_library(DicomClassifier STATIC "${SOURCES_FILES}")
add_library(DicomMetrics STATIC "${METRICS_SOURCES_FILES}")
add_library(DicomPreprocessing STATIC "${PREPROCESSING_SOURCES_FILES}")

# Include dirs
include_directories(DicomClassifier)
include_directories(metrics)
include_directories(preprocessing)


# C++ flags
set(USE_PTHREAD ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")






