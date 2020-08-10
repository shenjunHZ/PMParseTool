#include "AppDependency.hpp"

namespace App
{
    AppDependency::AppDependency()
        : mainWidgetUI_{ std::make_unique<ui::MainWidgetUI>() }
    {

    }

    bool AppDependency::initAppInstance()
    {
        mainWidgetUI_->initUI();
        int dlgCode = mainWidgetUI_->exec();

        if (QDialog::Rejected == dlgCode)
        {
            return false;
        }

        return true;
    }

} // namespace app