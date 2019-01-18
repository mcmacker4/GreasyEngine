#ifndef H_ENTRYPOINT
#define H_ENTRYPOINT

#if GR_WINDOWS

extern Greasy::Application* Greasy::CreateApplication();

int main() {
	auto app = Greasy::CreateApplication();
	Greasy::Start(app);

	delete app;
}

#endif

#endif