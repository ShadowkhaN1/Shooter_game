#ifndef _Enemy_H_
#define _Enemy_H_


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Enemy
{
public:
	Enemy();
	~Enemy();

	void DrawEnemy(sf::RenderWindow &Window);
	void Update();
	void LoadEnemy();
	void initializeEnemy();
	void NewEnemy();
	void randomf();
	void DeleteEnemy();
	float GetPostion_x();
	float GetPostion_y();
	void DeleteAllEnemy();
	

private:
	friend class Player;
	friend class Collision;
	sf::Texture EnemyTexture;
	
	float positionx;
	float positiony;
	vector<sf::Sprite> Enemyvec;
	vector<float> postionEnemy_x;
	vector<float> positionEnemy_y;
	
	int RightEnemy;
	sf::Clock clock2;
	float random;
	float EnemySpeed;
	vector<int> size_Enemy;
	sf::Sprite EnemySprite;
};


#endif _Enemy_H_