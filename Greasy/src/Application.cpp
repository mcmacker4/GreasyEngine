
#include <GLFW/glfw3.h>

#include "../include/Application.hpp"

namespace Greasy {

	Application* Application::application;

	Application::Application() {
		GR_LOG_INFO("Initializing Application.");
		try {
			if (!glfwInit())
				throw "Could not initialize GLFW.";
			CreateWindow();
			assert(window);

			layers = new LayerStack;
		} catch (const char* msg) {
			GR_LOG_ERROR(msg);
		}
	}

	Application::~Application() {
		delete window;
		glfwTerminate();
		GR_LOG_INFO("Application destroyed.");
	}

	void Application::CreateWindow() {
		GR_LOG_INFO("Creating window.");
		this->window = new Window();
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
		LayerStackIterator iterator(layers);
		while(iterator.HasNext()) {
			iterator.Next()->Update();
		}
	}

	void Application::Render() {
		LayerStackIterator iterator(layers);
		while(iterator.HasNext()) {
			iterator.Next()->Render();
		}
	}

	Application& Application::Get() {
		return *application;
	}

	void Start() {
		assert(!Application::application);
		Application::application = CreateApplication();
		Application::application->Run();
		delete Application::application;
	}

}