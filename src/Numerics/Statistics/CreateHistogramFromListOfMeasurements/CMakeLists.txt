cmake_minimum_required(VERSION 3.16.3)

project(CreateHistogramFromListOfMeasurements)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(CreateHistogramFromListOfMeasurements Code.cxx)
target_link_libraries(CreateHistogramFromListOfMeasurements ${ITK_LIBRARIES})

install(TARGETS CreateHistogramFromListOfMeasurements
  DESTINATION bin/ITKSphinxExamples/Numerics/Statistics
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Numerics/Statistics/CreateHistogramFromListOfMeasurements/
  COMPONENT Code
  )


enable_testing()
add_test(NAME CreateHistogramFromListOfMeasurementsTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/CreateHistogramFromListOfMeasurements)

