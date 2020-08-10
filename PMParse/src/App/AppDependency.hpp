#pragma once
#include <memory>
#include "ui/MainWidgetUI.hpp"

namespace App
{
    class AppDependency
    {
    public:
        AppDependency();
        bool initAppInstance();

    private:
        std::unique_ptr<ui::MainWidgetUI> mainWidgetUI_{nullptr};
    };
}