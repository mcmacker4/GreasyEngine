#include "../include/Application.hpp"
#include "../include/Log.hpp"

#include <GLFW/glfw3.h>

#include <cassert>

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
		OnStart();
		while (!window->ShouldClose()) {
			glClear(GL_COLOR_BUFFER_BIT);
			glfwPollEvents();
			OnUpdate();
		}
	}

	void Application::OnStart() {}

	void Application::OnUpdate() {
		window->Update();
		layers->Update();
	}

	void Application::OnRender() {
		layers->Render();
	}

	void Application::PushLayer(Layer* layer) {
		layers->Push(layer);
	}

	Layer* Application::PopLayer() {
		return layers->Pop();
	}

	Application& Application::Get() {
		return *application;
	}

	void Start(Application* application) {
		assert(!Application::application);
		Application::application = application;
		Application::application->Run();
	}

}