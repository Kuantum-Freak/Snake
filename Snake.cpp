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
	currDir = DIR_NORTH; // set our default direction
}

void Snake::move() {
	snake.push(currDir); // add a block to the front in the direction we are going
	snake.pop(); // remove a block from the tail
}

void Snake::eat() {
	snake.push(currDir); // add a block, but dont remove one, effectively incrementsing size by 1
}

void Snake::turn(Direction dir) {
	currDir = dir;
}

Coordinate Snake::head() {
	return snake[snake.size() - 1]->c; // the end of the snake is the head
}

void Snake::render() {
	for(size_t i = 0; i < snake.size(); ++i)
		gSnakeGame->renderBlock(snake[i]->c); // render each block of the snake
}

Snake::SnakeBody::SnakeBody() {
	Coordinate head = {MAP_W / 2, MAP_H / 2}; // place head at the middle of the map
	
	for(int i = 0; i < 4; ++i) {
		body.push_front(new Segment{head, DIR_NORTH}); // create a snake of size 4
		head.y++;
	}
}

Snake::SnakeBody::~SnakeBody() {
	for(auto s : body)
		delete s; // delete the segments
}

void Snake::SnakeBody::push(Direction dir) {
	Coordinate next = body[body.size() - 1]->c; // get the head location
	
	switch(dir) { // add one to the head depending on the direction
		case DIR_NORTH:
			next.y--;
		break;
		
		case DIR_EAST:
			next.x++;
		break;
		
		case DIR_SOUTH:
			next.y++;
		break;
		
		case DIR_WEST:
			next.x--;
		break;
	}
	/// @todo Check if user is going back towards itself
	
	if(!Game::inMap(next)) // Check if we are edge of map
		exit(0);
		
	for(size_t i = 0; i < body.size(); ++i) // Check if we have eaten ourself or not
		if(body[i]->c == next)
			exit(0);
	
	body.push_back( new Segment{next, dir} ); // add the new segment to our body
}

void Snake::SnakeBody::pop() {
	delete body[0]; // delete the tail
	body.pop_front(); // remove it from the body
}

size_t Snake::SnakeBody::size() {
	return body.size();
}

Snake::SnakeBody::Segment* Snake::SnakeBody::operator[](size_t idx) {
	return body[idx];
}