#include "Game.h"
#include <iostream>
#include <ctime>
#include "Config.h"
#include <unordered_set>
#include <map>
#include <queue>
#include <vector>
#include "CustomPrioQueue.h"

Game::Game()
{
	//Graph settings
	int maxVerteces = 10;
	int screenWidth = 800;
	int screenHeight = 600;

	//set begin Vertex at center
	this->vertexes.push_back(new Vertex((screenWidth / 2), (screenHeight / 2)));

	//seed random
	srand(time(nullptr));

	//generate Vertexes
	while(maxVerteces != 1)
	{
		int xPos = rand() % ((screenWidth-20) - 20 + 1) + 20;
		int yPos = rand() % ((screenHeight-20) - 20 + 1) + 20;
		if(this->PosibleVertex(xPos, yPos))
		{
			this->vertexes.push_back(new Vertex(xPos, yPos));
			maxVerteces--;
		}	
	}

	//generate edges
	for (size_t i = 0; i < this->vertexes.size(); i++)
	{
		int amountOfEdges = 2 + (rand() % (4 - 2));
		while(this->vertexes[i]->AmountOfEdges() <= amountOfEdges)
		{
			int randomIndex;
			if (i == this->vertexes.size() - 1)
			{
				randomIndex = rand() % (this->vertexes.size() - 1);
			}
			else
			{
				randomIndex = i + (rand() % (this->vertexes.size() - (i + 1)));
			}

			Edge* edge = new Edge(this->vertexes[i], (this->vertexes[randomIndex]));
			this->AddRenderable(edge);
		}

		/*int amountOfEdges = 2 + (rand() % (4 - 2));
		while(this->vertexes[i]->AmountOfEdges() <= amountOfEdges)
		{
			int randomIndex = (i - 1) + (rand() % (int)((this->vertexes.size - 1) - i));
			std::cout << randomIndex << std::endl;
			LOG(randomIndex);
			Edge* edge = new Edge(this->vertexes[i], (this->vertexes[randomIndex]));
			this->AddRenderable(edge);
		}*/
	}

	//add Vertexes to renderable
	for (std::vector<Vertex*>::iterator it = this->vertexes.begin(); it != this->vertexes.end(); ++it)
	{
		this->AddRenderable(*it);
	}

	//game objecten maken
	this->hero = new Hero("Holy Lord", this->vertexes.at(0), LoadTexture("lemmling_Cartoon_cow.png"));
	this->enemy = new Enemy("Bugs", this->vertexes.at(1), LoadTexture("bunney.png"));

	AddRenderable(hero);
	AddRenderable(enemy);
}

void Game::AddRenderable(IGameObject* obj)
{
	FWApplication::GetInstance()->AddRenderable(obj);
}

void Game::AddRenderable(Vertex* obj)
{
	FWApplication::GetInstance()->AddRenderable(obj);
}

void Game::AddRenderable(Edge* obj)
{
	FWApplication::GetInstance()->AddRenderable(obj);
}

bool Game::PosibleVertex(const int xPos, const int yPos)
{
	for (size_t i = 0; i < this->vertexes.size(); i++)
	{
		int XDistance = this->vertexes[i]->GetX() - xPos;
		int YDistance = this->vertexes[i]->GetY() - yPos;

		if(XDistance > -25 && XDistance < 25 && YDistance > -25 && YDistance < 25)
			return false;
	}
	return true;
}

void Game::moveHero()
{
	std::cout << "Method called" << std::endl;

	Vertex *start = this->hero->GetCurrentPosition();
	Vertex *goal = this->enemy->GetCurrentPosition();

	std::unordered_set<Vertex*> closedSet;
	CustomPrioQueue openSet;
	std::map<Vertex*, Vertex*> cameFrom;

	openSet.insert(start);

	std::map<Vertex*, int> gScore;
	gScore.emplace(start, 0);

	std::map<Vertex*, int> fScore;
	fScore.emplace(start, gScore.at(start) + Heuristic_cost_estimate(start, goal));

	while (!openSet.empty())
	{
		auto current = openSet.pop();

		if (current == goal)
		{
			std::cout << "EINDE" << std::endl;
			break;
		}

		closedSet.emplace(current);

		for (auto neighbor : current->GetEdges())
		{
			auto otherVertex = neighbor->getVertex(current);

			auto search = closedSet.find(otherVertex);
			if (search != closedSet.end())
			{
				continue;
			}

			int tentative_g_score = gScore[current] + Heuristic_cost_estimate(current, otherVertex);

			otherVertex->vertexCost = tentative_g_score;

			if (!openSet.isPresent(otherVertex))
			{
				openSet.insert(otherVertex);
			}
			else if (tentative_g_score >= gScore[otherVertex])
			{
				continue;
			}

			cameFrom[otherVertex] = current;
			gScore[otherVertex] = tentative_g_score;
			fScore[otherVertex] = gScore[otherVertex] + Heuristic_cost_estimate(otherVertex, goal);
		}

		std::cout << current << std::endl;
	}


	std::cout << gScore.at(start) << std::endl;
}

int Game::Heuristic_cost_estimate(Vertex* start, Vertex* goal)
{
	return sqrt(pow(*start->GetX() - *goal->GetX(), 2) + pow(*start->GetY() - *goal->GetY(), 2));
}

SDL_Texture* Game::LoadTexture(std::string path)
{
	return FWApplication::GetInstance()->LoadTexture(path);
}

Game::~Game()
{
}

