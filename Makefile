compile:
	g++ -I ./headers main.cpp -o maze -lsfml-graphics -lsfml-window -lsfml-system && echo "Build completed Successfully"

run:
	chmod +x ./run.sh && ./run.sh