import QtQuick 2.0

Rectangle{

}

//Rectangle{
//    id :bor1
//    width: 200
//    height: 100
//    color: "black"
//    property int myValue: 3
//    property real myReal: 0.0   //声明浮点型
//    property Component com1
//    property Component com2
//    Rectangle{
//        id: innerRec
//        anchors.fill: parent
//        anchors.topMargin: 5
//        anchors.bottomMargin: 5
//        anchors.leftMargin: myValue
//        anchors.rightMargin: myValue
//    }
//    Loader{
//        id:loader1
//        sourceComponent: com1
//        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 20
//        anchors.right: parent.right
//        anchors.rightMargin: 20
//        Connections{
//            target: loader1.item
//            function onBtnSig(value){
//                console.log(value)
//            }
//        }
//    }
//    Loader{
//        id:loader2
//        sourceComponent: com2
//        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 20
//        anchors.right: parent.right
//        anchors.rightMargin: 20
//        Connections{
//            target: loader2.item
//            function onBtnSig(value){
//                console.log(value)
//            }
//        }
//    }
//}
