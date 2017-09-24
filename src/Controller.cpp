#include "Controller.h"
#include <cmath>
#include <iostream>
#include <typeinfo>
#include <chrono>
#include <cmath>
#include <limits>

using namespace std;
using namespace std::chrono;

namespace mrsd
{
float delayTime = 0.0;
float gameTime = 0.0;
float prevTime = 0.0;
float loopIdx = 0.0;
int intMax = std::numeric_limits<int>::max();

int * dangerArray;
int explosionSize;
int width;

void Controller::control(const mrsd::Game& g, float t)
{
	// initialization
	if (loopIdx == 0.0) {
		width = g.getWidth();
		explosionSize = g.explosionSize;
		dangerArray = new int[width + 1];
		for (int i = 0; i < (width + 1); i ++) {
			dangerArray[i] = 0;
		}
		loopIdx++;
	}

	gameTime = g.getGameTime();

	// get the list of projectiles, each time will have list with different size

	if ((gameTime - prevTime) > delayTime) {
		prevTime = gameTime;
		// cout << "-------------------------" << gameTime << endl;
		const std::list<Projectile>& projectiles = g.getProjectiles();
		// cout << "######################################" << projectiles.size() << endl;
		for (std::list<Projectile>::const_iterator it = projectiles.begin();
		        it != projectiles.end(); it++)
		{
			Projectile p = *it;

			// cout << "Proj at Y:" << p.y << endl;
			if (p.y <= 10.0) {
				Prediction pred = trackProjectile(p, g);
				determineSafeSpots(pred, g);
				// cout << "Proj is going to explode at X:" << p.x << endl;
				// cout << "Predict X at: " << pred.x << endl;
			}
		}

		removeDangerMarkers(g);

		for (int i = 0; i < width; i++) {
			// cout << "size"  <<sizeof(dangerArray)/sizeof(int) << endl;
			cout << dangerArray[i];
			// cout << "testing" << endl;
		}
		cout << "" << endl;

		//control players
		const std::vector<Player*>& players = g.getPlayers();

		// cout << "players x? " << players.size() << endl;
		// for (std::vector<Player*>::const_iterator it = players.begin();
		//         it != players.end(); it++)
		// {
		// 	Player& player = *(*it);
		// 	cout << "player x at : " << player.x << endl;
		// }

		int minDist = intMax;
		int nearSafeIdx = 0;
		if (players.size() > 0) {
			if (players.size() > 1) {
				cout << "2 players" << endl;
				Player* pl2 = players[1];
				(*pl2).x = (3 * width) / 4;
			} else {
				cout << "1 players" << endl;
				// we get the players[0] pointer and give the original adreess to Player* pl1
				Player* pl1 = players[0];
				// we set the original adress's value to width/4
				// (*pl1).x = width / 4;

				// *player[0] return the original address, however when assign to Player pl1
				// , it called the copy constructor which assign the copy version to the pl1
				// you won't be able to change original address's player's x value
				// Player pl1 = *players[0];
				// pl1.x = width / 4;

				if (dangerArray[(int)((*pl1).x)] == 1) {
					for (int i = 0; i < width ; i++) {
						if (dangerArray[i] == 0 && abs(i - (int)((*pl1).x)) < minDist) {
							minDist = abs(i - (int)((*pl1).x));
							nearSafeIdx = i;
						}
					}
					(*pl1).x = (float)nearSafeIdx;
				}
			}
		}



		// for (std::vector<Player*>::iterator it = players.begin(); it != players.end();)
		// {
		// 	cout << "testing" << endl;
		// }
	}

}

void Controller::createPlayer(Game& g)
{

	if (p == 0)
	{
		p = new Player();
		p->dead = true;
	}
	if (p->dead)
	{
		p->dead = false;
		p->x = g.getWidth() / 2;
		g.newPlayer(p);
	}
	// else{
	// 	p->x = g.getWidth()/ 4;
	// }





}

Prediction Controller::trackProjectile(const Projectile& p, const Game& g)
{
	Prediction pred;
	float gravity = g.getGravity();
	// calculate the time from the start of proj to now
	float pTime = abs((p.x - 100) / p.vx);
	// calculate the total flight time using newtonian law
	float totalTime = abs(2 * p.vy / gravity);
	float leftTime = totalTime - pTime;
	float dangerX = 100 + totalTime * p.vx;
	pred.x = dangerX;
	pred.t = leftTime;
	//cout << "##################################" << endl;
	return pred;
}

void Controller::determineSafeSpots(Prediction pred, const Game& g)
{
	// int w = g.getWidth();
	float upperBound;
	float lowerBound;
	float uncertainty = 3.0;
	// if dangerArray[i] ==0 (safe), ==1(danger)
	// put danger marker on danger array base on the prediction
	if ((pred.x + explosionSize + uncertainty) >= width) {
		upperBound = width;
	} else if ((pred.x - explosionSize - uncertainty) < 0.0) {
		lowerBound = 0.0;
	} else {
		lowerBound = (pred.x - explosionSize - uncertainty);
		upperBound = (pred.x + explosionSize + uncertainty);
	}

	// cout << "upperBound is : " << upperBound << endl;
	// cout << "lowerBound is : " << lowerBound << endl;

	for (int i = std::ceil(lowerBound);
	        i < std::floor(upperBound); ++i) {
		// cout << "upperBound is : " << upperBound << endl;
		dangerArray[i] = 1;
	}



}

int Controller::pickSafeSpot(const Game& g)
{

	return 0;
}

void Controller::removeDangerMarkers(const mrsd::Game& g) {
	// change the dangerArray's 1 to 0 after the explosions;
	const std::list<Explosion>& explosions = g.getExplosions();
	// cout << "Explosion size: " << explosions.size() << endl;

	float upperBound;
	float lowerBound;
	float uncertainty = 2.0;

	for (std::list<Explosion>::const_iterator it = explosions.begin();
	        it != explosions.end(); it ++) {
		Explosion ex = *it;
		// cout << "The explosion x is :" << ex.x << endl;
		if ((ex.x + explosionSize + uncertainty) >= width) {
			upperBound = width;
		} else if ((ex.x - explosionSize - uncertainty) < 0.0) {
			lowerBound = 0.0;
		} else {
			lowerBound = (ex.x - explosionSize - uncertainty);
			upperBound = (ex.x + explosionSize + uncertainty);
		}

		for (int i = std::ceil(lowerBound);
		        i < std::floor(upperBound); i++) {
			dangerArray[i] = 0;
		}

	}

}

}
