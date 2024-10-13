import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import MyObj 1.0

Window{
    width: 640
    height: 480
    title: qsTr("Demo")
    Row{
        // 默认从左到右
        layoutDirection: Qt.RightToLeft // 修改为从右往左
    }

    Column{  //从上往下
        id:col
        spacing: 30
        leftPadding: 50
        topPadding: 50
        Button{
            width: 100
            height: 40
            text:"按钮1"
        }
        Button{
            width: 100
            height: 40
            text:"按钮2"
        }
        Button{
            width: 100
            height: 40
            text:"按钮3"
        }
    }

}


//Window{
//    id:window
//    width: 640
//    height: 400
//    title: qsTr("Demo")
//    signal qmlSig(int i, string s)

//    MyObject{
//        id:myobj
//    }

//    //通过信号与槽绑定.CPP文件的槽函数
////    Connections{
////        target: window
////        function OnQmlSig(i, s){
////            myobj.cppSlot(i,s)
////        }

////    }
//    Connections{
//        target: myobj
//        function onCppSig(i, s){
//            qmlSlot(i, s)
//        }
//    }

//    Component.onCompleted: {
//        qmlSig.connect(myobj.cppSlot)
//    }
//    function qmlSlot(i, s){
//        console.log(i, s)
//    }
//    function qmlFunc(i, s){
//        return "success"
//    }
//}

//Window{
//    id :window
//    width: 640
//    height: 400
//    visible: true
//    title: qsTr("Demo")
//    //signal MySig() // 声明信号
//    //相对于父控件的位置
//    x:50
//    y:50
//    minimumHeight: 300
//    minimumWidth: 400
//    maximumHeight: 400
//    maximumWidth: 640

//    // 信号与槽第一种方法
//    signal testSig(string s, int valueOf)
//    function func(ss, ii){
//        console.log(ss,ii)
//    }
//    Component{
//        id:com
//        signal btnSig(int value)
//        Button{
//            onClicked: {
//                btnSig(10)
//            }
//        }
//    }

//    MyRectangle{
//        com1: com
//        com2: com
//    }

//    Button{
//        width: 40
//        height: 30
//        onClicked: {
//            testSig("zhang", 99)
//        }
//    }
//    Component.onCompleted: {
//        testSig.connect(func)
//    }
//    // 信号与槽第二种方式
//    Connections{
//        target: window
//        //        onTestSig: {
//        //            console.log(s,value)
//        //        }
//        function onTestSig(str, iValue){
//            console.log(str, iValue)
//        }

//    }


//    //    Text {
//    //        id: name
//    //        elide: Text.ElideRight  //文本过长，设置省略部分
//    //        anchors.fill: parent
//    //        text: qsTr("text")
//    //    }


//    //    DelayButton{
//    //        width: 120
//    //        height: 30
//    //        delay: 3000
//    //        onProgressChanged: {
//    //            console.log(progress)
//    //        }
//    //    }
//    //    Column{
//    //        // 将radiobutton设置在一个
//    //        RadioButton{
//    //            checked:true
//    //            text:qsTr("单选框1")
//    //        }
//    //        RadioButton{
//    //            text:qsTr("单选框2")
//    //        }
//    //        RadioButton{
//    //            text:qsTr("单选框3")
//    //        }
//    //    }

//    //    // CheckBox
//    //    Column{
//    //        CheckBox{
//    //            checked:true
//    //            tristate: true  //判断是否有三种状态的模式
//    //            text:qsTr("复选框1")
//    //        }
//    //        CheckBox{
//    //            text:qsTr("复选框2")
//    //        }
//    //        CheckBox{
//    //            text:qsTr("复选框3")
//    //        }
//    //    }


