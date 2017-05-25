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

#include <deque>

#include "main.h"

enum Direction {
	DIR_NORTH,
	DIR_EAST,
	DIR_SOUTH,
	DIR_WEST
};

class Snake {
public:
	Snake();
	
	void move();
	void eat();
	void turn(Direction dir);
	Coordinate head();
	
	void render();
	
private:
	class SnakeBody {
	public:
		struct Segment {
			Coordinate c;
			Direction dir; /// @todo remove this as it is not needed
		};
	
		SnakeBody();
		~SnakeBody();
		
		void push(Direction dir);
		void pop();
		
		size_t size();
		
		Segment* operator[](size_t idx);
		
	private:		
		std::deque<Segment*> body; // deque b.c we will need to change the tail node often
		
	} snake;
	
	Direction currDir;
};