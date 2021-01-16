#include "PawnPhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"

void PawnPhysicsComponent::Update()
{
	// Get DELTA time from the previous frame
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	float gForce = 700.f;

	if (dt > 0.f)
	{
		//Set the wanted velocity as current
		m_velocity.x = m_wantedVelocity.x;

		//Accelerate Y of our velocity by gravity in time
		m_velocity.y += gForce * dt;

		//V = Dx / Dt => Dx = V * Dt
		sf::Vector2f deltaVelocity = dt * m_velocity;
		GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);
	}

	__super::Update();
}

void PawnPhysicsComponent::OnAddToWorld() {}