#include "PawnPhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"

void PawnPhysicsComponent::Update()
{
	// Get DELTA time from the previous frame
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	if (dt > 0.f)
	{
		//Set the wanted velocity as current
		m_velocity = m_wantedVelocity;

		//V = Dx / Dt => Dx = V * Dt
		sf::Vector2f deltaVelocity = dt * m_velocity;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);
	}

	__super::Update();
}

void PawnPhysicsComponent::OnAddToWorld() {}