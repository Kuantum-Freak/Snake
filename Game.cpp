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
#include "info.h"

#include <SDL.h>

#include "main.h"
#include "Window.h"
#include "Snake.h"
#include "Fruit.h"

static const int FPS = 45;

Game::Game() {
	window = new Window();
	snake = new Snake();
	fruit = new Fruit();
}

Game::~Game() {
	delete window;
	delete snake;
	delete fruit;
}

void Game::loop() {
	SDL_Event event;
	uint32_t FPS_Timer;
	
	while(!win()) {
		FPS_Timer = SDL_GetTicks(); // Get the time at the start of the frame
		
		snake->move();
		
		renderAll();
		
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					exit(0);
				break;
				
				case SDL_KEYUP: {
					switch(event.key.keysym.sym) {
						case SDLK_d:
							snake->turn(DIR_EAST);
						break;
						
						case SDLK_a:
							snake->turn(DIR_WEST);
						break;
						
						case SDLK_w:
							snake->turn(DIR_NORTH);
						break;
						
						case SDLK_s:
							snake->turn(DIR_SOUTH);
						break;
					}
				} break;
			}
		}
		
		int frameTicks = SDL_GetTicks() - FPS_Timer; // Get time it took to render frame
		if( frameTicks < 1000/FPS ) // If this was too big
			SDL_Delay( 1000/FPS - frameTicks ); // Wait remainging time
	}
}

void Game::renderAll() {
	snake->render();
	fruit->render();
}

bool Game::win() {
	return false;
}