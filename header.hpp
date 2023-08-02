#ifndef __HEADER_HPP__
#define __HEADER_HPP__

#include "src/rsdl.hpp"
#include <iostream>
#include<vector>
#include<string>
#include<time.h>


using namespace std;
void draw_steady_things(Window*window, vector<Platform> plat, vector<mPlatform> mplat, vector<bPlatform> bplat, vector<Enemy> enm, vector<Spring> spr);

void update(Window*window, Doodle &doodle, vector<Platform> plat, vector<mPlatform> &mplat, vector<bPlatform> bplat, vector<Enemy> enm, vector<Spring> spr);

void draw(Window*window, Doodle &doodle, vector<Platform> plat, vector<mPlatform> &mplat, vector<bPlatform> bplat, vector<Enemy> enm, vector<Spring> spr);
#endif
