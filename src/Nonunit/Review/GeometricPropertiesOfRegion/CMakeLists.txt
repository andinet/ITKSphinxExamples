cmake_minimum_required(VERSION 3.16.3)

project(GeometricPropertiesOfRegion)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


if(ENABLE_QUICKVIEW)
  find_package(VTK REQUIRED
    COMPONENTS
      ${_vtk_prefix}RenderingCore
      ${_vtk_prefix}RenderingGL2PSOpenGL2
    )

  if(VTK_VERSION VERSION_LESS "8.90.0")
    include(${VTK_USE_FILE})
  endif()

  add_executable(GeometricPropertiesOfRegion Code.cxx)
  target_link_libraries(GeometricPropertiesOfRegion ${ITK_LIBRARIES} ${VTK_LIBRARIES})

  if(NOT VTK_VERSION VERSION_LESS "8.90.0")
    vtk_module_autoinit(
      TARGETS GeometricPropertiesOfRegion
      MODULES ${VTK_LIBRARIES}
      )
  endif()
else()
  add_executable(GeometricPropertiesOfRegion Code.cxx)
  target_link_libraries(GeometricPropertiesOfRegion ${ITK_LIBRARIES})
endif()

install(TARGETS GeometricPropertiesOfRegion
  DESTINATION bin/ITKSphinxExamples/Nonunit/Review
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Nonunit/Review/GeometricPropertiesOfRegion/
  COMPONENT Code
  )


enable_testing()
add_test(NAME GeometricPropertiesOfRegionTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/GeometricPropertiesOfRegion)

