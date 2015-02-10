#ifndef _Player_H_
#define _Player_H_



#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Player
{
	
public:

	Player();
	~Player();
	void initialize();
	void Draw_Player(sf::RenderWindow &Window);
	void Update();
	void DrawShoot(sf::RenderWindow &Window);
	void newshoot();
	void LoadContent();
	void DeleteShoot();
	
	

private:
	friend class Enemy;
	friend class Collision;

	sf::Sprite PlayerAnimation;
	sf::Texture PlayerTexture;
	sf::FloatRect ShootCollision;
	sf::FloatRect enemycol;
	

	int right;
	sf::Sprite ShootSprite;
	sf::Texture ShootTexture ;
	float position_x;
    float position_y;
	float moveSpeed;
	sf::Clock clock;
	sf::Clock clock1;
	
	vector<int> size_shoot;
	vector<sf::Sprite>Shoot;
	vector<float>positionShoot_x;
	vector<float>positionShoot_y;
	


};


#endif _Player_H_