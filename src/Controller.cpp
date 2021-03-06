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
float explosionTime;
float timestep;

void Controller::control(const mrsd::Game& g, float t)
{
	// initialization
	if (loopIdx == 0.0) {
		width = g.getWidth();
		explosionTime = g.explosionTime;
		explosionSize = g.explosionSize;
		timestep = g.getTimeStep();
		dangerArray = new int[width + 1];
		for (int i = 0; i < (width + 1); i ++) {
			dangerArray[i] = 0;
		}
		loopIdx++;
	}

	gameTime = g.getGameTime();

	// get the list of projectiles, each time will have list with different size
	// if ((gameTime - prevTime) > delayTime) {
	prevTime = gameTime;
	// cout << "-------------------------" << gameTime << endl;
	const std::list<Projectile>& projectiles = g.getProjectiles();
	// cout << "######################################" << projectiles.size() << endl;
	for (std::list<Projectile>::const_iterator it = projectiles.begin();
	        it != projectiles.end(); it++)
	{
		Projectile p = *it;
		if (p.y <= 20.0) {
			Prediction pred = trackProjectile(p, g);
			determineSafeSpots(pred, g);
		}
	}

	int minDist = intMax;
	int nearSafeIdx = 0;

	if (p == 0) {
		cout << "px not exist" << endl;
	} else if (p->dead) {
		cout << "px died" << endl;
		for (int i = 0; i < width; i++) {
			cout << dangerArray[i];
		}
		// cout << "" << endl;
		// cout << "px  location is at " <<  (p->x) << endl;
		// cout << "dangerArray px  location is : " <<  dangerArray[(int)(p->x)] << endl;
		// cin.get();

	} else {
		for (int i = 2; i < (width - 2) ; i++) {
			if (dangerArray[i - 2] == 0 && dangerArray[i - 1] == 0 && dangerArray[i] == 0
			        && dangerArray[i + 1] == 0 && dangerArray[i + 2] == 0 && abs(i - (int)(p->x)) < minDist) {
				minDist = abs(i - (int)(p->x));
				nearSafeIdx = i;
			}
		}
		(p->x) = (float)nearSafeIdx;
	}



	int totalDangerNum = 0;
	for (int i = 0; i < width; i++) {
		// cout << "size"  <<sizeof(dangerArray)/sizeof(int) << endl;
		// cout << dangerArray[i];
		if (dangerArray[i] == 1) {
			totalDangerNum++;
		}

		if (totalDangerNum > (9 * width / 10)) {
			cout << "Almost dangers" << endl;
			// cin.get();
		}
	}

	cout << "" << endl;
	removeDangerMarkers(g);

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
	// cout << "vx : : " << p.vx << endl;
	// cout << "total time : " << totalTime << endl;
	// cout << "danger X : " << dangerX << endl;
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
	float uncertainty = 4.0;
	// if dangerArray[i] ==0 (safe), ==1(danger)
	// put danger marker on danger array base on the prediction
	if ((pred.x + explosionSize + uncertainty) >= width || (pred.x - explosionSize - uncertainty) >= width) {
		upperBound = width;
		lowerBound = width;
	} else if ((pred.x - explosionSize - uncertainty) < 0.0 || (pred.x + explosionSize + uncertainty) < 0.0) {
		upperBound = 0.0;
		lowerBound = 0.0;
	} else {
		lowerBound = (pred.x - explosionSize - uncertainty);
		upperBound = (pred.x + explosionSize + uncertainty);

	}

	// cout << "upperBound is : " << upperBound << endl;
	// cout << "lowerBound is : " << lowerBound << endl;

	for (int i = std::ceil(lowerBound);
	        i < std::floor(upperBound); ++i) {
		dangerArray[i] = 1;
	}
	// cout << "Pred X is : " << pred.x << endl;
	// cout << "upperBound is : " << upperBound << endl;
	// cout << "lowerBound is : " << lowerBound << endl;
}

int Controller::pickSafeSpot(const Game& g)
{

	return 0;
}

void Controller::removeDangerMarkers(const mrsd::Game& g) {
	// change the dangerArray's 1 to 0 after the explosions;
	const std::list<Explosion>& explosions = g.getExplosions();

	float upperBound;
	float lowerBound;
	float uncertainty = 2.0;

	for (std::list<Explosion>::const_iterator it = explosions.begin();
	        it != explosions.end(); it ++) {
		Explosion ex = *it;

		if ((ex.x + explosionSize + uncertainty) >= width) {
			upperBound = width;
		} else if ((ex.x - explosionSize - uncertainty) < 0.0) {
			lowerBound = 0.0;
		} else {
			lowerBound = (ex.x - explosionSize - uncertainty);
			upperBound = (ex.x + explosionSize + uncertainty);
		}
		const float t = timestep;
		ex.time += t;
		if (ex.time > explosionTime) {

			for (int i = std::ceil(lowerBound);
			        i < std::floor(upperBound); i++) {
				dangerArray[i] = 0;
			}
		}
	}

}

}

