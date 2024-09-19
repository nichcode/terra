#pragma once

#include "prime/prime_defines.h"

namespace terra {

	class Game
	{
	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void Update(f32 deltaTime) = 0;
	};

	Game* CreateGame();
}
