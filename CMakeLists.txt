if(UNIX)
    # Direct CMake to use icpx rather than the default C++ compiler/linker
    set(CMAKE_CXX_COMPILER icpx)
else() # Windows
    # Force CMake to use icx-cl rather than the default C++ compiler/linker 
    # (needed on Windows only)
    include (CMakeForceCompiler)
    CMAKE_FORCE_CXX_COMPILER (icx-cl IntelDPCPP)
    include (Platform/Windows-Clang)
endif()

cmake_minimum_required (VERSION 3.16.3)
project (WordCloud)

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# SET(CMAKE_CXX_COMPILER "clang++")
SET(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES  ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

include_directories(include)
include_directories(utils)
file(GLOB SRC src/*.cpp)
add_executable(main ${SRC})

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)


# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_custom_target(
	copy-compile-commands ALL
	${CMAKE_COMMAND} -E copy_if_different
	${CMAKE_BINARY_DIR}/compile_commands.json
	${CMAKE_CURRENT_LIST_DIR}
)

add_subdirectory(bloom)
add_subdirectory(wordcloud)





