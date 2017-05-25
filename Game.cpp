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
#include "Game.h"
#include "Window.h"
#include "Snake.h"
#include "Fruit.h"

static const int FPS = 45;
const int MAP_W = 30;
const int MAP_H = 30;

Game::Game() {
	// create our window, snake and a randomly placed fruit
	window = new Window();
	snake = new Snake();
	fruit = new Fruit();
}

Game::~Game() {
	// Delete all of the vars
	delete window;
	delete snake;
	delete fruit;
}

void Game::loop() {
	SDL_Event event;
	uint32_t FPS_Timer;
	unsigned long long moveCounter = 0;
	
	while(!win()) {
		FPS_Timer = SDL_GetTicks(); // Get the time at the start of the frame
		moveCounter++;
		
		if(moveCounter % 7 == 0) // only move the snake every 7th frame
			snake->move();
		
		renderAll();
		
		// if the snake's head is in the same location as a fruit
		// then make our snake longer and create a new fruit
		if(snake->head() == fruit->getLocation()) {
			snake->eat();
			delete fruit;
			fruit = new Fruit();
		}
		
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					exit(0);
				break;
				
				case SDL_KEYUP: {
					switch(event.key.keysym.sym) { // turn the snake accordingly
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
					} // KEY UP SWITCH END
				} break;
			} // EVENT SWITCH END
		} // EVENT LOOP END
		
		int frameTicks = SDL_GetTicks() - FPS_Timer; // Get time it took to render frame
		if( frameTicks < 1000/FPS ) // If this was too big
			SDL_Delay( 1000/FPS - frameTicks ); // Wait remainging time
	} // RENDER LOOP END
}

void Game::renderBlock(Coordinate& block) {
	SDL_SetRenderDrawColor(window->renderer, 0xFF, 0xFF, 0xFF, 0xFF); // WHITE
	
	SDL_Rect renBlock = { // location of the block to render
		block.x * (SCRN_W/MAP_W), 
		block.y * (SCRN_H/MAP_H),
		SCRN_W/MAP_W, 
		SCRN_H/MAP_H
	};
	
	SDL_RenderFillRect(window->renderer, &renBlock); // render it
}

void Game::renderAll() {
	window->clear();
	
	snake->render();
	fruit->render();
	
	SDL_RenderPresent(window->renderer);
}

bool Game::win() { /// @todo depreciated, need to remove
	return false;
}

bool Game::inMap(const Coordinate& c) {
	return    c.x >= 0 
		   && c.x < MAP_W
		   && c.y >= 0
		   && c.y < MAP_H;
}