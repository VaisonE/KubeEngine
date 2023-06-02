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
#include "kube_engine/api/include/core.hpp" // header
#include "kube_engine/core/render_engine/renderInterface.cc"
#include "kube_engine/core/render_engine/lowLevelRendering/vulkan/vulkan.cc"

namespace ke {
    void start(
        ke::renderAPI render_type,
        std::string ProjectName, 
        const uint32_t WIDTH, 
        const uint32_t HEIGHT
    ) {
        if (render_type == renderInterface::renderAPI::VULKAN) {
            renderInterface r(renderInterface::renderAPI::VULKAN, ProjectName, WIDTH, HEIGHT);
            r.runRender();
        }
    }
}