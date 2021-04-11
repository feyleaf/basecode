//SFML Ludum Dare Basecode
//By Benjamin C. Watt (feyleaf.com)
//April 11, 2021
#include "globals.h"
int main()
{
	unsigned int width = 600;
	sf::RenderWindow window(sf::VideoMode(width, 9*width/16), "SFML works!");
	sf::CircleShape cursor(4.0f);
	sf::CircleShape shape(100.f);
	cursor.setFillColor(sf::Color::Blue);
	shape.setFillColor(sf::Color::Cyan);

	//sf::Image _image;
	sf::Texture _tex;
	//_image.loadFromFile("images/greenguy.png");
	_tex.loadFromFile("images/greenguy.png");
	_tex.setSmooth(false);
	sf::Sprite _sprite;
	_sprite.setTexture(_tex);
	_sprite.setColor(sf::Color::White);
	_sprite.setPosition(sf::Vector2f(60.0f, 60.0f));

	sf::SoundBuffer sfxBuff;
	sfxBuff.loadFromFile("sounds/coin.wav");
	sf::Sound sfxSound;
	sfxSound.setBuffer(sfxBuff);

	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		window.draw(shape);
		window.draw(_sprite);
		window.draw(cursor);
		window.display();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
				sfxSound.play();
			if (event.type == sf::Event::MouseMoved)
			{
				sf::Mouse _mouse;
				sf::View view = window.getView();
				sf::View dview = window.getDefaultView();
				sf::Vector2i _ipos = _mouse.getPosition(window);
				sf::IntRect rect = window.getViewport(view);
				
				sf::Vector2f _pos = sf::Vector2f(_ipos);
				cursor.setPosition(_pos);
			}
			window.draw(shape);
			window.draw(_sprite);
			window.draw(cursor);
			window.display();
		}
	}
	return 0;
}