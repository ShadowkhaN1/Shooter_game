#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h";
#include "Enemy.h";
#include "Collision.h";
#include "Global.h";
#include "Background.h";
#include "Menu.h";
#include "Muzyka.h";
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>

int main()
{
	
	
	sf::RenderWindow Window( sf::VideoMode(ScreenWidth, ScreenHeight, 32 ), " SFML 2.0 Game" );
	
	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	
	
 Player player;
 Enemy enemy;
 Collision collision;
 Menu menu;
 Muzyka muzyka;
 Background background;
  


 std::string strin_score;

 


 


 srand((int) time(NULL));



 enum Stage
 {
	 menu_enum ,
	 game_enum,
	 end_enum
 };

 Stage stage=menu_enum;


	sf::SoundBuffer sound;
	sf::Sound dzwiek;									
	if( sound.loadFromFile("laserFire.wav"))
		dzwiek.setBuffer(sound);
	dzwiek.setVolume(100);

	sf::SoundBuffer musicBuffer;
	sf::Sound musicSound;									
	if( musicBuffer.loadFromFile("QuickSilver.wav"))
		musicSound.setBuffer(musicBuffer);

	sf::SoundBuffer SoundBoom;
	sf::Sound musicBoom;									
	if( SoundBoom.loadFromFile("explosion.wav"))
		musicBoom.setBuffer(SoundBoom);



	sf::Texture texture_background;
	sf::Sprite sprite_background;

	if(texture_background.loadFromFile("galaxy.jpg"))
		sprite_background.setTexture(texture_background);


	sf::Font font1;
	sf::Text text1;


	font1.loadFromFile("trado.ttf");
	text1.setFont(font1);
	text1.setCharacterSize(27);
	text1.setColor(sf::Color::White);
	text1.setScale(0.5,0.9); 
	text1.setPosition(700,30);

	

 player.LoadContent();
 player.initialize();

 enemy.LoadEnemy();
 enemy.initializeEnemy();

 collision.LoadBoom();
 collision.InitializeBoom();

 menu.LoadMenu();	

 muzyka.LoadBackground();

 background.Initialize();

    while( Window.isOpen() )
    {
        sf::Event Event;
        while( Window.pollEvent( Event ) )
        {
            
            if(( Event.type == sf::Event::Closed ) )
            {
                Window.close();
            }

		
        }
		
		Window.clear(sf::Color::Black);

	
	
		switch (stage)
		{
		case menu_enum:
			Window.setMouseCursorVisible(true);

			
				menu.PlayMusic();
		

			menu.DrawMenu(Window);

			menu.IsTextchecked(Window);

			if(menu.ChangeStage())
			{
				//enemy.DeleteAllEnemy();
				collision.SetLife(200,100);
				collision.SetPoints(0);
				stage=game_enum;

			}
			break;


		case game_enum:

			background.Update();
			
			background.DrawBackground(Window);

				if(!(menu.GetSoundString()))
					musicSound.stop();
				else
					muzyka.PlayMusic(musicSound);

				Window.setMouseCursorVisible(false);

				

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						{
							musicSound.stop();
							stage=menu_enum;
						}

			
		if (clock1.getElapsedTime().asSeconds()>=0.1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			player.newshoot();
			dzwiek.setVolume(100);
			dzwiek.play();	
			
			clock1.restart();	
	}
		
				if (clock2.getElapsedTime().asSeconds()>=0.1)
		{
			enemy.NewEnemy();
			clock2.restart();

	}
				

		player.Draw_Player(Window);
		player.Update();

		
		player.DeleteShoot();
		player.DrawShoot(Window);

		
		enemy.Update();
		enemy.DrawEnemy(Window);
		enemy.randomf();
		enemy.DeleteEnemy();

		collision.gameOver(player, enemy, musicBoom);

		if(collision.gameOver(player,enemy, musicBoom))
			stage=end_enum;

		
		collision.Collisionshootenemy(player, enemy, Window, musicBoom);
		collision.DrawBoom(Window);
		collision.DrawPoints(Window);
		
		itoa(collision.GetPoints(), collision.pointsString,10);
			text1.setString(collision.pointsString);
			Window.draw(text1);	

			menu.DrawHealth(Window, font1);


			break;
		case end_enum:


			menu.SetScore(text1.getString());
			

			Window.setMouseCursorVisible(true);
			musicSound.stop();
			
			menu.DrawEndMenu(Window);
			if(menu.ChangeStage())
			{
				//enemy.DeleteAllEnemy();
				collision.SetLife(200,100);
				collision.SetPoints(0);
				stage=game_enum;
			}
			menu.IsTextchecked(Window);
			break;
		
		}



		
        Window.display();
      
    }
    return 0;
}