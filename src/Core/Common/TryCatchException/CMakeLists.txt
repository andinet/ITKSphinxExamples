cmake_minimum_required(VERSION 3.16.3)

project( TryCatchException )

find_package( ITK REQUIRED )
include( ${ITK_USE_FILE} )

add_executable( TryCatchException Code.cxx )
target_link_libraries( TryCatchException ${ITK_LIBRARIES} )

install( TARGETS TryCatchException
  DESTINATION bin/ITKSphinxExamples/Core/Common
  COMPONENT Runtime
)

install( FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Core/Common/TryCatchException
  COMPONENT Code
)

enable_testing()
add_test( NAME TryCatchExceptionTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TryCatchException )
