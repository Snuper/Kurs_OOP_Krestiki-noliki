//Реализация класса Krestik
#include "Krestik.h"

void Krestik::Activated(bool XorO)
{
	if (XorO == true) image.loadFromFile("image/krestik/krestik.png");
	else image.loadFromFile("image/krestik/nolik.png");
	texture.loadFromImage(image);
	sprite.setOrigin(100, 100);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void Krestik::Win()
{
	sprite.setColor(Color::Green);
}

void Krestik::Restart()
{
	image.loadFromFile("image/krestik/kletke.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}
