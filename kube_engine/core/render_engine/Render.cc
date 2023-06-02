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
// Render.cc                                                          //    
// ================================================================== //

#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <vector>

class Render {
    public:
        virtual void setRenderSettings(
            std::string ProjectName, 
            const uint32_t WIDTH, 
            const uint32_t HEIGHT
        ) = 0;
        virtual void render() = 0;
};