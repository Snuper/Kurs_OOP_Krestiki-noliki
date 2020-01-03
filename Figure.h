//Абстрактный класс
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
		bool Activate = false; //Указывает на активность клетки
		int Selected = 0; //Хранит состояние клетки 2 = Крестик, 1 = Нолик, 0 = Неопределенность
		//Объекты классов sfml, которые нужны для отображение текстур
		String File;
		Image image;
		Texture texture;
		Sprite sprite;
		//Виртуальные функции
		virtual void Activated(bool XorO) = 0;
		virtual void Win() = 0;
		virtual void Restart() = 0;
};

#endif
