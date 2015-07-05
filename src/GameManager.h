/*
 * GameManager.h
 *
 *  Created on: 2011-12-20
 *      Author: vincentrou
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Player.h"

class GameManager {
public:
	GameManager();
	virtual ~GameManager();
private:
	std::vector<Player> players_;
	int player_turn_;
};

#endif /* GAMEMANAGER_H_ */
