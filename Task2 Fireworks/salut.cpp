#include "salut.hpp"
#include <iostream>
#include "math.h"
#include <random>

Rocket::Rocket()
{
	
	sprite = new sf::Sprite();
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("fire.png");
	
	for (int i = 0; i < debris.size(); i++)
	{
		debris[i].sprite->setTexture(*texture);
	}
	
}

void Rocket::update(float time)
{
	if (!exploded) {
		t += time / 100000;
		velocity.y = g * t - 3 * a * log(1 + t) - V0;
		sprite->move(velocity);
		if (sprite->getPosition().y <= 150)
		{
			t = 0;
			exploded = true;
			for (auto x:debris)
			{
				x.set_pos(get_x(), get_y());
				
			}
		};
	}
	else
	{
		t += time / 100000;
		for (auto x: debris)
		{
			if (x.sprite->getPosition().y <= dis_height- x.sprite->getTextureRect().height) {
				
				

				x.current_velocity.y = x.vec.y + 10 * t;
				x.sprite->move(x.current_velocity);
			}
		}
	}
}

Debris::Debris()
{
	//std::random_device rd;  //Will be used to obtain a seed for the random number engine
	//std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	//std::uniform_real_distribution<> dis_x(-1.0, 1.0);
	//sprite = new sf::Sprite();
	//vec.x = dis_x(gen);
	//std::uniform_real_distribution<> dis_y(-sqrt(1 - vec.x * vec.x), sqrt(1 - vec.x * vec.x));
	//vec.y = dis_y(gen);

	//vec.z = sqrt(1 - vec.x * vec.x - vec.y * vec.y);
	//float sgn = dis_x(gen);
	//if (sgn > 0) sgn = 1;
	//else sgn = -1;
	//vec.z = vec.z * sgn;
	////vec.y = dis(gen);
	////vec.z = dis(gen);
	//vec = vec * speed;
	//current_velocity.x = vec.x;
	//current_velocity.y = vec.y;
	//
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis_r(0.01, 1.0);
	std::uniform_real_distribution<> dis_f(0.0, 6.283);
	std::uniform_real_distribution<> dis_tet(0.0, 3.1415);
	sprite = new sf::Sprite();
	//float r = 1.0;
	float r = dis_r(gen);
	float f = dis_f(gen);
	float tet = dis_tet(gen);
	vec.x = r * cos(f) * sin(tet);
	vec.y = r * sin(f) * sin(tet);
	vec.z = r * cos(tet);
	
	vec = vec * speed;
	current_velocity.x = vec.x;
	current_velocity.y = vec.y;
	
}
