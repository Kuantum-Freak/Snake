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
struct Coordinate;

/// @brief A fruit on the screen
class Fruit {
public:
	Fruit();
	
	void render(); ///< Render the Fruit on the Screen
	
	/// @brief Gets the location of Fruit
	/// @return Coordinate The Coordinate of the Fruit
	Coordinate getLocation();
	
private:
	Coordinate loc; ///< The location of the Fruit
	
};