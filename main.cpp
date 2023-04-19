// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// for linux fontsm ./font/fontname
	View view(FloatRect(0.f, 0.f, 1920.f, 1080.f));
	
	// Create a video mode object
	VideoMode vm(800, 600);

	// Create and open a window for the game
	RenderWindow window(vm, "Chaos!", Style::Default);
	window.setView(view);

	vector<Vector2f> vertices;

	//copy code from timber and delete what dont need
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();

			}
			if (event.mouseButton.button == Mouse::Left)
			{
				Vector2i pixelPos = { event.mouseButton.x , event.mouseButton.y };
				Vector2f worldPos = window.mapPixelToCoords(pixelPos, view);
				vertices.push_back(worldPos);
			}

		}


		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		RectangleShape shape{ Vector2f(4,4) };



		for (size_t i = 0; i, vertices.size(); i++)
		{
			shape.setPosition(vertices.at(i));
			window.draw(shape);
		}



	}
	
}