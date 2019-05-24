OBJS = object/Functions.o object/GameMap.o object/GameObject.o object/main.o object/MapRenderer.o object/Menu.o object/MenuButton.o object/ProductionTile.o object/StringMap.o object/Tile.o
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Wc++11-extensions

LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

LDFLAGS = -L "SFML/lib"
CPPFLAGS = -I "SFML/include"

game: $(OBJS)
	$(CXX) $(CXXFLAGS) -o game $(OBJS) $(LDLIBS) $(LDFLAGS)

object/main.o: src/main.cpp
	g++ $(CXXFLAGS) -c src/main.cpp -o object/main.o $(CPPFLAGS)

object/Functions.o: src/Functions.cpp include/Functions.hpp
	g++ $(CXXFLAGS) -c src/Functions.cpp -o object/Functions.o $(CPPFLAGS)

object/GameMap.o: src/GameMap.cpp include/GameMap.h
	g++ $(CXXFLAGS) -c src/GameMap.cpp -o object/GameMap.o $(CPPFLAGS)

object/GameObject.o: src/GameObject.cpp include/GameObject.h
	g++ $(CXXFLAGS) -c src/GameObject.cpp -o object/GameObject.o $(CPPFLAGS)

object/MapRenderer.o: src/MapRenderer.cpp include/MapRenderer.h
	g++ $(CXXFLAGS) -c src/MapRenderer.cpp -o object/MapRenderer.o $(CPPFLAGS)

object/Menu.o: src/Menu.cpp include/Menu.h
	g++ $(CXXFLAGS) -c src/Menu.cpp -o object/Menu.o $(CPPFLAGS)

object/GameState.o: src/GameState.cpp include/GameState.h
	g++ $(CXXFLAGS) -c src/GameState.cpp -o object/GameState.o $(CPPFLAGS)

object/MenuButton.o: src/MenuButton.cpp include/MenuButton.h
	g++ $(CXXFLAGS) -c src/MenuButton.cpp -o object/MenuButton.o $(CPPFLAGS)

object/ProductionTile.o: src/ProductionTile.cpp include/ProductionTile.h
	g++ $(CXXFLAGS) -c src/ProductionTile.cpp -o object/ProductionTile.o $(CPPFLAGS)

object/StringMap.o: src/StringMap.cpp include/StringMap.h
	g++ $(CXXFLAGS) -c src/StringMap.cpp -o object/StringMap.o $(CPPFLAGS)

object/Tile.o: src/Tile.cpp include/Tile.h
	g++ $(CXXFLAGS) -c src/Tile.cpp -o object/Tile.o $(CPPFLAGS)
