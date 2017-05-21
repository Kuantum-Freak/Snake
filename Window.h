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

struct Window {
	Window();
	~Window();
	
	void clear();
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	const int SCRN_H = 680;
	const int SCRN_W = 420;
	
};