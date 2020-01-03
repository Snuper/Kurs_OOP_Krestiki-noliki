//����������� �����
#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;
using namespace sf;

class Figure
{
	public:
		bool Activate = false; //��������� �� ���������� ������
		int Selected = 0; //������ ��������� ������ 2 = �������, 1 = �����, 0 = ����������������
		//������� ������� sfml, ������� ����� ��� ����������� �������
		String File;
		Image image;
		Texture texture;
		Sprite sprite;
		//����������� �������
		virtual void Activated(bool XorO) = 0;
		virtual void Win() = 0;
		virtual void Restart() = 0;
};

#endif
