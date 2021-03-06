#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->jumpHeight = jumpHeight;
	row = 0;
	dmg = 50;
	faceRight = true;
	player.setSize(sf::Vector2f(50.0f, 60.0f));
	player.setOrigin(player.getSize() / 2.0f);
	player.setPosition(-150.0f, 0.0f);
	player.setTexture(texture);

}
Player::~Player()
{
}



void Player::Update(float deltaTime)
{
	row = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
		velocity.x -= speed;
		row = 1;
		faceRight = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
		row = 1;
		faceRight = 1;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed * 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed * 2;
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;
		velocity.y = -sqrt(1.25f * 981.0f * jumpHeight);

	}

	velocity.y += 981.0f * deltaTime;


	if (canJump = false) {
		row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	if (abs(velocity.x) > maxSpeed)
	{
		if (velocity.x < maxSpeed)
		{
			velocity.x = -1 * maxSpeed;
		}
		else
		{
			velocity.x = maxSpeed;
		}
	}
	velocity.x *= drag;
	if (abs(velocity.x) < 5)
	{
		velocity.x = 0;
	}
	animation.Update(row, deltaTime, faceRight);
	player.setTextureRect(animation.uvRect);
	player.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision on the bottom.
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
	}
}