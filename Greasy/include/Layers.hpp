#ifndef H_LAYERS
#define H_LAYERS

#include <stack>

namespace Greasy {

    class Layer {
    public:
        virtual void OnUpdate() = 0;
        virtual void OnRender() = 0;
    };

    class LayerStack {
        std::stack<Layer*> stack;
    public:
        void Push(Layer*);
        Layer* Pop();

		void Update();
		void Render();

    private:

        bool IsEmpty() const;

        friend class LayerStackIterator;
    };

    class LayerStackIterator {
        LayerStack *stack;
        LayerStack temp;

        bool reset = true;
    public:
        LayerStackIterator(LayerStack*);
        ~LayerStackIterator();

        bool HasNext();
        Layer* Next();

        void Reset();
    };

}

#endif