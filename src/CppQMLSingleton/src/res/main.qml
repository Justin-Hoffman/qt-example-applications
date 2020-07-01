import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2

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
                color: ExampleSingleton.color
                anchors.top: parent.top
                Text{
                    id: singleton_name
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    text: ExampleSingleton.name
                    color: "white"
                    font.pointSize: 16
                }
        }
        ListModel {
            id: nameModel
            ListElement { name: "Alice" }
            ListElement { name: "Bob" }
            ListElement { name: "Carol" }
            ListElement { name: "Eve" }
            ListElement { name: "Mallory" }
        }
        ListModel {
            id: colorModel
            ListElement { name: "Red"; color: "#FF0000"}
            ListElement { name: "Orange"; color: "#FFA500"}
            ListElement { name: "Yellow"; color: "#FFFF00"}
            ListElement { name: "Green"; color: "#00FF00" }
            ListElement { name: "Blue"; color: "#0000FF"}
            ListElement { name: "Indigo"; color: "#4B0082" }
            ListElement { name: "Violet"; color: "#EE82EE" }
        }

        ListView {
            id: nameList
            anchors.top: top_bar.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            width: parent.width/2
            clip: true
            focus: true
            visible: true

            model: nameModel

            delegate: Rectangle {
                width: parent.width
                height: 100
                color: index == nameList.currentIndex ? "grey": "white"
                
                Keys.onUpPressed: nameList.currentIndex = Math.max(0,nameList.currentIndex-1)
                Keys.onDownPressed: nameList.currentIndex = Math.min(nameList.count-1, nameList.currentIndex+1)
                Keys.onReturnPressed: ExampleSingleton.name = model.name

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                      nameList.currentIndex = index
                      nameList.focus = true
                      ExampleSingleton.name = model.name
                    }
                }
                Text{
                    id: name
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    width: 150
                    text: model.name
                    clip: true
                    font.pointSize: 14
                }

            }

        }
        
        ListView {
            id: colorList
            anchors.top: top_bar.bottom
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: parent.width/2
            clip: true
            focus: true
            visible: true

            model: colorModel

            delegate: Rectangle {
                width: parent.width
                height: 100
                color: index == colorList.currentIndex ? "grey": "white"
                
                Keys.onUpPressed: colorList.currentIndex = Math.max(0,colorList.currentIndex-1)
                Keys.onDownPressed: colorList.currentIndex = Math.min(colorList.count-1, colorList.currentIndex+1)
                Keys.onReturnPressed: ExampleSingleton.color = model.color

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                      colorList.currentIndex = index
                      colorList.focus = true
                      ExampleSingleton.color = model.color
                    }
                }
                Text{
                    id: name
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    width: 150
                    text: model.name
                    clip: true
                    font.pointSize: 14
                }

            }

        }

    }

}
