#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include "GameEngine/EntitySystem/Components/PawnPhysicsComponent.h"

#include "Game/Components/PlayerMovementComponent.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" //<-- Remember to include the new component we will use


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer(); 
	CreateObstacle();
	CreateBackground();
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	// Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>();

	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::Player);  // <-- Assign the texture to this entity

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player

	

	//m_player->AddComponent<PawnPhysicsComponent>();

	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
}

void GameBoard::CreateObstacle()
{
	
	GameEngine::Entity* platformLeft = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(platformLeft);

	platformLeft->SetPos(sf::Vector2f(50.0f, 300.0f));
	platformLeft->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRenderLeft = static_cast<GameEngine::SpriteRenderComponent*>
		(platformLeft->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRenderLeft->SetFillColor(sf::Color::Transparent);
	spriteRenderLeft->SetTexture(GameEngine::eTexture::PlatformLeft);

	platformLeft->AddComponent<GameEngine::CollidableComponent>();
	

	
	GameEngine::Entity* platformCenter = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(platformCenter);

	platformCenter->SetPos(sf::Vector2f(100.0f, 300.0f));
	platformCenter->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRenderCenter = static_cast<GameEngine::SpriteRenderComponent*>
		(platformCenter->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRenderCenter->SetFillColor(sf::Color::Transparent);
	spriteRenderCenter->SetTexture(GameEngine::eTexture::PlatformCenter);

	platformCenter->AddComponent<GameEngine::CollidableComponent>();

	
	
	GameEngine::Entity* platformRight = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(platformRight);

	platformRight->SetPos(sf::Vector2f(150.0f, 300.0f));
	platformRight->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRenderRight = static_cast<GameEngine::SpriteRenderComponent*>
		(platformRight->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRenderRight->SetFillColor(sf::Color::Transparent);
	spriteRenderRight->SetTexture(GameEngine::eTexture::PlatformRight);

	platformRight->AddComponent<GameEngine::CollidableComponent>();
	
}

void GameBoard::CreateBackground()
{
	GameEngine::Entity* background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(250.0f, 250.0f));
	background->SetSize(sf::Vector2f(500.0f, 500.0f));

	// Render
	GameEngine::SpriteRenderComponent* render = background->AddComponent<GameEngine::SpriteRenderComponent>();

	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::Background);  // <-- Assign the texture to this entity
	render->SetZLevel(-1);
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}