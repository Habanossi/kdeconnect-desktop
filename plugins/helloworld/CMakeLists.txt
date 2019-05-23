set(kdeconnect_helloworld_SRCS
    helloworldplugin.cpp
)

kdeconnect_add_plugin(kdeconnect_helloworld JSON kdeconnect_helloworld.json SOURCES ${kdeconnect_helloworld_SRCS})

target_link_libraries(kdeconnect_helloworld
    kdeconnectcore
    Qt5::DBus
    KF5::I18n
)
