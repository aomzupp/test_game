#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"Player.h"
#include "Platform.h"
#include "Monster.h"

static const float View_HEIGHT = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize((View_HEIGHT)*aspectRatio, View_HEIGHT);
}

int main()
{
	float x = -150.0f;

	
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Super AmongOh");
	sf::RectangleShape frame(sf::Vector2f(1080.0f, 1000.0f));
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_HEIGHT, View_HEIGHT));

	sf::Texture bgpng;
	if (!bgpng.loadFromFile("bg/21.png")) //blackground in game
	{
		printf("load fail");
	}

	sf::RectangleShape bg(sf::Vector2f(10000, 620));
	bg.setPosition(sf::Vector2f(-500, -360));
	bg.setTexture(&bgpng);

	sf::Texture player_texture;
	player_texture.loadFromFile("bg/25.png"); //player
	Player player(&player_texture, sf::Vector2u(4, 2), 0.2f, 300.0f);


	std::vector<Platform> platforms;
	std::vector<Platform> platformlonghon1;
	std::vector<Platform> platformlonghon2;
	std::vector<Monster> monster;
	sf::Texture floor;
	floor.loadFromFile("bg/27.png"); //floor in game
	sf::Texture bg1;
	bg1.loadFromFile("bg/20.png"); //sao gun chark
	sf::Texture bg2;
	bg2.loadFromFile("bg/23.png"); //bg out game
	sf::Texture floor1;
	floor1.loadFromFile("bg/24.png"); //floor out game
	sf::Texture block1;
	block1.loadFromFile("bg/26.png");
	sf::Texture monster1;
	

	bool brokenblock[100];
	bool blocklonghonClock = true;
	bool blockfordie[100];
	bool blocklonghon1 = true;
	bool blocklonghon2 = true;
	bool itemblock[100];
	

	/// ////////////////////////////////////////////// base 1 ////////////////////////////////////////////////////

	Platform blk1(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(350.0f, 110.0f)); //block long hon1
	platforms.push_back(Platform(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(450.0f, 110.0f))); //block1
	Platform blk3(&block1, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(500.0f, 0.0f)); //block long hon1
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(650.0f, -30.0f))); //block2
	Platform blk2(nullptr, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(840.0f, -30.0f)); //block secret
	Platform itemblock3(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(800.0f, -230.0f)); //block long hon1
	
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1070.0f, 110.0f))); //block3
	Platform itemblock4(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1070.0f, -90.0f)); //block long hon1
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 150.0f), sf::Vector2f(1500.0f, 200.0f))); //block4
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1640.0f, 110.0f))); //block5
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1770.0f, 110.0f))); //block7
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 150.0f), sf::Vector2f(1900.0f, 200.0f))); //block8
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 250.0f), sf::Vector2f(2200.0f, 200.0f))); //block8

	Platform blh1(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1950.0f, -30.0f)); //block long hon1
	Platform blh2(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2000.0f, -170.0f)); //block long hon1
	Platform itemblock1(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3000.0f, -200.0f)); //block long hon1
	Platform bfd1(nullptr, sf::Vector2f(250.0f, 50.0f), sf::Vector2f(1950.0f, 110.0f)); //block for die1



	/// ////////////////////////////////////////////// base 2 ////////////////////////////////////////////////////



	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2700.0f, 110.0f))); //block1
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(3000.0f, 0.0f))); //block2
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(2900.0f, -200.0f))); //block3
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3100.0f, -200.0f))); //block5
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3700.0f, 110.0f))); //block7
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3800.0f, -50.0f))); //block8
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(3900.0f, 110.0f))); //block9
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4000.0f, -50.0f))); //block10
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4100.0f, 110.0f))); //block11
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 150.0f), sf::Vector2f(4300.0f, 200.0f))); //block12
	



	Platform bfd2(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3300.0f, 310.0f)); //block for die2
	Platform itemblock2(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(4300.0f, -50.0f)); 

	/// ////////////////////////////////////////////// base 3 ////////////////////////////////////////////////////



	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5000.0f, 110.0f))); //block1
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5000.0f, -90.0f))); //block2
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5200.0f, -90.0f))); //block3
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5200.0f, 110.0f))); //block4
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5400.0f, 110.0f))); //block5
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5400.0f, -90.0f))); //block6
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(5850.0f, 290.0f))); //block7
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(5900.0f, 270.0f))); //block8
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 150.0f), sf::Vector2f(5950.0f, 250.0f))); //block9
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 200.0f), sf::Vector2f(6000.0f, 230.0f))); //block10
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 250.0f), sf::Vector2f(6050.0f, 210.0f))); //block11
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 300.0f), sf::Vector2f(6100.0f, 190.0f))); //block12
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 350.0f), sf::Vector2f(6150.0f, 170.0f))); //block13
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 400.0f), sf::Vector2f(6200.0f, 150.0f))); //block14
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 450.0f), sf::Vector2f(6250.0f, 130.0f))); //block15
	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 500.0f), sf::Vector2f(6300.0f, 110.0f))); //block16

	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(6670.0f, 235.0f))); //door to next map


	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	platforms.push_back(Platform(&floor, sf::Vector2f(2600.0f, 100.0f), sf::Vector2f(775.0f, 310.0f))); //floor in game1
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(2720.0f, 310.0f))); //floor in game2
	platforms.push_back(Platform(nullptr, sf::Vector2f(950.0f, 100.0f), sf::Vector2f(3950.0f, 310.0f))); //floor in game2
	platforms.push_back(Platform(nullptr, sf::Vector2f(2600.0f, 100.0f), sf::Vector2f(5850.0f, 310.0f))); //floor in game3

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	monster.push_back(Monster(&monster1, sf::Vector2u(0,0), 0.0f,1.0f, sf::Vector2f(0.0f, 100.0f)));








	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	int a = 0;
	float deltaTime = 0.0f;
	sf::Clock clock;

	float time = 0.0f;
	sf::Clock clock1;

	std::memset(itemblock, true, sizeof itemblock);
	std::memset(brokenblock, true, sizeof brokenblock);
	std::memset(blockfordie, true, sizeof blockfordie);

	while (window.isOpen())
	{
		window.clear(sf::Color(67, 169, 238));
		window.draw(bg);


		time = clock1.getElapsedTime().asMilliseconds();
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}

		/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		printf("x = %.f   y = %.f \n", player.GetPosition().x, player.GetPosition().y);
		printf("time = %.f ", time);
		player.Update(deltaTime);
		/*for (Platform& Platforms : platforms) Platforms.Update(deltaTime);*/
		if (player.GetPosition().x <= 6450)
		{
			if (player.GetPosition().x >= x)
			{
				view.setCenter(sf::Vector2f(player.GetPosition().x, 0));
				x++;
			}

		}

		Collider playerCollision = player.GetCollider();
		sf::Vector2f direction;


		for (Platform& platform : platforms) 
		{
			if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				player.OnCollision(direction);
			}
			for (Monster& monster : monster)
			{
				monster.Update(deltaTime);
				Collider monsterCollision = monster.GetCollider();
				if (platform.GetCollider().CheckCollision(monsterCollision, direction, 1.0f)) 
{
					monster.OnCollision(direction);
				}	
			}
		}	



		/// ////////////////////////////////////////block for die/////////////////////////////////////////////////////////////////////////


		if (player.GetPosition().x >= 1950 && player.GetPosition().x <= 2300) //block for die1
		{
			if (bfd1.GetCollider().CheckCollision(playerCollision, direction, 0.0f))
			{
				blockfordie[0] = false;

			}
		}
		if (blockfordie[0] == false)
		{
			if (player.GetPosition().y >= 230 && player.GetPosition().x >= 1950 && player.GetPosition().x <= 2300)
			{
				platformlonghon1.push_back(Platform(nullptr, sf::Vector2f(250.0f, 50.0f), sf::Vector2f(2050.0f, 100.0f)));
			}

		}
		else clock1.restart();
		for (Platform& p : platformlonghon1)
			if (p.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				player.OnCollision(direction);
		for (Platform& p : platformlonghon1)
			p.Draw(window);

		if (bfd2.GetCollider().CheckCollision(playerCollision, direction, 0.0f))
		{
			blockfordie[1] = false;


		}
		bfd2.Draw(window);

		/// 
		///////////////block long hon/////////////////// 
		/// 
		if (blh1.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
		{
			blocklonghon1 = false;
			player.OnCollision(direction); //block long hon
		}
		if (blocklonghon1 == false) blh1.Draw(window);

		/// 
		if (blh2.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
		{
			blocklonghon2 = false;
			player.OnCollision(direction); //block long hon
		}
		if (blocklonghon2 == false) blh2.Draw(window);
		
		
		/// /////////////////////item block///////////////////////////
		 
	
		if (itemblock1.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
		{
			itemblock[0] = false;
			player.OnCollision(direction); 
		}
		if (itemblock[0] == false) itemblock1.Draw(window);
		
		for (int i = 1; i < 6; i++) //block item gra deng 5 loop
		{
			if (itemblock2.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				itemblock[i] = false;
				player.OnCollision(direction);
			}
			if (itemblock[i] == false) itemblock2.Draw(window);
		}
		
		
		if (itemblock3.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
		{
			itemblock[6] = false;
			player.OnCollision(direction);
		}
		if (itemblock[6] == false) itemblock3.Draw(window);
		
		if (itemblock4.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
		{
			itemblock[7] = false;
			player.OnCollision(direction);
		}
		if (itemblock[7] == false) itemblock4.Draw(window);
		
		///////////////////////////////block loen dai///////////////////////////// 
		
		if (blk1.GetCollider().CheckCollision(playerCollision, direction, 0.0f))
			{
				brokenblock[0] = false;
			}
		blk1.Draw(window); 
		
		if (blk2.GetCollider().CheckCollision(playerCollision, direction, 0.0f))
		{
			brokenblock[1] = false;
		}
		blk2.Draw(window);
		
		if (blk3.GetCollider().CheckCollision(playerCollision, direction, 0.0f))
		{
			brokenblock[2] = false;
		}
		blk3.Draw(window);


		

		/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
		Platform Ex1(&bg2, sf::Vector2f(10, 1000), sf::Vector2f(6830, 225)); //block long hon
		if (Ex1.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			player.OnCollision(direction); //block long hon


		/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		window.setView(view);
		player.Draw(window);
		for (Platform& platform : platforms)
			platform.Draw(window);
		for (Monster& monster : monster)
		{
			monster.Draw(window);
		}
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}
	return 0;
}