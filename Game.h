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

struct Window;
class Snake;
class Fruit;
struct Coordinate;

extern const int MAP_W;
extern const int MAP_H;

class Game {
public:
	Game();
	~Game();
	
	void loop();
	
	void renderBlock(Coordinate& block);
	
private:
	Window* window;
	
	Snake* snake;
	Fruit* fruit;
	
	void renderAll();
	bool win();
	
};