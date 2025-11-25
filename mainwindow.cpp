#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <QHeaderView>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//Variables to store database queries
QString phone;
QString manufacturer;
QString releaseDate ;
QString price;
QString processorSpeed;
QString ramSize;
QString romSize;
QString batteryCapacity;
QString cameraResolution;
QString screenSize;
QString screenResolution;
QString operatingSystem;
QString displayType;
QString supportedNetworks;
QString formFactor;
QString age;

//Function to create specifications table
void setupSpecificationsTable(QTableWidget *tableWidget, const QString &headerText) {

    tableWidget->setRowCount(16);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    QTableWidgetItem *mergedHeaderItem = new QTableWidgetItem(headerText);
    mergedHeaderItem->setTextAlignment(Qt::AlignCenter);

    tableWidget->setItem(0, 0, mergedHeaderItem);
    tableWidget->setSpan(0, 0, 1, 2);

    tableWidget->setItem(1, 0, new QTableWidgetItem(QString("Manufacturer's name")));
    tableWidget->setItem(2, 0, new QTableWidgetItem(QString("Date of Release")));
    tableWidget->setItem(3, 0, new QTableWidgetItem(QString("Price at Release(NGN)")));
    tableWidget->setItem(4, 0, new QTableWidgetItem(QString("Processor Speed(GHz)")));
    tableWidget->setItem(5, 0, new QTableWidgetItem(QString("Ram size (GB)")));
    tableWidget->setItem(6, 0, new QTableWidgetItem(QString("Storage(ROM)")));
    tableWidget->setItem(7, 0, new QTableWidgetItem(QString("Battery Capacity(mAh)")));
    tableWidget->setItem(8, 0, new QTableWidgetItem(QString("Camera Resolution(MP)")));
    tableWidget->setItem(9, 0, new QTableWidgetItem(QString("Screen Size(Inches)")));
    tableWidget->setItem(10, 0, new QTableWidgetItem(QString("Screen Resolution")));
    tableWidget->setItem(11, 0, new QTableWidgetItem(QString("Operating System(OS) Version")));
    tableWidget->setItem(12, 0, new QTableWidgetItem(QString("Display Type")));
    tableWidget->setItem(13, 0, new QTableWidgetItem(QString("Supported Network Type")));
    tableWidget->setItem(14, 0, new QTableWidgetItem(QString("Form Factor")));
    tableWidget->setItem(15, 0, new QTableWidgetItem(QString("AGE")));
}


//Function to enter specificaion data
void setupSpecificationsTableData(QTableWidget *tableWidget, int b) {

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("sql8.freesqldatabase.com");
    database.setUserName("sql8809447");
    database.setPassword("jxU8gNvcT6");
   database.setDatabaseName("sql8809447");

    if (database.open()) {
        qDebug() << "GOOD";
    }
    else {
        qDebug() << "BAD";
    }

    database.open();
    QSqlQuery Query_Get_data(database);
    Query_Get_data.prepare("SELECT * FROM `Phone Specifications` WHERE id= :id");
    Query_Get_data.bindValue(":id", b);

    if (Query_Get_data.exec()) {
        if (Query_Get_data.next()) {
            phone = Query_Get_data.value("Phone_Version").toString();
            manufacturer = Query_Get_data.value("Manufacturer's_Name").toString();
            releaseDate = Query_Get_data.value("Date_of_Release").toString();
            price = Query_Get_data.value("Price_at_Release").toString();
            processorSpeed = Query_Get_data.value("Processor_Speed").toString();
            ramSize = Query_Get_data.value("RAM_Size").toString();
            romSize = Query_Get_data.value("ROM_Size").toString();
            batteryCapacity = Query_Get_data.value("Battery_Capacity").toString();
            cameraResolution = Query_Get_data.value("Camera_Resolution").toString();
            screenSize = Query_Get_data.value("Screen_Size").toString();
            screenResolution = Query_Get_data.value("Screen_Resolution").toString();
            operatingSystem = Query_Get_data.value("Operating_System").toString();
            displayType = Query_Get_data.value("Display_Type").toString();
            supportedNetworks = Query_Get_data.value("Supported_Network_Type").toString();
            formFactor = Query_Get_data.value("Form_Factor").toString();
            age = Query_Get_data.value("Age").toString();
        }
    }

    tableWidget->setItem(0, 1, new QTableWidgetItem(QString(phone)));
    tableWidget->setItem(1, 1, new QTableWidgetItem(QString(manufacturer)));
    tableWidget->setItem(2, 1, new QTableWidgetItem(QString(releaseDate)));
    tableWidget->setItem(3, 1, new QTableWidgetItem(QString(price)));
    tableWidget->setItem(4, 1, new QTableWidgetItem(QString(processorSpeed)));
    tableWidget->setItem(5, 1, new QTableWidgetItem(QString(ramSize)));
    tableWidget->setItem(6, 1, new QTableWidgetItem(QString(romSize)));
    tableWidget->setItem(7, 1, new QTableWidgetItem(QString(batteryCapacity)));
    tableWidget->setItem(8, 1, new QTableWidgetItem(QString(cameraResolution)));
    tableWidget->setItem(9, 1, new QTableWidgetItem(QString(screenSize)));
    tableWidget->setItem(10, 1, new QTableWidgetItem(QString(screenResolution)));
    tableWidget->setItem(11, 1, new QTableWidgetItem(QString(operatingSystem)));
    tableWidget->setItem(12, 1, new QTableWidgetItem(QString(displayType)));
    tableWidget->setItem(13, 1, new QTableWidgetItem(QString(supportedNetworks)));
    tableWidget->setItem(14, 1, new QTableWidgetItem(QString(formFactor)));
    tableWidget->setItem(15, 1, new QTableWidgetItem(QString(age)));
    database.close();
}


