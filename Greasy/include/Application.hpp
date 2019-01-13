#ifndef H_APPLICATION
#define H_APPLICATION

#include <Greasy.hpp>

namespace Greasy {

	class API Application {

		Window* window;

	public:

		virtual ~Application();

		const Window* GetWindow() const;

		void Start();
		virtual void Update();

	private:

		void CreateWindow();

	};

}

#endif