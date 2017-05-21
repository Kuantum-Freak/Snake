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
#include <cassert>

#include "main.h"
#include "Snake.h"
#include "Game.h"

Snake::Snake() {
	tail = {MAP_W / 2, MAP_H / 2};
	headDir = DIR_NORTH;
	snake.push_back( new Segment{5, DIR_NORTH} );
}

Snake::~Snake() {
	for(auto s : snake) {
		delete s;
	}
}

void Snake::move() {
	assert(snake[snake.size() - 1]->dir == headDir); // make sure that the direction of the head is correct
	
	snake[snake.size() - 1]->length++; // increment the length of the head segment
	
	snake[0]->length--; // decrement the tail segment
	
	switch(snake[0]->dir) {
		case DIR_NORTH:
			--tail.y;
		break;
		
		case DIR_EAST:
			++tail.x;
		break;
		
		case DIR_SOUTH:
			++tail.y;
		break;
		
		case DIR_WEST:
			--tail.x;
		break;
	}
	
	if(snake[0]->length == 0) { // if there is no tail segment remove it
		delete snake[0];
		snake.erase(snake.begin());
	}
}

void Snake::eat() {
	
}

void Snake::turn(Direction dir) {
	snake.push_back(new Segment{0, dir});
	headDir = dir;
}

Coordinate Snake::getHead() {
	return head;
}

void Snake::render() {
	Coordinate currBlock = tail;
	for(auto s : snake) {
		for(int i = 0; i < s->length; ++i) {
			gSnakeGame->renderBlock(currBlock);
			
			switch(s->dir) {
				case DIR_NORTH:
					--currBlock.y;
				break;
				
				case DIR_EAST:
					++currBlock.x;
				break;
				
				case DIR_SOUTH:
					++currBlock.y;
				break;
				
				case DIR_WEST:
					--currBlock.x;
				break;
			}
		}
	}
	
	head = currBlock; // update head. I know its hacky but it works
}