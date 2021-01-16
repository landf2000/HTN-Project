#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer(); 
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(10.0f, 10.0f));
	m_player->SetSize(sf::Vector2f(10.0f, 10.0f));

	m_player->AddComponent<GameEngine::RenderComponent>();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}