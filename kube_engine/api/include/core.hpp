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
#include <string>

#ifdef __cplusplus
extern "C++" {
#endif

namespace ke {
    enum renderAPI {
        VULKAN,
        DIRECT3D
    };

    void start(
        renderAPI render_type,
        std::string ProjectName, 
        const uint32_t WIDTH, 
        const uint32_t HEIGHT
    );
}

#ifdef __cplusplus
} // end extern "C++"
#endif