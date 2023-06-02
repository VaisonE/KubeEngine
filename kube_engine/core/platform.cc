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
// platform.cc                                                        //    
// ================================================================== //

enum PLATFORM {
    LINUX,
    LINUX_WAYLAND,
    LINUX_XORG,
    WINDOWS,
    ANDROID,
    IOS
};

#pragma once
#include <string>

#ifdef __linux__
    #include <GLFW/glfw3.h>

    // Using the 'Wayland'
    #include <wayland-client.h>
    // Using the 'X Window System'
    #include <xcb/xcb.h>

    PLATFORM build_platform = PLATFORM::LINUX;
#endif

#ifdef _WIN64
    #include <GLFW/glfw3.h>
    #include <Windows.h>

    PLATFORM build_platform = PLATFORM::WINDOWS;
#endif


/* =================================================================================== */
/* The 'platform' abstract class and its descendants contain the key components        */
/* for working with a specific platform on which the KubeEngine game engine was run.   */
/* Serves to implement polymorphism in code.                                           */
/*                                                                                     */
/* It has two virtual methods 'create_window' and 'get_platform_type'.                 */
/*                                                                                     */
/* 'create_window' - contains platform-specific code for creating a new window         */
/* 'get_platform_type' - returns the 'PLATFORM' enumerated type pointing               */
/*   to the type of the object of the 'platform' class descendant                      */
/* =================================================================================== */

class platform {
    public:
        virtual void create_window() = 0;
        virtual PLATFORM get_platform_type() = 0;
};


/* descendants of the 'platform' class */

class Linux : public platform {
    public:
        void create_window() override {
            glfwInit();
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow
            (WIDTH, HEIGHT, "Game", nullptr, nullptr);
        }
        
        PLATFORM get_platform_type() override {
            return PLATFORM::LINUX;
        }

    private:
        GLFWwindow* window;
        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;
};

class linux_wayland : public platform {
    public:
        void create_window() override {
            // Initialize Wayland connection
            wl_display* display = wl_display_connect(nullptr);
            if (!display) {
                //std::cout << "Failed to connect to Wayland display" << std::endl;
                //return 1;
            }

            // Initialize Wayland registry
            wl_registry* registry = wl_display_get_registry(display);
            wl_registry_add_listener(registry, /*&wl_registry_listener*/nullptr, nullptr);
            wl_display_dispatch(display);

            // Create the Wayland window
            wl_compositor* compositor = static_cast<wl_compositor*>(wl_registry_bind(registry, 1, &wl_compositor_interface, 1));
            wl_surface* surface = wl_compositor_create_surface(compositor);
            wl_shell_surface* shell_surface = wl_shell_get_shell_surface
                (static_cast<wl_shell*>(wl_registry_bind(registry, 3, &wl_shell_interface, 1)), surface);
                
            wl_shell_surface_set_toplevel(shell_surface);
        }

        PLATFORM get_platform_type() override {
            return PLATFORM::LINUX_WAYLAND;
        }
};

class linux_xorg : public platform {
    public:
        void create_window() override {
            // Initialize XCB connection
            xcb_connection_t* connection = xcb_connect(nullptr, nullptr);
            if (xcb_connection_has_error(connection)) {
                //std::cout << "Failed to connect to X server" << std::endl;
                //return 1;
            }

            // Get the first screen
            xcb_screen_t* screen = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;

            // Create the window
            xcb_window_t window = xcb_generate_id(connection);
            xcb_create_window(connection, XCB_COPY_FROM_PARENT, window, screen->root,
                0, 0, 500, 500, 0, XCB_WINDOW_CLASS_INPUT_OUTPUT,
                screen->root_visual, 0, nullptr);

            // Show the window
            xcb_map_window(connection, window);
            xcb_flush(connection);
        }
        
        PLATFORM get_platform_type() override {
            return PLATFORM::LINUX_XORG;
        }
};

class Windows : public platform {
    public:
        void create_window() override {

        }

        PLATFORM get_platform_type() override {
            return PLATFORM::WINDOWS;
        }
};


/* ================================================================== */
/* Depending on the type of platform in the build_platform variable,  */
/*  returns a class to work with a platform of the same type          */
/*   along with the 'new' operator                                    */                  
/* ================================================================== */

platform* get_platform() {
    if(build_platform == PLATFORM::LINUX) {
        return new Linux;
    }
    if(build_platform == PLATFORM::WINDOWS) {
        return new Windows;
    }
}