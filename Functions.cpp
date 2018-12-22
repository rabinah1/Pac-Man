#include <Functions.hpp>

std::vector<sf::CircleShape> turningPoints(sf::RenderWindow &window)
{
  std::vector<sf::CircleShape> points;
  int sizeX = window.getSize().x;
  int sizeY = window.getSize().y;

  sf::CircleShape point1(5);
  sf::CircleShape point2(5);
  sf::CircleShape point3(5);
  sf::CircleShape point4(5);
  sf::CircleShape point5(5);
  sf::CircleShape point6(5);
  sf::CircleShape point7(5);
  sf::CircleShape point8(5);
  sf::CircleShape point9(5);
  sf::CircleShape point10(5);
  sf::CircleShape point11(5);
  sf::CircleShape point12(5);
  sf::CircleShape point13(5);
  sf::CircleShape point14(5);
  sf::CircleShape point15(5);
  sf::CircleShape point16(5);
  sf::CircleShape point17(5);
  sf::CircleShape point18(5);
  sf::CircleShape point19(5);
  sf::CircleShape point20(5);
  sf::CircleShape point21(5);
  sf::CircleShape point22(5);
  sf::CircleShape point23(5);
  sf::CircleShape point24(5);
  sf::CircleShape point25(5);
  sf::CircleShape point26(5);
  sf::CircleShape point27(5);
  sf::CircleShape point28(5);
  sf::CircleShape point29(5);
  sf::CircleShape point30(5);

  point1.setFillColor(sf::Color::Red);
  point1.setOrigin(point1.getOrigin().x+point1.getLocalBounds().width/2, point1.getOrigin().y+point1.getLocalBounds().height/2);
  point1.setPosition(window.getSize().x/2*1.05, window.getSize().y/2*1.5);

  point2.setFillColor(sf::Color::Red);
  point2.setOrigin(point2.getOrigin().x+point2.getLocalBounds().width/2, point2.getOrigin().y+point2.getLocalBounds().height/2);
  point2.setPosition(window.getSize().x/2*0.94, window.getSize().y/2*1.5);

  point3.setFillColor(sf::Color::Red);
  point3.setOrigin(point3.getOrigin().x+point3.getLocalBounds().width/2, point3.getOrigin().y+point3.getLocalBounds().height/2);
  point3.setPosition(window.getSize().x/2*1.22, window.getSize().y/2*1.5);

  point4.setFillColor(sf::Color::Red);
  point4.setOrigin(point4.getOrigin().x+point4.getLocalBounds().width/2, point4.getOrigin().y+point4.getLocalBounds().height/2);
  point4.setPosition(window.getSize().x/2*0.77, window.getSize().y/2*1.5);

  point5.setFillColor(sf::Color::Red);
  point5.setOrigin(point5.getOrigin().x+point5.getLocalBounds().width/2, point5.getOrigin().y+point5.getLocalBounds().height/2);
  point5.setPosition(window.getSize().x/2*1.33, window.getSize().y/2*1.5);

  point6.setFillColor(sf::Color::Red);
  point6.setOrigin(point6.getOrigin().x+point6.getLocalBounds().width/2, point6.getOrigin().y+point6.getLocalBounds().height/2);
  point6.setPosition(window.getSize().x/2*0.65, window.getSize().y/2*1.5);

  point7.setFillColor(sf::Color::Red);
  point7.setOrigin(point7.getOrigin().x+point7.getLocalBounds().width/2, point7.getOrigin().y+point7.getLocalBounds().height/2);
  point7.setPosition(window.getSize().x/2*1.05, window.getSize().y/2*1.3);

  point8.setFillColor(sf::Color::Red);
  point8.setOrigin(point8.getOrigin().x+point8.getLocalBounds().width/2, point8.getOrigin().y+point8.getLocalBounds().height/2);
  point8.setPosition(window.getSize().x/2*0.94, window.getSize().y/2*1.3);

  point9.setFillColor(sf::Color::Red);
  point9.setOrigin(point9.getOrigin().x+point9.getLocalBounds().width/2, point9.getOrigin().y+point9.getLocalBounds().height/2);
  point9.setPosition(window.getSize().x/2*1.22, window.getSize().y/2*1.3);

  point10.setFillColor(sf::Color::Red);
  point10.setOrigin(point10.getOrigin().x+point10.getLocalBounds().width/2, point10.getOrigin().y+point10.getLocalBounds().height/2);
  point10.setPosition(window.getSize().x/2*0.77, window.getSize().y/2*1.3);

  point11.setFillColor(sf::Color::Red);
  point11.setOrigin(point11.getOrigin().x+point11.getLocalBounds().width/2, point11.getOrigin().y+point11.getLocalBounds().height/2);
  point11.setPosition(window.getSize().x/2*1.33, window.getSize().y/2*1.3);

  point12.setFillColor(sf::Color::Red);
  point12.setOrigin(point12.getOrigin().x+point12.getLocalBounds().width/2, point12.getOrigin().y+point12.getLocalBounds().height/2);
  point12.setPosition(window.getSize().x/2*0.65, window.getSize().y/2*1.3);

  point13.setFillColor(sf::Color::Red);
  point13.setOrigin(point13.getOrigin().x+point13.getLocalBounds().width/2, point13.getOrigin().y+point13.getLocalBounds().height/2);
  point13.setPosition(window.getSize().x/2*1.05, window.getSize().y/2*1.7);

  point14.setFillColor(sf::Color::Red);
  point14.setOrigin(point14.getOrigin().x+point14.getLocalBounds().width/2, point14.getOrigin().y+point14.getLocalBounds().height/2);
  point14.setPosition(window.getSize().x/2*0.94, window.getSize().y/2*1.7);

  point15.setFillColor(sf::Color::Red);
  point15.setOrigin(point15.getOrigin().x+point15.getLocalBounds().width/2, point15.getOrigin().y+point15.getLocalBounds().height/2);
  point15.setPosition(window.getSize().x/2*1.22, window.getSize().y/2*1.7);

  point16.setFillColor(sf::Color::Red);
  point16.setOrigin(point16.getOrigin().x+point16.getLocalBounds().width/2, point16.getOrigin().y+point16.getLocalBounds().height/2);
  point16.setPosition(window.getSize().x/2*0.77, window.getSize().y/2*1.7);

  point17.setFillColor(sf::Color::Red);
  point17.setOrigin(point17.getOrigin().x+point17.getLocalBounds().width/2, point17.getOrigin().y+point17.getLocalBounds().height/2);
  point17.setPosition(window.getSize().x/2*1.33, window.getSize().y/2*1.7);

  point18.setFillColor(sf::Color::Red);
  point18.setOrigin(point18.getOrigin().x+point18.getLocalBounds().width/2, point18.getOrigin().y+point18.getLocalBounds().height/2);
  point18.setPosition(window.getSize().x/2*0.65, window.getSize().y/2*1.7);

  point19.setFillColor(sf::Color::Red);
  point19.setOrigin(point19.getOrigin().x+point19.getLocalBounds().width/2, point19.getOrigin().y+point19.getLocalBounds().height/2);
  point19.setPosition(window.getSize().x/2*1.22, window.getSize().y/2*1.12);

  point20.setFillColor(sf::Color::Red);
  point20.setOrigin(point20.getOrigin().x+point20.getLocalBounds().width/2, point20.getOrigin().y+point20.getLocalBounds().height/2);
  point20.setPosition(window.getSize().x/2*0.77, window.getSize().y/2*1.12);

  point21.setFillColor(sf::Color::Red);
  point21.setOrigin(point21.getOrigin().x+point21.getLocalBounds().width/2, point21.getOrigin().y+point21.getLocalBounds().height/2);
  point21.setPosition(window.getSize().x/2*1.22, window.getSize().y/2*0.93);

  point22.setFillColor(sf::Color::Red);
  point22.setOrigin(point22.getOrigin().x+point22.getLocalBounds().width/2, point22.getOrigin().y+point22.getLocalBounds().height/2);
  point22.setPosition(window.getSize().x/2*0.77, window.getSize().y/2*0.93);

  point23.setFillColor(sf::Color::Red);
  point23.setOrigin(point23.getOrigin().x+point23.getLocalBounds().width/2, point23.getOrigin().y+point23.getLocalBounds().height/2);
  point23.setPosition(window.getSize().x/2*1.22, window.getSize().y/2*0.77);

  point24.setFillColor(sf::Color::Red);
  point24.setOrigin(point24.getOrigin().x+point24.getLocalBounds().width/2, point24.getOrigin().y+point24.getLocalBounds().height/2);
  point24.setPosition(window.getSize().x/2*0.77, window.getSize().y/2*0.77);

  point25.setFillColor(sf::Color::Red);
  point25.setOrigin(point25.getOrigin().x+point25.getLocalBounds().width/2, point25.getOrigin().y+point25.getLocalBounds().height/2);
  point25.setPosition(window.getSize().x/2*1.05, window.getSize().y/2*0.77);

  point26.setFillColor(sf::Color::Red);
  point26.setOrigin(point26.getOrigin().x+point26.getLocalBounds().width/2, point26.getOrigin().y+point26.getLocalBounds().height/2);
  point26.setPosition(window.getSize().x/2*0.94, window.getSize().y/2*0.77);

  point27.setFillColor(sf::Color::Red);
  point27.setOrigin(point27.getOrigin().x+point27.getLocalBounds().width/2, point27.getOrigin().y+point27.getLocalBounds().height/2);
  point27.setPosition(window.getSize().x/2*1.05, window.getSize().y/2*0.58);

  point28.setFillColor(sf::Color::Red);
  point28.setOrigin(point28.getOrigin().x+point28.getLocalBounds().width/2, point28.getOrigin().y+point28.getLocalBounds().height/2);
  point28.setPosition(window.getSize().x/2*0.94, window.getSize().y/2*0.58);

  point29.setFillColor(sf::Color::Red);
  point29.setOrigin(point29.getOrigin().x+point29.getLocalBounds().width/2, point29.getOrigin().y+point29.getLocalBounds().height/2);
  point29.setPosition(window.getSize().x/2*1.22, window.getSize().y/2*0.58);

  point30.setFillColor(sf::Color::Red);
  point30.setOrigin(point30.getOrigin().x+point30.getLocalBounds().width/2, point30.getOrigin().y+point30.getLocalBounds().height/2);
  point30.setPosition(window.getSize().x/2*0.77, window.getSize().y/2*0.58);

  points.push_back(point1);
  points.push_back(point2);
  points.push_back(point3);
  points.push_back(point4);
  points.push_back(point5);
  points.push_back(point6);
  points.push_back(point7);
  points.push_back(point8);
  points.push_back(point9);
  points.push_back(point10);
  points.push_back(point11);
  points.push_back(point12);
  points.push_back(point13);
  points.push_back(point14);
  points.push_back(point15);
  points.push_back(point16);
  points.push_back(point17);
  points.push_back(point18);
  points.push_back(point19);
  points.push_back(point20);
  points.push_back(point21);
  points.push_back(point22);
  points.push_back(point23);
  points.push_back(point24);
  points.push_back(point25);
  points.push_back(point26);
  points.push_back(point27);
  points.push_back(point28);
  points.push_back(point29);
  points.push_back(point30);
  return points;
}