//    // Button控件
//    //    Button{
//    //        id : btn
//    //        width: 100
//    //        height: 50
//    //        x:50
//    //        text:"按钮1"
//    //        autoRepeat: true  //不断触发按钮的点击，松开信号
//    //        autoRepeatDelay: 3000 // 设置第一次按下的间隔时间
//    //        autoRepeatInterval: 1000 // 不断触发的间隔时间设置
//    //        checkable: false
//    //        // flat:true // 若为true则不绘制背景色、
//    ////        onCheckableChanged: {
//    ////            console.log("changed", checkable)
//    ////        }
//    //        onClicked: {
//    //            console.log("clicked")
//    //        }
//    //        onPressed: {
//    //            console.log("onPressed")
//    //        }
//    //        onReleased: {
//    //            console.log("onReleased")
//    //        }
//    //        // 设置背景色
//    //        background: Rectangle{
//    //            anchors.fill: parent
//    //            color:
//    //            {
//    //                if (btn.pressed){
//    //                    return "green"
//    //                } else{
//    //                    return "red"
//    //                }
//    //            }
//    //        }

//    //    }












//    // MouseArea
//    //    MouseArea{
//    //        id : mouseArea
//    //        width: 200
//    //        height: 200
//    //        hoverEnabled: true  //悬停即触发信号
//    //        acceptedButtons:Qt.LeftButton | Qt.RightButton
//    //        Rectangle{
//    //            anchors.fill: parent
//    //            color: "black"
//    //        }
//    //        onHoveredChanged: {
//    //            console.log("悬停")
//    //        }

//    //        clicked: {
//    //            var ret = pressedButtons & Qt.LeftButton
//    //            if (ret) {
//    //                console.log("左键")
//    //            }else{
//    //                console.log("不是左键")
//    //            }
//    //            console.log("click")
//    //        }
//    //        onPressed: {
//    //            console.log("pressed")
//    //        }
//    //        onReleased: {
//    //            console.log("released")
//    //        }
//    //    }

//    // Component
//    // 帮助在控件生成时打印信息
//    //    Component.onCompleted: {
//    //        console.log("onCompleted", width, height)
//    //    }
//    //    Component
//    //    {
//    //        id:com
//    //        Rectangle{
//    //            width: 200
//    //            height: 100
//    //            color: "black"
//    //        }
//    //    }
//    //    Component{
//    //        id:com
//    //        Image {
//    //            id: img
//    //            source: "/Users/Administrator/Desktop/20200312104851256.png"
//    //            sourceSize.width: 100
//    //            sourceSize.height: 100
//    //        }
//    //    }

//    //    //动态的加载控件
//    //    Loader{
//    //        id :loader
//    //        //source: "/MyRectangle.qml"
//    //        sourceComponent: com
//    //        asynchronous: true
//    //    }
//    //    Button{
//    //        width: 50
//    //        height: 50
//    //        x:300
//    //        onClicked: {
//    // 销毁loader的内容
//    // loader.sourceComponent = null

//    //            loader.item.width = 50
//    //            loader.item.height = 40;
//    //        }
//    //    }

//    //    // 槽函数
//    //    onMySig: {

//    //    }

//    //    // 自带的宽度改变的信号与槽函数
//    //    onWidthChanged: {
//    //        console.log("width:",width)
//    //    }
//    //    Button{
//    //        id:btn1
//    //        text:"按钮1"
//    //        width:50
//    //        height: 40
//    //        objectName: "btn1" // 添加控件独有的名字
//    //        background: Rectangle{
//    //            border.color: btn1.focus?"blue":"yellow"
//    //        }
//    //        onClicked: {
//    //            console.log("btn1 clicked")
//    //        }
//    //        // 鼠标左键按下操作
//    //        Keys.onLeftPressed: {
//    //            btn1.focus = true
//    //        }
//    //    }
//    //    // 了解当前焦点发生改变
//    //    onActiveFocusItemChanged: {
//    //        console.log("Active Focus Item:",activeFocusItem, "object name:",activeFocusItem.objectName)
//    //    }


