cmake_minimum_required(VERSION 3.16.3)

project( ChangeImageOriginSpacingOrDirection )

find_package( ITK REQUIRED )
include( ${ITK_USE_FILE} )

add_executable( ChangeImageOriginSpacingOrDirection Code.cxx )
target_link_libraries( ChangeImageOriginSpacingOrDirection ${ITK_LIBRARIES} )

install( TARGETS ChangeImageOriginSpacingOrDirection
  DESTINATION bin/ITKSphinxExamples/Filtering/ImageGrid
  COMPONENT Runtime
  )

install( FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Filtering/ImageGrid/ChangeImageOriginSpacingOrDirection
  COMPONENT Code
  )

enable_testing()
add_test( NAME ChangeImageOriginSpacingOrDirectionTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ChangeImageOriginSpacingOrDirection
  ${CMAKE_CURRENT_BINARY_DIR}/HeadMRVolume.mha
  0.7
  8.4
  2.9
  4.4
  30.0
  )