std::vector<sf::ConvexShape> initMap(sf::RenderWindow &window)
{
  std::vector<sf::ConvexShape> mapShapes;
  int sizeX = window.getSize().x;
  int sizeY = window.getSize().y;
  
  sf::ConvexShape conv1;
  sf::ConvexShape conv2;
  sf::ConvexShape conv3;
  sf::ConvexShape conv4;
  sf::ConvexShape conv5;
  sf::ConvexShape conv6;
  sf::ConvexShape conv7;
  sf::ConvexShape conv8;
  sf::ConvexShape conv9;
  sf::ConvexShape conv10;
  sf::ConvexShape conv11;
  sf::ConvexShape conv12;
  sf::ConvexShape conv13;
  sf::ConvexShape conv14;
  sf::ConvexShape conv15;
  sf::ConvexShape conv16;
  sf::ConvexShape conv17;
  sf::ConvexShape conv18;
  sf::ConvexShape conv19;
  sf::ConvexShape conv20;
  sf::ConvexShape conv21;
  
  conv1.setPointCount(8);
  conv1.setPoint(0, sf::Vector2f(0, 0));
  conv1.setPoint(1, sf::Vector2f(0+20, 0));
  conv1.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv1.setPoint(3, sf::Vector2f(0+180, 0-100));
  conv1.setPoint(4, sf::Vector2f(0+180, 0-120));
  conv1.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv1.setPoint(6, sf::Vector2f(0-170, 0-100));
  conv1.setPoint(7, sf::Vector2f(0, 0-100));
  conv1.setOutlineColor(sf::Color::Blue);
  conv1.setFillColor(sf::Color::Transparent);
  conv1.setOutlineThickness(4);
  conv1.setPosition(sizeX*0.495, sizeY*0.90);

  conv2.setPointCount(8);
  conv2.setPoint(0, sf::Vector2f(0, 0));
  conv2.setPoint(1, sf::Vector2f(0+20, 0));
  conv2.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv2.setPoint(3, sf::Vector2f(0+180, 0-100));
  conv2.setPoint(4, sf::Vector2f(0+180, 0-120));
  conv2.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv2.setPoint(6, sf::Vector2f(0-170, 0-100));
  conv2.setPoint(7, sf::Vector2f(0, 0-100));
  conv2.setOutlineColor(sf::Color::Blue);
  conv2.setFillColor(sf::Color::Transparent);
  conv2.setOutlineThickness(4);
  conv2.setPosition(sizeX*0.495, sizeY*0.71);

  conv3.setPointCount(4);
  conv3.setPoint(0, sf::Vector2f(0, 0));
  conv3.setPoint(1, sf::Vector2f(0+180, 0));
  conv3.setPoint(2, sf::Vector2f(0+180, 0-20));
  conv3.setPoint(3, sf::Vector2f(0, 0-20));
  conv3.setOutlineColor(sf::Color::Blue);
  conv3.setFillColor(sf::Color::Transparent);
  conv3.setOutlineThickness(4);
  conv3.setPosition(sizeX*0.55, sizeY*0.71);

  conv4.setPointCount(4);
  conv4.setPoint(0, sf::Vector2f(0, 0));
  conv4.setPoint(1, sf::Vector2f(0+180, 0));
  conv4.setPoint(2, sf::Vector2f(0+180, 0-20));
  conv4.setPoint(3, sf::Vector2f(0, 0-20));
  conv4.setOutlineColor(sf::Color::Blue);
  conv4.setFillColor(sf::Color::Transparent);
  conv4.setOutlineThickness(4);
  conv4.setPosition(sizeX*0.35, sizeY*0.71);

  conv5.setPointCount(6);
  conv5.setPoint(0, sf::Vector2f(0, 0));
  conv5.setPoint(1, sf::Vector2f(0+20, 0));
  conv5.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv5.setPoint(3, sf::Vector2f(0+100, 0-100));
  conv5.setPoint(4, sf::Vector2f(0+100, 0-120));
  conv5.setPoint(5, sf::Vector2f(0, 0-120));
  conv5.setOutlineColor(sf::Color::Blue);
  conv5.setFillColor(sf::Color::Transparent);
  conv5.setOutlineThickness(4);
  conv5.setPosition(sizeX*0.69, sizeY*0.805);

  conv6.setPointCount(6);
  conv6.setPoint(0, sf::Vector2f(0, 0));
  conv6.setPoint(1, sf::Vector2f(0-20, 0));
  conv6.setPoint(2, sf::Vector2f(0-20, 0-100));
  conv6.setPoint(3, sf::Vector2f(0-100, 0-100));
  conv6.setPoint(4, sf::Vector2f(0-100, 0-120));
  conv6.setPoint(5, sf::Vector2f(0, 0-120));
  conv6.setOutlineColor(sf::Color::Blue);
  conv6.setFillColor(sf::Color::Transparent);
  conv6.setOutlineThickness(4);
  conv6.setPosition(sizeX*0.30, sizeY*0.805);

  conv7.setPointCount(8);
  conv7.setPoint(0, sf::Vector2f(0, 0));
  conv7.setPoint(1, sf::Vector2f(0-390, 0));
  conv7.setPoint(2, sf::Vector2f(0-390, 0-20));
  conv7.setPoint(3, sf::Vector2f(0-190, 0-20));
  conv7.setPoint(4, sf::Vector2f(0-190, 0-120));
  conv7.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv7.setPoint(6, sf::Vector2f(0-170, 0-20));
  conv7.setPoint(7, sf::Vector2f(0, 0-20));
  conv7.setOutlineColor(sf::Color::Blue);
  conv7.setFillColor(sf::Color::Transparent);
  conv7.setOutlineThickness(4);
  conv7.setPosition(sizeX*0.45, sizeY*0.9);

  conv8.setPointCount(8);
  conv8.setPoint(0, sf::Vector2f(0, 0));
  conv8.setPoint(1, sf::Vector2f(0+375, 0));
  conv8.setPoint(2, sf::Vector2f(0+375, 0-20));
  conv8.setPoint(3, sf::Vector2f(0+190, 0-20));
  conv8.setPoint(4, sf::Vector2f(0+190, 0-120));
  conv8.setPoint(5, sf::Vector2f(0+170, 0-120));
  conv8.setPoint(6, sf::Vector2f(0+170, 0-20));
  conv8.setPoint(7, sf::Vector2f(0, 0-20));
  conv8.setOutlineColor(sf::Color::Blue);
  conv8.setFillColor(sf::Color::Transparent);
  conv8.setOutlineThickness(4);
  conv8.setPosition(sizeX*0.55, sizeY*0.9);

  conv9.setPointCount(4);
  conv9.setPoint(0, sf::Vector2f(0, 0));
  conv9.setPoint(1, sf::Vector2f(0+350, 0));
  conv9.setPoint(2, sf::Vector2f(0+350, 0-100));
  conv9.setPoint(3, sf::Vector2f(0, 0-100));
  conv9.setOutlineColor(sf::Color::Blue);
  conv9.setFillColor(sf::Color::Transparent);
  conv9.setOutlineThickness(4);
  conv9.setPosition(sizeX*0.405, sizeY*0.52);

  conv10.setPointCount(4);
  conv10.setPoint(0, sf::Vector2f(0, 0));
  conv10.setPoint(1, sf::Vector2f(0+20, 0));
  conv10.setPoint(2, sf::Vector2f(0+20, 0-120));
  conv10.setPoint(3, sf::Vector2f(0, 0-120));
  conv10.setOutlineColor(sf::Color::Blue);
  conv10.setFillColor(sf::Color::Transparent);
  conv10.setOutlineThickness(4);
  conv10.setPosition(sizeX*0.35, sizeY*0.62);

  conv11.setPointCount(4);
  conv11.setPoint(0, sf::Vector2f(0, 0));
  conv11.setPoint(1, sf::Vector2f(0+20, 0));
  conv11.setPoint(2, sf::Vector2f(0+20, 0-120));
  conv11.setPoint(3, sf::Vector2f(0, 0-120));
  conv11.setOutlineColor(sf::Color::Blue);
  conv11.setFillColor(sf::Color::Transparent);
  conv11.setOutlineThickness(4);
  conv11.setPosition(sizeX*0.63, sizeY*0.62);

  conv12.setPointCount(8);
  conv12.setPoint(0, sf::Vector2f(0, 0));
  conv12.setPoint(1, sf::Vector2f(0+20, 0));
  conv12.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv12.setPoint(3, sf::Vector2f(0+180, 0-100));
  conv12.setPoint(4, sf::Vector2f(0+180, 0-120));
  conv12.setPoint(5, sf::Vector2f(0-170, 0-120));
  conv12.setPoint(6, sf::Vector2f(0-170, 0-100));
  conv12.setPoint(7, sf::Vector2f(0, 0-100));
  conv12.setOutlineColor(sf::Color::Blue);
  conv12.setFillColor(sf::Color::Transparent);
  conv12.setOutlineThickness(4);
  conv12.setPosition(sizeX*0.495, sizeY*0.35);

  conv13.setPointCount(8);
  conv13.setPoint(0, sf::Vector2f(0, 0));
  conv13.setPoint(1, sf::Vector2f(0, 0+20));
  conv13.setPoint(2, sf::Vector2f(0+150, 0+20));
  conv13.setPoint(3, sf::Vector2f(0+150, 0+110));
  conv13.setPoint(4, sf::Vector2f(0+170, 0+110));
  conv13.setPoint(5, sf::Vector2f(0+170, 0-100));
  conv13.setPoint(6, sf::Vector2f(0+150, 0-100));
  conv13.setPoint(7, sf::Vector2f(0+150, 0));
  conv13.setOutlineColor(sf::Color::Blue);
  conv13.setFillColor(sf::Color::Transparent);
  conv13.setOutlineThickness(4);
  conv13.setPosition(sizeX*0.55, sizeY*0.33);

  conv14.setPointCount(8);
  conv14.setPoint(0, sf::Vector2f(0, 0));
  conv14.setPoint(1, sf::Vector2f(0, 0+20));
  conv14.setPoint(2, sf::Vector2f(0-160, 0+20));
  conv14.setPoint(3, sf::Vector2f(0-160, 0+110));
  conv14.setPoint(4, sf::Vector2f(0-180, 0+110));
  conv14.setPoint(5, sf::Vector2f(0-180, 0-100));
  conv14.setPoint(6, sf::Vector2f(0-160, 0-100));
  conv14.setPoint(7, sf::Vector2f(0-160, 0));
  conv14.setOutlineColor(sf::Color::Blue);
  conv14.setFillColor(sf::Color::Transparent);
  conv14.setOutlineThickness(4);
  conv14.setPosition(sizeX*0.446, sizeY*0.33);

  conv15.setPointCount(4);
  conv15.setPoint(0, sf::Vector2f(0, 0));
  conv15.setPoint(1, sf::Vector2f(0+100, 0));
  conv15.setPoint(2, sf::Vector2f(0+100, 0-20));
  conv15.setPoint(3, sf::Vector2f(0, 0-20));
  conv15.setOutlineColor(sf::Color::Blue);
  conv15.setFillColor(sf::Color::Transparent);
  conv15.setOutlineThickness(4);
  conv15.setPosition(sizeX*0.247, sizeY*0.26);

  conv16.setPointCount(4);
  conv16.setPoint(0, sf::Vector2f(0, 0));
  conv16.setPoint(1, sf::Vector2f(0+100, 0));
  conv16.setPoint(2, sf::Vector2f(0+100, 0-20));
  conv16.setPoint(3, sf::Vector2f(0, 0-20));
  conv16.setOutlineColor(sf::Color::Blue);
  conv16.setFillColor(sf::Color::Transparent);
  conv16.setOutlineThickness(4);
  conv16.setPosition(sizeX*0.69, sizeY*0.26);

  conv17.setPointCount(4);
  conv17.setPoint(0, sf::Vector2f(0, 0));
  conv17.setPoint(1, sf::Vector2f(0+100, 0));
  conv17.setPoint(2, sf::Vector2f(0+100, 0+70));
  conv17.setPoint(3, sf::Vector2f(0, 0+70));
  conv17.setOutlineColor(sf::Color::Blue);
  conv17.setFillColor(sf::Color::Transparent);
  conv17.setOutlineThickness(4);
  conv17.setPosition(sizeX*0.247, sizeY*0.09);

  conv18.setPointCount(4);
  conv18.setPoint(0, sf::Vector2f(0, 0));
  conv18.setPoint(1, sf::Vector2f(0+100, 0));
  conv18.setPoint(2, sf::Vector2f(0+100, 0+70));
  conv18.setPoint(3, sf::Vector2f(0, 0+70));
  conv18.setOutlineColor(sf::Color::Blue);
  conv18.setFillColor(sf::Color::Transparent);
  conv18.setOutlineThickness(4);
  conv18.setPosition(sizeX*0.69, sizeY*0.09);

  conv19.setPointCount(4);
  conv19.setPoint(0, sf::Vector2f(0, 0));
  conv19.setPoint(1, sf::Vector2f(0+180, 0));
  conv19.setPoint(2, sf::Vector2f(0+180, 0+70));
  conv19.setPoint(3, sf::Vector2f(0, 0+70));
  conv19.setOutlineColor(sf::Color::Blue);
  conv19.setFillColor(sf::Color::Transparent);
  conv19.setOutlineThickness(4);
  conv19.setPosition(sizeX*0.55, sizeY*0.09);

  conv20.setPointCount(4);
  conv20.setPoint(0, sf::Vector2f(0, 0));
  conv20.setPoint(1, sf::Vector2f(0+180, 0));
  conv20.setPoint(2, sf::Vector2f(0+180, 0+70));
  conv20.setPoint(3, sf::Vector2f(0, 0+70));
  conv20.setOutlineColor(sf::Color::Blue);
  conv20.setFillColor(sf::Color::Transparent);
  conv20.setOutlineThickness(4);
  conv20.setPosition(sizeX*0.35, sizeY*0.09);

  conv21.setPointCount(4);
  conv21.setPoint(0, sf::Vector2f(0, 0));
  conv21.setPoint(1, sf::Vector2f(0+1150, 0));
  conv21.setPoint(2, sf::Vector2f(0+1150, 0+1050));
  conv21.setPoint(3, sf::Vector2f(0, 0+1050));
  conv21.setOutlineColor(sf::Color::Blue);
  conv21.setFillColor(sf::Color::Transparent);
  conv21.setOutlineThickness(4);
  conv21.setPosition(sizeX*0.2, sizeY*0.01);
  
  mapShapes.push_back(conv1);
  mapShapes.push_back(conv2);
  mapShapes.push_back(conv3);
  mapShapes.push_back(conv4);
  mapShapes.push_back(conv5);
  mapShapes.push_back(conv6);
  mapShapes.push_back(conv7);
  mapShapes.push_back(conv8);
  mapShapes.push_back(conv9);
  mapShapes.push_back(conv10);
  mapShapes.push_back(conv11);
  mapShapes.push_back(conv12);
  mapShapes.push_back(conv13);
  mapShapes.push_back(conv14);
  mapShapes.push_back(conv15);
  mapShapes.push_back(conv16);
  mapShapes.push_back(conv17);
  mapShapes.push_back(conv18);
  mapShapes.push_back(conv19);
  mapShapes.push_back(conv20);
  mapShapes.push_back(conv21);
  return mapShapes;
}
