compile:
	g++ -I ./headers main.cpp -o maze -lsfml-graphics -lsfml-window -lsfml-system && echo "Build completed Successfully"

run:
	./run.sh