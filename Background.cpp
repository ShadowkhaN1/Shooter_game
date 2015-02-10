#include "Background.h"
#include "Global.h"




Background::Background()
{
}

Background::~Background()
{
}


void Background::Initialize()
{
	if(texture_background.loadFromFile("galaxy.jpg"))
		sprite_background.setTexture(texture_background);
	

	if(texture.loadFromFile("Starfield_512.png"))
		sprite.setTexture(texture);

	sprite.setPosition(0,0);

	for (int i = 0; i < 2; i++)
	{
sprite_vect.push_back(sprite);
	}
	
	position_x.push_back(0);
	position_x.push_back(512);


	for (int i = 0; i < sprite_vect.size(); i++)
	{
sprite_vect[i].setPosition(position_x[i],0);
	}
	
	SpeedBackground=20;

}


void Background::DrawBackground(sf::RenderWindow &Window)
{
	
		Window.draw(sprite_background);
	
			

	for (unsigned int i = 0; i < sprite_vect.size(); i++)
	{
Window.draw(sprite_vect[i]);
	}
	
	
}

void Background::Update()
{
	for (int i = 0; i < sprite_vect.size(); i++)
	{
		sprite_vect[i].setPosition(position_x[i]-=SpeedBackground*clock.getElapsedTime().asSeconds(),0);


		if (position_x[i]+512<0)
		{
			sprite_vect.erase(sprite_vect.begin());
			position_x.erase(position_x.begin());
			sprite_vect.push_back(sprite);
			position_x.push_back(position_x[i]+512);
			sprite_vect[i].setPosition(position_x[i],0);
		}

	}
	clock.restart();





}