//Function to create comparsion table
void setupComparisonTable(QTableWidget *tableWidget, int a) {

    tableWidget->setRowCount(16);
    tableWidget->setColumnCount(a);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);

    tableWidget->setItem(0, 0, new QTableWidgetItem(QString("SPECS/PHONES")));
    tableWidget->setItem(1, 0, new QTableWidgetItem(QString("Manufacturer's name")));
    tableWidget->setItem(2, 0, new QTableWidgetItem(QString("Date of Release")));
    tableWidget->setItem(3, 0, new QTableWidgetItem(QString("Price at Release(NGN)")));
    tableWidget->setItem(4, 0, new QTableWidgetItem(QString("Processor Speed(GHz)")));
    tableWidget->setItem(5, 0, new QTableWidgetItem(QString("Ram size (GB)")));
    tableWidget->setItem(6, 0, new QTableWidgetItem(QString("Storage(ROM)")));
    tableWidget->setItem(7, 0, new QTableWidgetItem(QString("Battery Capacity(mAh)")));
    tableWidget->setItem(8, 0, new QTableWidgetItem(QString("Camera Resolution(MP)")));
    tableWidget->setItem(9, 0, new QTableWidgetItem(QString("Screen Size(Inches)")));
    tableWidget->setItem(10, 0, new QTableWidgetItem(QString("Screen Resolution")));
    tableWidget->setItem(11, 0, new QTableWidgetItem(QString("Operating System")));
    tableWidget->setItem(12, 0, new QTableWidgetItem(QString("Display Type")));
    tableWidget->setItem(13, 0, new QTableWidgetItem(QString("Supported Network Type")));
    tableWidget->setItem(14, 0, new QTableWidgetItem(QString("Form Factor")));
    tableWidget->setItem(15, 0, new QTableWidgetItem(QString("AGE")));

    tableWidget->setWordWrap(true);
    tableWidget->resizeRowsToContents();
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


//Function to enter comparison data
void setupComparisonTableData(const QString& search, int a, QTableWidget *tableWidget) {

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("sql8.freesqldatabase.com");
    database.setUserName("sql8809447");
    database.setPassword("jxU8gNvcT6");
   database.setDatabaseName("sql8809447");

    if (database.open()) {
        qDebug() << "GOOD";
    }
    else {
        qDebug() << "BAD";
    }

    database.open();
    QSqlQuery query(database);
    query.prepare(
        "SELECT id "
        "FROM `Phone Specifications` "
        "WHERE "
        "`Phone_Version` = :search"
        );

    query.bindValue(":search", search);

    if (query.exec() && query.next()) {
        int b = query.value("id").toInt();

        QSqlQuery Query_Get_data(database);
        Query_Get_data.prepare("SELECT * FROM `Phone Specifications` WHERE id= :id");
        Query_Get_data.bindValue(":id", b);

        if (Query_Get_data.exec()) {
            if (Query_Get_data.next()) {
                phone = Query_Get_data.value("Phone_Version").toString();
                manufacturer = Query_Get_data.value("Manufacturer's_Name").toString();
                releaseDate = Query_Get_data.value("Date_of_Release").toString();
                price = Query_Get_data.value("Price_at_Release").toString();
                processorSpeed = Query_Get_data.value("Processor_Speed").toString();
                ramSize = Query_Get_data.value("RAM_Size").toString();
                romSize = Query_Get_data.value("ROM_Size").toString();
                batteryCapacity = Query_Get_data.value("Battery_Capacity").toString();
                cameraResolution = Query_Get_data.value("Camera_Resolution").toString();
                screenSize = Query_Get_data.value("Screen_Size").toString();
                screenResolution = Query_Get_data.value("Screen_Resolution").toString();
                operatingSystem = Query_Get_data.value("Operating_System").toString();
                displayType = Query_Get_data.value("Supported_Network_Type").toString();
                supportedNetworks = Query_Get_data.value("Phone_Version").toString();
                formFactor = Query_Get_data.value("Form_Factor").toString();
                age = Query_Get_data.value("Age").toString();

                tableWidget->setItem(0, a, new QTableWidgetItem(QString(phone)));
                tableWidget->setItem(1, a, new QTableWidgetItem(QString(manufacturer)));
                tableWidget->setItem(2, a, new QTableWidgetItem(QString(releaseDate)));
                tableWidget->setItem(3, a, new QTableWidgetItem(QString(price)));
                tableWidget->setItem(4, a, new QTableWidgetItem(QString(processorSpeed)));
                tableWidget->setItem(5, a, new QTableWidgetItem(QString(ramSize)));
                tableWidget->setItem(6, a, new QTableWidgetItem(QString(romSize)));
                tableWidget->setItem(7, a, new QTableWidgetItem(QString(batteryCapacity)));
                tableWidget->setItem(8, a, new QTableWidgetItem(QString(cameraResolution)));
                tableWidget->setItem(9, a, new QTableWidgetItem(QString(screenSize)));
                tableWidget->setItem(10, a, new QTableWidgetItem(QString(screenResolution)));
                tableWidget->setItem(11, a, new QTableWidgetItem(QString(operatingSystem)));
                tableWidget->setItem(12, a, new QTableWidgetItem(QString(displayType)));
                tableWidget->setItem(13, a, new QTableWidgetItem(QString(supportedNetworks)));
                tableWidget->setItem(14, a, new QTableWidgetItem(QString(formFactor)));
                tableWidget->setItem(15, a, new QTableWidgetItem(QString(age)));

            }
        }
    }
    database.close();
}

std::vector<int> searchFound;

void searchDatabase(const QString& search, int a, QListWidget *listViewWidget) {
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("sql8.freesqldatabase.com");
    database.setUserName("sql8809447");
    database.setPassword("jxU8gNvcT6");
   database.setDatabaseName("sql8809447");

    database.open();
    searchFound.clear();
    QSqlQuery query(database);
    if (a == 1) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE "
            "`Manufacturer's_Name` = :search"
        );
    }
    else if (a == 2) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE "
            "LOWER(`Date_of_Release`) LIKE LOWER(CONCAT('%', :search, '%'))"
        );
    }
    else if (a == 3) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE "
            "LOWER(`Display_Type`) LIKE LOWER(CONCAT('%', :search, '%'))"
            );
    }
    else if (a == 4) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE "
            "LOWER(`Supported_Network_Type`) = :search"
            );
    }
    else if (a == 5) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE "
            "LOWER(`Form_Factor`) = :search"
            );
    }
    else if (a == 6) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE "
            "LOWER(`Operating_System`) LIKE LOWER(CONCAT('%', :search, '%'))"
            );
        qDebug() << search;
    }

    query.bindValue(":search", search);

    if (query.exec()) {
        while (query.next()) {
            searchFound.push_back(query.value("id").toInt());
        }
        for (int j=0; j<searchFound.size(); ++j) {
            QSqlQuery detailQuery(database);
            detailQuery.prepare("SELECT * FROM `Phone Specifications` WHERE id= :id");
            detailQuery.bindValue(":id", searchFound[j]);

            if (detailQuery.exec()) {
                if (detailQuery.next()) {
                    QString listItem = detailQuery.value("Phone_Version").toString();
                    listViewWidget->addItem(listItem);
                    qDebug() << listItem;
                }
            }
        }
    }
    if (searchFound.empty()) {
        qDebug() << "Not Found";
    }
    else {
        qDebug() << "Found";
        qDebug() << searchFound.size();
    }

    database.close();
}

