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
cmake_minimum_required(VERSION 3.10)
project(KubeEngine)


# Find the Vulkan package
find_package(Vulkan REQUIRED)

# Add the source files
set(SOURCES main.cpp)

# Add the executable
add_executable(KubeEngine ${SOURCES})

# Link the executable with the Vulkan library
target_link_libraries(KubeEngine Vulkan::Vulkan)
