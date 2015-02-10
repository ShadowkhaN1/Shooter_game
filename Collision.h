
#ifndef _Collision_H_
#define _Collision_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>




class Collision
{
	friend class Enemy;
	friend class Player;

public:
	Collision();
	~Collision();

	void Collisionshootenemy(Player &gracz, Enemy &przeciwnik, sf::RenderWindow &Window, sf::Sound &soundBoom);
	void LoadBoom();
	void InitializeBoom();
	bool gameOver(Player &player, Enemy &enemy, sf::Sound & soundboom);
	void DrawEndGame(sf::RenderWindow &Window);
	void DrawPoints(sf::RenderWindow &Window);
	int StripLife();
	void SetLife(float life, float life_x);
	void SetPoints(int point);
	int GetPoints();
	void DrawBoom(sf::RenderWindow &Window);
	
	
	

char pointsString[9];
	
private:
	sf::Texture TextureBoom;
	sf::Sprite SpriteBoom;
	vector<sf::Sprite> Boomvector;
	vector<int> Animated;
	vector<float> positionBoom_x;
	vector<float> positionBoom_y;
	sf::Clock clock4;
	sf::Clock clock1;
	sf::Text text;
	sf::Texture over;
	sf::Sprite gameover;
	sf::Text HealthPoints;
	sf::RectangleShape HealthRect;
	int points;
	std::vector<int> animation;
	float Zycie_x;
	float zycie;
	
};

#endif _Collision_H_