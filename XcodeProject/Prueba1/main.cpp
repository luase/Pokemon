#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const** argv)
{
    
    sf::RenderWindow window(sf::VideoMode(700, 500), "Pokemon OOP");
    
    //Icono de aplicación
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    //backgrounds
    sf::Texture texture;
    sf::Texture backgrund2;
    if (!texture.loadFromFile(resourcePath() + "background.jpg")) {
        return EXIT_FAILURE;
    }
    if (!backgrund2.loadFromFile(resourcePath() + "background2.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    sf::Sprite back2(backgrund2);
    
    //Titulo ventana1
    sf::Texture titulo;
    if (!titulo.loadFromFile(resourcePath() + "Poketitulo3.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite titulo1(titulo);
    titulo1.setPosition(sf::Vector2f(30, 125));
    
    //Fuente
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "Pokemon GB.ttf")) {
        return EXIT_FAILURE;
    }
    //Ventana 1
    sf::Text text("\t\t\t\tAlan Antonio \tJaime Saul \tUlises ", font, 10);
    text.setFillColor(sf::Color::Black);
    sf::Text start("Press Space", font, 30);
    start.setFillColor(sf::Color::Black);
    start.setPosition(175, 375);
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "PokeSong.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
    
    //Venatana2
    sf::Text name1, name2;
    string player1, player2;
    sf::Text setplayer1("Set the Player 1 name: ", font, 15);
    setplayer1.setFillColor(sf::Color::Red);
    setplayer1.setPosition(150, 110);
    sf::Text setplayer2("Set the Player 2 name: ", font, 15);
    setplayer2.setFillColor(sf::Color::Red);
    setplayer2.setPosition(150, 200);
    
    sf::RectangleShape rectangle1, rectangle2;
    rectangle1.setSize(sf::Vector2f(300, 30));
    rectangle1.setOutlineColor(sf::Color::Black);
    rectangle1.setOutlineThickness(2);
    rectangle1.setPosition(150, 133);
    
    rectangle2.setSize(sf::Vector2f(300, 30));
    rectangle2.setOutlineColor(sf::Color::Black);
    rectangle2.setOutlineThickness(2);
    rectangle2.setPosition(150, 223);
    
    
    
    bool gotoventana2 =  false;
    bool player1setname = false;
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Space){
                    music.stop();
                    gotoventana2  = true;
                }
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }
            if (gotoventana2){
                if(event.type == sf::Event::TextEntered){
                    if(event.text.unicode < 128 && player1.size()<10 && event.key.code != sf::Keyboard::Enter){
                        player1.push_back((char)event.text.unicode);
                        name1.setFont(font);
                        name1.setCharacterSize(15);
                        name1.setString(player1);
                        name1.setFillColor(sf::Color::Black);
                        name1.setPosition(150, 140);
                        player1setname = true;
                    }
                }
            }
            
        }

        window.clear();
        if(!gotoventana2){
            window.draw(sprite);
            window.draw(text);
            window.draw(start);
            window.draw(titulo1);
        }
        if(gotoventana2){
            window.draw(back2);
            window.draw(setplayer1);
            window.draw(setplayer2);
            window.draw(rectangle1);
            window.draw(rectangle2);
            window.draw(name1);
            
            
            
        }

        
        // Update the window
        window.display();
    }
    
    std::cout << player1 << std::endl;

    return EXIT_SUCCESS;
}