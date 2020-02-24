#pragma once
#include <SFML/Graphics.hpp>
static const int dis_width = 1500;
static const int dis_height = 900;


class Debris
{
public:
	Debris();
	void update(float time);
	sf::Vector3f vec{ 0,0,0 };
	sf::Vector2f current_velocity{ 0,0 };
	const float speed = 0.2;

	sf::Sprite* sprite;
	void set_pos(float _x, float _y) { sprite->setPosition(_x, _y); }
	~Debris()=default;
};

class Rocket
{
public:
	Rocket();
	void update(float time);	  
    float get_x() { return sprite->getPosition().x; };
	float get_y() { return sprite->getPosition().y; };

	bool exploded = false;
	float t = 0;
	float a = 20.0;
	const float g = 10.0;
	const float V0 = 0.1;
	sf::Vector2f velocity {0,0};

	std::vector<Debris> debris{ 1000 };
	//sf::Vector3f gravity{ 0,-10.0,0};


	//sf::Vector3f react_force{ 0,a,0 };
	


	sf::Sprite* sprite;
	~Rocket() = default;

};

class GameWindow
{
public:
	GameWindow(std::unique_ptr<sf::RenderWindow>&& _window) { window = std::move(_window);}

	void draw_rocket(Rocket& obj) { window->draw(*obj.sprite);};
	void draw_debris(std::vector<Debris>& debris)
	{
		for (auto x: debris)
		{
			window->draw(*x.sprite);
		}
	}


	std::unique_ptr<sf::RenderWindow> window;
	sf::Vector2u size;							  //размер окна


};

