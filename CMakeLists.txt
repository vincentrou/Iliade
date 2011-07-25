cmake_minimum_required (VERSION 2.6)
project (Iliade)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#add_executable(iliade src/iliade.cpp)
add_subdirectory(src)
