#ifndef H_APPLICATION
#define H_APPLICATION

#include <Greasy.hpp>

namespace Greasy {

	class API Application {

		Window* window;

		static Application* application;

	public:

		Application();
		~Application();

		static void Start();

		static Application& Get();

	private:

		void Initialize();

		void Run();
		void Update();

		void CreateWindow();

	};

}

#endif