#include <iostream>
#include <SFML/Graphics.hpp>
#include<list>
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    static int value{ 0 };
    sf::RectangleShape blok(sf::Vector2f(48.f, 36.f));
    blok.setPosition(window.getSize().x-48, 36);
    
    sf::Font font;
    font.loadFromFile("./fonts/arialbd.ttf");
    sf::Text text; 
    text.setFont(font);
    text.setPosition(window.getSize().x - 40, 35);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(30);
    
    sf::CircleShape mycircle(60.f); mycircle.setFillColor(sf::Color::Green);
    list<sf::CircleShape> circles;
    list<sf::CircleShape>::iterator it;
   




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
                    if (mycircle.getPosition().y + (2 * mycircle.getRadius()) <= window.getSize().y)
                    {
                        if (mycircle.getPosition().x + (2 * mycircle.getRadius()) <= window.getSize().x)
                        {
                            circles.push_back(mycircle);
                            it = --circles.end();
                            mycircle.setPosition((*it).getPosition().x + 2 * mycircle.getRadius(), (*it).getPosition().y);
                            value++;
                        }
                        else
                        {
                            mycircle.setPosition(0, mycircle.getPosition().y + 2 * mycircle.getRadius());
                            if (mycircle.getPosition().y + (2 * mycircle.getRadius()) <= window.getSize().y)
                            {
                                circles.push_back(mycircle);
                                it = --circles.end();
                                mycircle.setPosition((*it).getPosition().x + 2 * mycircle.getRadius(), (*it).getPosition().y);
                                value++;
                            }
                        }
                    }
                    
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (circles.size() == 1)
                    {
                        circles.pop_back();
                        mycircle.setPosition(0, 0);
                        value--;
                    }

                    if (circles.size() > 1)
                    {
                        mycircle.setPosition((*it).getPosition().x, (*it).getPosition().y);
                        circles.pop_back();
                        it = --circles.end();
                        value--;
                    }
                }
                text.setString(to_string(value));
            }
        }
        window.clear();


        window.draw(blok);
        window.draw(text);
        
        
        for (auto& mycircle : circles)
        {
            window.draw(mycircle);
        }


        window.display();
    }

}
    

  