
#include "Player.h";
#include "Collision.h";
#include "Global.h";
#include "Menu.h";
#include <iostream>
#include <vector>

Player::Player()
{
}

Player::~Player()
{
}

void Player::LoadContent()
{
	if (PlayerTexture.loadFromFile("shipAnimation.png"))
		PlayerAnimation.setTexture(PlayerTexture);

	if (ShootTexture.loadFromFile("laser.jpg"))
		ShootSprite.setTexture(ShootTexture);
	

}
void Player:: initialize()
{
	position_x=10;
	position_y=300;
	right=0;
	moveSpeed=300;
	
	
}

void Player:: Draw_Player(sf::RenderWindow &Window)
{
	PlayerAnimation.setTextureRect(sf::IntRect(right*115, 0, 115, 69));
	
	Window.draw(PlayerAnimation);
}

void Player::Update()
{
	right++;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		position_x+=moveSpeed*clock.getElapsedTime().asSeconds();


	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		position_x-=moveSpeed*clock.getElapsedTime().asSeconds();
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		position_y-=moveSpeed*clock.getElapsedTime().asSeconds();
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		position_y+=moveSpeed*clock.getElapsedTime().asSeconds();
	

	if(position_x+115>=ScreenWidth)
		position_x=ScreenWidth-115;

		else if(position_x<=0)
			position_x=0;

		if (position_y+69>=ScreenHeight)
			position_y=ScreenHeight-69;

		else if(position_y<=0)
			position_y=0;


	if (right==8)
		right=0;


	std::cout<<position_x<<"      "<<position_y<<endl;

	
	PlayerAnimation.setPosition(position_x, position_y);
	clock.restart();
	
}

void Player::DrawShoot(sf::RenderWindow &Window)
{
	
	for (unsigned int i = 0; i < size_shoot.size(); i++)
	{
		
		Shoot[i].setPosition(positionShoot_x[i]+=moveSpeed*clock1.getElapsedTime().asSeconds(), positionShoot_y[i]);
		
		Window.draw(Shoot[i]);
	
	}
	clock1.restart();
}


void Player::newshoot()
{
	positionShoot_x.push_back(position_x+110);
	positionShoot_y.push_back(position_y+30);
	size_shoot.push_back(1);
	Shoot.push_back(ShootSprite);
	
}

void Player::DeleteShoot()
{
	for (unsigned int i = 0; i < size_shoot.size(); i++)
	{
		if (positionShoot_x[i]>=800)
	{
		positionShoot_x.erase(positionShoot_x.begin());
		positionShoot_y.erase(positionShoot_y.begin());
			Shoot.erase(Shoot.begin());
			size_shoot.erase(size_shoot.begin());
		
	}
	}

}

