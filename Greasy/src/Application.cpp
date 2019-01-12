
#include <GLFW/glfw3.h>

#include "../include/Application.hpp"

namespace Greasy {

	Application::~Application() {
		GR_LOG_INFO("Destroying application.");
		delete window;

		glfwTerminate();
	}

	const Window* Application::GetWindow() const {
		return window;
	}

	void Application::CreateWindow() {
		GR_LOG_INFO("Creating window.");
		this->window = new Window();
	}

	void Application::Start(Application* application) {

		GR_LOG_INFO("Initializing Application.");

		try {

			if (!glfwInit())
				throw "Could not initialize GLFW.";

			application->CreateWindow();
			auto window = application->GetWindow();
			while (!window->ShouldClose()) {
				glfwPollEvents();
				application->Update();
			}

		} catch (const char* msg) {

			GR_LOG_ERROR(msg);

		}


	}

}