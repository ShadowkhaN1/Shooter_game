#ifndef _Menu_H_
#define _Menu_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "Collision.h";
#include <fstream>
#include <string>

class Menu
{
public:
	Menu();
	~Menu();

	void LoadMenu();
	void DrawMenu(sf::RenderWindow &Window);
	void DrawHealth(sf::RenderWindow &Window,sf::Font &font);
	void IsTextchecked(sf::RenderWindow &Window);
	bool ChangeStage();
	void DrawEndMenu(sf::RenderWindow &Window);
	bool GetSoundString();
	void PlayMusic();
	void SetScore(std::string String);

private:
	sf::Texture MenuTexture, MenuEndtexture;
	sf::Sprite MenuSprite, MenuEndSprite;
	sf::Text TextHealth;
	sf::Font font;
	sf::Clock clock;
	sf::Sound sound;
	sf::SoundBuffer buffersound;
	sf::Text Score, text_menu;
	vector<sf::Text> text_vect;
	bool stage;
	Collision collision;
	std::ofstream Score_txt;
	std::string Score_string;
};



#endif _Menu_H_