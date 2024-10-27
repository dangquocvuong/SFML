#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
    sf::RenderWindow mWindow;
    //sf::CircleShape mPlayer;
    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;

    sf::Texture mTexture;
    sf::Sprite mPlayer;
};

#endif //GAME_HPP