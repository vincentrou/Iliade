/*
 * army.cpp
 *
 *  Created on: 2011-07-21
 *      Author: vincentrou
 */

#include "army.hpp"
#include <utilite/UtiLite.h>

Army::Army():
generator_("../data/units.yaml")
{};

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
		//TODO a changer
		sum += it->get_army_point();
		//sum += warriors_[it].get_army_point();
	}
	return sum;
}

void Army::add_n_rand_warrior(int nb)
{
	Warrior rand_unit;
	for(int i=0;i<nb;i++)
	{
		rand_unit = generator_.warrior_generation();
		ULOGGER_DEBUG("Random type name: %s.",rand_unit.get_type_name().c_str());
		this->add_warrior(rand_unit);
	}
	ULOGGER_INFO("Add %d warrior in army",nb);
}

void Army::fill()
{
	this->clear();
	this->add_n_rand_warrior(Army::c_max_warrior);
	ULOGGER_INFO("End filling player army");
}

void Army::clear()
{
	warriors_.clear();
}
