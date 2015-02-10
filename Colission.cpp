
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h";
#include "Enemy.h";
#include "Global.h";
#include "Collision.h";
#include "Menu.h";
#include <iostream>
#include <vector>
#include <ctime>


Collision::Collision()
{
}

Collision::~Collision()
{
}


void Collision::LoadBoom()
{	
	if(TextureBoom.loadFromFile("explosion.png"))
		SpriteBoom.setTexture(TextureBoom);
	SpriteBoom.setTextureRect(sf::IntRect(0*72, 0, 72,123 ));
}

void Collision::InitializeBoom()
{
	zycie=200;
	Zycie_x=100;
	points=0;
	HealthRect.setSize(sf::Vector2f(Zycie_x,20));
	HealthRect.setFillColor(sf::Color(144,7,7,255));
	HealthRect.setPosition(65, ScreenHeight-80);
	gameover.setPosition(0,0);


	

}

void Collision::Collisionshootenemy(Player &gracz, Enemy &przeciwnik, sf::RenderWindow &Window, sf::Sound &soundBoom )
{
	
	for ( unsigned int j=0; j<gracz.size_shoot.size(); j++)
	{
		
	for (unsigned int i = 0; i <przeciwnik.size_Enemy.size() ; i++)
		{
			if    ( gracz.Shoot[j].getGlobalBounds().intersects(przeciwnik.Enemyvec[i].getGlobalBounds()))
			{
				points+=50;
				soundBoom.play();
				soundBoom.setVolume(25);


				positionBoom_x.push_back(przeciwnik.postionEnemy_x[i]);
				positionBoom_y.push_back(przeciwnik.positionEnemy_y[i]);
				Boomvector.push_back(SpriteBoom);
				Boomvector[(Boomvector.size())-1].setPosition(positionBoom_x[(positionBoom_x.size())-1], positionBoom_y[(positionBoom_y.size())-1]);
				animation.push_back(0);


			przeciwnik.Enemyvec.erase(przeciwnik.Enemyvec.begin()+i);
			przeciwnik.size_Enemy.erase(przeciwnik.size_Enemy.begin()+i);
			przeciwnik.postionEnemy_x.erase(przeciwnik.postionEnemy_x.begin()+i);
			przeciwnik.positionEnemy_y.erase(przeciwnik.positionEnemy_y.begin()+i);

			gracz.positionShoot_x.erase(gracz.positionShoot_x.begin()+j);
			gracz.positionShoot_y.erase(gracz.positionShoot_y.begin()+j);
			gracz.Shoot.erase(gracz.Shoot.begin()+j);
			gracz.size_shoot.erase(gracz.size_shoot.begin()+j);


			
			}
			
	}

}
	
}


bool Collision::gameOver(Player &player, Enemy &enemy, sf::Sound &soundboom)

{
	for (unsigned int i = 0; i < enemy.size_Enemy.size(); i++)
	{
		if(player.PlayerAnimation.getGlobalBounds().intersects(enemy.Enemyvec[i].getGlobalBounds()))
		{
	if(zycie<=50)		
			return true;
				
					
			soundboom.play();

			positionBoom_x.push_back(enemy.postionEnemy_x[i]);
				positionBoom_y.push_back(enemy.positionEnemy_y[i]);
				Boomvector.push_back(SpriteBoom);
				Boomvector[(Boomvector.size())-1].setPosition(positionBoom_x[(positionBoom_x.size())-1], positionBoom_y[(positionBoom_y.size())-1]);
				animation.push_back(0);

			enemy.Enemyvec.erase(enemy.Enemyvec.begin()+i);
			enemy.size_Enemy.erase(enemy.size_Enemy.begin()+i);
			enemy.postionEnemy_x.erase(enemy.postionEnemy_x.begin()+i);
			enemy.positionEnemy_y.erase(enemy.positionEnemy_y.begin()+i);

			zycie-=50;
			HealthRect.setSize(sf::Vector2f(Zycie_x-=25,20));	
			
		}
		
	}
	
return false;

}



void Collision:: DrawPoints(sf::RenderWindow &Window)
{
	HealthRect.setSize(sf::Vector2f(Zycie_x,20));
	Window.draw(HealthRect);

}


int Collision::StripLife()
{


	return zycie;
}


void Collision::SetLife(float life, float life_x)
{
	zycie=life;
	Zycie_x=life_x;
}

void Collision::SetPoints(int point)
{

	points=point;

}

int Collision::GetPoints()
{

	return points;
}



void Collision::DrawBoom(sf::RenderWindow &Window)
{

	
		for (int i = 0; i < animation.size(); i++)
		{

		
	
for (unsigned int i = 0; i < Boomvector.size(); i++)
{
	
	

					Boomvector[i].setTextureRect(sf::IntRect((animation[i]++)*72, 0, 72,123 ));	
					clock1.restart();
	
		Window.draw(Boomvector[i]);
		
	}
if (animation[i]>11)
			{
				Boomvector.erase(Boomvector.begin()+i);
				positionBoom_x.erase(positionBoom_x.begin()+i);
				positionBoom_y.erase(positionBoom_y.begin()+i);
				animation.erase(animation.begin()+i);
		}
	}


}