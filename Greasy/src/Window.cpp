#include <Greasy.hpp>

#include "../include/Window.hpp"
#include "Window.hpp"

namespace Greasy {

	Window::Window() {
		this->_window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
		if(this->_window == NULL)
			throw "Error creating window";

		glfwMakeContextCurrent(this->_window);
	}

	Window::~Window() {
		GR_LOG_INFO("Destroying window.");
		glfwDestroyWindow(_window);
	}

	bool Window::ShouldClose() const {
		return glfwWindowShouldClose(_window) == GLFW_TRUE;
	}

	void Window::Close() {
		return glfwSetWindowShouldClose(_window, GLFW_TRUE);
	}

}