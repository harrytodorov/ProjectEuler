project(ProjectEuler)

# enable C++11 standard
set(CMAKE_CXX_STANDARD 11)

# set the needed source files for problem 1
set (SOURCE_FILES_P001 cpp/src/p001.cpp)
add_executable (p001 ${SOURCE_FILES_P001})
