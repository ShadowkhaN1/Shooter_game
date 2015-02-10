
#include "Player.h";
#include "Enemy.h";
#include "Menu.h";
#include "Global.h";
#include "Collision.h";
#include <iostream>
#include <vector>
#include <ctime>



Menu::Menu()
{
}

Menu::~Menu()
{
}


void Menu::LoadMenu()
{

	if(MenuTexture.loadFromFile("mainMenu.jpg"))
		MenuSprite.setTexture(MenuTexture);

	if(MenuEndtexture.loadFromFile("endMenu.png"))
		MenuEndSprite.setTexture(MenuEndtexture);


	if (font.loadFromFile("trado.ttf"))
	{
		text_menu.setFont(font);

		text_menu.setCharacterSize(48);
		text_menu.setColor(sf::Color::Black);
		
	}
	
	if(buffersound.loadFromFile("menuMusic.wav"))
		sound.setBuffer(buffersound);



	for (int i = 0; i < 4; i++)
	{
	text_vect.push_back(text_menu);
	}
	
	text_vect[0].setPosition(280, 240);
	text_vect[0].setString("New Game");

	text_vect[1].setPosition(320,300);
	text_vect[1].setString("Music");

	text_vect[2].setPosition(340,360);
	text_vect[2].setString("Exit");

	text_vect[3].setPosition(480,300);
	text_vect[3].setString("On");



	
	Score_txt.open("Score.txt", std::ios::in | std::ios::out);


}


void Menu::DrawMenu(sf::RenderWindow &Window)
{

	Window.draw(MenuSprite);

}

void Menu::DrawHealth(sf::RenderWindow &Window, sf::Font &font)
{


		TextHealth.setFont(font);
		
		TextHealth.setColor(sf::Color::White);
		TextHealth.setCharacterSize(20);
		TextHealth.setScale(0.5,0.9);
		TextHealth.setPosition(70,ScreenHeight-80);
		TextHealth.setString("Health");

		Window.draw(TextHealth);
		
		stage=false;

}


void Menu::IsTextchecked(sf::RenderWindow &Window)
{

			if(sf::Mouse::getPosition(Window).x>=280 && sf::Mouse::getPosition(Window).x<=510 && sf::Mouse::getPosition(Window).y>=255 && sf::Mouse::getPosition(Window).y<=285 )
		{
			text_vect[0].setStyle(sf::Text::Bold);
			
		}
		else
			text_vect[0].setStyle(sf::Text::Regular);	

		
		 if(sf::Mouse::getPosition(Window).x>=320 && sf::Mouse::getPosition(Window).x<=440 && sf::Mouse::getPosition(Window).y>=312 && sf::Mouse::getPosition(Window).y<=345 )
		 {
			 text_vect[1].setStyle(sf::Text::Bold);
				Window.draw(text_vect[3]);

		 }
		else
			text_vect[1].setStyle(sf::Text::Regular);	


		if(sf::Mouse::getPosition(Window).x>=342 && sf::Mouse::getPosition(Window).x<=419 && sf::Mouse::getPosition(Window).y>=375 && sf::Mouse::getPosition(Window).y<=405 )
		{
			text_vect[2].setStyle(sf::Text::Bold);
	
		}
		else
			text_vect[2].setStyle(sf::Text::Regular);	


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&  sf::Mouse::getPosition(Window).x>=342 && sf::Mouse::getPosition(Window).x<=419 && sf::Mouse::getPosition(Window).y>=375 && sf::Mouse::getPosition(Window).y<=405 )
		{
			Score_txt<<" Twoj wynik to "<<Score_string;
			Window.close();
		}



		else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(Window).x>=320 && sf::Mouse::getPosition(Window).x<=440 && sf::Mouse::getPosition(Window).y>=312 && sf::Mouse::getPosition(Window).y<=345 && clock.getElapsedTime().asSeconds()>=0.2 )
		{
			if(text_vect[3].getString()=="On")
				text_vect[3].setString("Off");

			 else
				 text_vect[3].setString("On");

			clock.restart();
		}

	
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(Window).x>=280 && sf::Mouse::getPosition(Window).x<=510 && sf::Mouse::getPosition(Window).y>=255 && sf::Mouse::getPosition(Window).y<=285 )
		{
			sound.stop();
			stage=true;
		}
	

			for (unsigned int i = 0; i < text_vect.size()-1; i++)
	{
		Window.draw(text_vect[i]);
	}

}


bool Menu::ChangeStage()
{

	if(stage==true)
		return true;

	else
	return false;

	
}

void Menu::DrawEndMenu(sf::RenderWindow &Window)
{

	Window.draw(MenuEndSprite);
}


bool Menu::GetSoundString()
{

	if(text_vect[3].getString()=="On")
		return true;
	else
		return false;
	
}


void Menu::PlayMusic()
{ 
	
	if(text_vect[3].getString()=="On")
	{
	if(!(sound.getStatus()))
	sound.play();
	}
	else
		sound.stop();

}

void Menu::SetScore(std::string String)
{

	Score_string=String;

}