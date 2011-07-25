/*
 * army.hpp
 *
 *  Created on: 2011-07-21
 *      Author: vincentrou
 */

#ifndef ARMY_HPP_
#define ARMY_HPP_

#include <vector>
#include "warrior.hpp"

class Army{
public:
	Army();
	~Army();

	void add_warrior(Warrior& unit);
	int get_army_point();

private:
	std::vector<Warrior> warriors_;
};
#endif /* ARMY_HPP_ */
