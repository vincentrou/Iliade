/*
 * army.cpp
 *
 *  Created on: 2011-07-21
 *      Author: vincentrou
 */

#include "army.hpp"

Army::Army(){};

Army::~Army(){};

void Army::add_warrior(Warrior& unit)
{
	warriors_.push_back(unit);
}

int Army::get_army_point()
{
	int sum = 0;
	for(std::vector<Warrior>::iterator it = warriors_.begin(); it != warriors_.end(); ++it)
	//for(int it = 0; it < warriors_.size(); ++it)
	{
		sum += it->get_army_point();
		//sum += warriors_[it].get_army_point();
	}
	return sum;
}
