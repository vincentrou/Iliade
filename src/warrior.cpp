/*
 * warrior.cpp
 *
 *  Created on: 2011-07-19
 *      Author: vincentrou
 */

#include "warrior.hpp"

#include "unit_id.hpp"

Warrior::Warrior(void):army_point_(0)
{

	id_ = n_unit::id_manager::instance().next_id();
}

Warrior::~Warrior(void)
{
}

int Warrior::get_id(void) const
{
	return id_;
}
void Warrior::set_id(const int id)
{
	id_ = id;
}

void Warrior::set_army_point(const int value)
{
	army_point_ = value;
}

int Warrior::get_army_point()
{
	return army_point_;
}

bool Warrior::is_protected()
{
	return protected_;
}
