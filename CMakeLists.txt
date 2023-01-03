cmake_minimum_required(VERSION 3.20)
project(proxy-socket5 CXX)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS /utf-8)
set(CMAKE_DEBUG_POSTFIX d)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_compile_options($<$<AND:$<NOT:$<COMPILE_LANGUAGE:CUDA>>,$<OR:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>>:/MP8>)

add_compile_options(/wd4828)
add_definitions(-DUNICODE -D_UNICODE)

set(PROJECT_NAME proxy-socket5)

add_executable(${PROJECT_NAME} "")

set(header_path 
      ${CMAKE_CURRENT_SOURCE_DIR}
)

set(headers 
      ${header_path}/proxy.h
      ${header_path}/socket.h
)

set(sources
	  ./proxy.cpp
      ./socket.cpp
      ./proxy_main.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC 
    ${headers}
    PRIVATE
    ${sources}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
PRIVATE
)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
)