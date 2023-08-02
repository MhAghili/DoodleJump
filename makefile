doodleJump.out: main.o rsdl.o class.o header.o 
	g++ -std=c++11 main.o rsdl.o class.o header.o -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer -o doodle.out
main.o: main.cpp rsdl.o header.o class.o
	g++ -std=c++11 -c  main.cpp src/rsdl.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
header.o: class.hpp header.hpp header.cpp 
	g++  -std=c++11 -c  header.cpp src/rsdl.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
claas.o: class.hpp header.hpp class.cpp 
	g++  -std=c++11 -c  class.cpp src/rsdl.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
rsdl.o: src/rsdl.cpp src/rsdl.hpp
	g++  -std=c++11 -c src/rsdl.cpp -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer


clean:
	rm -f doodleJump.out *.o