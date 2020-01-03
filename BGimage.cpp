//Реализация класса BGimage
#include "BGimage.h"
BGimage::BGimage(String F)
{
	image.loadFromFile("image/map/" + F);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

void BGimage::Activated(bool XorO)
{
	;
}

void BGimage::Win()
{
	;
}

void BGimage::Restart()
{
	;
}
