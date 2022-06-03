#include "../include/Player.h"

Player::Player(Rectangle playerRec, int windowWidth, int windowHeight)
: _playerRectangle(playerRec), _windowWidth(windowWidth), _windowHeight(windowHeight)
{ }
    
void Player::Tick(float deltaTime)
{
    if (IsKeyPressed(KEY_SPACE))
        Jump(deltaTime);

    Gravity(deltaTime);

    CheckScreenBounds();

    // update player position
    _playerRectangle.y += _playerVelocity * deltaTime;

    DrawRectangle(_playerRectangle.x, _playerRectangle.y, _playerRectangle.width, _playerRectangle.height, GREEN);
}

void Player::CheckScreenBounds()
{
    // check screen bounds
    if (_playerRectangle.y + _playerRectangle.height >= _windowHeight)
    {
        // hit the ground, game over
        _playerRectangle.y = _windowHeight - _playerRectangle.height; // make sure the player stays in frame
        Die();
        return;
    }
    else if (_playerRectangle.y <= 0) 
    {
        _canJump = false;
        _playerRectangle.y = 0; // make sure the player stays in frame
        return;
    }

    _canJump = true;
}

void Player::Gravity(float deltaTime)
{
    _playerVelocity += _playerGravity * deltaTime;
}

void Player::Jump(float deltaTime)
{
    if(!_canJump) return;
    _playerVelocity += _playerJumpHeight;
}

void Player::Die()
{
    _playerVelocity = 0;
    _canJump = false;
    Game::GameOver();
}