#pragma once

#include <string>
#include "Vertex.h"
#include "IGameObject.h"

class AgentBase : public IGameObject
{
public:
	AgentBase(const std::string& name, Vertex* spot, SDL_Texture* texture);
	void Update(float deltaTime) override;
	void Draw() override;
	void setPosition(Vertex* vertex);
	Vertex* getPosition();
	int GetX();
	int GetY();
	~AgentBase();
private:
	std::string name;
	Vertex* currentPosition;

	const int imageWidht = 50;
	const int imageHeight = 50;
};

