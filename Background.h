#include <SFML\Graphics.hpp>
#include <vector>

class Background
{
public:
	Background();
	~Background();

	void Initialize();
	void DrawBackground(sf::RenderWindow &Window);
	void Update();

private:

	sf::Texture texture, texture_background;
	sf::Sprite sprite, sprite_background;
	std::vector<sf::Sprite> sprite_vect;
	std::vector<float>position_x;
	sf::Clock clock;
	int SpeedBackground;
};

