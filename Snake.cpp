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
#include "Snake.h"

Snake::Snake() {
	
}

Snake::~Snake() {
	
}

void Snake::move() {
	std::assert(snake[snake.size() - 1]->dir == headDir); // make sure that the direction of the head is correct
	
	++snake[snake.size() - 1]->length; // increment the length of the head segment
	
	--snake[0]->length; // decrement the tail segment
	if(snake[0]->length == 0) { // if there is no tail segment remove it
		delete snake[0];
		snake.erase(0);
	}
}