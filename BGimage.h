//����� ���������
#ifndef BGIMAGE_H
#define BGIMAGE_H

#include "Figure.h"

class BGimage : public Figure
{
	public:
		BGimage(String F); 
		// �� ������ � ���� �������� �����
		void Activated(bool XorO);
		void Restart();
		void Win();
};

#endif
