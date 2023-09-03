#pragma once

#include <Ghost/Core.h>
#include <Ghost/Layer.h>

#include <vector>

namespace Ghost
{

    class GHOST_API LayerStack
    {
        public:
            LayerStack();
            ~LayerStack();

            void PushLayer(Layer* layer);
            void PushOverLay(Layer* overlay);
            void PopLayer(Layer* layer);
            void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return m_Layers.end(); }
        private:
            std::vector<Layer*> m_Layers;
            std::vector<Layer*>::iterator m_LayerInsert;
    };

}