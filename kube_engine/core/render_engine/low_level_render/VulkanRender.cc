// ================================================================ //
//  VulkanRender.cc                                                 //
// ================================================================ //
//           KubeEngine is an open source game engine               //
//          Copyright (C) 2023 The KubeEngine authors.              //                         
//                                                                  //
//            Licensed under the Apache License v.2;                //
//  You may not use this file except in compliance with the License //
//                                                                  //
// https://github.com/VaisonE/KubeEngine/blob/main/license          //
//                                                                  //
//                     All Rights Reserved                          //
// ================================================================ //

#pragma once
#include "kube_engine/core/render_engine/low_level_render/RenderEngineInterface.cc"

#include <vulkan/vulkan.h>
#include <iostream>

class VulkanRender /*: public RenderEngineInterface*/ {
    VkInstance instance;
    
    public:
        void runRender() {
            initVulkan();
        }

        ~VulkanRender() {
            cleaning();
        }

    private:

        void initVulkan();
        void cleaning();
        void createInstance();
};

void VulkanRender::initVulkan() {
    createInstance();
}

void VulkanRender::createInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;


    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) 
        throw std::runtime_error("failed to create instance!");
}

void VulkanRender::cleaning() {
    vkDestroyInstance(instance, nullptr);
}