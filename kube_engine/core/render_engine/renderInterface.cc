// ================================================================== //
// KubeEngine is an open source game engine.                          //
// Copyright (C) 2023 The KubeEngine authors                          //
//                                                                    //
// Licensed under the Apache License v.2;                             //
// You may not use this file except in compliance with the License    //
//                                                                    //
// https://github.com/VaisonE/KubeEngine/blob/main/license            //
//                                                                    //
// All Rights Reserved                                                //
// ================================================================== //
// renderInterface.cc                                                 //    
// ================================================================== //

#pragma once
#include "kube_engine/core/render_engine/lowLevelRendering/vulkan/vulkan.h"

class renderInterface {
    public:
        enum renderAPI {
            VULKAN,
            DIRECT3D
        };

        renderInterface (
            renderAPI render_type,
            std::string ProjectName, 
            const uint32_t WIDTH, 
            const uint32_t HEIGHT
        ) {
            this->render_type = render_type;
            this->ProjectName = ProjectName;
            this->HEIGHT = HEIGHT;
            this->WIDTH = WIDTH;

            if (render_type == renderAPI::VULKAN) 
                render = new vulkanRender;
        }
        ~renderInterface() {
            delete render;
        }

        void runRender() {
            render->setRenderSettings(ProjectName, WIDTH, HEIGHT);
            render->render();
        }
    
    private:
        Render* render;

        renderAPI render_type;
        std::string ProjectName; 
        uint32_t HEIGHT;
        uint32_t WIDTH;
};