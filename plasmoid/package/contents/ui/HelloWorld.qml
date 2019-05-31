import QtQuick 2.1
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.kdeconnect 1.0

QtObject {

    id: root

    property alias device: checker.device
    readonly property alias available: checker.available

    readonly property PluginChecker pluginChecker: PluginChecker {
        id: checker
        pluginName: "helloworld"
    }

    property variant helloWorld: null

    function ring() {
        if (helloWorld) {
            helloWorld.sendHelloWorld();
            console.log("ringed");
        }
    }

    onAvailableChanged: {
        if (available) {
            helloWorld = HelloWorldDbusInterfaceFactory.create(device.id())
        } else {
            helloWorld = null
        }
    }
}
