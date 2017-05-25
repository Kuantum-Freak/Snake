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

// Forward Declaration
class Game;

/// @brief A Cartesian Coordinate
struct Coordinate {
	int x; ///< x Coordinate
	int y; ///< y Coordinate
	
	/// @brief Checks if 2 Coordinates are the same
	/// @param b The Coordinate to check against
	/// @return bool If the 2 Coordinates are the same
	bool operator==(Coordinate b);
};

extern Game* gSnakeGame; ///< The Snake Game

int main(int argc, char* argv[]); ///< PRGM Entry Point