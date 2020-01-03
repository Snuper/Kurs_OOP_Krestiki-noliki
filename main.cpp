#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "Figure.h"
#include "BGimage.h"
#include "Krestik.h"

/*
����� ���������� ��� ���� ���������

1 - ������������ (��� ���� ������ �� �������� �� ������� �������)
2 - ������������ (������� 3 ������, ���� �� ������� - �����������)
3 - �����������
4 - ������������, ���������� �������������
5 - ������ �������������



*/

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1200, 700), "Krestiki Noliki");
	
	bool Game = true; //������� ����������, ��������������� ��� ���������� ���� ��� ������
	
	srand(time(NULL));
		
	Krestik *Krestiki[10]; //������ ������ Krestiki � ������� ����� ������ �� ������� ���� �� ������
	
	Krestik obj_krestik_0("kletke.png", 115, 115);
		Krestiki[0] = &obj_krestik_0;
	Krestik obj_krestik_1("kletke.png", 350, 115);
		Krestiki[1] = &obj_krestik_1;
	Krestik obj_krestik_2("kletke.png", 585, 115);
		Krestiki[2] = &obj_krestik_2;
	Krestik obj_krestik_3("kletke.png", 115, 350);
		Krestiki[3] = &obj_krestik_3;
	Krestik obj_krestik_4("kletke.png", 350, 350);
		Krestiki[4] = &obj_krestik_4;
	Krestik obj_krestik_5("kletke.png", 585, 350);
		Krestiki[5] = &obj_krestik_5;
	Krestik obj_krestik_6("kletke.png", 115, 585);
		Krestiki[6] = &obj_krestik_6;
	Krestik obj_krestik_7("kletke.png", 350, 585);
		Krestiki[7] = &obj_krestik_7;
	Krestik obj_krestik_8("kletke.png", 585, 585);
		Krestiki[8] = &obj_krestik_8;
	
	BGimage obj_bgi("setka.png"); //�����, ���� �������� �������� ������
	
	int temp = rand()%10+0; //������ ������ - �� ��� ����� ������������, ����� ��� ����, ����� ����������� ��������� �����, ������� ��� ����� ���������� �������
	bool temp_XorO;
	if (temp > 5) temp_XorO = true;
	else temp_XorO = false; //true = �������, � false = �����
		
	Krestik obj_krestik_XorO(950, 115, temp_XorO); //10 ������, ������� ��������� � ���� � ���������� ��� ������ �����
		Krestiki[9] = &obj_krestik_XorO;
	
	while (window.isOpen()) //���� ������� ��������, ���� ������� ����
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
    		if (event.key.code == sf::Keyboard::Escape)
        		window.close();
        		
			if (event.type == Event::MouseButtonPressed)
			if (event.key.code == Mouse::Left and Game == true) //���� ������ ����� ������ � ������� ���������� Game �������
			for (int i = 0; i < 9; i++) //���������� ��������, ���� ���� ������������ �������
			{
				if (Krestiki[i]->sprite.getGlobalBounds().contains(Mouse::getPosition().x-100, Mouse::getPosition().y-100))
				{	//�������� ���������� ������� � ������������ � ������������ �����
					if (Krestiki[9]->XorO == true and Krestiki[i]->Activate == false)
					{	//������ ��������� � 10 ������ � �������� ��������� ������� ������, ����� �������� ������ ��������� �������
						Krestiki[i]->Activated(Krestiki[9]->XorO);
						Krestiki[i]->Activate = true;
						Krestiki[i]->Selected = 2;
						Krestiki[9]->Activated(false);
						Krestiki[9]->XorO = false;
					}
					else if (Krestiki[i]->Activate == false) //����� �����
					{
						Krestiki[i]->Activated(Krestiki[9]->XorO);
						Krestiki[i]->Activate = true;
						Krestiki[i]->Selected = 1;
						Krestiki[9]->Activated(true);
						Krestiki[9]->XorO = true;
					}
				}
			}
		}
		if (Krestiki[0]->Selected == 2 and Krestiki[1]->Selected == 2 and Krestiki[2]->Selected == 2)
		{
			Game = false; //���������� Game ������������ � ��������� false � ��������� ��� ����
			Krestiki[0]->Win(); //������� �������� ���������� ���������� ����� Win, ������� ����������� �������� �����
			Krestiki[1]->Win();
			Krestiki[2]->Win();
		}
		else if (Krestiki[0]->Selected == 1 and Krestiki[1]->Selected == 1 and Krestiki[2]->Selected == 1)
		{
			Game = false;
			Krestiki[0]->Win();
			Krestiki[1]->Win();
			Krestiki[2]->Win();
		}
		
		else if (Krestiki[3]->Selected == 2 and Krestiki[4]->Selected == 2 and Krestiki[5]->Selected == 2)
		{
			Game = false;
			Krestiki[3]->Win();
			Krestiki[4]->Win();
			Krestiki[5]->Win();
		}
		else if (Krestiki[3]->Selected == 1 and Krestiki[4]->Selected == 1 and Krestiki[5]->Selected == 1)
		{
			Game = false;
			Krestiki[3]->Win();
			Krestiki[4]->Win();
			Krestiki[5]->Win();
		}
		
		else if (Krestiki[6]->Selected == 2 and Krestiki[7]->Selected == 2 and Krestiki[8]->Selected == 2)
		{
			Game = false;
			Krestiki[6]->Win();
			Krestiki[7]->Win();
			Krestiki[8]->Win();
		}
		else if (Krestiki[6]->Selected == 1 and Krestiki[7]->Selected == 1 and Krestiki[8]->Selected == 1)
		{
			Game = false;
			Krestiki[6]->Win();
			Krestiki[7]->Win();
			Krestiki[8]->Win();
		}
		
		else if (Krestiki[0]->Selected == 2 and Krestiki[3]->Selected == 2 and Krestiki[6]->Selected == 2)
		{
			Game = false;
			Krestiki[0]->Win();
			Krestiki[3]->Win();
			Krestiki[6]->Win();
		}
		else if (Krestiki[0]->Selected == 1 and Krestiki[3]->Selected == 1 and Krestiki[6]->Selected == 1)
		{
			Game = false;
			Krestiki[0]->Win();
			Krestiki[3]->Win();
			Krestiki[6]->Win();
		}
		
		else if (Krestiki[1]->Selected == 2 and Krestiki[4]->Selected == 2 and Krestiki[7]->Selected == 2)
		{
			Game = false;
			Krestiki[1]->Win();
			Krestiki[4]->Win();
			Krestiki[7]->Win();
		}
		else if (Krestiki[1]->Selected == 1 and Krestiki[4]->Selected == 1 and Krestiki[7]->Selected == 1)
		{
			Game = false;
			Krestiki[1]->Win();
			Krestiki[4]->Win();
			Krestiki[7]->Win();
		}
		
		else if (Krestiki[2]->Selected == 2 and Krestiki[5]->Selected == 2 and Krestiki[8]->Selected == 2)
		{
			Game = false;
			Krestiki[2]->Win();
			Krestiki[5]->Win();
			Krestiki[8]->Win();
		}
		else if (Krestiki[2]->Selected == 1 and Krestiki[5]->Selected == 1 and Krestiki[8]->Selected == 1)
		{
			Game = false;
			Krestiki[2]->Win();
			Krestiki[5]->Win();
			Krestiki[8]->Win();
		}
		
		else if (Krestiki[0]->Selected == 2 and Krestiki[4]->Selected == 2 and Krestiki[8]->Selected == 2)
		{
			Game = false;
			Krestiki[0]->Win();
			Krestiki[4]->Win();
			Krestiki[8]->Win();
		}
		else if (Krestiki[0]->Selected == 1 and Krestiki[4]->Selected == 1 and Krestiki[8]->Selected == 1)
		{
			Game = false;
			Krestiki[0]->Win();
			Krestiki[4]->Win();
			Krestiki[8]->Win();
		}
		
		else if (Krestiki[2]->Selected == 2 and Krestiki[4]->Selected == 2 and Krestiki[6]->Selected == 2)
		{
			Game = false;
			Krestiki[2]->Win();
			Krestiki[4]->Win();
			Krestiki[6]->Win();
		}
		else if (Krestiki[2]->Selected == 1 and Krestiki[4]->Selected == 1 and Krestiki[6]->Selected == 1)
		{
			Game = false;
			Krestiki[2]->Win();
			Krestiki[4]->Win();
			Krestiki[6]->Win();
		}
		if (Keyboard::isKeyPressed(Keyboard::R)) //��� ������� �� R ������������ ��� ��������� � ����������� ��������� 10 ������
		{
			Game = true;
			temp = rand()%10+0;
			if (temp > 5) temp_XorO = false;
			else temp_XorO = true;
			Krestiki[9]->Activated(temp_XorO);
			
			for (int i = 0; i < 9; i++)
			{
				Krestiki[i]->Restart();
				Krestiki[i]->Activate = false;
				Krestiki[i]->Selected = 0;
				Krestiki[i]->sprite.setColor(Color::White);
			}
		}
		//��������� ��������
		window.clear();
		window.draw(obj_bgi.sprite);
		for (int i = 0; i < 10; i++)
		{
			window.draw(Krestiki[i]->sprite);
		}
		window.display();
	}
 
	return 0;
}
