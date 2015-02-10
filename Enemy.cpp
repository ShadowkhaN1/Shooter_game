#include "Player.h";
#include "Enemy.h";
#include "Global.h";
#include "Collision.h";
#include "Menu.h";
#include <iostream>
#include <ctime>


using namespace std;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::initializeEnemy()
{

	RightEnemy=0;
	EnemySpeed=200;
}

void Enemy::LoadEnemy()
{
	if (EnemyTexture.loadFromFile("mineAnimation.png"))
		EnemySprite.setTexture(EnemyTexture);
}


void Enemy::DrawEnemy(sf::RenderWindow &Window)
{
	for (unsigned int i = 0; i < size_Enemy.size(); i++)
	{
		Enemyvec[i].setTextureRect(sf::IntRect(RightEnemy*47, 0, 47, 61));
	
	Window.draw(Enemyvec[i]);
	}
}

void Enemy::Update()
{
RightEnemy++;
for (unsigned int i = 0; i < size_Enemy.size(); i++)
{

	Enemyvec[i].setPosition(postionEnemy_x[i]-=EnemySpeed* clock2.getElapsedTime().asSeconds(), positionEnemy_y[i]);
}
if (RightEnemy==8)
		RightEnemy=0;

clock2.restart();
}


void Enemy::randomf()
{
	random=static_cast<float>(rand() %(ScreenHeight-80));
}

void Enemy::NewEnemy()
{

	Enemyvec.push_back(EnemySprite);
	size_Enemy.push_back(1);
	positionEnemy_y.push_back(random);
	postionEnemy_x.push_back(1000);
	
}

void Enemy::DeleteEnemy()
{

	for (unsigned int i = 0; i < size_Enemy.size(); i++)
	{
		if (postionEnemy_x[i]<=0 )
		{
			
			Enemyvec.erase(Enemyvec.begin());
			size_Enemy.erase(size_Enemy.begin());
			postionEnemy_x.erase(postionEnemy_x.begin());
			positionEnemy_y.erase(positionEnemy_y.begin());
		
		}

	}

}


void Enemy::DeleteAllEnemy()
{

	for (int i = 0; i < size_Enemy.size(); i++)
	{
		Enemyvec.erase(Enemyvec.begin(), Enemyvec.end());
		positionEnemy_y.erase(positionEnemy_y.begin(), positionEnemy_y.end());
			postionEnemy_x.erase(postionEnemy_x.begin(), postionEnemy_x.end());
	}

}