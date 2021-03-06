#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <Main.hpp>
#include <unistd.h>
#include <Player.hpp>
#include <Enemy.hpp>
#include <Functions.hpp>
#include <cstdlib>
#include <time.h>
#include <chrono>

int main()
{
    int retValue = 0;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pac-Man", sf::Style::Fullscreen);
    sf::Event event;
    sf::Font font;
    font.loadFromFile("Ubuntu-B.ttf");
    sf::Text StartButton("Start Game", font, 100);
    sf::Text ExitButton("Exit", font, 100);
    sf::Text TitleText("Pac-Man", font, 200);
    StartButton.setFillColor(sf::Color::Black);
    ExitButton.setFillColor(sf::Color::Black);
    TitleText.setFillColor(sf::Color::Red);
    StartButton.setPosition(window.getSize().x/2-StartButton.getLocalBounds().width/2,
                            window.getSize().y-StartButton.getLocalBounds().height*5);
    ExitButton.setPosition(window.getSize().x/2-ExitButton.getLocalBounds().width/2,
                           window.getSize().y-ExitButton.getLocalBounds().height*2);
    TitleText.setPosition(window.getSize().x/2-TitleText.getLocalBounds().width/2,
                          window.getSize().y-TitleText.getLocalBounds().height*7);

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        if (StartButton.getGlobalBounds().contains(mousePosF)) {
            StartButton.setFillColor(sf::Color::Blue);
        } else if (ExitButton.getGlobalBounds().contains(mousePosF)) {
            ExitButton.setFillColor(sf::Color::Blue);
        } else {
            ExitButton.setFillColor(sf::Color::Black);
            StartButton.setFillColor(sf::Color::Black);
        }
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::MouseButtonPressed:
                if (StartButton.getGlobalBounds().contains(mousePosF)) {
                    retValue = Game(window, font);
                    if (retValue == 1) {
                        window.close();
                        break;
                    }
                } else if (ExitButton.getGlobalBounds().contains(mousePosF)) {
                    window.close();
                    break;
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(StartButton);
        window.draw(ExitButton);
        window.draw(TitleText);
        window.display();
    }
    return 0;
}


