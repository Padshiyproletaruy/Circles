#include <iostream>
#include <SFML/Graphics.hpp>
#include<list>
using namespace std;
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::CircleShape mycircle(60.f); mycircle.setFillColor(sf::Color::Green);
    list<sf::CircleShape> circles;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
          window.close();
        }
        window.clear();
        if (event.type == sf::Event::MouseButtonPressed) //Mouse button Pressed
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (mycircle.getPosition().x + 120 > 800) mycircle.setPosition(0, mycircle.getPosition().y + 120);
                circles.push_back(mycircle);
                mycircle.setPosition(sf::Vector2f{ mycircle.getPosition().x + 2 * mycircle.getRadius(),mycircle.getPosition().y });
            }

            if (event.mouseButton.button == sf::Mouse::Right) 
            {
                circles.pop_back();
            
            }

        }
        for (auto &mycircle : circles) {
            window.draw(mycircle);
        }


        window.display();
    }

   
}