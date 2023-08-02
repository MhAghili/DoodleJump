#include"class.hpp"
#include"header.hpp"
#include "src/rsdl.hpp"
#include <iostream>
#include<vector>
#include<string>
#include<time.h>


using namespace std;

#define window_length 1024
#define WINDOW_width 640
#define Doodle_length 124
#define Doodle_width 120

int main() {
	vector<Platform> plat;
	vector<mPlatform> mplat;
	vector<bPlatform> bplat;
	vector<Enemy> enm;
	vector<Spring> spr;
	int tedad;
	cin >> tedad;
	for (int i = 0; i<tedad; i++) {
		double x;
		double y;
		string name;
		cin >> x >> y >> name;
		if (name == "platform")
			plat.push_back(Platform(x, y));
		if (name == "mplatform")
			mplat.push_back(mPlatform(x, y));
		if (name == "bplatform")
			bplat.push_back(bPlatform(x, y));
		if (name == "enemy")
			enm.push_back(Enemy(x, y));
		if (name == "spring")
			spr.push_back(Spring(x, y));
	}



	Doodle doodle;

	Window *window = new Window(WINDOW_width, window_length, "Doodle jump");
	while (true) {
		update(window, doodle, plat, mplat, bplat, enm, spr);
		draw(window, doodle, plat, mplat, bplat, enm, spr);
		delay(15);
	}
	return 0;
}