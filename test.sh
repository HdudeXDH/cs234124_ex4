
g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror -DNDEBUG test.cpp Mtmchkin.cpp Cards/*.cpp Players/*.cpp utilities.cpp
valgrind --leak-check=full ./mtmchkin

rm submission.zip
zip -r submission.zip tool/main.cpp Mtmchkin.h Mtmchkin.cpp Cards Players dry.pdf Exception.h
~mtm/public/2122b/ex4/finalCheck submission.zip