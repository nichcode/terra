
#include "prime/prime.h"
#include "terra/terra_engine.h"
#include "terra/terra_game.h"

namespace terra {

	struct Data
	{
		b8 Running = false;
		prime::Timestep Timestep;
	};

	static Data s_Data;

	void Engine::CloseGame()
	{
		s_Data.Running = false;
	}

	void Engine::Run(Game* game)
	{
		prime::Engine::Init();
		game->Init();
		s_Data.Running = true;

		while (s_Data.Running)
		{
			s_Data.Timestep.Tick();

			game->Update(s_Data.Timestep.GetDT());
		}

		game->Shutdown();
	}
}