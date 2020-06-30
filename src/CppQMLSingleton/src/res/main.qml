import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2

import ExampleItemEditable 0.1
import ExampleSingleton 0.1

ApplicationWindow {
    visible: true
    width: 1200
    height: 800
    title: qsTr("Cpp QML Singleton Example")

    GridView{
        width: parent.width
        height: parent.height
        anchors.top: parent.top
        focus: true
        
        Rectangle {
                id: top_bar
                width: parent.width
                height: 100
                color: "#0047AB"
                anchors.top: parent.top
                Text{
                    id: singleton_name
                    anchors.top: parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: ExampleSingleton.name
                    color: "white"
                }
        }

        ListView {
            id: list
            anchors.top: top_bar.bottom
            anchors.bottom: parent.bottom
            width: parent.width
            clip: true
            focus: true
            visible: true

            model: ExampleItemModelEditable {}

            delegate: Rectangle {
                width: parent.width
                height: 100
                color: index == list.currentIndex ? "grey": "white"
                
                Keys.onUpPressed: list.currentIndex = Math.max(0,list.currentIndex-1)
                Keys.onDownPressed: list.currentIndex = Math.min(list.count-1, list.currentIndex+1)
                Keys.onReturnPressed: ExampleSingleton.name = model.name

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                      list.currentIndex = index
                      ExampleSingleton.name = model.name
                    }
                }
                Text{
                    id: name
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: description.left
                    width: 150
                    text: model.name
                    clip: true
                    font.pointSize: 14
                }

                Text{
                    id: description
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.left: name.right
                    text: model.description
                    clip: true
                    font.pointSize: 12
                }

                Text{
                    id: value1
                    anchors.left: parent.left
                    anchors.top: name.bottom
                    text: model.value1
                    font.pointSize: 8
                }

                Text{
                    id: value2
                    anchors.right: parent.right
                    anchors.top: name.bottom
                    text: model.value2
                    font.pointSize: 8
                }

            }

        }

    }

}
