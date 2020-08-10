#pragma once
#include <QtWidgets/QApplication>
#include <QtCore/QSharedMemory>
#include <memory>

namespace config
{
class AppConfig
{
public:
    AppConfig(QApplication& app);
    bool runOnlyOne();
    void releaseShareMemory();

private:
    bool isRunning();

private:
    std::unique_ptr<QSharedMemory> m_sharedMenPtr{ nullptr };
};
} // namespace config