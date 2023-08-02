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