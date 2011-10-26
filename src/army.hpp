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
#include "warrior_cfg.hpp"

class Army{
public:
	Army();
	~Army();

	void add_warrior(Warrior& unit);
	int get_army_point();
	void add_n_rand_warrior(int nb);
	void fill();
	void clear();

	static const int c_max_warrior = 13;
private:
	std::vector<Warrior> warriors_;
	WarriorCfg generator_;
};
#endif /* ARMY_HPP_ */
