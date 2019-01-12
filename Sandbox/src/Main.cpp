#include <Greasy.hpp>

class Sandbox : public Greasy::Application {
	
public:

	void Update() {}

};


int main() {
	auto application = new Sandbox();
	Greasy::Application::Start(application);

	delete application;
}