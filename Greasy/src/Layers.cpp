#include "../include/Layers.hpp"

namespace Greasy {

	/*
		LayerStack
	*/

    void LayerStack::Push(Layer* layer) {
        stack.push(layer);
    }

    Layer* LayerStack::Pop() {
        auto popped = stack.top();
        stack.pop();
        return popped;
    }

	void LayerStack::Render() {
		LayerStackIterator iter(this);
		while (iter.HasNext()) {
			iter.Next()->OnRender();
		}
	}

	void LayerStack::Update() {
		LayerStackIterator iter(this);
		while (iter.HasNext()) {
			iter.Next()->OnUpdate();
		}
	}

    bool LayerStack::IsEmpty() const {
        return stack.empty();
    }

	/*
		LayerStackIterator
	*/

    LayerStackIterator::LayerStackIterator(LayerStack* stack)
            : stack(stack) {}

    LayerStackIterator::~LayerStackIterator() {
        if(!reset) {
            Reset();
        }
    }

    bool LayerStackIterator::HasNext() {
        return !stack->IsEmpty();
    }

    Layer* LayerStackIterator::Next() {
        reset = false;
        auto next = stack->Pop();
        temp.Push(next);
        return next;
    }

    void LayerStackIterator::Reset() {
        while(!temp.IsEmpty()) {
            stack->Push(temp.Pop());
        }
    }

}