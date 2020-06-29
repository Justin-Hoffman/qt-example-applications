import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2

import ExampleItem 0.1
ApplicationWindow {
    visible: true
    width: 1200
    height: 800
    title: qsTr("Example Custom List Model")

    Frame{
        width: parent.width
        height: parent.height
        anchors.top: parent.top
        focus: true

        ListView {
            id: list
            anchors.fill: parent
            visible: true
            clip: true
            focus: true

            model: ExampleItemModel {}

            delegate: Rectangle {
                width: parent.width
                height: 100
                color: index == list.currentIndex ? "grey": "white"

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: list.currentIndex = index
                    Keys.onUpPressed: list.decrementCurrentIndex()
                    Keys.onDownPressed: list.incrementCurrentIndex()
                }

                Text{
                    id: name
                    anchors.top: parent.top
                    anchors.left: parent.left
                    width: 40
                    text: model.name
                    font.pointSize: 14
                }

                Text{
                    id: description
                    anchors.top: parent.top
                    anchors.right: parent.right
                    text: model.description
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
