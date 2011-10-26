/*
 * Player.h
 *
 *  Created on: 2011-08-11
 *      Author: vincentrou
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "army.hpp"

class Player {
public:
	Player();
	virtual ~Player();

	/**
	 * @function victory_point
	 * @brief return victory point of the player
	 */
	int victory_point() const {
		return (boat_victory_point_+city_victory_point_+2*(have_poseidon_+have_athena_)+have_agamemnon_+5*have_helen_);
	}
	int boat_victory_point() const{ return boat_victory_point_;}
	int city_victory_point() const{ return city_victory_point_;}
	bool poseidon() const {return have_poseidon_;}
	void poseidon(const bool have) {have_poseidon_ = have;}
	bool athena() const{return have_athena_;}
	void athena(const bool have) {have_athena_ = have;}
	void helen(const bool have) {have_helen_ = have;}

	enum POINT_TYPE{BOAT, CITY, HELEN};
	void add_victory_point(const int point, const POINT_TYPE type);

private:
	Army army_;
	int boat_victory_point_;
	int city_victory_point_;
	bool have_poseidon_;
	bool have_athena_;
	bool have_agamemnon_;
	bool have_helen_;
	bool player_turn_;
};

#endif /* PLAYER_H_ */
