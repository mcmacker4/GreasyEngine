#ifndef H_APPLICATION
#define H_APPLICATION

#include <Greasy.hpp>

namespace Greasy {

	class API Application {

		Window* window;
		LayerStack* layers;

		static Application* application;

	public:

		Application();
		virtual ~Application();

		virtual void Update();
		virtual void Render();

		void PushLayer(Layer*);
		Layer* PopLayer();

		static Application& Get();

	private:

		void Run();

		void CreateWindow();

		friend void Start();

	};

	extern Application* CreateApplication();

	void Start();

}

#endif