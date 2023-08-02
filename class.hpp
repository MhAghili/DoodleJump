#ifndef __CLASS_HPP__
#define __CLASS_HPP__

#include "src/rsdl.hpp"
#include <iostream>
#include<vector>



using namespace std;

#define window_length 1024
#define WINDOW_width 640
#define Doodle_length 124
#define Doodle_width 120
#define window_length 1024
#define WINDOW_width 640
#define Doodle_length 124
#define Doodle_width 120

class Doodle {
public:

	void update1(Window*window);
	void update2(Window*window);
	void up();
	void down() ;
	void chang(int h);
        int count() { return counter; }
	void draw1(Window*window) ;
	void draw2(Window*window);
	void flag(int x) ;
	int flags() { return statu; }
	int get_x() { return x; }
        int get_y() { return y; }
        void velocity();
private:
	double x = WINDOW_width / 2 - Doodle_length / 2;
	double y = Doodle_width;
	int counter = 0;
	double v = 5;
	int statu = 1;
	
};
class Platform {
public:
	void draw(Window*window);
	Platform(double w, double h);
	int get_x() { return x; }
        int get_y() { return y; }

private:
	double x;
	double y;

};

class mPlatform {
public:
	void draw(Window*window) ;
	mPlatform(double w, double h);
	void update(Window*window) ;
	int get_x() { return x; }
        int get_y() { return y; }



private:
	double x;
	double y;
	double v = 3;

};

class bPlatform {
public:
	void draw(Window*window) ;
	bPlatform(double w, double h);
	int get_x() { return x; }
        int get_y() { return y; }

private:
	double x;
	double y;

};
class Enemy {
public:
	void draw(Window*window) ;
	Enemy(double w, double h);
	int get_x() { return x; }
        int get_y() { return y; }

private:
	double x;
	double y;

};
class Spring {
public:
	void draw(Window*window);
	Spring(double w, double h) ;
	int get_x() { return x; }
        int get_y() { return y; }
private:
	int x;
	int y;


};
#endif
