#ifndef GITHUBACTIONSTESTPLUGIN_H
#define GITHUBACTIONSTESTPLUGIN_H

#include "githubactionstest_global.h"

#include <extensionsystem/iplugin.h>

namespace Githubactionstest {
namespace Internal {

class GithubactionstestPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Githubactionstest.json")

public:
    GithubactionstestPlugin();
    ~GithubactionstestPlugin() override;

    bool initialize(const QStringList &arguments, QString *errorString) override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

private:
    void triggerAction();
};

} // namespace Internal
} // namespace Githubactionstest

#endif // GITHUBACTIONSTESTPLUGIN_H
