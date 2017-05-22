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

#include <cstdlib>

#include "main.h"
#include "Fruit.h"
#include "Game.h"

Fruit::Fruit() {
	loc = { rand() % MAP_W, rand() % MAP_H };
}

void Fruit::render() {
	gSnakeGame->renderBlock(loc);
}

Coordinate Fruit::getLocation() {
	return loc;
}