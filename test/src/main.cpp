
#include "terra/terra.h"
#include "terra/terra_main.h"

void OnWindowClose(const prime::Window* window)
{
	terra::Engine::CloseGame();
}

class TestGame : public terra::Game
{
private:
	prime::Window m_Window;
	prime::Device m_Device;

public:
	virtual void Init() override;
	virtual void Shutdown() override;

	virtual void Update(f32 deltaTime) override;
};

void TestGame::Init()
{
	m_Window.Init(prime::WindowProperties());
	prime::SetWindowCloseCallback(OnWindowClose);

	m_Device.Init(prime::DeviceTypeOpenGL, &m_Window);
	m_Device.SetClearColor(.2f, .2f, .2f, 1.0f);
	m_Device.SetVSync(true);
}

void TestGame::Shutdown()
{
	m_Device.Shutdown();
	m_Window.Destroy();
}

void TestGame::Update(f32 deltaTime)
{
	prime::PollEvents();

	m_Device.Clear();
	m_Device.SwapBuffers();
}

terra::Game* terra::CreateGame()
{
	return new TestGame();
}