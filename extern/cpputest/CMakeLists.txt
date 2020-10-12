
configure_file(CMakeLists.txt.in cpputest-download/CMakeLists.txt)
# Call CMake to download and CppUTest
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cpputest-download )
if(result)
  message(FATAL_ERROR "CMake step for cpputest failed: ${result}")
endif()
# Build the downloaded google test
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cpputest-download )
if(result)
  message(FATAL_ERROR "Build step for cpputest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Prevent installation of GTest with your project
#set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
#set(INSTALL_GMOCK OFF CACHE BOOL "" FORCE)

set(TESTS OFF CACHE BOOL "" FORCE)

# Add cpputest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/cpputest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/cpputest-build)

         