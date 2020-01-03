//Класс наследник
#ifndef BGIMAGE_H
#define BGIMAGE_H

#include "Figure.h"

class BGimage : public Figure
{
	public:
		BGimage(String F); 
		// он хранит в себе текстуру сетки
		void Activated(bool XorO);
		void Restart();
		void Win();
};

#endif
