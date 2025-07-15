#include <iostream>
#include <SFML/Graphics.hpp>
#include<list>
using namespace std;
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::CircleShape mycircle(60.f); mycircle.setFillColor(sf::Color::Green);
    list<sf::CircleShape> circles;
    list<sf::CircleShape>::iterator it = circles.begin();
    int index{ 0 };




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

           
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if ((mycircle.getPosition().x + 120 > window.getSize().x)) {
                        mycircle.setPosition(0, mycircle.getPosition().y + 120);
                        index = mycircle.getPosition().x;
                    }
                    circles.push_back(mycircle);
                    mycircle.setPosition( mycircle.getPosition().x + 2 * mycircle.getRadius(),mycircle.getPosition().y);
                    
                }

                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if ((circles.size() != 0) && (mycircle.getPosition().y >= 0))
                    {
                        if (mycircle.getPosition().x == 0)
                            mycircle.setPosition(index, mycircle.getPosition().y);
                        mycircle.setPosition(mycircle.getPosition().x - 2 * mycircle.getRadius(), mycircle.getPosition().y);
                        circles.pop_back();
                    }
                }

            }
            window.clear();
            for (auto& mycircle : circles) 
            {
                window.draw(mycircle);
            }


            window.display();

        }
    }

   
}