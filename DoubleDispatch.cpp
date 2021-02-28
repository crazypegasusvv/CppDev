#include <iostream>
// source taken from wikipedia
class SpaceShip {};
class ApolloSpacecraft : public SpaceShip {};

class Asteroid {
public:
  virtual void CollideWith(SpaceShip&) {
    std::cout << "Asteroid hit a SpaceShip\n";
  }
  virtual void CollideWith(ApolloSpacecraft&) {
    std::cout << "Asteroid hit an ApolloSpacecraft\n";
  }
};

class ExplodingAsteroid : public Asteroid {
public:
  void CollideWith(SpaceShip&) override {
    std::cout << "ExplodingAsteroid hit a SpaceShip\n";
  }
  void CollideWith(ApolloSpacecraft&) override {
    std::cout << "ExplodingAsteroid hit an ApolloSpacecraft\n";
  }
};

int main()
{
	Asteroid theAsteroid;
	SpaceShip theSpaceShip;
	ApolloSpacecraft theApolloSpacecraft;
	theAsteroid.CollideWith(theSpaceShip); 
	theAsteroid.CollideWith(theApolloSpacecraft);
	std::cout << std::endl;
	ExplodingAsteroid theExplodingAsteroid;
	theExplodingAsteroid.CollideWith(theSpaceShip); 
	theExplodingAsteroid.CollideWith(theApolloSpacecraft);
	std::cout<< std::endl;
	Asteroid& theAsteroidReference = theExplodingAsteroid;
	theAsteroidReference.CollideWith(theSpaceShip); 
	theAsteroidReference.CollideWith(theApolloSpacecraft);
	std::cout << std::endl;
	SpaceShip& theSpaceShipReference = theApolloSpacecraft;
	theAsteroid.CollideWith(theSpaceShipReference);
	theAsteroidReference.CollideWith(theSpaceShipReference);
	return 0;
}
