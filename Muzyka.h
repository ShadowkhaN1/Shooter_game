#ifndef _Muzyka_H_
#define _Muzyka_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>

class Muzyka
{
public:
	Muzyka();
	~Muzyka();

	void LoadBackground();
	void PlayMusic(sf::Sound &sound);
	void StopMusic(sf::Sound &sound);
	void DrawBackground(sf::RenderWindow &Window);
private:
	sf::Texture TextureBackground;
sf::Sprite SpriteBackground;
float backgroundposition_x;
};



#endif _Muzyka_H_