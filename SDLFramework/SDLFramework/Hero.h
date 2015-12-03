#pragma once
#include "AgentBase.h"
class Hero :
	public AgentBase
{
public:
	Hero(const std::string& name, Vertex* spot, SDL_Texture* texture);
	void Move();
	void OnCollision(IGameObject obj);
	typeobject getType() override;
	void Update(float deltaTime) override;
	void Draw() override;
	~Hero();
private:
	bool moved = false;
};
