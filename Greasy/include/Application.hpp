#ifndef H_APPLICATION
#define H_APPLICATION

#include <Greasy.hpp>

namespace Greasy {

	class API Application {
			
		Window* window;

	public:
		virtual ~Application();

		virtual void Update() = 0;

		const Window* GetWindow() const;

		static void Start(Application* application);

	private:

		void CreateWindow();

	};

}

#endif