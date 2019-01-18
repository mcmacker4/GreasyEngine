#include "../include/Window.hpp"
#include "../include/Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Greasy {

	Window::Window() {
		this->window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
		if (this->window == NULL) {
			throw "Error creating window";
		}

		glfwMakeContextCurrent(this->window);
		if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
			throw "Error loading GLAD.";
		}

		glViewport(0, 0, 800, 600);
		glClearColor(0.3f, 0.6f, 0.9f, 1.0f);
	}

	Window::~Window() {
		glfwDestroyWindow(window);
		GR_LOG_INFO("Window destroyed.");
	}

	void Window::Update() {
		glfwSwapBuffers(window);
	}

	bool Window::ShouldClose() const {
		return glfwWindowShouldClose(window) == GLFW_TRUE;
	}

	void Window::Close() {
		return glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

}