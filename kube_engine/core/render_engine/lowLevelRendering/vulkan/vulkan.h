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
// vulkan.h                                                           //    
// ================================================================== //

#pragma once
#include "kube_engine/core/platform.cc"
#include "kube_engine/core/render_engine/Render.cc"

#include <vulkan/vulkan.h>
#include <optional>

class vulkanRender : public Render {
    public:
        void setRenderSettings(
            std::string ProjectName, 
            const uint32_t WIDTH, 
            const uint32_t HEIGHT
        ) override {
            this->ProjectName = ProjectName;
            this->HEIGHT = HEIGHT;
            this->WIDTH = WIDTH;
        }

        void render() override {
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();
        }

    private:
        struct VulkanExpansions {
            void get_extensions_vulkan();
        };

        struct QueueFamilyIndices {
            std::optional<uint32_t> graphicsFamily;
            bool isComplete() { return graphicsFamily.has_value(); }
        };
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        bool isDeviceSuitable(VkPhysicalDevice device);

        void initWindow();
        void initVulkan();
        void mainLoop();
        void cleanup();

        void createInstance();
        void pickPhysicalDevice();
    private:
        std::string ProjectName;
        uint32_t HEIGHT;
        uint32_t WIDTH;

        GLFWwindow* window;
        VkInstance instance;
};