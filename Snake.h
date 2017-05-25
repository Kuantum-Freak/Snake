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
	DIR_NORTH, ///< North Direction
	DIR_EAST,  ///< East Direction
	DIR_SOUTH, ///< South Direction
	DIR_WEST   ///< West Direction
};

/// @brief The Snake in the game
/// Uses two classes nested inside of each other, could make it one big class
/// but wanted to see how it would work. It worked better than I expected
class Snake {
public:
	Snake();
	
	void move(); ///< Moves the Snake forward by one block
	void eat();  ///< Increments the size of the snake by one
	
	/// @brief Turns the snake in a direction
	/// @param The direction to turn
	void turn(Direction dir);
	
	/// @brief Returns the location of the head
	/// @return Coordinate The location of the head
	Coordinate head();
	
	void render(); ///< Renders the Snake on the Screen
	
private:
	/// @brief The main body of the snake
	class SnakeBody {
	public:
		/// @brief A piece of the body
		/// @todo Shorten this to just a Coordinate and no direction
		struct Segment {
			Coordinate c;
			Direction dir; /// @todo remove this as it is not needed
		};
	
		SnakeBody();
		~SnakeBody();
		
		/// @brief Add a segment to the front of the snake
		/// @param The direction to add it in
		void push(Direction dir);
		
		void pop(); ///< Remove a segment from the end of the snake
		
		/// @brief Get the size of the Snake
		/// @return size_t The size of the snake
		size_t size();
		
		/// @brief Gets a spefic segment of the snake
		/// @param idx The index of the snake to get
		/// @return Segment* The Segment at given index
		Segment* operator[](size_t idx);
		
	private:		
		// deque b.c we will need to change the tail node often
		std::deque<Segment*> body; ///< The body of the snake
		
	} snake;
	
	Direction currDir; ///< The current direction of the snake
};