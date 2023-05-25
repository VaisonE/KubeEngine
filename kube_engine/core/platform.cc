// =============================================================== 
// KubeEngine is an open source game engine.
// Copyright (C) 2023 The KubeEngine authors
//
// Licensed under the Apache License v.2;
// You may not use this file except in compliance with the License
// 
// https://github.com/VaisonE/KubeEngine/blob/main/license
// 
// All Rights Reserved
// =============================================================== 

#ifdef __unix__
    #include <vulkan/vulkan.h>

    // Using the 'Wayland'
    #include <wayland-client.h>
    // Using the 'X Window System'
    #include <xcb/xcb.h>
#endif

#ifdef _WIN32
    #include <vulkan/vulkan.h>
    #include <Windows.h>
#endif

#ifdef _WIN64
    #include <vulkan/vulkan.h>
    #include <Windows.h>
#endif