void searchDatabase_range(float b, float c, int a, QListWidget *listViewWidget) {
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("sql8.freesqldatabase.com");
    database.setUserName("sql8809447");
    database.setPassword("jxU8gNvcT6");
   database.setDatabaseName("sql8809447");

    database.open();
    searchFound.clear();
    QSqlQuery query(database);
    if (a == 3) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Processor_Speed` BETWEEN :b AND :c"
            );
    }
    else if (a==4) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `RAM_Size` BETWEEN :b AND :c"
            );
    }
    else if (a==5) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `ROM_Size` BETWEEN :b AND :c"
            );
    }
    else if (a==6) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Battery_Capacity` >= :b"
            );
    }
    else if (a==7) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Battery_Capacity` BETWEEN :b AND :c"
            );
    }
    else if (a==8) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Camera_Resolution` >= :b"
            );
    }
    else if (a==9) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Camera_Resolution` BETWEEN :b AND :c"
            );
    }
    else if (a==10) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Screen_Size` < :b"
            );
    }
    else if (a==11) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Screen_Size` BETWEEN :b AND :c"
            );
    }
    else if (a==12) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Price_at_Release` BETWEEN :b AND :c"
            );
    }
    else if (a==13) {
        query.prepare(
            "SELECT id "
            "FROM `Phone Specifications` "
            "WHERE `Age` = :b"
            );
    }

    query.bindValue(":b", b);
    query.bindValue(":c", c);

    if (query.exec()) {
        while (query.next()) {
            searchFound.push_back(query.value("id").toInt());
        }
        for (int j=0; j<searchFound.size(); ++j) {
            QSqlQuery detailQuery(database);
            detailQuery.prepare("SELECT * FROM `Phone Specifications` WHERE id= :id");
            detailQuery.bindValue(":id", searchFound[j]);

            if (detailQuery.exec()) {
                if (detailQuery.next()) {
                    QString listItem = detailQuery.value("Phone_Version").toString();
                    listViewWidget->addItem(listItem);
                    qDebug() << listItem;
                }
            }
        }
    }
    if (searchFound.empty()) {
        qDebug() << "Not Found";
    }
    else {
        qDebug() << "Found";
        qDebug() << searchFound.size();
    }

    database.close();
}

void compareDatabase(const QString& search, QListWidget *listViewWidget) {
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("sql8.freesqldatabase.com");
    database.setUserName("sql8809447");
    database.setPassword("jxU8gNvcT6");
   database.setDatabaseName("sql8809447");

    database.open();
    searchFound.clear();
    QSqlQuery query(database);
    query.prepare(
        "SELECT id "
        "FROM `Phone Specifications` "
        "WHERE "
        "`Manufacturer's_Name` = :search"
    );

    query.bindValue(":search", search);

    if (query.exec()) {
        while (query.next()) {
            searchFound.push_back(query.value("id").toInt());
        }
        for (int j=0; j<searchFound.size(); ++j) {
            QSqlQuery detailQuery(database);
            detailQuery.prepare("SELECT * FROM `Phone Specifications` WHERE id= :id");
            detailQuery.bindValue(":id", searchFound[j]);

            if (detailQuery.exec()) {
                if (detailQuery.next()) {
                    QString listItem = detailQuery.value("Phone_Version").toString();
                    listViewWidget->addItem(listItem);
                    qDebug() << listItem;
                }
            }
        }
    }
    if (searchFound.empty()) {
        qDebug() << "Not Found";
    }
    else {
        qDebug() << "Found";
        qDebug() << searchFound.size();
    }

    database.close();
}


MainWindow::~MainWindow()
{
    delete ui;
}


int columnCount=1;
std::vector<int> checkedPhones;
void MainWindow::on_MainMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    columnCount=1;
    ui->comparsionTable->clearContents();
    ui->comparsionTable->setRowCount(0);
    ui->comparsionTable->setColumnCount(0);
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
}


//Specifications Comaprison Menu
void MainWindow::on_SpecComparison_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
    columnCount=1;
    ui->comparsionTable->clearContents();
    ui->comparsionTable->setRowCount(0);
    ui->comparsionTable->setColumnCount(0);
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
}


void MainWindow::on_SearchMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
}


