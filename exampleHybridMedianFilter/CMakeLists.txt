cmake_minimum_required(VERSION 3.5)

project(probandoAlgoritmoEnLibDicom LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

add_library(DicomClassifier STATIC IMPORTED)
set_target_properties(DicomClassifier PROPERTIES
    IMPORTED_LOCATION "/home/jair/dicom-classifier/build/libDicomClassifier.a"
    INTERFACE_INCLUDE_DIRECTORIES "/home/jair/dicom-classifier/DicomClassifier"
)

add_library(DicomMetrics STATIC IMPORTED)
set_target_properties(DicomMetrics PROPERTIES
    IMPORTED_LOCATION "/home/jair/dicom-classifier/build/libDicomMetrics.a"
    INTERFACE_INCLUDE_DIRECTORIES "/home/jair/dicom-classifier/metrics"
)

add_library(DicomPreprocessing STATIC IMPORTED)
set_target_properties(DicomPreprocessing PROPERTIES
    IMPORTED_LOCATION "/home/jair/dicom-classifier/build/libDicomPreprocessing.a"
    INTERFACE_INCLUDE_DIRECTORIES "/home/jair/dicom-classifier/preprocessing"
)

add_executable(probandoAlgoritmoEnLibDicom main.cpp)
target_link_libraries(probandoAlgoritmoEnLibDicom DicomClassifier DicomMetrics DicomPreprocessing -ldcmdata -ldcmimgle -ldcmimage -ldcmjpeg -lpthread OpenMP::OpenMP_CXX)


