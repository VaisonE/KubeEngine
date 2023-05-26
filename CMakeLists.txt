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


# Find the Vulkan package
find_package(Vulkan REQUIRED)

# Add the source files
set(SOURCES 
    main.cpp
)

# Add the executable
add_executable(KubeEngine ${SOURCES})

# Директории для поиска заголовочных файлов
target_include_directories(KubeEngine PRIVATE ../KubeEngine)

# Link the executable with the Vulkan library
target_link_libraries(KubeEngine Vulkan::Vulkan)

# Если xorg
target_link_libraries(KubeEngine xcb)
