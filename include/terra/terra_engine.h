#pragma once

int main(int argc, char** argv);

namespace terra {

	class Game;

	class Engine
	{
	private:
		friend int::main(int argc, char** argv);

	public:
		static void CloseGame();

	private:
		static void Run(Game* game);
	};
}
