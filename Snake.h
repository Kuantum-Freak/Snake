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
	~Snake();
	
	void move();
	void eat();
	void turn();
	
	void render();
	
private:
	struct Segment {
		int length;
		Direction end;
	};
	
	Direction headDir;
	std::vector<Segment*> snake;

};