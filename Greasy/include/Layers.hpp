#ifndef H_LAYERS
#define H_LAYERS

namespace Greasy {

    class Layer {
    public:
        virtual void Update() = 0;
        virtual void Render() = 0;
    };

    class LayerStack {
        std::stack<Layer*> stack;
    public:
        void Push(Layer*);
        Layer* Pop();

    private:
        void Update();
        void Render();

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