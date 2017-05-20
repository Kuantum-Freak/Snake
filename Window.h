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

extern const int SCRN_H;
extern const int SCRN_W;

class Window {
public:
	Window();
	~Window();
	
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	void clear();
	
};