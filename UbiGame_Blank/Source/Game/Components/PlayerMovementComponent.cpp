#include "PlayerMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

#include "GameEngine/EntitySystem/Components/PawnPhysicsComponent.h"

using namespace Game;

const float gravity = 5.0f;

void PlayerMovementComponent::Update() 
{
       
	Component::Update();

    float playerVelocity = 100.f;

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    /*
    sf::Vector2f wantedVelocity = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        wantedVelocity.x -= playerVelocity * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        wantedVelocity.x += playerVelocity * dt;
    }

    PawnPhysicsComponent* pawnPhys = GetEntity()->GetComponent<PawnPhysicsComponent>();
    if (pawnPhys)
    {
        pawnPhys->SetVelocity(wantedVelocity);
    }

    */

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    //Gravity
    displacement.y += gravity * dt * 100;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        displacement.x -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        displacement.x += inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        displacement.x -= inputAmount * dt;
    }

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement); 

    
}

void PlayerMovementComponent::OnAddToWorld() {}