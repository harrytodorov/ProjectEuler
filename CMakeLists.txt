project(ProjectEuler)

# enable C++11 standard
set(CMAKE_CXX_STANDARD 11)

# Holding all source files for solved problems
set (SOLVED_PROBLEMS cpp/src/p001.cpp
					 cpp/src/p002.cpp
					 cpp/src/p003.cpp
					 cpp/src/p004.cpp
)

# Holding utilities files
set (UTILITIES cpp/src/utilities.h)

# Main driver program
set (MAIN_PROGRAM cpp/src/ProjectEulerMain.cpp)
add_executable (ProjectEuler ${MAIN_PROGRAM})

# # set the needed source files for problem 1
# set (SOURCE_FILES_P001 cpp/src/p001.cpp)
# add_executable (p001 ${SOURCE_FILES_P001})

# # set the needed source files for problem 2
# set (SOURCE_FILES_P002 cpp/src/p002.cpp)
# add_executable (p002 ${SOURCE_FILES_P002})

# # set the needed source files for problem 3
# set (SOURCE_FILES_P003 cpp/src/p003.cpp cpp/src/utilities.h)
# add_executable (p003 ${SOURCE_FILES_P003})

# # set the needed source files for problem 4
# set (SOURCE_FILES_P004 cpp/src/p004.cpp )
# add_executable (p004 ${SOURCE_FILES_P004})

# # set needed source files for problem 61
# set (SOURCE_FILES_P061 cpp/src/p061.cpp)
# add_executable (p061 ${SOURCE_FILES_P061})

# # set needed source files for problem 65
# set (SOURCE_FILES_P065 cpp/src/p065.cpp)
# add_executable (p065 ${SOURCE_FILES_P065})
