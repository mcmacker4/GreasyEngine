#include <Greasy.hpp>

class Sandbox : public Greasy::Application {
public:
	void Update();
};

void Sandbox::Update() {
	GR_LOG_DEBUG("Sandbox Update");
	Application::Update();
}

class Scene : public Greasy::Layer {
	void Update() override;
	void Render() override;
};

void Scene::Update() {
	GR_LOG_DEBUG("Updating Scene");
}

void Scene::Render() {
	GR_LOG_DEBUG("Rendering Scene");
}

class GUI : public Greasy::Layer {
	void Update() override;
	void Render() override;
};

void GUI::Update() {
	GR_LOG_DEBUG("Updating GUI");
}

void GUI::Render() {
	GR_LOG_DEBUG("Rendering GUI");
}

Greasy::Application* Greasy::CreateApplication() {
	return new Sandbox();
}

int main() {
	Greasy::Start();
	auto app = Greasy::Application::Get();
	auto sceneLayer = new Scene;
	auto guiLayer = new GUI;
	app.PushLayer(sceneLayer);
	app.PushLayer(guiLayer);
}