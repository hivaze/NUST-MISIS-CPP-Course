# Install script for directory: /Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/prj.lab

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/rational/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/complex/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/matrixa/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/matrixl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/dynarray/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuea/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/queuel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/stacka/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/stackl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/sergey/Desktop/CODE-W/CLion Projects/bratchikov_s_s/cmake-build-debug/prj.lab/ortogeo/cmake_install.cmake")
endif()

