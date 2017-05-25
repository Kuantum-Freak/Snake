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

// Forward Declarations
struct Window;
class Snake;
class Fruit;
struct Coordinate;

extern const int MAP_W; ///< The Map Width
extern const int MAP_H; ///< The Map Height

/// @brief Stores the information on our game and various functions utilized in the game
class Game {
public:
	Game();
	~Game();
	
	void loop(); ///< The main game loop
	
	/// @brief Renders a white block on the screen
	/// @param block The cordinate of the block to render
	void renderBlock(Coordinate& block);
	
	/// @brief Checks if the supplied Coordinate is in the map
	/// @return bool If the Coordinate is in the map or not
	static bool inMap(const Coordinate& c);
	
private:
	Window* window; ///< The Window for our game
	
	Snake* snake; ///< The Snake
	Fruit* fruit; ///< The Fruit
	
	void renderAll(); ///< Renders all the items on the screen
	bool win(); ///< DEPRECIATED
	
};