//    // 矩形控件
//    //    Rectangle{
//    //        id:rec1
//    //        x:100
//    //        y:100
//    //        z:1  //控件当前控件的显示顺序
//    //        width: 100
//    //        height: 100
//    //        color:"black"
//    //        focus: true // 判断当前控件是否拥有焦点
//    //        // 鼠标操作
//    //        MouseArea{
//    //            anchors.fill:parent // 填充父类控件
//    //            onClicked: {
//    //                console.log("on clicked")
//    //            }
//    //        }
//    //        Keys.onReturnPressed: {
//    //            console.log("on return press")
//    //        }
//    //        border.width: 2 //设置控件边框宽度
//    //        border.color: "red" // 设置控件边框颜色
//    //        radius: 2 //修改控件边框的圆角弧度
//    //        gradient: Gradient{
//    //            GradientStop{position: 0.0; color: "grey"}
//    //            GradientStop{position: 1.0; color: "blue"}
//    //        }
//    //    }
//    //    Rectangle{
//    //        id:root
//    //        width: 100
//    //        height: 100
//    //        state: "red_color"
//    //        // 状态选项，可以进行控件状态修改
//    //        states: [
//    //            State {
//    //                name: "red_color"
//    //                PropertyChanges {
//    //                    target: root
//    //                    color:"red"
//    //                    width:200
//    //                }
//    //            },
//    //            State {
//    //                name: "blue_color"
//    //                PropertyChanges {
//    //                    target: root
//    //                    color:"blue"
//    //                    width:50
//    //                }
//    //            }
//    //        ]
//    //        MouseArea{
//    //            anchors.fill: parent
//    //            onPressed: {
//    //                root.state = "red_color"
//    //            }
//    //            onReleased: {
//    //                root.state = "blue_color"
//    //            }
//    //        }
//    //    }

//    //    Rectangle{
//    //        id : flashingblob
//    //        width: 75
//    //        height: 75
//    //        anchors.left: root.right
//    //        color: "blue"
//    //        opacity: 0.1
//    //        // 创建鼠标进行捕获
//    //        MouseArea{
//    //            anchors.fill: parent
//    //            onClicked: {
//    //                animateColor.start()
//    //                animateOpacity.start()
//    //            }
//    //        }
//    //        // 制作动画效果
//    //        PropertyAnimation{
//    //            id:animateColor
//    //            target: flashingblob
//    //            properties: "color"
//    //            to:"green"
//    //            duration: 1000
//    //        }
//    //        NumberAnimation{
//    //            id:animateOpacity
//    //            target: flashingblob
//    //            properties: "opacity"
//    //            from: 0.1
//    //            to:1.0
//    //            duration: 1000
//    //        }
//    //        NumberAnimation{
//    //            id:animatWidth
//    //            target: flashingblob
//    //            properties: "width"
//    //            from:75
//    //            to:200
//    //            duration: 1000  //控制动画效果持续时间
//    //        }
//    //    }


//    // 锚点功能
//    //    Rectangle{
//    //        id:rec2
//    //        // x:rec1.width + 20   绝对方式设置坐标
//    //        width: 50
//    //        height: 30
//    //        anchors.left: rec1.right // 与第一个控件左对齐
//    //        anchors.leftMargin: 10 // 设置与第一个控件的间隔
//    //        // anchors.centerIn: parent // 居中于父控件
//    //        // anchors.horizontalCenter: parent.horizontalCenter  水平布局
//    //        // anchors.verticalCenter: parent.verticalCenter 垂直布局
//    //        // rotation: 90 // 实现旋转
//    //        // scale: 2 //放缩控件
//    //        // border.width: 2 //设置控件边框宽度
//    //        // border.color: "red" // 设置控件边框颜色
//    //    }

//    //    MyRectangle{
//    //        x:100
//    //        y:50
//    //        myValue: 4  //设置属性
//    //    }

//}