int Game(sf::RenderWindow &window, sf::Font font)
{
    int round = 1;
    int control = 1;
    std::string setControl = "Right";
    int speed = 4;
    int enemySpeed = 4;
    int counter = 0;
    int index = 0;
    int pause = 0;
    int currentCont = 0;
    int temp = 0;
    float temp_var = 0.0;
    int sizeX = window.getSize().x;
    int sizeY = window.getSize().y;
    int randDir = 0;
    int checker = 0;
    int loop_check = 0;
    int endRet = 0;
    std::ostringstream ss_points;
    std::ostringstream ss_lives;
    std::ostringstream ss_rounds;
    std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> currPoint;
    sf::Event event;
    sf::Texture pac1;
    sf::Texture pac2;
    sf::Texture pac3;
    sf::Texture pac4;
    sf::Texture pac5;
    sf::Texture E1;
    sf::Texture E2;
    sf::Texture E3;
    sf::Texture E4;
    sf::Text readyText("Get ready!", font, 80);
    sf::Text menuButton("Menu", font, 80);
    sf::Text exitButton("Exit", font, 80);
    sf::Text pointsText("Points: 0", font, 50);
    sf::Text livesText("Lives: 3", font, 50);
    sf::Text roundsText("Round: 1", font, 50);

    readyText.setFillColor(sf::Color::White);
    menuButton.setFillColor(sf::Color::White);
    exitButton.setFillColor(sf::Color::White);
    pointsText.setFillColor(sf::Color::White);
    livesText.setFillColor(sf::Color::White);
    roundsText.setFillColor(sf::Color::White);
    readyText.setPosition(window.getSize().x/2-readyText.getLocalBounds().width/2,
                          window.getSize().y-readyText.getLocalBounds().height*10);
    menuButton.setPosition(window.getSize().x/2-menuButton.getLocalBounds().width/2,
                           window.getSize().y-menuButton.getLocalBounds().height*6);
    exitButton.setPosition(window.getSize().x/2-exitButton.getLocalBounds().width/2,
                           window.getSize().y-exitButton.getLocalBounds().height*3);
    pointsText.setPosition(window.getSize().x*0.82, window.getSize().y*0.11);
    livesText.setPosition(window.getSize().x*0.82, window.getSize().y*0.04);
    roundsText.setPosition(window.getSize().x*0.82, window.getSize().y*0.18);
    pac1.loadFromFile("Pac1.png");
    pac2.loadFromFile("Pac2.png");
    pac3.loadFromFile("Pac3.png");
    pac4.loadFromFile("Pac4.png");
    pac5.loadFromFile("Pac5.png");
    E1.loadFromFile("Enemy1.png");
    E2.loadFromFile("Enemy2.png");
    E3.loadFromFile("Enemy3.png");
    E4.loadFromFile("Enemy4.png");
    E1.setSmooth(true);
    E2.setSmooth(true);
    E3.setSmooth(true);
    E4.setSmooth(true);
    pac1.setSmooth(true);
    pac2.setSmooth(true);
    pac3.setSmooth(true);
    pac4.setSmooth(true);
    pac5.setSmooth(true);
    std::vector<sf::Texture> textureVector;
    textureVector.push_back(pac1);
    textureVector.push_back(pac2);
    textureVector.push_back(pac3);
    textureVector.push_back(pac4);
    textureVector.push_back(pac5);
    textureVector.push_back(pac4);
    textureVector.push_back(pac3);
    textureVector.push_back(pac2);
    textureVector.push_back(pac1);
    int len = textureVector.size();

    sf::Sprite mySprite;
    sf::Sprite Enemy1;
    sf::Sprite Enemy2;
    sf::Sprite Enemy3;
    sf::Sprite Enemy4;

    Enemy1.setTexture(E1);
    Enemy1.setOrigin(Enemy1.getOrigin().x+Enemy1.getLocalBounds().width/2,
                     Enemy1.getOrigin().y+Enemy1.getLocalBounds().height/2);
    Enemy1.setRotation(0);
    Enemy1.setPosition(window.getSize().x/2*0.86, window.getSize().y/2*0.95);

    Enemy2.setTexture(E2);
    Enemy2.setOrigin(Enemy2.getOrigin().x+Enemy2.getLocalBounds().width/2,
                     Enemy2.getOrigin().y+Enemy2.getLocalBounds().height/2);
    Enemy2.setRotation(0);
    Enemy2.setPosition(window.getSize().x/2*0.95, window.getSize().y/2*0.95);

    Enemy3.setTexture(E3);
    Enemy3.setOrigin(Enemy3.getOrigin().x+Enemy3.getLocalBounds().width/2,
                     Enemy3.getOrigin().y+Enemy3.getLocalBounds().height/2);
    Enemy3.setRotation(0);
    Enemy3.setPosition(window.getSize().x/2*1.04, window.getSize().y/2*0.95);

    Enemy4.setTexture(E4);
    Enemy4.setOrigin(Enemy4.getOrigin().x+Enemy4.getLocalBounds().width/2,
                     Enemy4.getOrigin().y+Enemy4.getLocalBounds().height/2);
    Enemy4.setRotation(0);
    Enemy4.setPosition(window.getSize().x/2*1.13, window.getSize().y/2*0.95);

    mySprite.setTexture(pac5);
    mySprite.setTexture(pac1);
    mySprite.setOrigin(mySprite.getOrigin().x+mySprite.getLocalBounds().width/2,
                       mySprite.getOrigin().y+mySprite.getLocalBounds().height/2);
    mySprite.setRotation(0);
    mySprite.setPosition(window.getSize().x/2, window.getSize().y/2*1.5);

    Player player1(0, 3, 0, len, textureVector, mySprite, 2);
    Enemy enemy1(1, Enemy1, E1, 0, 0, 0);
    Enemy enemy2(1, Enemy2, E2, 0, 0, 2);
    Enemy enemy3(1, Enemy3, E3, 0, 0, 4);
    Enemy enemy4(1, Enemy4, E4, 0, 0, 6);
    std::vector<sf::ConvexShape> mapShapes = initMap(window);
    std::vector<sf::ConvexShape> intersect_shapes = mapShapes;
    intersect_shapes.erase(intersect_shapes.begin()+20);
    std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>> turnPoints = turningPoints(window);
    std::vector<sf::CircleShape> collectPoints = collPoints(window);
    std::vector<Enemy> enemyList;
    enemyList.push_back(enemy1);
    enemyList.push_back(enemy2);
    enemyList.push_back(enemy3);
    enemyList.push_back(enemy4);
    int **AdjMat = createAdjacency();

    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
            it->initLines();
            std::vector<std::tuple<int, sf::RectangleShape>> vec = it->getLines();
    }
    for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
        window.draw(*it);
    for (auto it = collectPoints.begin(); it != collectPoints.end(); it++)
        window.draw(*it);
    window.draw(enemy1.getSprite());
    window.draw(enemy2.getSprite());
    window.draw(enemy3.getSprite());
    window.draw(enemy4.getSprite());
    window.draw(player1.getSprite());
    window.draw(readyText);
    window.draw(pointsText);
    window.draw(livesText);
    window.draw(roundsText);
    window.display();
    sleep(3);
    std::chrono::steady_clock sc;
    auto start = sc.now();
    auto current = sc.now();
    int intersect_flag = 0;
    int collection_delay = 0;

    while (window.isOpen()) {
        sf::Text pointsText("Points: "+ss_points.str(), font, 50);
        sf::Text livesText("Lives: "+ss_lives.str(), font, 50);
        sf::Text roundsText("Round: "+ss_rounds.str(), font, 50);
        pointsText.setFillColor(sf::Color::White);
        livesText.setFillColor(sf::Color::White);
        pointsText.setPosition(window.getSize().x*0.82, window.getSize().y*0.11);
        livesText.setPosition(window.getSize().x*0.82, window.getSize().y*0.04);
        roundsText.setPosition(window.getSize().x*0.82, window.getSize().y*0.18);
        ss_points.str("");
        ss_lives.str("");
        ss_rounds.str("");
        ss_points << player1.getPoints();
        ss_lives << player1.getLives();
        ss_rounds << round;
        current = sc.now();
        sf::Vector2f spritePos = player1.getPos();
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
            std::vector<std::tuple<int, sf::RectangleShape>> vec = it->getLines();
            for (auto temp = vec.begin(); temp != vec.end(); temp++) {
                if (std::get<1>(*temp).getGlobalBounds().intersects(player1.getSprite().getGlobalBounds())) {
                    for (auto it_map = intersect_shapes.begin(); it_map != intersect_shapes.end(); it_map++) {
                        if (std::get<1>(*temp).getGlobalBounds().intersects(it_map->getGlobalBounds())) {
                            // 1 = left, 2 = up, 3 = right, 4 = down
                            int PC = it_map->getPointCount(); // point count of the shape
                            std::vector<sf::Vector2f> corner_list;
                            for (int i = 0; i < PC; i++) {
                                auto temp_point = it_map->getPoint(i);
                                temp_point.x = it_map->getPosition().x+it_map->getPoint(i).x;
                                temp_point.y = it_map->getPosition().y+it_map->getPoint(i).y;
                                corner_list.push_back(temp_point);
                            }
                            // corner_list contains the coordinates of the intersecting shape
                            if (std::get<0>(*temp) == 1) { // Intersection with player and shape was at left
                                int point_check_up = 0;
                                int point_check_up_enemy = 0;
                                int point_check_down = 0;
                                int point_check_down_enemy = 0;
                                for (int i = 0; i < PC; i++) {
                                    if (corner_list[i].x > player1.getPos().x && corner_list[i].y < player1.getPos().y+20) {
                                        point_check_up = 1;
                                        if (corner_list[i].x < (*it).getPos().x)
                                            point_check_up_enemy = 1;
                                    }
                                    if (corner_list[i].x > player1.getPos().x && corner_list[i].y > player1.getPos().y-20) {
                                        point_check_down = 1;
                                        if (corner_list[i].x < (*it).getPos().x)
                                            point_check_down_enemy = 1;
                                    }
                                }
                                if (point_check_up == 1 && point_check_down == 1) {
                                    if ((*it).getSprite().getGlobalBounds().intersects(it_map->getGlobalBounds())) {
                                        if (point_check_up_enemy == 1 && point_check_down_enemy == 1) {
                                            intersect_flag = 1;
                                            break;
                                        }
                                    } else {
                                        intersect_flag = 1;
                                        break;
                                    }
                                }
                            } else if (std::get<0>(*temp) == 2) { // Intersection with player and shape was at up
                                int point_check_left = 0;
                                int point_check_left_enemy = 0;
                                int point_check_right = 0;
                                int point_check_right_enemy = 0;
                                for (int i = 0; i < PC; i++) {
                                    if (corner_list[i].y > player1.getPos().y && corner_list[i].x < player1.getPos().x+20) {
                                        point_check_left = 1;
                                        if (corner_list[i].y < (*it).getPos().y)
                                            point_check_left_enemy = 1;
                                    }
                                    if (corner_list[i].y > player1.getPos().y && corner_list[i].x > player1.getPos().x-20) {
                                        point_check_right = 1;
                                        if (corner_list[i].y < (*it).getPos().y)
                                            point_check_right_enemy = 1;
                                    }
                                }
                                if (point_check_left == 1 && point_check_right == 1) {
                                    if ((*it).getSprite().getGlobalBounds().intersects(it_map->getGlobalBounds())) {
                                        if (point_check_left_enemy == 1 && point_check_right_enemy == 1) {
                                            intersect_flag = 1;
                                            break;
                                        }
                                    } else {
                                        intersect_flag = 1;
                                        break;
                                    }
                                }
                            } else if (std::get<0>(*temp) == 3) { // Intersection with player and shape was at right
                                int point_check_up = 0;
                                int point_check_up_enemy = 0;
                                int point_check_down = 0;
                                int point_check_down_enemy = 0;
                                for (int i = 0; i < PC; i++) {
                                    if (corner_list[i].x < player1.getPos().x && corner_list[i].y < player1.getPos().y+20) {
                                        point_check_up = 1;
                                        if (corner_list[i].x > (*it).getPos().x)
                                            point_check_up_enemy = 1;
                                    }
                                    if (corner_list[i].x < player1.getPos().x && corner_list[i].y > player1.getPos().y-20) {
                                        point_check_down = 1;
                                        if (corner_list[i].x > (*it).getPos().x)
                                            point_check_down_enemy = 1;
                                    }
                                }
                                if (point_check_up == 1 && point_check_down == 1) {
                                    if ((*it).getSprite().getGlobalBounds().intersects(it_map->getGlobalBounds())) {
                                        if (point_check_up_enemy == 1 && point_check_down_enemy == 1) {
                                            intersect_flag = 1;
                                            break;
                                        }
                                    } else {
                                        intersect_flag = 1;
                                        break;
                                    }
                                }
                            } else if (std::get<0>(*temp) == 4) { // Intersection with player and shape was at down
                                int point_check_left = 0;
                                int point_check_left_enemy = 0;
                                int point_check_right = 0;
                                int point_check_right_enemy = 0;
                                for (int i = 0; i < PC; i++) {
                                    if (corner_list[i].y < player1.getPos().y && corner_list[i].x < player1.getPos().x+20) {
                                        point_check_left = 1;
                                        if (corner_list[i].y > (*it).getPos().y)
                                            point_check_left_enemy = 1;
                                    }
                                    if (corner_list[i].y < player1.getPos().y && corner_list[i].x > player1.getPos().x-20) {
                                        point_check_right = 1;
                                        if (corner_list[i].y > (*it).getPos().y)
                                            point_check_right_enemy = 1;
                                    }
                                }
                                if (point_check_left == 1 && point_check_right == 1) {
                                    if ((*it).getSprite().getGlobalBounds().intersects(it_map->getGlobalBounds())) {
                                        if (point_check_left_enemy == 1 && point_check_right_enemy == 1) {
                                            intersect_flag = 1;
                                            break;
                                        }
                                    } else {
                                        intersect_flag = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (intersect_flag == 1) {
                        intersect_flag = 0;
                        continue;
                    } else { // If there was an intersection with the player and no obstacles
                        if (std::get<0>(*temp) == 1) { // left
                            // If the enemy moves horizontally, do nothing
                            // If the enemy moves vertically
                            int min_dist = 100000;
                            std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>>::iterator min_point;
                            if (it->getDir() == 3 || it->getDir() == 4) {
                                // loop every turnpoint, and get the one that is closest in the axis of movement
                                for (auto point_it = turnPoints.begin(); point_it != turnPoints.end(); point_it++) {
                                    // If a turnpoint is on the axis of movement of the enemy
                                    if (abs(std::get<0>(*point_it).getPosition().x - it->getPos().x) <= 20) {
                                        if (abs(std::get<0>(*point_it).getPosition().y - it->getPos().y) <= min_dist) {
                                            min_dist = abs(std::get<0>(*point_it).getPosition().y - it->getPos().y);
                                            min_point = point_it;
                                        }
                                    }
                                }
                                if (std::get<0>(*min_point).getPosition().y > it->getPos().y)
                                    it->setDir(4);
                                else
                                    it->setDir(3);
                            }
                            it->setVisibleFlag(1);
                            it->setNextDir(1);
                            it->setLastPlayerCoord_x(player1.getPos().x);
                            it->setXCoordFlag(1);
                            it->setYCoordFlag(0);
                        } else if (std::get<0>(*temp) == 2) { // up
                            // If the enemy moves vertically, do nothing
                            // If the enemy moves horizontally
                            int min_dist = 100000;
                            std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>>::iterator min_point;
                            if (it->getDir() == 1 || it->getDir() == 2) {
                                // loop every turnpoint, and get the one that is closes in the axis of movement
                                for (auto point_it = turnPoints.begin(); point_it != turnPoints.end(); point_it++) {
                                    // If a turnpoint is on the axis of movement of the enemy
                                    if (abs(std::get<0>(*point_it).getPosition().y - it->getPos().y) <= 20) {
                                        if (abs(std::get<0>(*point_it).getPosition().x - it->getPos().x) <= min_dist) {
                                            min_dist = abs(std::get<0>(*point_it).getPosition().x - it->getPos().x);
                                            min_point = point_it;
                                        }
                                    }
                                }
                                if (std::get<0>(*min_point).getPosition().x > it->getPos().x)
                                    it->setDir(2);
                                else
                                    it->setDir(1);
                            }
                            it->setVisibleFlag(1);
                            it->setNextDir(3);
                            it->setLastPlayerCoord_y(player1.getPos().y);
                            it->setYCoordFlag(1);
                            it->setXCoordFlag(0);
                        } else if (std::get<0>(*temp) == 3) { // right
                            // If the enemy moves horizontally, do nothing
                            // If the enemy moves vertically
                            int min_dist = 100000;
                            std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>>::iterator min_point;
                            if (it->getDir() == 3 || it->getDir() == 4) {
                                // loop every turnpoint, and get the one that is closes in the axis of movement
                                for (auto point_it = turnPoints.begin(); point_it != turnPoints.end(); point_it++) {
                                    // If a turnpoint is on the axis of movement of the enemy
                                    if (abs(std::get<0>(*point_it).getPosition().x - it->getPos().x) <= 20) {
                                        if (abs(std::get<0>(*point_it).getPosition().y - it->getPos().y) <= min_dist) {
                                            min_dist = abs(std::get<0>(*point_it).getPosition().y - it->getPos().y);
                                            min_point = point_it;
                                        }
                                    }
                                }
                                if (std::get<0>(*min_point).getPosition().y > it->getPos().y)
                                    it->setDir(4);
                                else
                                    it->setDir(3);
                            }
                            it->setVisibleFlag(1);
                            it->setNextDir(2);
                            it->setLastPlayerCoord_x(player1.getPos().x);
                            it->setXCoordFlag(1);
                            it->setYCoordFlag(0);
                        } else if (std::get<0>(*temp) == 4) { // down
                            // If the enemy moves vertically, do nothing
                            // If the enemy moves horizontally
                            int min_dist = 100000;
                            std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>>::iterator min_point;
                            if (it->getDir() == 1 || it->getDir() == 2) {
                                // loop every turnpoint, and get the one that is closes in the axis of movement
                                for (auto point_it = turnPoints.begin(); point_it != turnPoints.end(); point_it++) {
                                    // If a turnpoint is on the axis of movement of the enemy
                                    if (abs(std::get<0>(*point_it).getPosition().y - it->getPos().y) <= 20) {
                                        if (abs(std::get<0>(*point_it).getPosition().x - it->getPos().x) <= min_dist) {
                                            min_dist = abs(std::get<0>(*point_it).getPosition().x - it->getPos().x);
                                            min_point = point_it;
                                        }
                                    }
                                }
                                if (std::get<0>(*min_point).getPosition().x > it->getPos().x)
                                    it->setDir(2);
                                else
                                    it->setDir(1);
                            }
                            it->setVisibleFlag(1);
                            it->setNextDir(4);
                            it->setLastPlayerCoord_y(player1.getPos().y);
                            it->setYCoordFlag(1);
                            it->setXCoordFlag(0);
                        }
                    }
                }
            }
            if (it->getSprite().getGlobalBounds().intersects(player1.getSprite().getGlobalBounds())) {
                if (player1.getLives() > 0) {
                    player1.decLives();
                    temp_var = 0.0;
                    for (auto end_it = enemyList.begin(); end_it != enemyList.end(); end_it++) {
                        end_it->setPos(sf::Vector2f(window.getSize().x/2*(0.86+temp_var), window.getSize().y/2*0.95));
                        end_it->setStartPos(0);
                        end_it->setDir(0);
                        end_it->setChecker(0);
                        end_it->setXCoordFlag(0);
                        end_it->setYCoordFlag(0);
                        end_it->setLastPlayerCoord_y(0.0);
                        end_it->setLastPlayerCoord_x(0.0);
                        end_it->setVisibleFlag(0);
                        end_it->resetDirCounter();
                        temp_var = temp_var+0.09;
                    }
                    player1.setPos(sf::Vector2f(window.getSize().x/2, window.getSize().y/2*1.5));
                    player1.setDir(0);
                    player1.setRot(0);
                    setControl = "Right";
                    control = 1;
                    temp = 0;
                    loop_check = 0;
                    sleep(2);
                    start = sc.now();
                    break;
                } else {
                    for (int h = 0; h < 72; h++)
                        delete [] AdjMat[h];
                    delete [] AdjMat;
                    AdjMat = 0;
                    endRet = gameOver(window, font);
                    return endRet;
                }
            }
        }
        loop_check = 0;

        for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
            if (it->getDirCounter() <= 4)
                it->incDirCounter();
        }

        if (collection_delay > 0)
            collection_delay -= 1;

        for (auto collect_it = collectPoints.begin(); collect_it != collectPoints.end(); collect_it++) {
            if ((*collect_it).getGlobalBounds().intersects(player1.getSprite().getGlobalBounds()) and collection_delay == 0) {
                if (collectPoints.size() <= 1) {
                    round += 1;
                    player1.incLives();
                    player1.incPoints();
                    temp_var = 0.0;
                    for (auto end_it = enemyList.begin(); end_it != enemyList.end(); end_it++) {
                        end_it->setPos(sf::Vector2f(window.getSize().x/2*(0.86+temp_var), window.getSize().y/2*0.95));
                        end_it->setStartPos(0);
                        end_it->setDir(0);
                        end_it->setChecker(0);
                        end_it->setXCoordFlag(0);
                        end_it->setYCoordFlag(0);
                        end_it->setLastPlayerCoord_y(0.0);
                        end_it->setLastPlayerCoord_x(0.0);
                        end_it->setVisibleFlag(0);
                        end_it->resetDirCounter();
                        temp_var = temp_var+0.09;
                    }
                    player1.setPos(sf::Vector2f(window.getSize().x/2, window.getSize().y/2*1.5));
                    player1.setDir(0);
                    player1.setRot(0);
                    setControl = "Right";
                    control = 1;
                    temp = 0;
                    loop_check = 0;
                    sleep(2);
                    start = sc.now();
                    collectPoints = collPoints(window);
                    break;
                }
                if (collect_it == collectPoints.end()-1) {
                    player1.incPoints();
                    collectPoints.pop_back();
                    collection_delay = 20;
                    break;
                } else {
                    player1.incPoints();
                    collectPoints.erase(collect_it);
                    collection_delay = 20;
                    break;
                }
            }
        }

        for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
            if (static_cast<std::chrono::duration<double>>(current-start).count() < it->getStartDelay())
                continue;
            if (loop_check <= 1) { // The first two enemies
                if (it->getPos().x <= sizeX*0.5 && it->getStartPos() == 0) {
                    it->setPos(sf::Vector2f((*it).getPos().x+enemySpeed, it->getPos().y));
                } else if (it->getStartPos() == 0) {
                    if (it->getPos().y >= sizeY/2*0.77) {
                        it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y-enemySpeed));
                    } else {
                        it->setStartPos(1);
                        it->setInitRand(rand() % 2);
                    }
                }
            } else { // The last two enemies
                if (it->getPos().x >= sizeX*0.5 && it->getStartPos() == 0) {
                    it->setPos(sf::Vector2f((*it).getPos().x-enemySpeed, it->getPos().y));
                } else if (it->getStartPos() == 0) {
                    if (it->getPos().y >= sizeY/2*0.77) {
                        it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y-enemySpeed));
                    } else {
                        it->setStartPos(1);
                        it->setInitRand(rand() % 2);
                    }
                }
            }
            loop_check++;
        }

        for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
            if (it->getStartPos() == 1 && it->getChecker() == 0) {
                it->setChecker(1);
                if (it->getInitRand() == 0)
                    it->setDir(1);
                else
                    it->setDir(2);
            }
        }

        for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
            if (it->getDir() == 1) // left
                it->setPos(sf::Vector2f(it->getPos().x - enemySpeed, it->getPos().y));
            else if ((*it).getDir() == 2) // right
                it->setPos(sf::Vector2f(it->getPos().x + enemySpeed, it->getPos().y));
            else if (it->getDir() == 3) // up
                it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y - enemySpeed));
            else if ((*it).getDir() == 4) // down
                it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y + enemySpeed));
        }

        if (counter == 2) {
            counter = 0;
            if (temp == 0)
                player1.changeTexture();
        }
        counter = counter + 1;
        for (auto it = turnPoints.begin(); it != turnPoints.end(); it++) {
            if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 &&
                abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 &&
                ((std::get<1>(*it) != "Left" && control == 2) || (std::get<2>(*it) != "Right" && control == 1) ||
                 (std::get<3>(*it) != "Up" && control == 3) || (std::get<4>(*it) != "Down" && control == 4))) {
                temp = 1;
                speed = 0;
                currPoint = *it;
                break;
            }
        }

        for (auto enemy_it = enemyList.begin(); enemy_it != enemyList.end(); enemy_it++) {
            for (auto it = turnPoints.begin(); it != turnPoints.end(); it++) {
                if (abs(std::get<0>(*it).getPosition().x - enemy_it->getPos().x) <= 4 &&
                    abs(std::get<0>(*it).getPosition().y - enemy_it->getPos().y) <= 4 &&
                    enemy_it->getDirCounter() > 3 && enemy_it->getVisibleFlag() == 0) {
                    enemy_it->resetDirCounter();
                    enemy_it->incCrossCount();
                    std::vector<int> dirVector;
                    if (std::get<1>(*it) == "Left")
                        dirVector.push_back(1);
                    if (std::get<2>(*it) == "Right")
                        dirVector.push_back(2);
                    if (std::get<3>(*it) == "Up")
                        dirVector.push_back(3);
                    if (std::get<4>(*it) == "Down")
                        dirVector.push_back(4);
                    int vSize = dirVector.size();
                    srand(time(0) + enemy_it->getCrossCount());
                    randDir = rand() % vSize;
                    enemy_it->setDir(dirVector.at(randDir));
                } else if (abs(std::get<0>(*it).getPosition().x - enemy_it->getPos().x) <= 4 &&
                           abs(std::get<0>(*it).getPosition().y - enemy_it->getPos().y) <= 4 &&
                           enemy_it->getDirCounter() > 3 && enemy_it->getVisibleFlag() == 1) {
                    if (enemy_it->getXCoordFlag() == 1) {
                        if (abs(enemy_it->getLastPlayerCoord_x() - enemy_it->getPos().x) <= 15) {
                            enemy_it->setVisibleFlag(0);
                            enemy_it->setXCoordFlag(0);
                            enemy_it->setYCoordFlag(0);
                        }
                    } else if (enemy_it->getYCoordFlag() == 1) {
                        if (abs(enemy_it->getLastPlayerCoord_y() - enemy_it->getPos().y) <= 15) {
                            enemy_it->setVisibleFlag(0);
                            enemy_it->setXCoordFlag(0);
                            enemy_it->setYCoordFlag(0);
                        }
                    }
                    enemy_it->setDir(enemy_it->getNextDir());
                }
            }
        }
        if (setControl == "Right") {
            if (control == 2) {
                control = 1;
            } else {
                for (auto it = turnPoints.begin(); it != turnPoints.end(); it++) {
                    if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 &&
                        abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<2>(*it) == "Right") {
                        control = 1;
                        break;
                    }
                }
            }
        } else if (setControl == "Left") {
            if (control == 1) {
                control = 2;
            } else {
                for (auto it = turnPoints.begin(); it != turnPoints.end(); it++) {
                    if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 &&
                        abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<1>(*it) == "Left") {
                        control = 2;
                        break;
                    }
                }
            }
        } else if (setControl == "Up") {
            if (control == 4) {
                control = 3;
            } else {
                for (auto it = turnPoints.begin(); it != turnPoints.end(); it++) {
                    if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 &&
                        abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<3>(*it) == "Up") {
                        control = 3;
                        break;
                    }
                }
            }
        } else if (setControl == "Down") {
            if (control == 3) {
                control = 4;
            } else {
                for (auto it = turnPoints.begin(); it != turnPoints.end(); it++) {
                    if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 &&
                        abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<4>(*it) == "Down") {
                        control = 4;
                        break;
                    }
                }
            }
        }
        if (control == 1) { // Right
            if (temp == 0) {
                speed = 4;
            } else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") ||
                       (std::get<2>(currPoint) == "Right" && setControl == "Right") ||
                       (std::get<3>(currPoint) == "Up" && setControl == "Up") ||
                       (std::get<4>(currPoint) == "Down" && setControl == "Down")) {
                temp = 0;
                speed = 4;
            }
            player1.setDir(1);
            player1.setRot(0);
            player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x+speed, player1.getSprite().getPosition().y));
        } else if (control == 2) { // Left
            if (temp == 0) {
                speed = 4;
            } else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") ||
                       (std::get<2>(currPoint) == "Right" && setControl == "Right") ||
                       (std::get<3>(currPoint) == "Up" && setControl == "Up") ||
                       (std::get<4>(currPoint) == "Down" && setControl == "Down")) {
                temp = 0;
                speed = 4;
            }
            player1.setDir(2);
            player1.setRot(180);
            player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x-speed, player1.getSprite().getPosition().y));
        } else if (control == 3) { // Up
            if (temp == 0) {
                speed = 4;
            } else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") ||
                       (std::get<2>(currPoint) == "Right" && setControl == "Right") ||
                       (std::get<3>(currPoint) == "Up" && setControl == "Up") ||
                       (std::get<4>(currPoint) == "Down" && setControl == "Down")) {
                temp = 0;
                speed = 4;
            }
            player1.setDir(3);
            player1.setRot(270);
            player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y-speed));
        } else if (control == 4) { // Down
            if (temp == 0) {
                speed = 4;
            } else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") ||
                       (std::get<2>(currPoint) == "Right" && setControl == "Right") ||
                       (std::get<3>(currPoint) == "Up" && setControl == "Up") ||
                       (std::get<4>(currPoint) == "Down" && setControl == "Down")) {
                temp = 0;
                speed = 4;
            }
            player1.setDir(4);
            player1.setRot(90);
            player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y+speed));
        }
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    while (1) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                        if (menuButton.getGlobalBounds().contains(mousePosF)) {
                            menuButton.setFillColor(sf::Color::Blue);
                        } else if (exitButton.getGlobalBounds().contains(mousePosF)) {
                            exitButton.setFillColor(sf::Color::Blue);
                        } else {
                            menuButton.setFillColor(sf::Color::White);
                            exitButton.setFillColor(sf::Color::White);
                        }
                        while (window.pollEvent(event)) {
                            switch (event.type) {
                            case sf::Event::KeyPressed:
                                if (event.key.code == sf::Keyboard::Escape) {
                                    pause = 1;
                                    break;
                                }
                            case sf::Event::MouseButtonPressed:
                                if (menuButton.getGlobalBounds().contains(mousePosF)) {
                                    for (int h = 0; h < 72; h++)
                                        delete [] AdjMat[h];
                                    delete [] AdjMat;
                                    AdjMat = 0;
                                    return 0;
                                } else if (exitButton.getGlobalBounds().contains(mousePosF)) {
                                    for (int h = 0; h < 72; h++)
                                        delete [] AdjMat[h];
                                    delete [] AdjMat;
                                    AdjMat = 0;
                                    return 1;
                                }
                            }
                        }
                        window.clear(sf::Color::Black);
                        for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
                            window.draw(*it);
                        for (auto it = collectPoints.begin(); it != collectPoints.end(); it++)
                            window.draw(*it);
                        for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
                            window.draw(it->getSprite());
                            std::vector<std::tuple<int, sf::RectangleShape>> vec = it->getLines();
                        }
                        window.draw(player1.getSprite());
                        window.draw(menuButton);
                        window.draw(exitButton);
                        window.draw(pointsText);
                        window.draw(livesText);
                        window.draw(roundsText);
                        window.display();
                        if (pause == 1) {
                            pause = 0;
                            break;
                        }
                    }
                } else if (event.key.code == sf::Keyboard::Up) {
                    setControl = "Up";
                } else if (event.key.code == sf::Keyboard::Down) {
                    setControl = "Down";
                } else if (event.key.code == sf::Keyboard::Left) {
                    setControl = "Left";
                } else if (event.key.code == sf::Keyboard::Right) {
                    setControl = "Right";
                }
            }
        }
        window.clear(sf::Color::Black);
        for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
            window.draw(*it);
        for (auto it = collectPoints.begin(); it != collectPoints.end(); it++)
            window.draw(*it);
        for (auto it = enemyList.begin(); it != enemyList.end(); it++) {
            window.draw(it->getSprite());
            it->updateLines();
            std::vector<std::tuple<int, sf::RectangleShape>> vec = it->getLines();
        }
        window.draw(player1.getSprite());
        window.draw(pointsText);
        window.draw(livesText);
        window.draw(roundsText);
        window.display();
    }
    return 0;
}
