#ifndef H_APPLICATION
#define H_APPLICATION

#include "Core.hpp"
#include "Window.hpp"
#include "Layers.hpp"

namespace Greasy {

	class API Application {

		Window* window;
		LayerStack* layers;

		static Application* application;

	public:

		Application();
		virtual ~Application();

		virtual void OnStart();
		virtual void OnUpdate();
		virtual void OnRender();

		void PushLayer(Layer*);
		Layer* PopLayer();

		static Application& Get();

	private:

		void Run();

		void CreateWindow();

		API friend void Start(Application*);

	};

	Application* CreateApplication();

	API void Start(Application*);

}

#endif