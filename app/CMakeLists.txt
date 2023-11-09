# CMakeList.txt : CMake project for Curves, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CurvesApp")

add_executable (CurvesApp "main.cpp")

# Connect CurvesLib.	

target_include_directories(CurvesApp PRIVATE "../lib/include")

find_package(OpenMP REQUIRED)
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

target_link_libraries(CurvesApp PRIVATE CurvesLib OpenMP::OpenMP_CXX)



# Copy DLL to the same location as the executable
add_custom_command(TARGET CurvesApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:CurvesLib>
    $<TARGET_FILE_DIR:CurvesApp>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CurvesApp PROPERTY CXX_STANDARD 20)
endif()