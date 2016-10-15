
/* Name : Steven Kronmueller
 * Course : CST8236 - Graphics
 * Project 1 : Rotating Windmills
 * Date : October 14th, 2016
 *
 * This program makes 3 Bowsermills and unfortunately the rotations do not working exactly like the example.
 *
 */

#include <SFML/Graphics.hpp>
#include "TransformNode.h"
#include <iostream>
#include <SFML/Audio.hpp>

int main(int argc, char* argv)
{
	sf::RenderWindow window(sf::VideoMode(950, 800), "Project 1 - BowserMills");

	// Creating all the shapes for windmill 1
	sf::CircleShape windmillFan1(25.0f, 25.0f);
	sf::RectangleShape windmill1Arm1(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill1Arm2(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill1Arm3(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill1Arm4(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmillBase(sf::Vector2<float>(100.0f, 300.0f));

	// Creating all the shapes for windmill 2
	sf::CircleShape windmillFan2(25.0f, 25.0f);
	sf::RectangleShape windmill2Arm1(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill2Arm2(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill2Arm3(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill2Arm4(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmillBase2(sf::Vector2<float>(100.0f, 300.0f));

	// Creating all the shapes for windmill 3
	sf::CircleShape windmillFan3(25.0f, 25.0f);
	sf::RectangleShape windmill3Arm1(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill3Arm2(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill3Arm3(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmill3Arm4(sf::Vector2<float>(100.0f, 20.0f));
	sf::RectangleShape windmillBase3(sf::Vector2<float>(100.0f, 300.0f));

	/* Coloring the shapres (For testing)
	windmillFan1.setFillColor(sf::Color::Magenta);
	windmill1Arm1.setFillColor(sf::Color::White);
	windmill1Arm2.setFillColor(sf::Color::Blue);
	windmill1Arm3.setFillColor(sf::Color::Green);
	windmill1Arm4.setFillColor(sf::Color::Yellow);

	windmillFan2.setFillColor(sf::Color::Magenta);
	windmill2Arm1.setFillColor(sf::Color::White);
	windmill2Arm2.setFillColor(sf::Color::Blue);
	windmill2Arm3.setFillColor(sf::Color::Green);
	windmill2Arm4.setFillColor(sf::Color::Yellow);

	windmillFan3.setFillColor(sf::Color::Magenta);
	windmill3Arm1.setFillColor(sf::Color::White);
	windmill3Arm2.setFillColor(sf::Color::Blue);
	windmill3Arm3.setFillColor(sf::Color::Green);
	windmill3Arm4.setFillColor(sf::Color::Yellow);
	*/

	// Giving our windmill base(s) a texture (Bowser)
	sf::Texture windmillBaseTexture;
	windmillBaseTexture.loadFromFile("res/Bowser.jpg");

	// Giving our windmill arm(s) a texture (Fireballs)
	sf::Texture windmillArmTexture;
	windmillArmTexture.loadFromFile("res/Fireball.png");

	// Giving our windmill fan(s) a texture (Mushroom)
	sf::Texture windmillFanTexture;
	windmillFanTexture.loadFromFile("res/Mushroom.jpg");

	// Giving our background a texture (Bowser Castle)
	sf::Texture bowserTexture;
	bowserTexture.loadFromFile("res/BowserCastle.png");
	bowserTexture.setRepeated(true);

	// Giving our sprite the bowser castle texture
	sf::Sprite bowserCastleSprite;
	bowserCastleSprite.setTexture(bowserTexture);
	bowserCastleSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

	// Loading Audio (Mario Music)
	sf::SoundBuffer buffer;
	buffer.loadFromFile("res/Music.wav");
	sf::Sound sound(buffer);

	// Set our windmills position
	windmillBase.setPosition(200.0f, 400.0f);
	windmillBase2.setPosition(450.0f, 400.0f);
	windmillBase3.setPosition(700.0f, 400.0f);

	// Set our windmills origin to the center of their towers (ie. half the size of the x and half the size of the y)
	windmillBase.setOrigin(50.0f, 150.0f);
	windmillBase2.setOrigin(50.0f, 150.0f);
	windmillBase3.setOrigin(50.0f, 150.0f);

	// Set the positions of our windmill fans (positioned in bowser's hand)
	windmillFan1.setPosition(10.0f, -125.0f);
	windmillFan2.setPosition(10.0f, -125.0f);
	windmillFan3.setPosition(10.0f, -125.0f);

	// Set the origins of our windmill fans
	windmillFan1.setOrigin(0.0f, 0.0f);
	windmillFan2.setOrigin(0.0f, 0.0f);
	windmillFan3.setOrigin(0.0f, 0.0f);

	// Setting our windmill arms 90 degress apart
	windmill1Arm1.setRotation(45.0f);
	windmill1Arm2.setRotation(135.0f);
	windmill1Arm3.setRotation(225.0f);
	windmill1Arm4.setRotation(315.0f);
	
	windmill2Arm1.setRotation(45.0f);
	windmill2Arm2.setRotation(135.0f);
	windmill2Arm3.setRotation(225.0f);
	windmill2Arm4.setRotation(315.0f);

	windmill3Arm1.setRotation(45.0f);
	windmill3Arm2.setRotation(135.0f);
	windmill3Arm3.setRotation(225.0f);
	windmill3Arm4.setRotation(315.0f);

	// Setting the positions of our windmill arms
	windmill1Arm1.setPosition(25.0f, 25.0f);
	windmill1Arm2.setPosition(25.0f, 25.0f);
	windmill1Arm3.setPosition(25.0f, 25.0f);
	windmill1Arm4.setPosition(25.0f, 25.0f);

	windmill2Arm1.setPosition(25.0f, 25.0f);
	windmill2Arm2.setPosition(25.0f, 25.0f);
	windmill2Arm3.setPosition(25.0f, 25.0f);
	windmill2Arm4.setPosition(25.0f, 25.0f);

	windmill3Arm1.setPosition(25.0f, 25.0f);
	windmill3Arm2.setPosition(25.0f, 25.0f);
	windmill3Arm3.setPosition(25.0f, 25.0f);
	windmill3Arm4.setPosition(25.0f, 25.0f);

	// Setting the origins of our windmill arms
	windmill1Arm1.setOrigin(10.0f, 10.0f);
	windmill1Arm2.setOrigin(10.0f, 10.0f);
	windmill1Arm3.setOrigin(10.0f, 10.0f);
	windmill1Arm4.setOrigin(10.0f, 10.0f);

	windmill2Arm1.setOrigin(10.0f, 10.0f);
	windmill2Arm2.setOrigin(10.0f, 10.0f);
	windmill2Arm3.setOrigin(10.0f, 10.0f);
	windmill2Arm4.setOrigin(10.0f, 10.0f);

	windmill3Arm1.setOrigin(10.0f, 10.0f);
	windmill3Arm2.setOrigin(10.0f, 10.0f);
	windmill3Arm3.setOrigin(10.0f, 10.0f);
	windmill3Arm4.setOrigin(10.0f, 10.0f);

	
	// Adding our textures to our windmills (Mushrooms, Fireballs, Bowsers)
	windmillFan1.setTexture(&windmillFanTexture);
	windmill1Arm1.setTexture(&windmillArmTexture);
	windmill1Arm2.setTexture(&windmillArmTexture);
	windmill1Arm3.setTexture(&windmillArmTexture);
	windmill1Arm4.setTexture(&windmillArmTexture);
	windmillBase.setTexture(&windmillBaseTexture);

	windmillFan2.setTexture(&windmillFanTexture);
	windmill2Arm1.setTexture(&windmillArmTexture);
	windmill2Arm2.setTexture(&windmillArmTexture);
	windmill2Arm3.setTexture(&windmillArmTexture);
	windmill2Arm4.setTexture(&windmillArmTexture);
	windmillBase2.setTexture(&windmillBaseTexture);

	windmillFan3.setTexture(&windmillFanTexture);
	windmill3Arm1.setTexture(&windmillArmTexture);
	windmill3Arm2.setTexture(&windmillArmTexture);
	windmill3Arm3.setTexture(&windmillArmTexture);
	windmill3Arm4.setTexture(&windmillArmTexture);
	windmillBase3.setTexture(&windmillBaseTexture);

	// Transformations for the windmills
	TransformNode leftWindmillFan(&windmillFan1);
	TransformNode leftWindmillArm1(&windmill1Arm1);
	TransformNode leftWindmillArm2(&windmill1Arm2);
	TransformNode leftWindmillArm3(&windmill1Arm3);
	TransformNode leftWindmillArm4(&windmill1Arm4);
	TransformNode leftWindmillBase(&windmillBase);

	TransformNode middleWindmillFan(&windmillFan2);
	TransformNode middleWindmillArm1(&windmill2Arm1);
	TransformNode middleWindmillArm2(&windmill2Arm2);
	TransformNode middleWindmillArm3(&windmill2Arm3);
	TransformNode middleWindmillArm4(&windmill2Arm4);
	TransformNode middleWindmillBase(&windmillBase2);

	TransformNode rightWindmillFan(&windmillFan3);
	TransformNode rightWindmillArm1(&windmill3Arm1);
	TransformNode rightWindmillArm2(&windmill3Arm2);
	TransformNode rightWindmillArm3(&windmill3Arm3);
	TransformNode rightWindmillArm4(&windmill3Arm4);
	TransformNode rightWindmillBase(&windmillBase3);

	// Joining the transformations together for our windmills
	leftWindmillFan.AddChild(&leftWindmillArm1);
	leftWindmillFan.AddChild(&leftWindmillArm2);
	leftWindmillFan.AddChild(&leftWindmillArm3);
	leftWindmillFan.AddChild(&leftWindmillArm4);
	leftWindmillBase.AddChild(&leftWindmillFan);

	middleWindmillFan.AddChild(&middleWindmillArm1);
	middleWindmillFan.AddChild(&middleWindmillArm2);
	middleWindmillFan.AddChild(&middleWindmillArm3);
	middleWindmillFan.AddChild(&middleWindmillArm4);
	middleWindmillBase.AddChild(&middleWindmillFan);

	rightWindmillFan.AddChild(&rightWindmillArm1);
	rightWindmillFan.AddChild(&rightWindmillArm2);
	rightWindmillFan.AddChild(&rightWindmillArm3);
	rightWindmillFan.AddChild(&rightWindmillArm4);
	rightWindmillBase.AddChild(&rightWindmillFan);

	// These transforms will be used for the windmills
	sf::Transform windmill1Transform;
	sf::Transform windmill2Transform;
	sf::Transform windmill3Transform;

	sf::Clock deltaTime;
	sf::Clock timer;

	// All our booleans for the key presses
	bool key1 = false;
	bool key2 = false;
	bool key3 = false;
	bool key4 = false;
	bool keyA = false;
	bool keyHeld = false;

	// Some magic to get the background moving
	sf::IntRect backgroundRect = bowserCastleSprite.getTextureRect();
	float secondTimer = 0.0f;
	float movementSpeed = 150.0f;

	// Using to calculate the mouse movement
	sf::Vector2<int> previousPosition;
	previousPosition = sf::Mouse::getPosition(window);

	while (window.isOpen())
	{
		float elaspedTime = deltaTime.restart().asSeconds();
		secondTimer += elaspedTime;

		sf::Event sfEvent;

		while (window.pollEvent(sfEvent)) {
			if (sfEvent.type == sf::Event::Closed) {
				window.close();
			}

			else if (sfEvent.type == sf::Event::KeyPressed) {
				keyHeld = true;
				sound.play();
				sound.setLoop(true);
				if (sfEvent.key.code == sf::Keyboard::Num1) {
					// if num1 is pressed, it's set to true.
					key1 = true;
					key2 = false;
					key3 = false;
					key4 = false;
				}

				else if (sfEvent.key.code == sf::Keyboard::Num2) {
					// if num2 is pressed, it's set to true.
					key1 = false;
					key2 = true;
					key3 = false;
					key4 = false;

				}

				else if (sfEvent.key.code == sf::Keyboard::Num3) {
					// if num3 is pressed, it's set to true.
					key1 = false;
					key2 = false;
					key3 = true;
					key4 = false;

				}

				else if (sfEvent.key.code == sf::Keyboard::Num4) {
					// if num4 is pressed, it's set to true.
					key1 = false;
					key2 = false;
					key3 = false;
					key4 = true;
					// Bring all the windmills upright again to their default position (0.0f)
					windmillBase.setRotation(0.0f);
					windmillBase2.setRotation(0.0f);
					windmillBase3.setRotation(0.0f);

				}
				else if (sfEvent.key.code == sf::Keyboard::A) {
					// this is just incorrect
					key1 = true;
					key2 = true;
					key3 = true;
					key4 = false;
					keyA = true;
				}
			}
			else if (sfEvent.type == sf::Event::KeyReleased) {
				keyHeld = false;
			}
			// Y
			else if (sfEvent.type == sf::Event::MouseMoved) {
				
				// This allows us to get the coordinates of the mouse position (ie. 100,0)
				sf::Vector2i localPosition = sf::Mouse::getPosition(window);
				std::cout << "X: " << localPosition.x << " Y: " << localPosition.y << std::endl;
				// For calculating the mouse movements
				float deltaX = float(sfEvent.mouseMove.x) - localPosition.x;
				float deltaY = float(sfEvent.mouseMove.y) - localPosition.y;

				// If the mouse moves on the x-axis (horizontally)
				if (deltaX != 0) {
					if (key1) {
						// rotate around the middle windmill (angle, center x, center y)??
						windmill1Transform.rotate(10.0f, { 400.0f, 450.0f });
					}
					else if (key2) {
						// rotate around the first windmill
						windmill2Transform.rotate(10.0f, { 250.0f, 450.0f });
					}
					else if (key3) {
						// rotate around the middle windmill
						windmill3Transform.rotate(10.0f, { 400.0f, 450.0f });
					}
					else if (keyA) {
						// rotate around their left neighbours?!?!
						windmill1Transform.rotate(10.0f, { 400.0f, 450.0f });
						windmill2Transform.rotate(10.0f, { 250.0f, 450.0f });
						windmill3Transform.rotate(10.0f, { 400.0f, 450.0f });
					}
					// If the mouse moves on the x-axis (horizontally)
					if (deltaY != 0) {
						if (key1) {

						}
						else if (key2) {
	
						}
						else if (key3) {

						}
						else if (keyA) {
		
						}
					}
					// Update the previous mouse position with the new mouse position
					previousPosition = localPosition;
				}
			}
		}

		// Some more crazy magic for the moving background
		sf::IntRect deltaRect = backgroundRect;
		deltaRect.left = backgroundRect.left + (int)(movementSpeed * secondTimer);
		bowserCastleSprite.setTextureRect(deltaRect);

		if (secondTimer > 1.0f)
		{
			secondTimer -= 1.0f;
			backgroundRect.left += (int)movementSpeed;
			if (backgroundRect.left >= (float)bowserTexture.getSize().x) {
				backgroundRect.left -= bowserTexture.getSize().x;
			}
		}

		// Clear the window
		window.clear();
		// Draw the sprite background
		window.draw(bowserCastleSprite);
		// Draw each of the windmills
		leftWindmillBase.Draw(&window , windmill1Transform);
		middleWindmillBase.Draw(&window, windmill2Transform);
		rightWindmillBase.Draw(&window, windmill3Transform);
		// Display the window
		window.display();

		// To indefinitely rotate the arms of the windmills
		windmill1Arm1.rotate(45 * elaspedTime);
		windmill1Arm2.rotate(45 * elaspedTime);
		windmill1Arm3.rotate(45 * elaspedTime);
		windmill1Arm4.rotate(45 * elaspedTime);

		windmill2Arm1.rotate(45 * elaspedTime);
		windmill2Arm2.rotate(45 * elaspedTime);
		windmill2Arm3.rotate(45 * elaspedTime);
		windmill2Arm4.rotate(45 * elaspedTime);

		windmill3Arm1.rotate(45 * elaspedTime);
		windmill3Arm2.rotate(45 * elaspedTime);
		windmill3Arm3.rotate(45 * elaspedTime);
		windmill3Arm4.rotate(45 * elaspedTime);

	}

	return 0;
}