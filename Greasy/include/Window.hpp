#ifndef H_WINDOW_PUB
#define H_WINDOW_PUB


struct GLFWwindow;

namespace Greasy {

	class API Window {
		GLFWwindow* _window;

	public:
		Window();
		~Window();

		bool ShouldClose() const;
		void Close();
	};

}

#endif