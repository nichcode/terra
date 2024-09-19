#pragma once

#include "terra_engine.h"
#include "terra_game.h"

int main(int argc, char** argv)
{
	terra::Game* game = terra::CreateGame();
	terra::Engine::Run(game);

	delete game;
	game = nullptr;
	return 0;
}