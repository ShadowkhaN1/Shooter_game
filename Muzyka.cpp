
#include "Player.h";
#include "Enemy.h";
#include "Menu.h";
#include "Collision.h";
#include "Muzyka.h";
#include <iostream>
#include <vector>
#include <ctime>



Muzyka::Muzyka()
{
}

Muzyka::~Muzyka()
{
}


void Muzyka::LoadBackground()
{

	if(TextureBackground.loadFromFile("endMenu.png"))
		SpriteBackground.setTexture(TextureBackground);


	backgroundposition_x=0;
}

void Muzyka::PlayMusic(sf::Sound &sound)
{
	if(!sound.getStatus())
		sound.play();
	sound.setVolume(40);



}

void Muzyka::StopMusic(sf::Sound &sound)
{

	sound.stop();

}

void Muzyka::DrawBackground(sf::RenderWindow &Window)
{
	SpriteBackground.setPosition(backgroundposition_x+=10, 0);
	Window.draw(SpriteBackground);
}