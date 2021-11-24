#include <iostream>
#include <cstdlib> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;
using namespace std;

int taille = 27;
int width = (taille * taille) * 2, height = (taille * taille) * 1.245;
int num;
int dir = 1;
bool mort = false;
bool tabmm = false;
char pseudo[][15] = {
    "EvanBay : ",
    "Test1 : ",
    "test2 : ",
    "test3 : ",
    "test4 : "
};
#define NUM(pseudo) (sizeof(pseudo) / sizeof(*pseudo))
bool start = false;
bool good = false;
bool aff = false;

struct snake
{
    int x, y;
}s[100];

struct fruit
{
    int x, y;
}f;

void spawnf()
{
    f.x = rand() % taille * 2;
    f.y = rand() % taille * 1.245;
}

int game(sf::RenderWindow* app, Event event);

void Action(sf::RenderWindow* app)
{
    for (int i = num; i > 0; i--)
    {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0) s[0].y -= 1;
    if (dir == 1) s[0].x += 1;
    if (dir == 2) s[0].y += 1;
    if (dir == 3) s[0].x -= 1;

    if (s[0].x == f.x && s[0].y == f.y)
    {
        num++;
        spawnf();
    }
}

void move()
{
    if (Keyboard::isKeyPressed(Keyboard::Up) && dir != 2)  dir = 0;
    if (Keyboard::isKeyPressed(Keyboard::Right) && dir != 3) dir = 1;
    if (Keyboard::isKeyPressed(Keyboard::Down) && dir != 0) dir = 2;
    if (Keyboard::isKeyPressed(Keyboard::Left) && dir != 1) dir = 3;
}