void MainWindow::on_SearchButton_clicked()
{
    // Set the font size
    QFont font = ui->label_6->font();
    font.setPointSize(12);
    ui->label_6->setFont(font);

    // Center the text
    QPalette palette = ui->label_6->palette();
    palette.setColor(QPalette::WindowText, Qt::black);
    ui->label_6->setAlignment(Qt::AlignCenter);
    ui->label_6->setPalette(palette);


    if (ui->Manufacturer->isChecked()) {
        ui->label_6->setText("Phones manufactured by " + ui->manufacturerCombo->currentText());
        if (ui->manufacturerCombo->currentIndex()==1) {
            searchDatabase("Apple", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==2) {
            searchDatabase("Huawei", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==3) {
            searchDatabase("Tecno", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==4) {
            searchDatabase("Redmi", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==5) {
            searchDatabase("HTC", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==6) {
            searchDatabase("Oppo", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==7) {
            searchDatabase("Infinix", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==8) {
            searchDatabase("Nokia", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==9) {
            searchDatabase("LG", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==10) {
            searchDatabase("Samsung", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==11) {
            searchDatabase("Microsoft", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==12) {
            searchDatabase("ZTE", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==13) {
            searchDatabase("Sony", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==14) {
            searchDatabase("Xiaomi", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==15) {
            searchDatabase("Vivo", 1, ui->listWidget);
        }
        else if (ui->manufacturerCombo->currentIndex()==16) {
            searchDatabase("Motorola", 1, ui->listWidget);
        }

        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->releaseDate->isChecked()) {
        bool ok1, ok2;
        ui->label_6->setText("Phones manufactured between the years " + ui->releaseEdit2->toPlainText() + " and " + ui->releaseEdit2->toPlainText());
        QString year1str = ui->releaseEdit1->toPlainText();
        QString year2str = ui->releaseEdit2->toPlainText();
        int year1 = year1str.toInt(&ok1);
        int year2 = year2str.toInt(&ok2);
        if (ok1 && ok2) {
            for (; year1 <= year2; ++year1) {
                QString year = QString::number(year1);
                searchDatabase(year, 2, ui->listWidget);
                ui->stackedWidget->setCurrentIndex(21);
                ui->releaseEdit1->setText("");
                ui->releaseEdit2->setText("");
            }
        }
        else {
            QMessageBox::warning(this, "Input Error", "Please enter valid years.");
            ui->releaseEdit1->setText("");
            ui->releaseEdit2->setText("");
        }
    }
    else if (ui->processorSpeed->isChecked()) {
        bool ok1, ok2;
        ui->label_6->setText("Phones with processor speed between " + ui->processorEdit1->toPlainText() + "GHz and " + ui->processorEdit2->toPlainText() + "GHz");
        QString processorSpeed1str = ui->processorEdit1->toPlainText();
        QString processorSpeed2str = ui->processorEdit2->toPlainText();
        float processorSpeed1 = processorSpeed1str.toFloat(&ok1);
        float processorSpeed2 = processorSpeed2str.toFloat(&ok2);
        if (ok1 && ok2) {
            searchDatabase_range(processorSpeed1, processorSpeed2, 3, ui->listWidget);
            ui->stackedWidget->setCurrentIndex(21);
            ui->processorEdit1->setText("");
            ui->processorEdit2->setText("");
        }
        else {
            QMessageBox::warning(this, "Input Error", "Please enter valid numbers for processor speed.");
            ui->processorEdit1->setText("");
            ui->processorEdit2->setText("");
        }
    }
    else if (ui->RAMsize->isChecked()){
        bool ok1, ok2;
        ui->label_6->setText("Phones with RAM between " + ui->ramEdit1->toPlainText() + "GB and " + ui->ramEdit2->toPlainText() + "GB");
        QString ram1str = ui->ramEdit1->toPlainText();
        QString ram2str = ui->ramEdit2->toPlainText();
        int ram1 = ram1str.toInt(&ok1);
        int ram2 = ram2str.toInt(&ok2);
        if (ok1 && ok2) {
            searchDatabase_range(ram1, ram2, 4, ui->listWidget);
            ui->stackedWidget->setCurrentIndex(21);
            ui->ramEdit1->setText("");
            ui->ramEdit2->setText("");
        }
        else {
            QMessageBox::warning(this, "Input Error", "Please enter valid numbers for RAM size.");
            ui->ramEdit1->setText("");
            ui->ramEdit2->setText("");
        }
    }
    else if (ui->ROMsize->isChecked()){
        bool ok1, ok2;
        ui->label_6->setText("Phones with ROM between " + ui->romEdit1->toPlainText() + "GB and " + ui->romEdit2->toPlainText() + "GB");
        QString rom1str = ui->romEdit1->toPlainText();
        QString rom2str = ui->romEdit2->toPlainText();
        int rom1 = rom1str.toInt(&ok1);
        int rom2 = rom2str.toInt(&ok2);
        if (ok1 && ok2) {
            searchDatabase_range(rom1, rom2, 5, ui->listWidget);
            ui->stackedWidget->setCurrentIndex(21);
            ui->romEdit1->setText("");
            ui->romEdit2->setText("");
        }
        else {
            QMessageBox::warning(this, "Input Error", "Please enter valid numbers for ROM size.");
            ui->romEdit1->setText("");
            ui->romEdit2->setText("");
        }
    }
    else if (ui->batteryCapacity->isChecked()){
        ui->label_6->setText("Phones with " + ui->batteryCombo->currentText() + " Battery Capacity");
        if (ui->batteryCombo->currentIndex()== 0){
            searchDatabase_range(3000, 0, 6, ui->listWidget);
        }
        else if (ui->batteryCombo->currentIndex()== 1){
            searchDatabase_range(1000, 2999, 7, ui->listWidget);
        }
        else if (ui->batteryCombo->currentIndex()== 2){
            searchDatabase_range(0, 999, 7, ui->listWidget);
        }
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->cameraResolution->isChecked()){
        ui->label_6->setText("Phones with " + ui->cameraCombo->currentText() + " Camera Resolution");
        if (ui->cameraCombo->currentIndex()== 0){
            searchDatabase_range(8, 0, 8, ui->listWidget);
        }
        else if (ui->cameraCombo->currentIndex()== 1){
            searchDatabase_range(2, 7, 9, ui->listWidget);
        }
        else if (ui->cameraCombo->currentIndex()== 2){
            searchDatabase_range(0, 2, 9, ui->listWidget);
        }
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->screenSize->isChecked()){
        ui->label_6->setText("Phones with " + ui->screenSCombo->currentText() + " Screen Size");
        if (ui->screenSCombo->currentIndex()== 0){
            searchDatabase_range(5.4, 0, 10, ui->listWidget);
        }
        else if (ui->screenSCombo->currentIndex()== 1){
            searchDatabase_range(5.5, 6.5, 11, ui->listWidget);
        }
        else if (ui->screenSCombo->currentIndex()== 2){
            searchDatabase_range(0, 999, 11, ui->listWidget);
        }
        else if (ui->screenSCombo->currentIndex()== 3){
            searchDatabase_range(0, 999, 10, ui->listWidget);
        }
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->displayType->isChecked()){
        ui->label_6->setText("Phones with " + ui->displayCombo->currentText() + " Screen");
        searchDatabase(ui->displayCombo->currentText(), 3, ui->listWidget);
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->supportedNetworks->isChecked()){
        ui->label_6->setText("Phones that support " + ui->networksCombo->currentText());
        searchDatabase(ui->networksCombo->currentText(), 4, ui->listWidget);
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->formFactor->isChecked()){
        ui->label_6->setText(ui->formCombo->currentText() + " Phones");
        searchDatabase(ui->formCombo->currentText(), 5, ui->listWidget);
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->OSversion->isChecked()){
        ui->label_6->setText(ui->OSCombo->currentText() + " Phones");
        searchDatabase(ui->OSCombo->currentText(), 6, ui->listWidget);
        ui->stackedWidget->setCurrentIndex(21);
    }
    else if (ui->releasePrice->isChecked()){
        bool ok1, ok2;
        ui->label_6->setText("Phones with price between " + ui->priceEdit1->toPlainText() + "NGN and " + ui->priceEdit2->toPlainText() + "NGN");
        QString price1str = ui->priceEdit1->toPlainText();
        QString price2str = ui->priceEdit2->toPlainText();
        int price1 = price1str.toInt(&ok1);
        int price2 = price2str.toInt(&ok2);
        if (ok1 && ok2) {
            searchDatabase_range(price1, price2, 12, ui->listWidget);
            ui->stackedWidget->setCurrentIndex(21);
            ui->priceEdit1->setText("");
            ui->priceEdit2->setText("");
        }
        else {
            QMessageBox::warning(this, "Input Error", "Please enter valid prices.");
            ui->priceEdit1->setText("");
            ui->priceEdit2->setText("");
        }
    }
    else if (ui->age->isChecked()){
        bool ok;
        ui->label_6->setText("Phones " + ui->ageEdit->toPlainText() + " year(s) old");
        QString agestr = ui->ageEdit->toPlainText();
        int age = agestr.toInt(&ok);
        if (ok) {
            searchDatabase_range(age, 0, 13, ui->listWidget);
            ui->stackedWidget->setCurrentIndex(21);
            ui->ageEdit->setText("");
        }
        else {
            QMessageBox::warning(this, "Input Error", "Please enter valid age.");
            ui->ageEdit->setText("");
        }
    }
    else {
        QMessageBox::information(this, "ERROR", "Please check a specificationto perform search");
        ui->ageEdit->setText("");
        ui->priceEdit1->setText("");
        ui->priceEdit2->setText("");
    }
}


//Infinix menu
void MainWindow::on_Infinix_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_Hot60_clicked()
{
    int i =1;
    setupSpecificationsTable(ui->specWidget, "INFINIX HOT 60 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Hot60Pro_clicked()
{
    int i =2;
    setupSpecificationsTable(ui->specWidget, "INFINIX HOT 60 Pro SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Hot60ProPlus_clicked()
{
    int i =3;
    setupSpecificationsTable(ui->specWidget, "INFINIX HOT 60 Pro+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Hot60i_clicked()
{
    int i =7;
    setupSpecificationsTable(ui->specWidget, "INFINIX Hot 60i SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Note50ProPlus_clicked()
{
    int i =4;
    setupSpecificationsTable(ui->specWidget, "INFINIX NOTE 50 Pro+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_GT30Pro_clicked()
{
    int i =5;
    setupSpecificationsTable(ui->specWidget, "INFINIX GT 30 Pro SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Note50_clicked()
{
    int i =6;
    setupSpecificationsTable(ui->specWidget, "INFINIX Note 50 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Smart9_clicked()
{
    int i =8;
    setupSpecificationsTable(ui->specWidget, "INFINIX Smart 9 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_ZeroFlip_clicked()
{
    int i =9;
    setupSpecificationsTable(ui->specWidget, "INFINIX Zero Flip SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Hot50Pro_clicked()
{
    int i =10;
    setupSpecificationsTable(ui->specWidget, "INFINIX Hot 50 Pro SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}



//OPPO menu
void MainWindow::on_Oppo_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_K13TurboPro_clicked()
{
    int i =11;
    setupSpecificationsTable(ui->specWidget, "OPPO K13 TURBO PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_K13Turbo_clicked()
{
    int i =12;
    setupSpecificationsTable(ui->specWidget, "OPPO K13 TURBO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Reno14Pro_clicked()
{
    int i =13;
    setupSpecificationsTable(ui->specWidget, "OPPO RENO 14 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Reno14_clicked()
{
    int i =14;
    setupSpecificationsTable(ui->specWidget, "OPPO RENO 14 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_FindX8Ultra_clicked()
{
    int i =15;
    setupSpecificationsTable(ui->specWidget, "OPPO FIND X8 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_FinX8splus_clicked()
{
    int i =16;
    setupSpecificationsTable(ui->specWidget, "OPPO FIND X8+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_FindX8s_clicked()
{
    int i =17;
    setupSpecificationsTable(ui->specWidget, "OPPO FIND X8S SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_FindN5_clicked()
{
    int i =18;
    setupSpecificationsTable(ui->specWidget, "OPPO FIND N5 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Reno13Pro_clicked()
{
    int i =19;
    setupSpecificationsTable(ui->specWidget, "OPPO RENO 13 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Reno13_clicked()
{
    int i =20;
    setupSpecificationsTable(ui->specWidget, "OPPO RENO 13 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//REDMI MENU
void MainWindow::on_Redmi_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_K80Ultra_clicked()
{
    int i =21;
    setupSpecificationsTable(ui->specWidget, "REDMI K80 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Note14ProPlus_clicked()
{
    int i =22;
    setupSpecificationsTable(ui->specWidget, "REDMI NOTE 14 PRO+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_A5_clicked()
{
    int i =23;
    setupSpecificationsTable(ui->specWidget, "REDMI A5 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Turbo4_clicked()
{
    int i =24;
    setupSpecificationsTable(ui->specWidget, "REDMI TURBO 4 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Note14Pro_clicked()
{
    int i =25;
    setupSpecificationsTable(ui->specWidget, "REDMI NOTE 14 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Note14_clicked()
{
    int i =26;
    setupSpecificationsTable(ui->specWidget, "REDMI NOTE 14 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_A3X_clicked()
{
    int i =27;
    setupSpecificationsTable(ui->specWidget, "REDMI A3X SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_A3_clicked()
{
    int i =28;
    setupSpecificationsTable(ui->specWidget, "REDMI A3 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Redmi14C_clicked()
{
    int i =29;
    setupSpecificationsTable(ui->specWidget, "REDMI 14C SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Redmi12_clicked()
{
    int i =30;
    setupSpecificationsTable(ui->specWidget, "REDMI 12 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Apple Menu
void MainWindow::on_Apple_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_proMax16_clicked()
{
    int i =31;
    setupSpecificationsTable(ui->specWidget, "iPHONE 16 PRO MAX SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Pro16_clicked()
{
    int i =32;
    setupSpecificationsTable(ui->specWidget, "iPHONE 16 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Plus16_clicked()
{
    int i =33;
    setupSpecificationsTable(ui->specWidget, "iPHONE 16 PLUS SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_sixteen_clicked()
{
    int i =34;
    setupSpecificationsTable(ui->specWidget, "iPHONE 16 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_e16_clicked()
{
    int i =35;
    setupSpecificationsTable(ui->specWidget, "iPHONE 16e SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_PRoMax15_clicked()
{
    int i =36;
    setupSpecificationsTable(ui->specWidget, "iPHONE 15 PRO MAX SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Pro15_clicked()
{
    int i =37;
    setupSpecificationsTable(ui->specWidget, "iPHONE 15 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Plus15_clicked()
{
    int i =38;
    setupSpecificationsTable(ui->specWidget, "iPHONE 15 PLUS SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_fifthteen_clicked()
{
    int i =39;
    setupSpecificationsTable(ui->specWidget, "iPHONE 15 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_ProMax14_clicked()
{
    int i =40;
    setupSpecificationsTable(ui->specWidget, "iPHONE 14 PRO MAX SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//HTC Menu
void MainWindow::on_HTC_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_U23Pro_clicked()
{
    int i =41;
    setupSpecificationsTable(ui->specWidget, "U23 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Desire22Pro_clicked()
{
    int i =42;
    setupSpecificationsTable(ui->specWidget, "DESIRE 22 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_U20_clicked()
{
    int i =43;
    setupSpecificationsTable(ui->specWidget, "U20 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Desire21Pro_clicked()
{
    int i =44;
    setupSpecificationsTable(ui->specWidget, "DESIRE 21 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_WildfireE3_clicked()
{
    int i =45;
    setupSpecificationsTable(ui->specWidget, "WILDFIRE E3 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_WildfireR70_clicked()
{
    int i =46;
    setupSpecificationsTable(ui->specWidget, "WILDFIRE R70 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_U12plus_clicked()
{
    int i =47;
    setupSpecificationsTable(ui->specWidget, "U12+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Exodus1_clicked()
{
    int i =48;
    setupSpecificationsTable(ui->specWidget, "EXODUS 1 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Desire20plus_clicked()
{
    int i =49;
    setupSpecificationsTable(ui->specWidget, "DESIRE 20+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_OneM9_clicked()
{
    int i =50;
    setupSpecificationsTable(ui->specWidget, "ONE M9 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Nokia Menu
void MainWindow::on_Nokia_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_G42_clicked()
{
    int i =51;
    setupSpecificationsTable(ui->specWidget, "NOKIA G42 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_XR21_clicked()
{
    int i =52;
    setupSpecificationsTable(ui->specWidget, "NOKIA XR 21 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_XR20_clicked()
{
    int i =53;
    setupSpecificationsTable(ui->specWidget, "NOKIA XR20 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_C32_clicked()
{
    int i =54;
    setupSpecificationsTable(ui->specWidget, "NOKIA C32 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_G60_clicked()
{
    int i =55;
    setupSpecificationsTable(ui->specWidget, "NOKIA G60 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_G42_2_clicked()
{
    int i =56;
    setupSpecificationsTable(ui->specWidget, " SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_G400_clicked()
{
    int i =57;
    setupSpecificationsTable(ui->specWidget, "NOKIA G400 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_G310_clicked()
{
    int i =58;
    setupSpecificationsTable(ui->specWidget, "NOKIA G310 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Nokia220_clicked()
{
    int i =59;
    setupSpecificationsTable(ui->specWidget, "NOKIA 220 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Nokia235_clicked()
{
    int i =60;
    setupSpecificationsTable(ui->specWidget, "NOKIA 235 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//LG Menu
void MainWindow::on_LG_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}


void MainWindow::on_Wing_clicked()
{
    int i =121;
    setupSpecificationsTable(ui->specWidget, "WING SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Velvet_clicked()
{
    int i =122;
    setupSpecificationsTable(ui->specWidget, "VELVET SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_G8ThinQ_clicked()
{
    int i =123;
    setupSpecificationsTable(ui->specWidget, "G8 THINQ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_V60ThinQ_clicked()
{
    int i =124;
    setupSpecificationsTable(ui->specWidget, "V60 THINQ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_K92_clicked()
{
    int i =125;
    setupSpecificationsTable(ui->specWidget, "K92 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Stylo6_clicked()
{
    int i =126;
    setupSpecificationsTable(ui->specWidget, "STYLO 6 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_G7ThinQ_clicked()
{
    int i =127;
    setupSpecificationsTable(ui->specWidget, "G7 THINQ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_V50ThinQ_clicked()
{
    int i =128;
    setupSpecificationsTable(ui->specWidget, "V50 THINQ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Q70_clicked()
{
    int i =129;
    setupSpecificationsTable(ui->specWidget, "Q70 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_V40ThinQ_clicked()
{
    int i =130;
    setupSpecificationsTable(ui->specWidget, "V40 THINQ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Samsung Menu
void MainWindow::on_Samsung_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}


void MainWindow::on_Ultra24_clicked()
{
    int i =61;
    setupSpecificationsTable(ui->specWidget, "GALAXY 24 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Plus24_clicked()
{
    int i =62;
    setupSpecificationsTable(ui->specWidget, "GALAXY 24+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S24_clicked()
{
    int i =63;
    setupSpecificationsTable(ui->specWidget, "GALAXY 24 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Fold5_clicked()
{
    int i =64;
    setupSpecificationsTable(ui->specWidget, "GALAXY FOLD 5 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Flip5_clicked()
{
    int i =65;
    setupSpecificationsTable(ui->specWidget, "GALAXY FLIP 5 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Ultra23_clicked()
{
    int i =66;
    setupSpecificationsTable(ui->specWidget, "GALAXY 23 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Plus23_clicked()
{
    int i =67;
    setupSpecificationsTable(ui->specWidget, "GALAXY 23+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_A74_clicked()
{
    int i =68;
    setupSpecificationsTable(ui->specWidget, "GALAXY A74 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_A54_clicked()
{
    int i =69;
    setupSpecificationsTable(ui->specWidget, "GALAXY A54 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_A34_clicked()
{
    int i =70;
    setupSpecificationsTable(ui->specWidget, "GALAXY A34 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Sony Menu
void MainWindow::on_Sony_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void MainWindow::on_VI1_clicked()
{
    int i =81;
    setupSpecificationsTable(ui->specWidget, "XPERIA 1 VI SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_V5_clicked()
{
    int i =82;
    setupSpecificationsTable(ui->specWidget, "XPERIA 5V SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_V10_clicked()
{
    int i =83;
    setupSpecificationsTable(ui->specWidget, "XPERIA 10 V SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_ProI_clicked()
{
    int i =84;
    setupSpecificationsTable(ui->specWidget, "XPERIA PRO-I SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_IV1_clicked()
{
    int i =85;
    setupSpecificationsTable(ui->specWidget, "XPERIA 1 IV SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_IV5_clicked()
{
    int i =86;
    setupSpecificationsTable(ui->specWidget, "XPERIA 5 IV SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_IV10_clicked()
{
    int i =87;
    setupSpecificationsTable(ui->specWidget, "XPERIA 10 IV SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Pro_clicked()
{
    int i =88;
    setupSpecificationsTable(ui->specWidget, "XPERIA PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_III1_clicked()
{
    int i =89;
    setupSpecificationsTable(ui->specWidget, "XPERIA 1 III SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_III5_clicked()
{
    int i =90;
    setupSpecificationsTable(ui->specWidget, "XPERIA 5 III SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Xiaomi Menu
void MainWindow::on_Xiaomi_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_C13_clicked()
{
    int i =111;
    setupSpecificationsTable(ui->specWidget, "REDMI 13C SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Note13_clicked()
{
    int i =112;
    setupSpecificationsTable(ui->specWidget, "REDMI NOTE 13 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Pro13_clicked()
{
    int i =113;
    setupSpecificationsTable(ui->specWidget, "13 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_X5Pro_clicked()
{
    int i =114;
    setupSpecificationsTable(ui->specWidget, "POCO X5 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Lite12_clicked()
{
    int i =115;
    setupSpecificationsTable(ui->specWidget, "12 LITE SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Mi11Ultra_clicked()
{
    int i =116;
    setupSpecificationsTable(ui->specWidget, "MI 11 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_K70Pro_clicked()
{
    int i =117;
    setupSpecificationsTable(ui->specWidget, "REDMI K70 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Pad6Pro_clicked()
{
    int i =118;
    setupSpecificationsTable(ui->specWidget, "PAD 6 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Civi4Pro_clicked()
{
    int i =119;
    setupSpecificationsTable(ui->specWidget, "CIVI 4 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_MixFold3_clicked()
{
    int i =120;
    setupSpecificationsTable(ui->specWidget, "MIX FOLD 3 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Vivo Menu
void MainWindow::on_Vivo_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_X60_clicked()
{
    int i =91;
    setupSpecificationsTable(ui->specWidget, "X60 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_X60Pro_clicked()
{
    int i =92;
    setupSpecificationsTable(ui->specWidget, "X60 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_X50_clicked()
{
    int i =93;
    setupSpecificationsTable(ui->specWidget, "X50 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_X50Pro_clicked()
{
    int i =94;
    setupSpecificationsTable(ui->specWidget, "X50 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Y20_clicked()
{
    int i =95;
    setupSpecificationsTable(ui->specWidget, "Y20 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Y51_clicked()
{
    int i =96;
    setupSpecificationsTable(ui->specWidget, "Y51 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S1_clicked()
{
    int i =97;
    setupSpecificationsTable(ui->specWidget, "S1 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_V15_clicked()
{
    int i =98;
    setupSpecificationsTable(ui->specWidget, "V15 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_V17_clicked()
{
    int i =99;
    setupSpecificationsTable(ui->specWidget, "V17 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_iQOO_clicked()
{
    int i =100;
    setupSpecificationsTable(ui->specWidget, "IQ00 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Motorola Menu
void MainWindow::on_Motorola_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_Edge40Pro_clicked()
{
    int i =71;
    setupSpecificationsTable(ui->specWidget, "EDGE 40 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge40_clicked()
{
    int i =72;
    setupSpecificationsTable(ui->specWidget, "EDGE 40 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge30Ultra_clicked()
{
    int i =73;
    setupSpecificationsTable(ui->specWidget, "EDGE 30 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge30Fusion_clicked()
{
    int i =74;
    setupSpecificationsTable(ui->specWidget, "EDGE 30 FUSION SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge30Pro_clicked()
{
    int i =75;
    setupSpecificationsTable(ui->specWidget, "EDGE 30 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge30_clicked()
{
    int i =76;
    setupSpecificationsTable(ui->specWidget, "EDGE 30 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge20Pro_clicked()
{
    int i =77;
    setupSpecificationsTable(ui->specWidget, "EDGE 20 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge20Lite_clicked()
{
    int i =78;
    setupSpecificationsTable(ui->specWidget, "EDGE 20 LITE SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Edge_clicked()
{
    int i =79;
    setupSpecificationsTable(ui->specWidget, "EDGE SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_EdgePlus_clicked()
{
    int i =80;
    setupSpecificationsTable(ui->specWidget, "EDGE+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Huawei Menu
void MainWindow::on_Huawei_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_Pura70Ultra_clicked()
{
    int i =141;
    setupSpecificationsTable(ui->specWidget, "PURA 70 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Pura70Pro_clicked()
{
    int i =142;
    setupSpecificationsTable(ui->specWidget, "PURA 70 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Pura70_clicked()
{
    int i =143;
    setupSpecificationsTable(ui->specWidget, "PURA 70 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_MateX6_clicked()
{
    int i =144;
    setupSpecificationsTable(ui->specWidget, "MATE X6 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_MateX5UltimateDesign_clicked()
{
    int i =145;
    setupSpecificationsTable(ui->specWidget, "MATE X5 ULTIMATE DESIGN SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Mate50Pro_clicked()
{
    int i =146;
    setupSpecificationsTable(ui->specWidget, " MATE 50 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Mate50_clicked()
{
    int i =147;
    setupSpecificationsTable(ui->specWidget, "MATE 50 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Nova12Pro_clicked()
{
    int i =148;
    setupSpecificationsTable(ui->specWidget, "NOVA 12 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Nova12SE_clicked()
{
    int i =149;
    setupSpecificationsTable(ui->specWidget, "NOVA 12 SE SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Nova12i_clicked()
{
    int i =150;
    setupSpecificationsTable(ui->specWidget, "NOVA 12i SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Microsoft Menu
void MainWindow::on_Microsoft_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}


void MainWindow::on_SurfaceDuo_clicked()
{
    int i =151;
    setupSpecificationsTable(ui->specWidget, "SURFACE DUO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_SurfaceDuo2_clicked()
{
    int i =152;
    setupSpecificationsTable(ui->specWidget, "SURFACE DUO 2 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Lumina950_clicked()
{
    int i =153;
    setupSpecificationsTable(ui->specWidget, "LUMINA 950 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Lumina1020_clicked()
{
    int i =154;
    setupSpecificationsTable(ui->specWidget, "LUMINA 1020 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Lumina650_clicked()
{
    int i =155;
    setupSpecificationsTable(ui->specWidget, "LUMINA 650 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_KinTwo_clicked()
{
    int i =156;
    setupSpecificationsTable(ui->specWidget, "KIN TWO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//Tecno Menu
void MainWindow::on_Tecno_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}


void MainWindow::on_S20Proplus_clicked()
{
    int i =131;
    setupSpecificationsTable(ui->specWidget, "SPARK S20 PRO+ SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S10Pro_clicked()
{
    int i =132;
    setupSpecificationsTable(ui->specWidget, "SPARK S10 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S9Pro_clicked()
{
    int i =133;
    setupSpecificationsTable(ui->specWidget, "SPARK S9 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S8Pro_clicked()
{
    int i =134;
    setupSpecificationsTable(ui->specWidget, "SPARK S8 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S7Pro_clicked()
{
    int i =135;
    setupSpecificationsTable(ui->specWidget, "SPARK S7 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S6_clicked()
{
    int i =136;
    setupSpecificationsTable(ui->specWidget, "SPARK S6 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S5Pro_clicked()
{
    int i =137;
    setupSpecificationsTable(ui->specWidget, "SPARK S5 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S4_clicked()
{
    int i =138;
    setupSpecificationsTable(ui->specWidget, "SPARK S4 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S3Pro_clicked()
{
    int i =139;
    setupSpecificationsTable(ui->specWidget, "SPARK S3 PRO SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_S2_clicked()
{
    int i =140;
    setupSpecificationsTable(ui->specWidget, "SPARK S2 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


//ZTE Mneu
void MainWindow::on_ZTE_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}


void MainWindow::on_NubiaZ70SUltra_clicked()
{
    int i =101;
    setupSpecificationsTable(ui->specWidget, "NUBIA Z70S ULTRA   SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_NubiaFlip2_clicked()
{
    int i =102;
    setupSpecificationsTable(ui->specWidget, "NUBIA FLIP 2 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_NubiaFocus2512_clicked()
{
    int i =103;
    setupSpecificationsTable(ui->specWidget, "NUBIA FOCUS 2 (512GB) SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_NubiaFocus2256_clicked()
{
    int i =104;
    setupSpecificationsTable(ui->specWidget, "NUBIA FOCUS 2 (256GB) SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_NubiaNeo3G_clicked()
{
    int i =105;
    setupSpecificationsTable(ui->specWidget, "NUBIA NEO 3G SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_NubiaNeo4G_clicked()
{
    int i =106;
    setupSpecificationsTable(ui->specWidget, "NUBIA NEO 4G SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_NubiaNeo5G_clicked()
{
    int i =107;
    setupSpecificationsTable(ui->specWidget, "NUBIA NEO 5G SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_NubiaMusic2_clicked()
{
    int i =108;
    setupSpecificationsTable(ui->specWidget, "NUBIA MUSIC 2 SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Axon60Ultra_clicked()
{
    int i =109;
    setupSpecificationsTable(ui->specWidget, "AXON 60 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Axon40Ultra_clicked()
{
    int i =110;
    setupSpecificationsTable(ui->specWidget, "AXON 40 ULTRA SPECIFICATIONS");
    setupSpecificationsTableData(ui->specWidget, i);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (ui->comboBox->currentIndex()==1) {
        ui->listWidget_3->clear();
        compareDatabase("Apple", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==2) {
        ui->listWidget_3->clear();
        compareDatabase("Huawei", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==3) {
        ui->listWidget_3->clear();
        compareDatabase("Tecno", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==4) {
        ui->listWidget_3->clear();
        compareDatabase("Redmi", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==5) {
        ui->listWidget_3->clear();
        compareDatabase("HTC", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==6) {
        ui->listWidget_3->clear();
        compareDatabase("Oppo", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==7) {
        ui->listWidget_3->clear();
        compareDatabase("Infinix", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==8) {
        ui->listWidget_3->clear();
        compareDatabase("Nokia", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==9) {
        ui->listWidget_3->clear();
        compareDatabase("LG", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==10) {
        ui->listWidget_3->clear();
        compareDatabase("Samsung", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==11) {
        ui->listWidget_3->clear();
        compareDatabase("Microsoft", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==12) {
        ui->listWidget_3->clear();
        compareDatabase("ZTE", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==13) {
        ui->listWidget_3->clear();
        compareDatabase("Sony", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==14) {
        ui->listWidget_3->clear();
        compareDatabase("Xiaomi", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==15) {
        ui->listWidget_3->clear();
        compareDatabase("Vivo", ui->listWidget_3);
    }
    else if (ui->comboBox->currentIndex()==16) {
        ui->listWidget_3->clear();
        compareDatabase("Motorola", ui->listWidget_3);
    }
}


void MainWindow::on_add_clicked()
{
    if (ui->listWidget_3->selectedItems().isEmpty()) {
        QMessageBox::information(this, "ERROR", "Please select a phone to add.");
    }
    else {
        QString text = ui->listWidget_3->currentItem()->text();
        ui->listWidget_2->addItem(text);
        ui->listWidget_3->clearSelection();
    }
}


void MainWindow::on_remove_clicked()
{
    if (ui->listWidget_2->selectedItems().isEmpty()) {
        QMessageBox::information(this, "ERROR", "Please select a phone to remove.");
    }
    else {
        int selectedRow = ui->listWidget_2->row(ui->listWidget_2->currentItem());
        delete ui->listWidget_2->takeItem(selectedRow);
        ui->listWidget_2->clearSelection();
    }
}


void MainWindow::on_COMPARE_clicked()
{
    int itemCount = ui->listWidget_2->count();
    if (itemCount < 2){
        QMessageBox::information(this, "ERROR", "Please select at least 2 phones.");
    }
    else {
        qDebug() << itemCount;
        int columns = itemCount + 1;


        setupComparisonTable(ui->comparsionTable, columns);
        for (int i=0; i<itemCount; ++i) {
            QString itemText = ui->listWidget_2->item(i)->text();
            setupComparisonTableData(itemText, i+1, ui->comparsionTable);
            qDebug() << itemText;
        }

        ui->stackedWidget->setCurrentIndex(3);
        ui->listWidget_2->clear();
        ui->listWidget_3->clear();
    }
}



void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}


void MainWindow::on_github_clicked()
{
    QString link = "https://github.com/Igb0kwe/SPECS";
    QDesktopServices::openUrl(QUrl(link));
}

