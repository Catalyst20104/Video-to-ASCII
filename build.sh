g++ -o a.out main.cpp $(pkg-config --cflags --libs opencv4)

./a.out
