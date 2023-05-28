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

#pragma once 
#include "kube_engine/core/platform.cc"
#include "kube_engine/core/render_engine/VulkanRender.cc"

void render() {
    platform *os = get_platform();
    os->create_window();

    VulkanRender();
    while (true) {
        
    }

    delete os;
}