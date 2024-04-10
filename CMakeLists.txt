cmake_minimum_required(VERSION 3.28)

project(ModularRandomApplicantDataGenerator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

# gcc cannot yet compile module with exported namespace correctly,
# therefore using clang is enforced for this project
set(CMAKE_CXX_COMPILER "clang++")

add_executable(generator generator.o config.o)

set_target_properties(generator PROPERTIES LINKER_LANGUAGE CXX)

# Create config.o
add_custom_command(
  OUTPUT config.o
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -O3 -fmodule-file=config=config.pcm -fmodule-file=cstdlib.pcm -c ${CMAKE_CURRENT_SOURCE_DIR}/config.cc -o config.o
  DEPENDS config.pcm ${CMAKE_CURRENT_SOURCE_DIR}/config.cc ${CMAKE_CURRENT_SOURCE_DIR}/cstdlib.pcm
  COMMENT "Compiling config.cc"
)

add_custom_target(config.o)

add_dependencies(generator config.o)

# Precompile config.cc
add_custom_command(
  OUTPUT config.pcm
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -x c++-module ${CMAKE_CURRENT_SOURCE_DIR}/config.cc --precompile -o config.pcm -fmodule-file=cstdlib.pcm
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/config.cc ${CMAKE_CURRENT_SOURCE_DIR}/cstdlib.pcm
  COMMENT "Precompiling config.cc"
)

add_custom_target(config.pcm)

# Create generator.o
add_custom_command(
  OUTPUT generator.o
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -O3 -fmodule-file=config=config.pcm -fmodule-file=cassert.pcm -fmodule-file=cstdio.pcm -fmodule-file=cstdlib.pcm -fmodule-file=ctime.pcm -c ${CMAKE_CURRENT_SOURCE_DIR}/generator.cc -o generator.o
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/generator.cc ${CMAKE_CURRENT_SOURCE_DIR}/cassert.pcm ${CMAKE_CURRENT_SOURCE_DIR}/cstdio.pcm ${CMAKE_CURRENT_SOURCE_DIR}/cstdlib.pcm ${CMAKE_CURRENT_SOURCE_DIR}/ctime.pcm ${CMAKE_CURRENT_SOURCE_DIR}/config.pcm
  COMMENT "Compiling generator.cc"
)

add_custom_target(generator.o)

add_dependencies(generator generator.o)

# Precompile cassert
add_custom_command(
  OUTPUT cassert.pcm
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -x c++-system-header cassert --precompile -o ${CMAKE_CURRENT_SOURCE_DIR}/cassert.pcm
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/generator.cc
  COMMENT "Precompiling cassert.pcm"
)

add_custom_target(cassert.pcm)

add_dependencies(generator.o cassert.pcm)

# Precompile cstdio
add_custom_command(
  OUTPUT cstdio.pcm
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -x c++-system-header cstdio --precompile -o cstdio.pcm
  COMMENT "Precompiling cstdio.pcm"
)

add_custom_target(cstdio.pcm)

add_dependencies(generator.o cstdio.pcm)

# Precompile cstdlib
add_custom_command(
  OUTPUT cstdlib.pcm
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -x c++-system-header cstdlib --precompile -o cstdlib.pcm
  COMMENT "Precompiling cstdlib.pcm"
)

add_custom_target(cstdlib.pcm)

# Precompile ctime
add_custom_command(
  OUTPUT ctime.pcm
  COMMAND ${CMAKE_CXX_COMPILER} -std=c++23 -x c++-system-header ctime --precompile -o ctime.pcm
  COMMENT "Precompiling ctime.pcm"
)

add_custom_target(ctime.pcm)

add_dependencies(generator.o ctime.pcm)