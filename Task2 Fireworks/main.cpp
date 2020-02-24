#include <SFML/Graphics.hpp>
#include "salut.hpp"
int main()
{
	std::unique_ptr<sf::RenderWindow> window_ptr(new sf::RenderWindow(sf::VideoMode(1500, 900), "Salut!"));
	GameWindow window(std::move(window_ptr));
	const int n = 5;
	float len = dis_width / n;
	std::vector<Rocket> rockets{n};
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("rocket.png");
	std::vector<sf::Color> colors = { sf::Color::White,sf::Color::Cyan,sf::Color::Red,sf::Color::Green,sf::Color::Magenta };
	for (int i = 0; i < rockets.size(); i++)
	{
		rockets[i].a += rockets[i].a *i;
		rockets[i].sprite->setTexture(*texture);
		rockets[i].sprite->setPosition(len*i- rockets[i].sprite->getTextureRect().width / 2+75, dis_height - rockets[i].sprite->getTextureRect().height);
		for (auto it = rockets[i].debris.begin();it!=rockets[i].debris.end();++it)
		{
			it->sprite->setColor(colors[i]);
		}
		rockets[i].sprite->setColor(colors[i]);
	}
	
	sf::Clock clock;
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {};
		while (window.window->isOpen()) {
			float time = clock.getElapsedTime().asSeconds();
			sf::Event event;
			while (window.window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.window->close();
			}
			
			window.window->clear();

			for (size_t i = 0; i < rockets.size(); i++) {
				rockets[i].update(time);
				if (!rockets[i].exploded) window.draw_rocket(rockets[i]);
				else {
					window.draw_debris(rockets[i].debris);
				}
				continue;
			}


			window.window->display();


		}
	
}