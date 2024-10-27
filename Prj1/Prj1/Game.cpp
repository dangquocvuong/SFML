#include "Game.hpp"

//640 480
Game::Game() :
    mWindow(sf::VideoMode(640, 480), "SFML Applicaion"),
    mPlayer(),
    mTexture(),
    mIsMovingUp{ false },
    mIsMovingDown{ false },
    mIsMovingLeft{ false },
    mIsMovingRight{ false }
{
    if (!mTexture.loadFromFile("D:\\SFML\\Projects\\SFML_Game_Development\\MyPrj\\Debug\\Media\\Textures\\Eagle.png"))
    {
        //handle loading err;
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);

    //uncomment this part if "sf::CircleShape mPlayer" is enabled
    /*mPlayer.setRadius(40.f);
    mPlayer.setPosition(0.f, 0.f);
    mPlayer.setFillColor(sf::Color::Red);*/
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame(sf::seconds(1.f / 60.f));
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Game::update(sf::Time deltaTime)
{
    //typedef sf::Vector2<float> sf::Vector2f, contains 2 member variables x & y. This data type refers to the mathematical concept.
    //dont confuse sf::Vector2f and std::vector.
    float PlayerSpeed = 500.f;
    sf::Vector2f movement(0.f, 0.f);

    if (mIsMovingUp)
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;

    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}