/*import QtQuick 2.1
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.kdeconnect 1.0

QtObject {

    id: root

    property alias device: checker.device
    readonly property alias available: checker.available

    readonly property PluginChecker pluginChecker: PluginChecker {
        id: checker
        pluginName: "ping"
    }

    property variant ping: null

    function ring() {
        if (ping) {
            console.log("pinged");
            ping.sendPing();
        }
    }

    onAvailableChanged: {
        if (available) {
            console.log("ping available")
            ping = PingDbusInterfaceFactory.create(device.id())
        } else {
            ping = null
        }
    }
}
*/
