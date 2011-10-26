/*
 * Player.cpp
 *
 *  Created on: 2011-08-11
 *      Author: vincentrou
 */

#include "Player.h"
#include <utilite/UtiLite.h>

Player::Player() {
	// TODO Auto-generated constructor stub
	//TODO initiate army
	army_.fill();

}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::add_victory_point(const int point, const Player::POINT_TYPE type)
{
	if(type == Player::BOAT)
		boat_victory_point_ += point;
	else if(type == Player::CITY)
		city_victory_point_ += point;
	else if(type == Player::HELEN)
		have_helen_ = true;
	else
		ULOGGER_WARN("Unknown point type");
}
