/**
 *insert license header here
 */

#include "helloworldplugin.h"

#include <KLocalizedString>
#include <KPluginFactory>

#include <QDebug>
#include <QDBusConnection>
#include <QLoggingCategory>

#include <core/device.h>
#include <core/daemon.h>

K_PLUGIN_FACTORY_WITH_JSON( KdeConnectPluginFactory, "kdeconnect_helloworld.json", registerPlugin< HelloWorldPlugin >(); )

Q_LOGGING_CATEGORY(KDECONNECT_PLUGIN_HELLOWORLD, "kdeconnect.plugin.helloworld")

HelloWorldPlugin::HelloWorldPlugin(QObject* parent, const QVariantList& args)
    : KdeConnectPlugin(parent, args)
{
//     qCDebug(KDECONNECT_PLUGIN_HELLOWORLD) << "HelloWorld plugin constructor for device" << device()->name();
}

HelloWorldPlugin::~HelloWorldPlugin()
{
//     qCDebug(KDECONNECT_PLUGIN_HELLOWORLD) << "HelloWorld plugin destructor for device" << device()->name();
}

bool HelloWorldPlugin::receivePacket(const NetworkPacket& np)
{
    Daemon::instance()->sendSimpleNotification(QStringLiteral("helloworldReceived"), device()->name(), np.get<QString>(QStringLiteral("message"),i18n("Hello World!")), QStringLiteral("dialog-ok"));

    return true;
}

void HelloWorldPlugin::sendHelloWorld()
{
    NetworkPacket np(PACKET_TYPE_HELLOWORLD);
    bool success = sendPacket(np);
    qCDebug(KDECONNECT_PLUGIN_HELLOWORLD) << "sendHelloWorld:" << success;
}

void HelloWorldPlugin::sendHelloWorld(const QString& customMessage)
{
    NetworkPacket np(PACKET_TYPE_HELLOWORLD);
    if (!customMessage.isEmpty()) {
        np.set(QStringLiteral("message"), customMessage);
    }
    bool success = sendPacket(np);
    qCDebug(KDECONNECT_PLUGIN_HELLOWORLD) << "sendHelloWorld:" << success;
}

QString HelloWorldPlugin::dbusPath() const
{
    return "/modules/kdeconnect/devices/" + device()->id() + "/helloworld";
}

#include "helloworldplugin.moc"

