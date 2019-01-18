#ifndef H_WINDOW_PUB
#define H_WINDOW_PUB

#include "./Core.hpp"

struct GLFWwindow;

namespace Greasy {

	class API Window {
		GLFWwindow* window;

	public:
		Window();
		~Window();

		void Update();
		bool ShouldClose() const;
		void Close();
	};

}

#endif