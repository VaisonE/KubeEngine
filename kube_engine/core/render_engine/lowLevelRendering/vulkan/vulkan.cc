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
// vulkan.cc                                                          //    
// ================================================================== //

#pragma once
#include "kube_engine/core/render_engine/lowLevelRendering/vulkan/vulkan.h"

// Creating a window with GLFW
void vulkanRender::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, ProjectName.c_str(), nullptr, nullptr);
}

void vulkanRender::initVulkan() {
    createInstance();
    pickPhysicalDevice();
}

void vulkanRender::cleanup() {
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}

void vulkanRender::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}




void vulkanRender::createInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = ProjectName.c_str();
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "KubeEngine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Getting a list of required extensions using the function GLFW
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    // Instance creation
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
} 