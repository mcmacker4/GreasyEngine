#include <Greasy.hpp>

class Sandbox : public Greasy::Application {};


int main() {
	auto application = new Sandbox();
	application->Start();
	delete application;
}