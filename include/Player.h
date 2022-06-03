#include "raylib.h"
#include "../include/Game.h"

class Player
{
public:
    Player(Rectangle playerRec, int windowWidth, int windowHeight);
    void Tick(float deltaTime); // called every frame
    void Jump(float deltaTime);
    void Gravity(float deltaTime);
    void CheckScreenBounds();
    void Die();
private:
    Rectangle _playerRectangle{}; // placeholder player rec
    float _playerVelocity{};
    float _playerJumpHeight{-300.f};
    float _playerGravity{650.f}; 
    int _windowWidth{};
    int _windowHeight{};
    bool _canJump{true};
};