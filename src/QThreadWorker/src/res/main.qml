import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2

import QThreadWorker 0.1

ApplicationWindow {
    visible: true
    width: 1200
    height: 800
    title: qsTr("Cpp Worker Thread Example")

    GridView{
        width: parent.width
        height: parent.height
        anchors.top: parent.top
        focus: true
        
        Rectangle {
                id: top_bar
                width: parent.width
                height: 100
                color: WorkManager.color
                anchors.top: parent.top
                GridView{
                    width: parent.width
                    height: parent.height
                    TextEdit {
                        id: number
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        text: "6"
                        color: "white"
                        font.pointSize: 16
                    }
                    Button {
                        id: factor_button
                        width: 250
                        height: 80
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        text: "factor"
                        onClicked: WorkManager.factors(parseInt(number.text))
                    }
                }
        }
        ListView {
            id: nameList
            anchors.top: top_bar.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            width: parent.width
            clip: true
            focus: true
            visible: true

            model: PrimeFactorsModel { id: factors_model; objectName: "factors_model" }

            delegate: Rectangle {
                width: parent.width
                height: 100
                
                Text{
                    id: name
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    width: 150
                    text: model.number
                    clip: true
                    font.pointSize: 14
                }

            }

        }
        
    }

}