int gameo(sf::RenderWindow* app, Event event)
{
    sf::Texture deathmenue;
    if (!deathmenue.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/menud.png"))
        return EXIT_FAILURE;
    sf::Sprite death(deathmenue);

    if (tabmm == false) {
        mort = true;
        app->clear();
        app->draw(death);
        app->display();

    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Texture tab;
        if (!tab.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/tab.png"))
            return EXIT_FAILURE;
        sf::Sprite tabm(tab);
        sf::Font font;

        if (!font.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/arial.ttf")) {
            printf("error");
        }

        sf::Text name;
        name.setFont(font);
        std::stringstream ss;
        ss << num;
        name.setCharacterSize(17);
        name.setFillColor(sf::Color::Black);
        name.setStyle(sf::Text::Bold);

        printf("%d\n", event.mouseButton.x);
        printf("%d\n", event.mouseButton.y);

        if (sf::Mouse::getPosition((*app)).x > 618 && sf::Mouse::getPosition((*app)).x < 772
            && sf::Mouse::getPosition((*app)).y > 253 && sf::Mouse::getPosition((*app)).y < 320)
        {
            mort = false;
            start = true;
            game(app, event);
            printf("TU JOEU");
        }

        if (sf::Mouse::getPosition((*app)).x > 618 && sf::Mouse::getPosition((*app)).x < 875
            && sf::Mouse::getPosition((*app)).y > 407 && sf::Mouse::getPosition((*app)).y < 485)
        {
            tabmm = true;
            app->clear();
            app->draw(tabm);

            for (int i = 0; i < NUM(pseudo); i++)
            {
                name.setString(pseudo[i] + ss.str());
                name.setPosition(300, 200 + (50 * i));
                app->draw(name);
            }
            app->display();
        }

        if (sf::Mouse::getPosition((*app)).x > 618 && sf::Mouse::getPosition((*app)).x < 850
            && sf::Mouse::getPosition((*app)).y > 560 && sf::Mouse::getPosition((*app)).y < 645)
        {
            app->close();
        }
    }
    return 0;
}


int games(sf::RenderWindow* app, Event event) {

    if (start == false)
    {
        if (good == false)
        {
            sf::Texture deathmenue;
            if (!deathmenue.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/menud.png"))
                return EXIT_FAILURE;
            sf::Sprite death(deathmenue);

            good = true;
            app->clear();
            app->draw(death);
            app->display();
        }
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Texture tab;
        if (!tab.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/tab.png"))
            return EXIT_FAILURE;
        sf::Sprite tabm(tab);
        sf::Font font;

        if (!font.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/arial.ttf")) {
            printf("error");
        }

        sf::Text name;
        name.setFont(font);
        std::stringstream ss;
        ss << num;
        name.setCharacterSize(17);
        name.setFillColor(sf::Color::Black);
        name.setStyle(sf::Text::Bold);

        printf("%d\n", event.mouseButton.x);
        printf("%d\n", event.mouseButton.y);

        if (sf::Mouse::getPosition((*app)).x > 618 && sf::Mouse::getPosition((*app)).x < 772
            && sf::Mouse::getPosition((*app)).y > 253 && sf::Mouse::getPosition((*app)).y < 320)
        {
            mort = false;
            start = true;
            game(app, event);
        }

        if (sf::Mouse::getPosition((*app)).x > 618 && sf::Mouse::getPosition((*app)).x < 875
            && sf::Mouse::getPosition((*app)).y > 407 && sf::Mouse::getPosition((*app)).y < 485)
        {
            tabmm = true;

            app->clear();
            app->draw(tabm);

            for (int i = 0; i < NUM(pseudo); i++)
            {
                name.setString(pseudo[i] + ss.str());
                name.setPosition(300, 200 + (50 * i));
                app->draw(name);
            }
            app->display();
        }

        if (sf::Mouse::getPosition((*app)).x > 618 && sf::Mouse::getPosition((*app)).x < 850
            && sf::Mouse::getPosition((*app)).y > 560 && sf::Mouse::getPosition((*app)).y < 645)
        {
            app->close();
        }
    }
    return 0;
}

void score(sf::RenderWindow* app)
{
    sf::Font font;
    if (!font.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/arial.ttf")) {
        printf("error");
    }
    sf::Text text;
    text.setFont(font);
    std::stringstream ss;
    ss << num;
    text.setString("Score : " + ss.str());
    text.setCharacterSize(17);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(1300, 10);

    app->draw(text);
}

int box(sf::RenderWindow* app)
{
    sf::Texture allan;

    if (dir == 0) {
        if (!allan.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/maillot1.png"))
            return EXIT_FAILURE;
        sf::Sprite maillot(allan);
    }

    if (dir == 1) {
        if (!allan.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/maillot3.png"))
            return EXIT_FAILURE;
        sf::Sprite maillot(allan);
    }

    if (dir == 2) {
        if (!allan.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/maillot2.png"))
            return EXIT_FAILURE;
        sf::Sprite maillot(allan);
    }

    if (dir == 3) {
        if (!allan.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/maillot0.png"))
            return EXIT_FAILURE;
        sf::Sprite maillot(allan);
    }

    RectangleShape box(Vector2f(taille, taille));
    box.setTexture(&allan);
    box.setTextureRect(sf::IntRect(10, 10, 100, 100));

    for (int i = 0; i < num; i++)
    {
        box.setPosition(s[i].x * taille, s[i].y * taille);
        app->draw(box);
    }
    return 0;
}

int head(sf::RenderWindow* app)
{

    sf::Texture allan;

    if (!allan.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/Allan.png"))
        return EXIT_FAILURE;
    sf::Sprite test(allan);

    RectangleShape head(Vector2f(taille, taille));
    head.setTexture(&allan);
    head.setTextureRect(sf::IntRect(10, 10, 100, 100));
    head.setPosition(s[0].x * taille, s[0].y * taille);
    app->draw(head);
    return 0;
}


int tail(sf::RenderWindow* app)
{

    sf::Texture allan;
    if (!allan.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/cap.png"))
        return EXIT_FAILURE;
    sf::Sprite test(allan);

    RectangleShape head(Vector2f( taille, taille));
    head.setTexture(&allan);
    head.setTextureRect(sf::IntRect(10, 10, 100, 100));
    head.setPosition(s[num - 1].x * taille, s[num - 1].y * taille);
    app->draw(head);
    return 0;
}


int apple(sf::RenderWindow* app)
{
    sf::Texture food;
    if (!food.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/ballon.png"))
        return EXIT_FAILURE;
    sf::Sprite testf(food);

    sf::CircleShape apple(taille / 1.25);
    apple.setTexture(&food);
    apple.setTextureRect(sf::IntRect(10, 10, 100, 100));
    apple.setPosition(f.x * taille, f.y * taille);
    app->draw(apple);
    return 0;
}

int game(sf::RenderWindow* app, Event event) {

    app->setFramerateLimit(60);
    Clock timer;
    Clock time;
    Clock col;

    num = 5;
    spawnf();
    for (int i = 0; i < num; i++)
    {
        s[i].x = 27;
        s[i].y = 14;
    }

    sf::Texture texture;

    if (!texture.loadFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/Background.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Music music;
    if (!music.openFromFile("C:/Users/evanb/source/repos/SnakeAlpha/src/sound.wav"))
        return EXIT_FAILURE;

    music.play();

    while (app->isOpen())
    {
        Event event;
        while (app->pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                if (event.key.code == Keyboard::Escape)
                    app->close();
                break;
            }
        }
        move();
        if (start == true) {

            if (mort == false)
            {
                app->clear();
                app->draw(sprite);

                box(app);
                head(app);
                tail(app);
                apple(app);

                if (timer.getElapsedTime().asMilliseconds() > 125)
                {
                    Action(app);
                    timer.restart();
                }
                if (time.getElapsedTime().asMilliseconds() > 10)
                {
                    score(app);
                    time.restart();
                }
                app->display();
            }
            if (col.getElapsedTime().asMilliseconds() > 300)
            {
                if (s[0].x == taille * 2 + 1 || s[0].y == 34 || s[0].y == -1 || s[0].x == -1) {
                    gameo(app, event);
                }
                for (int i = 1; i < num; i++) {
                    if (s[0].x == s[i].x && s[0].y == s[i].y) {
                        gameo(app, event);
                    }
                }
            }
        }
        games(app, event);
    }
    return 0;
}

int main(Event event)
{
    RenderWindow app(sf::VideoMode(width, height), "Snake Game", Style::Titlebar);
    game(&app, event);
}