import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import com.parkingsystem 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 1400
    height: 900
    title: "Система управления парковкой"
    color: "#f0f2f5"

    ParkingManager {
        id: parkingManager
        
        onParkingSessionsChanged: {
            statusBar.updateActive()
        }
        
        onOwnersChanged: {
            ownersList.model = null
            ownersList.model = parkingManager.owners
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        // === ЗАГОЛОВОК (БЕЗ КНОПКИ СТАТИСТИКА) ===
        Rectangle {
            Layout.fillWidth: true
            height: 70
            color: "#2c3e50"
            radius: 10

            RowLayout {
                anchors.fill: parent
                anchors.margins: 15
                spacing: 20

                Text {
                    text: "🏢 Парковка"
                    color: "white"
                    font.bold: true
                    font.pixelSize: 28
                }

                Item { Layout.fillWidth: true }
            }
        }

        // === ТАБЫ ===
        TabBar {
            id: tabBar
            Layout.fillWidth: true
            background: Rectangle {
                color: "transparent"
            }

            TabButton {
                text: "🅿️  Места"
                background: Rectangle {
                    color: tabBar.currentIndex === 0 ? "#3498db" : "#bdc3c7"
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }
                padding: 12
                width: 150
            }

            TabButton {
                text: "👤  Владельцы"
                background: Rectangle {
                    color: tabBar.currentIndex === 1 ? "#3498db" : "#bdc3c7"
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }
                padding: 12
                width: 150
            }

            TabButton {
                text: "🚗  Транспорт"
                background: Rectangle {
                    color: tabBar.currentIndex === 2 ? "#3498db" : "#bdc3c7"
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }
                padding: 12
                width: 150
            }

            TabButton {
                text: "📋  Сессии"
                background: Rectangle {
                    color: tabBar.currentIndex === 3 ? "#3498db" : "#bdc3c7"
                    radius: 6
                }
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                }
                padding: 12
                width: 150
            }
        }

        // === СОДЕРЖИМОЕ ===
        StackLayout {
            currentIndex: tabBar.currentIndex
            Layout.fillWidth: true
            Layout.fillHeight: true

            // === ВКЛ. 1: МЕСТА ===
            ColumnLayout {
                spacing: 15

                Rectangle {
                    Layout.fillWidth: true
                    height: 100
                    color: "white"
                    radius: 8

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        spacing: 10

                        TextField {
                            id: spotNumField
                            placeholderText: "Номер (A001)"
                            placeholderTextColor: "#95a5a6"
                            color: "#2c3e50"
                            Layout.preferredWidth: 150
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            padding: 10
                        }

                        ComboBox {
                            id: spotTypeBox
                            model: ["Обычное", "VIP", "Инвалид", "Мотоцикл"]
                            Layout.preferredWidth: 150
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            contentItem: Text {
                                text: spotTypeBox.currentText
                                color: "#2c3e50"
                                leftPadding: 10
                            }
                        }

                        ComboBox {
                            id: spotStatusBox
                            model: ["Свободно", "Занято", "Заблокировано"]
                            Layout.preferredWidth: 150
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            contentItem: Text {
                                text: spotStatusBox.currentText
                                color: "#2c3e50"
                                leftPadding: 10
                            }
                        }

                        Button {
                            text: "➕ Добавить"
                            background: Rectangle {
                                color: "#27ae60"
                                radius: 4
                            }
                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                font.bold: true
                                horizontalAlignment: Text.AlignHCenter
                            }
                            padding: 10
                            onClicked: {
                                if (spotNumField.text) {
                                    parkingManager.addParkingSpot(spotNumField.text, spotTypeBox.currentText, spotStatusBox.currentText)
                                    spotNumField.clear()
                                    showMessage("✅ Место добавлено!")
                                } else {
                                    showError("❌ Заполните номер места!")
                                }
                            }
                        }

                        Item { Layout.fillWidth: true }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"
                    radius: 8

                    ScrollView {
                        anchors.fill: parent
                        anchors.margins: 10
                        clip: true

                        ListView {
                            id: spotsList
                            model: parkingManager.parkingSpots
                            spacing: 8
                            boundsBehavior: Flickable.StopAtBounds

                            delegate: Rectangle {
                                width: spotsList.width
                                height: 60
                                radius: 6
                                color: modelData.status === "Свободно" ? "#d5f4e6" : modelData.status === "Занято" ? "#f4d5d5" : "#ffe0b2"
                                border.color: "#bdc3c7"
                                border.width: 1

                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    spacing: 15

                                    Text {
                                        text: "📍 " + modelData.spotNumber
                                        font.bold: true
                                        font.pixelSize: 16
                                        color: "#2c3e50"
                                    }

                                    Text {
                                        text: "Тип: " + modelData.spotType
                                        color: "#2c3e50"
                                    }

                                    Text {
                                        text: "Статус: " + modelData.status
                                        color: "#2c3e50"
                                        font.bold: true
                                    }

                                    Item { Layout.fillWidth: true }

                                    Button {
                                        text: "❌"
                                        background: Rectangle {
                                            color: "#e74c3c"
                                            radius: 4
                                        }
                                        contentItem: Text {
                                            text: parent.text
                                            color: "white"
                                            font.bold: true
                                        }
                                        width: 40
                                        height: 40
                                        onClicked: {
                                            parkingManager.deleteParkingSpot(index)
                                            showMessage("✅ Место удалено!")
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // === ВКЛ. 2: ВЛАДЕЛЬЦЫ ===
            ColumnLayout {
                spacing: 15

                Rectangle {
                    Layout.fillWidth: true
                    height: 100
                    color: "white"
                    radius: 8

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        spacing: 10

                        TextField {
                            id: ownerNameField
                            placeholderText: "ФИО"
                            placeholderTextColor: "#95a5a6"
                            color: "#2c3e50"
                            Layout.preferredWidth: 200
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            padding: 10
                        }

                        TextField {
                            id: ownerPhoneField
                            placeholderText: "Телефон"
                            placeholderTextColor: "#95a5a6"
                            color: "#2c3e50"
                            Layout.preferredWidth: 180
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            padding: 10
                        }

                        TextField {
                            id: ownerCityField
                            placeholderText: "Город"
                            placeholderTextColor: "#95a5a6"
                            color: "#2c3e50"
                            Layout.preferredWidth: 150
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            padding: 10
                        }

                        Button {
                            text: "➕ Добавить"
                            background: Rectangle {
                                color: "#27ae60"
                                radius: 4
                            }
                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                font.bold: true
                            }
                            padding: 10
                            onClicked: {
                                if (ownerNameField.text) {
                                    parkingManager.addOwner(ownerNameField.text, ownerPhoneField.text, ownerCityField.text)
                                    ownerNameField.clear()
                                    ownerPhoneField.clear()
                                    ownerCityField.clear()
                                    showMessage("✅ Владелец добавлен!")
                                } else {
                                    showError("❌ Заполните ФИО!")
                                }
                            }
                        }

                        Item { Layout.fillWidth: true }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"
                    radius: 8

                    ScrollView {
                        anchors.fill: parent
                        anchors.margins: 10
                        clip: true

                        ListView {
                            id: ownersList
                            model: parkingManager.owners
                            spacing: 8
                            boundsBehavior: Flickable.StopAtBounds

                            delegate: Rectangle {
                                width: ownersList.width
                                height: 80
                                radius: 6
                                color: index % 2 === 0 ? "#f8f9fa" : "white"
                                border.color: "#bdc3c7"
                                border.width: 1

                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    spacing: 15

                                    ColumnLayout {
                                        spacing: 3
                                        Layout.fillWidth: true

                                        Text {
                                            text: "👤 " + modelData.name
                                            font.bold: true
                                            font.pixelSize: 14
                                            color: "#2c3e50"
                                        }

                                        Text {
                                            text: modelData.phone + " | " + modelData.city
                                            color: "#2c3e50"
                                            font.pixelSize: 12
                                        }
                                    }

                                    RowLayout {
                                        spacing: 8
                                        Layout.preferredWidth: 110

                                        Button {
                                            text: "✏️"
                                            background: Rectangle {
                                                color: "#3498db"
                                                radius: 5
                                            }
                                            contentItem: Text {
                                                text: parent.text
                                                color: "white"
                                                font.pixelSize: 14
                                            }
                                            Layout.preferredWidth: 45
                                            Layout.preferredHeight: 40
                                            onClicked: {
                                                editOwnerDialog.index = index
                                                editNameInput.text = modelData.name
                                                editPhoneInput.text = modelData.phone
                                                editCityInput.text = modelData.city
                                                editOwnerDialog.open()
                                            }
                                        }

                                        Button {
                                            text: "❌"
                                            background: Rectangle {
                                                color: "#e74c3c"
                                                radius: 5
                                            }
                                            contentItem: Text {
                                                text: parent.text
                                                color: "white"
                                                font.pixelSize: 14
                                            }
                                            Layout.preferredWidth: 45
                                            Layout.preferredHeight: 40
                                            onClicked: {
                                                var hasVehicles = false
                                                for (var i = 0; i < parkingManager.vehicles.length; i++) {
                                                    if (parkingManager.vehicles[i].ownerId === modelData.id) {
                                                        hasVehicles = true
                                                        break
                                                    }
                                                }
                                                
                                                if (hasVehicles) {
                                                    showError("❌ Нельзя удалить: у владельца есть ТС!")
                                                } else {
                                                    parkingManager.deleteOwner(index)
                                                    showMessage("✅ Владелец удален!")
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // === ВКЛ. 3: ТРАНСПОРТ ===
            ColumnLayout {
                spacing: 15

                Rectangle {
                    Layout.fillWidth: true
                    height: 100
                    color: "white"
                    radius: 8

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        spacing: 10

                        TextField {
                            id: plateField
                            placeholderText: "Номер (A123BC177)"
                            placeholderTextColor: "#95a5a6"
                            color: "#2c3e50"
                            Layout.preferredWidth: 180
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            padding: 10
                        }

                        ComboBox {
                            id: vehicleTypeBox
                            model: ["Легковой", "Внедорожник", "Грузовой", "Мотоцикл"]
                            Layout.preferredWidth: 150
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            contentItem: Text {
                                text: vehicleTypeBox.currentText
                                color: "#2c3e50"
                                leftPadding: 10
                            }
                        }

                        ComboBox {
                            id: vehicleOwnerBox
                            model: parkingManager.owners
                            textRole: "name"
                            Layout.preferredWidth: 200
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            contentItem: Text {
                                text: vehicleOwnerBox.currentText
                                color: "#2c3e50"
                                leftPadding: 10
                            }
                        }

                        Button {
                            text: "➕ Добавить"
                            background: Rectangle {
                                color: "#27ae60"
                                radius: 4
                            }
                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                font.bold: true
                            }
                            padding: 10
                            onClicked: {
                                if (plateField.text && vehicleOwnerBox.currentIndex >= 0) {
                                    var owner = parkingManager.owners[vehicleOwnerBox.currentIndex]
                                    parkingManager.addVehicle(plateField.text, vehicleTypeBox.currentText, owner.id)
                                    plateField.clear()
                                    showMessage("✅ ТС добавлено!")
                                } else {
                                    showError("❌ Заполните номер и выберите владельца!")
                                }
                            }
                        }

                        Item { Layout.fillWidth: true }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"
                    radius: 8

                    ScrollView {
                        anchors.fill: parent
                        anchors.margins: 10
                        clip: true

                        ListView {
                            id: vehiclesList
                            model: parkingManager.vehicles
                            spacing: 8
                            boundsBehavior: Flickable.StopAtBounds

                            delegate: Rectangle {
                                width: vehiclesList.width
                                height: 60
                                radius: 6
                                color: index % 2 === 0 ? "#e8f4f8" : "white"
                                border.color: "#bdc3c7"
                                border.width: 1

                                RowLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    spacing: 15

                                    Text {
                                        text: "🚗 " + modelData.licensePlate
                                        font.bold: true
                                        font.pixelSize: 16
                                        color: "#2c3e50"
                                    }

                                    Text {
                                        text: "Тип: " + modelData.vehicleType
                                        color: "#2c3e50"
                                    }

                                    Text {
                                        text: "Владелец ID: " + modelData.ownerId
                                        color: "#2c3e50"
                                    }

                                    Item { Layout.fillWidth: true }

                                    Button {
                                        text: "❌"
                                        background: Rectangle {
                                            color: "#e74c3c"
                                            radius: 4
                                        }
                                        contentItem: Text {
                                            text: parent.text
                                            color: "white"
                                        }
                                        width: 40
                                        height: 40
                                        onClicked: {
                                            parkingManager.deleteVehicle(index)
                                            showMessage("✅ ТС удалено!")
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // === ВКЛ. 4: СЕССИИ ===
            ColumnLayout {
                spacing: 15

                Rectangle {
                    Layout.fillWidth: true
                    height: 100
                    color: "white"
                    radius: 8

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 15
                        spacing: 10

                        ComboBox {
                            id: sessionSpotBox
                            model: parkingManager.parkingSpots
                            textRole: "spotNumber"
                            Layout.preferredWidth: 150
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            contentItem: Text {
                                text: sessionSpotBox.currentText
                                color: "#2c3e50"
                                leftPadding: 10
                            }
                        }

                        ComboBox {
                            id: sessionVehicleBox
                            model: parkingManager.vehicles
                            textRole: "licensePlate"
                            Layout.preferredWidth: 200
                            background: Rectangle {
                                color: "#ecf0f1"
                                radius: 4
                                border.color: "#bdc3c7"
                                border.width: 1
                            }
                            contentItem: Text {
                                text: sessionVehicleBox.currentText
                                color: "#2c3e50"
                                leftPadding: 10
                            }
                        }

                        Button {
                            text: "▶️  Начать"
                            background: Rectangle {
                                color: "#27ae60"
                                radius: 4
                            }
                            contentItem: Text {
                                text: parent.text
                                color: "white"
                                font.bold: true
                            }
                            padding: 10
                            onClicked: {
                                if (sessionSpotBox.currentIndex >= 0 && sessionVehicleBox.currentIndex >= 0) {
                                    var vehicle = parkingManager.vehicles[sessionVehicleBox.currentIndex]
                                    var spot = parkingManager.parkingSpots[sessionSpotBox.currentIndex]
                                    
                                    if (spot.status === "Занято") {
                                        showError("❌ Это место уже занято!")
                                        return
                                    }
                                    
                                    if (spot.status === "Заблокировано") {
                                        showError("❌ Это место заблокировано!")
                                        return
                                    }
                                    
                                    if (spot.spotType === "Мотоцикл" && vehicle.vehicleType !== "Мотоцикл") {
                                        showError("❌ На место для мотоциклов может припарковаться только мотоцикл!")
                                        return
                                    }
                                    
                                    if (spot.spotType === "Инвалид" && vehicle.vehicleType !== "Легковой") {
                                        showError("❌ На место для инвалидов может припарковаться только легковой автомобиль!")
                                        return
                                    }
                                    
                                    if (spot.spotType === "VIP" && vehicle.vehicleType === "Грузовой") {
                                        showError("❌ Грузовик не может припарковаться на VIP место!")
                                        return
                                    }
                                    
                                    parkingManager.addParkingSession(spot.id, vehicle.id, vehicle.licensePlate, 
                                                                    vehicle.vehicleType, vehicle.ownerId, new Date())
                                    showMessage("✅ Парковка начата!")
                                } else {
                                    showError("❌ Выберите место и ТС!")
                                }
                            }
                        }

                        Item { Layout.fillWidth: true }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"
                    radius: 8

                    ScrollView {
                        anchors.fill: parent
                        anchors.margins: 10
                        clip: true

                        ListView {
                            id: sessionsList
                            model: parkingManager.parkingSessions
                            spacing: 8
                            boundsBehavior: Flickable.StopAtBounds

                            delegate: Rectangle {
                                width: sessionsList.width
                                height: 110
                                radius: 6
                                
                                color: {
                                    var exitTime = modelData.exitTime
                                    if (!exitTime || exitTime.toString() === "Invalid Date" || !exitTime.isValid()) {
                                        return "#fff3cd"
                                    }
                                    return "#d4edda"
                                }
                                
                                border.color: "#bdc3c7"
                                border.width: 1

                                ColumnLayout {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    spacing: 8

                                    RowLayout {
                                        spacing: 15

                                        Text {
                                            text: "🚗 " + modelData.licensePlate
                                            font.bold: true
                                            font.pixelSize: 14
                                            color: "#2c3e50"
                                        }

                                        Text {
                                            text: "🅿️ Место: " + getSpotNumber(modelData.spotId)
                                            color: "#2c3e50"
                                        }

                                        Text {
                                            text: modelData.vehicleType
                                            color: "#7f8c8d"
                                        }

                                        Item { Layout.fillWidth: true }
                                    }

                                    RowLayout {
                                        spacing: 15

                                        Text {
                                            text: "⏰ Въезд: " + Qt.formatDateTime(modelData.entryTime, "dd.MM.yyyy hh:mm:ss")
                                            color: "#2c3e50"
                                            font.pixelSize: 12
                                        }

                                        Text {
                                            visible: modelData.exitTime && modelData.exitTime.isValid && modelData.exitTime.toString() !== "Invalid Date"
                                            text: "🚪 Выезд: " + Qt.formatDateTime(modelData.exitTime, "dd.MM.yyyy hh:mm:ss")
                                            color: "#27ae60"
                                            font.pixelSize: 12
                                            font.bold: true
                                        }

                                        Text {
                                            visible: !modelData.exitTime || !modelData.exitTime.isValid || modelData.exitTime.toString() === "Invalid Date"
                                            text: "⏳ Активная парковка"
                                            color: "#e67e22"
                                            font.bold: true
                                        }

                                        Item { Layout.fillWidth: true }

                                        Button {
                                            visible: !modelData.exitTime || !modelData.exitTime.isValid || modelData.exitTime.toString() === "Invalid Date"
                                            text: "✓ Выезд"
                                            background: Rectangle {
                                                color: "#3498db"
                                                radius: 4
                                            }
                                            contentItem: Text {
                                                text: parent.text
                                                color: "white"
                                                font.bold: true
                                                horizontalAlignment: Text.AlignHCenter
                                            }
                                            padding: 8
                                            onClicked: {
                                                parkingManager.endParkingSession(index, new Date())
                                                showMessage("✅ Парковка завершена!")
                                            }
                                        }

                                        Button {
                                            text: "❌"
                                            background: Rectangle {
                                                color: "#e74c3c"
                                                radius: 4
                                            }
                                            contentItem: Text {
                                                text: parent.text
                                                color: "white"
                                            }
                                            width: 40
                                            height: 40
                                            onClicked: {
                                                parkingManager.deleteParkingSession(index)
                                                showMessage("✅ Сессия удалена!")
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // === СТАТУС БАР ===
        Rectangle {
            id: statusBar
            Layout.fillWidth: true
            height: 50
            color: "#34495e"
            radius: 8

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 30

                Text {
                    text: "📊 Мест: " + parkingManager.parkingSpots.length
                    color: "white"
                    font.bold: true
                }

                Text {
                    text: "👤 Владельцев: " + parkingManager.owners.length
                    color: "white"
                    font.bold: true
                }

                Text {
                    text: "🚗 ТС: " + parkingManager.vehicles.length
                    color: "white"
                    font.bold: true
                }

                Text {
                    text: "📋 Всего сессий: " + parkingManager.parkingSessions.length
                    color: "white"
                    font.bold: true
                }

                Text {
                    id: activeSessText
                    text: "⏳ Активных: 0"
                    color: "#e67e22"
                    font.bold: true
                }

                Item { Layout.fillWidth: true }

                Text {
                    text: "v1.0"
                    color: "#95a5a6"
                    font.pixelSize: 12
                }
            }
            
            function updateActive() {
                var count = 0
                for (var i = 0; i < parkingManager.parkingSessions.length; i++) {
                    var session = parkingManager.parkingSessions[i]
                    if (!session.exitTime || !session.exitTime.isValid || session.exitTime.toString() === "Invalid Date") {
                        count++
                    }
                }
                activeSessText.text = "⏳ Активных: " + count
            }
        }
    }

    // === ДИАЛОГИ ===
    Dialog {
        id: editOwnerDialog
        title: "Редактировать владельца"
        modal: true
        width: 400
        height: 250

        property int index: -1

        ColumnLayout {
            anchors.fill: parent
            spacing: 10

            TextField {
                id: editNameInput
                placeholderText: "ФИО"
                placeholderTextColor: "#95a5a6"
                color: "#2c3e50"
                Layout.fillWidth: true
                background: Rectangle {
                    color: "#ecf0f1"
                    radius: 4
                    border.color: "#bdc3c7"
                    border.width: 1
                }
                padding: 8
            }

            TextField {
                id: editPhoneInput
                placeholderText: "Телефон"
                placeholderTextColor: "#95a5a6"
                color: "#2c3e50"
                Layout.fillWidth: true
                background: Rectangle {
                    color: "#ecf0f1"
                    radius: 4
                    border.color: "#bdc3c7"
                    border.width: 1
                }
                padding: 8
            }

            TextField {
                id: editCityInput
                placeholderText: "Город"
                placeholderTextColor: "#95a5a6"
                color: "#2c3e50"
                Layout.fillWidth: true
                background: Rectangle {
                    color: "#ecf0f1"
                    radius: 4
                    border.color: "#bdc3c7"
                    border.width: 1
                }
                padding: 8
            }
        }

        onAccepted: {
            if (editOwnerDialog.index >= 0) {
                parkingManager.updateOwner(editOwnerDialog.index, editNameInput.text, 
                                         editPhoneInput.text, editCityInput.text)
                showMessage("✅ Владелец обновлен!")
            }
        }

        standardButtons: Dialog.Ok | Dialog.Cancel
    }

    // === УВЕДОМЛЕНИЯ ===
    Rectangle {
        id: messageBox
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        width: 400
        height: 50
        color: "#27ae60"
        radius: 8
        visible: false
        z: 1000

        Text {
            id: messageText
            anchors.centerIn: parent
            color: "white"
            font.bold: true
            font.pixelSize: 14
        }

        Timer {
            id: messageTimer
            interval: 3000
            onTriggered: messageBox.visible = false
        }
    }

    Rectangle {
        id: errorBox
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        width: 400
        height: 50
        color: "#e74c3c"
        radius: 8
        visible: false
        z: 1000

        Text {
            id: errorText
            anchors.centerIn: parent
            color: "white"
            font.bold: true
            font.pixelSize: 14
        }

        Timer {
            id: errorTimer
            interval: 3000
            onTriggered: errorBox.visible = false
        }
    }

    // === ФУНКЦИИ ===
    function getSpotNumber(spotId) {
        for (var i = 0; i < parkingManager.parkingSpots.length; i++) {
            if (parkingManager.parkingSpots[i].id === spotId) {
                return parkingManager.parkingSpots[i].spotNumber
            }
        }
        return "N/A"
    }

    function showMessage(text) {
        messageText.text = text
        messageBox.visible = true
        messageTimer.restart()
    }

    function showError(text) {
        errorText.text = text
        errorBox.visible = true
        errorTimer.restart()
    }
    
    Component.onCompleted: {
        statusBar.updateActive()
    }
}
