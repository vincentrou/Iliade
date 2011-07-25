/*
 * warrior.hpp
 *
 *  Created on: 2011-07-19
 *      Author: vincentrou
 */

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_


#include <vector>

/**
 * @class Warrior warrior.hpp
 * @brief class to describe a warrior in Iliade
 */

class Warrior
{
public:
	Warrior();

	~Warrior();

	int get_id() const;
	void set_id(const int id);
	void set_army_point(const int value);
	int get_army_point();
	bool is_protected();

private:
	int id_;
	int army_point_;
	bool protected_;


};


#endif /* WARRIOR_HPP_ */
