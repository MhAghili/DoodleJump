#include"class.hpp"
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
     void Doodle::update1(Window*window) {

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
	void Doodle::update2(Window*window) {

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
	void Doodle::up() {
		while (counter<0) {
			y = y + 5;
			counter = counter - 1;
			//delay(10);
		}
	}
	void Doodle::down() {
		y = y + v;
		counter = counter + 1;
		//delay(10);		
	}
	void Doodle::chang(int h) {
		y = h;
	}
	void Doodle::draw1(Window*window) {

		window->draw_img("assets/assets/main_pictures/right.png", Rectangle(x, window_length - y, Doodle_length, Doodle_width));
	}
	void Doodle::draw2(Window*window) {

		window->draw_img("assets/assets/main_pictures/left.png", Rectangle(x, window_length - y, Doodle_length, Doodle_width));
	}
	void Doodle::flag(int x) {
		statu = x;
	}
	void Doodle::velocity() {
		v = v*(-1);
	}
	void Platform::draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/platform.png", Rectangle(x - 120 / 2, window_length - y - 36, 120, 36));
	}
	Platform::Platform(double w, double h) {
		x = w;
		y = h;
	}
	void mPlatform::draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/mplatform.png", Rectangle(x - 120 / 2, window_length - y - 36, 120, 36));
	}
	mPlatform::mPlatform(double w, double h) {
		x = w;
		y = h;
	}
	void mPlatform::update(Window*window) {

		x = x + v;
		if (x>640)
			v = v*(-1);
		if (x<0)
			v = v*(-1);
	}
	void bPlatform::draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/bplatform.png", Rectangle(x - 120 / 2, window_length - y - 36, 120, 36));
	}
	bPlatform::bPlatform(double w, double h) {
		x = w;
		y = h;
	}
    void Enemy::draw(Window*window) {
		window->draw_img("assets/assets/main_pictures/enemy.png", Rectangle(x - 136 / 2, window_length - y - 184, 136, 184));
	}
	Enemy::Enemy(double w, double h) {
		x = w;
		y = h;
	} 
    void Spring::draw(Window*window) {

		window->draw_img("assets/assets/main_pictures/spring.png", Rectangle(x - 56 / 2, window_length - y - 46, 56, 46));
	}
	Spring::Spring(double w, double h) {
		x = w;
		y = h;
	}



