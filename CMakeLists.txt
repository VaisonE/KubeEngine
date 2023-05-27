# =============================================================== 
# KubeEngine is an open source game engine.
# Copyright (C) 2023 The KubeEngine authors
#
# Licensed under the Apache License v.2;
# You may not use this file except in compliance with the License
# 
# https://github.com/VaisonE/KubeEngine/blob/main/license
# 
# All Rights Reserved
# =============================================================== 
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project(KubeEngine)

# Set the variable PLATFORM to Windows or Linux
set(PLATFORM Linux)

# =============================================================== 
# Find the Vulkan package and source path
find_package(Vulkan REQUIRED)
set(SOURCES 
    kube_engine/api/kube_engine_core_api.cpp
)

# Compilation, header search directories, compiler settings
if(PLATFORM STREQUAL "Windows")
    add_library(KubeEngine SHARED ${SOURCES})
    target_include_directories(KubeEngine PRIVATE ../KubeEngine)
    target_compile_definitions(KubeEngine PRIVATE -DKUBE_ENGINE_BUILD_DLL)
    target_compile_options(KubeEngine PRIVATE /W4 /MP /EHsc)
else()
    add_library(KubeEngine SHARED ${SOURCES})
    target_include_directories(KubeEngine PRIVATE ../KubeEngine)
    target_compile_definitions(KubeEngine PRIVATE -DKUBE_ENGINE_BUILD_DLL)
    target_compile_options(KubeEngine PRIVATE -Wall -fPIC -fexceptions)
endif()

# Linking with dependencies
target_link_libraries(KubeEngine Vulkan::Vulkan)
if(PLATFORM STREQUAL "Windows")
    target_link_libraries(KubeEngine user32)
    target_link_libraries(KubeEngine gdi32)
else()
    target_link_libraries(KubeEngine xcb)
    target_link_libraries(KubeEngine dl)
endif()