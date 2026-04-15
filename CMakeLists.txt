#  @file CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Vix AI NLP module.
#
#  Header-only natural language processing module for Vix.
#  Provides tokenizers, embeddings, pipelines, and model loading
#  primitives.
#
#  Public targets:
#    - vix_ai_nlp
#    - vix::ai::nlp
#
#  Installation:
#    Installs headers, exported targets, and CMake package files
#    for find_package(vix_ai_nlp CONFIG REQUIRED).

cmake_minimum_required(VERSION 3.20)

project(vix_ai_nlp VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(VIX_AI_NLP_BUILD_TESTS "Build vix_ai_nlp tests" OFF)
option(VIX_AI_NLP_INSTALL "Install vix_ai_nlp targets" ON)
option(VIX_AI_NLP_WARNINGS "Enable extra warnings for vix_ai_nlp" ON)

if(DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()

add_library(vix_ai_nlp INTERFACE)
add_library(vix::ai::nlp ALIAS vix_ai_nlp)

target_include_directories(vix_ai_nlp INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(vix_ai_nlp INTERFACE cxx_std_20)

target_compile_definitions(vix_ai_nlp INTERFACE
  VIX_AI_NLP_VERSION="${PROJECT_VERSION}"
)

if(VIX_AI_NLP_WARNINGS)
  if(MSVC)
    target_compile_options(vix_ai_nlp INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_nlp INTERFACE
      -Wall
      -Wextra
      -Wpedantic
    )
  endif()
endif()

if(VIX_AI_NLP_BUILD_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

if(VIX_AI_NLP_INSTALL)
  install(TARGETS vix_ai_nlp
    EXPORT vix_ai_nlpTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
  )

  install(EXPORT vix_ai_nlpTargets
    FILE vix_ai_nlpTargets.cmake
    NAMESPACE vix::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nlp
  )

  configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/vix_ai_nlpConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nlp"
  )

  write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nlp"
  )
endif()

message(STATUS "vix::ai::nlp configured (${PROJECT_VERSION})")
message(STATUS "Include dir: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install: ${VIX_AI_NLP_INSTALL}")
message(STATUS "Tests: ${VIX_AI_NLP_BUILD_TESTS}")
