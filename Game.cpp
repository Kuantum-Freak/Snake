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
	
	while(!win()) {
		
		renderAll();
		
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					exit(0);
				break;
			}
		}
	}
}

void Game::renderAll() {
	snake->render();
	fruit->render();
}

bool Game::win() {
	return false;
}