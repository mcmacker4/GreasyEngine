
#include <GLFW/glfw3.h>

#include "../include/Application.hpp"

namespace Greasy {

	Application* Application::application;

	Application::Application() {}

	Application::~Application() {
		delete window;
		glfwTerminate();
		GR_LOG_INFO("Application destroyed.");
	}

	void Application::CreateWindow() {
		GR_LOG_INFO("Creating window.");
		this->window = new Window();
	}

	void Application::Initialize() {
		GR_LOG_INFO("Initializing Application.");
		try {
			if (!glfwInit())
				throw "Could not initialize GLFW.";
			CreateWindow();
			assert(window);
		} catch (const char* msg) {
			GR_LOG_ERROR(msg);
		}
	}

	void Application::Run() {
		assert(window);
		while (!window->ShouldClose()) {
			glClear(GL_COLOR_BUFFER_BIT);
			glfwPollEvents();
			Update();
		}
	}

	void Application::Update() {
		window->Update();
	}

	void Application::Start() {
		Application::application = new Application;
		application->Initialize();
		application->Run();
		delete Application::application;
	}

	Application& Application::Get() {
		return *application;
	}

}