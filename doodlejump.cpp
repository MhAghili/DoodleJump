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

class Doodle {
public:

	void update1(Window*window) {

		//y += 1;
		x += 11;
		if (x>WINDOW_width) {
			x = x - WINDOW_width - Doodle_width;
		}
		if (y>window_length) {
			y = y - window_length;
		}
		if (y<0) {
			y = y + window_length;
		}


	}
	void update2(Window*window) {

		//y += 1;
		x -= 11;
		if (x<0 - Doodle_width) {
			x = x + WINDOW_width + Doodle_width;
		}
		if (y>window_length) {
			y = y - window_length;
		}
		if (y<0) {
			y = y + window_length;
		}

	}
	void up() {
		while (counter<0) {
			y = y + 5;
			counter = counter - 1;
			//delay(10);
		}
	}
	void down() {
		y = y + v;
		counter = counter + 1;
		//delay(10);		
	}
	void chang(int h) {
		y = h;
	}
	int count() { return counter; }

	void draw1(Window*window) {

		window->draw_img("assets/assets/main_pictures/right.png", Rectangle(x, window_length - y, Doodle_length, Doodle_width));
	}
	void draw2(Window*window) {

		window->draw_img("assets/assets/main_pictures/left.png", Rectangle(x, window_length - y, Doodle_length, Doodle_width));
	}
	void flag(int x) {
		statu = x;
	}
	int flags() {
		return statu;
	}
	int get_x() { return x; }

	int get_y() { return y; }

	void velocity() {
		v = v*(-1);
	}

private:
	double x = WINDOW_width / 2 - Doodle_length / 2;
	double y = Doodle_width;
	int counter = 0;
	double v = 5;
	int statu = 1;

};
class Platform {
public:
	void draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/platform.png", Rectangle(x - 120 / 2, window_length - y - 36, 120, 36));
	}
	Platform(double w, double h) {
		x = w;
		y = h;
	}
	int get_x() { return x; }

	int get_y() { return y; }

private:
	double x;
	double y;

};

class mPlatform {
public:
	void draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/mplatform.png", Rectangle(x - 120 / 2, window_length - y - 36, 120, 36));
	}
	mPlatform(double w, double h) {
		x = w;
		y = h;
	}
	void update(Window*window) {

		x = x + v;
		if (x>640)
			v = v*(-1);
		if (x<0)
			v = v*(-1);
	}
	int get_x() { return x; }

	int get_y() { return y; }



private:
	double x;
	double y;
	double v = 3;

};

class bPlatform {
public:
	void draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/bplatform.png", Rectangle(x - 120 / 2, window_length - y - 36, 120, 36));
	}
	bPlatform(double w, double h) {
		x = w;
		y = h;
	}
	int get_x() { return x; }

	int get_y() { return y; }


private:
	double x;
	double y;

};
class Enemy {
public:
	void draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/enemy.png", Rectangle(x - 136 / 2, window_length - y - 184, 136, 184));
	}
	Enemy(double w, double h) {
		x = w;
		y = h;
	}
	int get_x() { return x; }

	int get_y() { return y; }


private:
	double x;
	double y;

};
class Spring {
public:
	void draw(Window*window) {

		window->draw_img("assets/assets/main_pictures/spring.png", Rectangle(x - 56 / 2, window_length - y - 46, 56, 46));
	}
	Spring(double w, double h) {
		x = w;
		y = h;
	}
	int get_x() { return x; }

	int get_y() { return y; }

private:
	int x;
	int y;


};


void draw_steady_things(Window*window, vector<Platform> plat, vector<mPlatform> mplat, vector<bPlatform> bplat, vector<Enemy> enm, vector<Spring> spr) {
	for (int i = 0; i<plat.size(); i++)
		plat[i].draw(window);

	for (int j = 0; j<mplat.size(); j++)
		mplat[j].draw(window);

	for (int k = 0; k<bplat.size(); k++)
		bplat[k].draw(window);

	for (int d = 0; d<enm.size(); d++)
		enm[d].draw(window);

	for (int s = 0; s<spr.size(); s++)
		spr[s].draw(window);

}




void update(Window*window, Doodle &doodle, vector<Platform> plat, vector<mPlatform> &mplat, vector<bPlatform> bplat, vector<Enemy> enm, vector<Spring> spr) {

	char pressedChar;

	while (window->has_pending_event()) {
		Event event = window->poll_for_event();
		switch (event.get_type()) {
		case Event::EventType::QUIT:
			exit(0);
			break;
		}
		switch (event.get_type()) {
		case Event::KEY_PRESS:
			pressedChar = event.get_pressed_key();
			Event e = window->poll_for_event();
			if (pressedChar == 'a') {
				do
				{
					window->clear();
					window->draw_img("assets/assets/main_pictures/background.png");
					doodle.update2(window);
					doodle.draw2(window);
					for (int i = 0; i<plat.size(); i++) {
						if ((doodle.get_x()>plat[i].get_x() - 50) && (doodle.get_x()<plat[i].get_x() + 40) && (doodle.get_y() == plat[i].get_y()))
							doodle.velocity();
					}
					doodle.down();

					for (int i = 0; i<mplat.size(); i++)
						mplat[i].update(window);
					draw_steady_things(window, plat, mplat, bplat, enm, spr);
					window->update_screen();
					e = window->poll_for_event();
					doodle.flag(2);
					delay(15);
				} while (e.get_type() != Event::KEY_RELEASE);
			}
			if (pressedChar == 'd') {
				do
				{
					window->clear();
					window->draw_img("assets/assets/main_pictures/background.png");
					doodle.update1(window);
					doodle.draw1(window);
					for (int i = 0; i<plat.size(); i++) {
						if ((doodle.get_x()>plat[i].get_x() - 50) && (doodle.get_x()<plat[i].get_x() + 40) && (doodle.get_y() == plat[i].get_y()))
							doodle.velocity();
					}
					doodle.down();
					for (int i = 0; i<mplat.size(); i++)
						mplat[i].update(window);
					draw_steady_things(window, plat, mplat, bplat, enm, spr);
					window->update_screen();
					e = window->poll_for_event();
					doodle.flag(1);
					delay(15);
				} while (e.get_type() != Event::KEY_RELEASE);
			}
		}
	}

	for (int i = 0; i<plat.size(); i++) {
		if ((doodle.get_x()>plat[i].get_x() - 50) && (doodle.get_x()<plat[i].get_x() + 40) && (doodle.get_y() == plat[i].get_y()))
			doodle.velocity();
	}
	doodle.down();
	for (int i = 0; i<mplat.size(); i++)
		mplat[i].update(window);


}



void draw(Window*window, Doodle &doodle, vector<Platform> plat, vector<mPlatform> &mplat, vector<bPlatform> bplat, vector<Enemy> enm, vector<Spring> spr) {
	window->clear();
	window->draw_img("assets/assets/main_pictures/background.png");
	draw_steady_things(window, plat, mplat, bplat, enm, spr);
	if (doodle.flags() == 1) {
		doodle.draw1(window);
	}
	else {
		doodle.draw2(window);
	}
	window->update_screen();
}


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