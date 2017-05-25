/* 
 * Copyright (c) 2017 The Gupta Empire - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Aryan Gupta <me@theguptaempire.net>
 * 
 * =============================================================================
 * @author 			Aryan Gupta
 * @project 		
 * @title 			
 * @date			(YYYY-MM-DD)
 * @fversion		1.0.0
 * @description 	
 * =============================================================================
 */

#pragma once

#include <SDL.h>

extern const int SCRN_H; ///< The Window Height
extern const int SCRN_W; ///< The Window Width

/// @brief A Window struct to hold basic Window information
struct Window {
	Window();
	~Window();
	
	void clear(); ///< Clears out the Window contents
	
	static void initSDL(); ///< initializes SDL library 
	
	SDL_Window* window;     ///< Tha main Window
	SDL_Renderer* renderer; ///< The renderer for our Window
	
};