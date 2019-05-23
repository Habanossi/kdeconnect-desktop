/**
 * license header here
 */

#ifndef HELLOWORLDPLUGIN_H
#define HELLOWORLDPLUGIN_H

#include <QObject>

#include <core/kdeconnectplugin.h>

#define PACKET_TYPE_HELLOWORLD QStringLiteral("kdeconnect.helloworld")

class Q_DECL_EXPORT HelloWorldPlugin
    : public KdeConnectPlugin
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.kdeconnect.device.helloworld")

public:
    explicit HelloWorldPlugin(QObject* parent, const QVariantList& args);
    ~HelloWorldPlugin() override;

    Q_SCRIPTABLE void sendHelloWorld();
    Q_SCRIPTABLE void sendHelloWorld(const QString& customMessage);

    bool receivePacket(const NetworkPacket& np) override;
    void connected() override {}

    QString dbusPath() const override;
};

#endif
