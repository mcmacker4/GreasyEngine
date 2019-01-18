#include <Greasy.hpp>



/*
	LAYER: Scene
*/

class Scene : public Greasy::Layer {
	void OnUpdate();
	void OnRender();
};

void Scene::OnUpdate() {
}

void Scene::OnRender() {
	GR_LOG_DEBUG("Rendering Scene");
}

/*
	LAYER: GUI
*/

class GUI : public Greasy::Layer {
	void OnUpdate();
	void OnRender();
};

void GUI::OnUpdate() {
}

void GUI::OnRender() {
	GR_LOG_DEBUG("Rendering GUI");
}

/*
	APPLICATION: Sandbox
*/

class Sandbox : public Greasy::Application {
public:
	void OnStart();
	void OnUpdate();
	void OnRender();
};

void Sandbox::OnStart() {
	GR_LOG_DEBUG("Sandbox start");
	PushLayer(new Scene);
	PushLayer(new GUI);
}

void Sandbox::OnUpdate() {
	Application::OnUpdate();
}

void Sandbox::OnRender() {
	Application::OnRender();
}

Greasy::Application* Greasy::CreateApplication() {
	return new Sandbox();
}

#if !GR_WINDOWS

int main() {
	auto app = Greasy::CreateApplication();
	Greasy::Start(app);

	delete app;
}

#endif