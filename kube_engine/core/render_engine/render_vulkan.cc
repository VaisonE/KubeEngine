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
#include "core/platform.cc"

#include <iostream>

int render() {
    // Initialize XCB connection
    xcb_connection_t* connection = xcb_connect(nullptr, nullptr);
    if (xcb_connection_has_error(connection)) {
        std::cout << "Failed to connect to X server" << std::endl;
        return 1;
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

