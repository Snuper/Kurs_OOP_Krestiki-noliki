//����� ���������
#ifndef KRESTIK_H
#define KRESTIK_H

#include "Figure.h"

class Krestik : public Figure
{
	public:
		int x, y;
		bool XorO;
		Krestik(String F, int x, int y) : x(x), y(y) //������ ������������ � ���������� ������������
		{//��� ����*�������
			image.loadFromFile("image/krestik/" + F);
			texture.loadFromImage(image);
			sprite.setOrigin(100, 100);
			sprite.setTexture(texture);
			sprite.setPosition(x, y);
		}
		Krestik(int x, int y, bool XorO) : XorO(XorO) ,x(x), y(y)
		{//� ��� ������, �� �� ����, ��� ��� ��������� ������ �������� � ������������� ��� ������ ����� ��� �������� ����������� �������������
			if (XorO == true) image.loadFromFile("image/krestik/krestik.png");
			else image.loadFromFile("image/krestik/nolik.png");
			texture.loadFromImage(image);
			sprite.setOrigin(100, 100);
			sprite.setTexture(texture);
			sprite.setPosition(x, y);
		}
		
		//�� ����� ����������� �������
		void Activated(bool XorO);
		void Restart();
		void Win();
};

#endif
