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
	currDir = DIR_NORTH;
}

Snake::~Snake() {
	
}

void Snake::move() {
	snake.push(currDir);
	snake.pop();
}

void Snake::eat() {
	snake.push(currDir);
}

void Snake::turn(Direction dir) {
	currDir = dir;
}

Coordinate Snake::head() {
	return snake[snake.size() - 1]->c;
}

void Snake::render() {
	for(size_t i = 0; i < snake.size(); ++i) {
		gSnakeGame->renderBlock(snake[i]->c);
	}
}

Snake::SnakeBody::SnakeBody() {
	Coordinate head = {MAP_W / 2, MAP_H / 2};
	for(int i = 0; i < 4; ++i) {
		body.push_back(new Segment{head, DIR_NORTH});
		head.y++;
	}
}

Snake::SnakeBody::~SnakeBody() {
	for(auto s : body)
		delete s;
}

void Snake::SnakeBody::push(Direction dir) {
	Coordinate next = body[body.size() - 1]->c;
	
	switch(dir) {
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
	
	body.push_back( new Segment{next, dir} );
}

void Snake::SnakeBody::pop() {
	delete body[0];
	body.pop_front();
}

size_t Snake::SnakeBody::size() {
	return body.size();
}

Snake::SnakeBody::Segment* Snake::SnakeBody::operator[](size_t idx) {
	return body[idx];
}