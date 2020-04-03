#pragma once

#include <QtCore/QSettings>
#include <QtCore/QTimer>
#include <QtCore/QThread>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtGui/QMovie>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QMainWindow>
#include "../lib/DatamuseAPI.h"
#include "../lib/SettingsWrapper.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
	\brief Основной класс графической части приложения
    \author Сергей Братчиков
	\date 22/12/2019

	Реализация библиотеки synonymizer_lib в графическом интерфейсе
*/
class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    /*!
        \brief Создание главного окна
        \param settings Экземпляр конфигурирующего объекта
        \param datamuseAPI Экземпляр Datamuse API-клиента
    */
    MainWindow(SettingsWrapper *settings, DatamuseAPI *datamuseAPI);
//    ~MainWindow();

    //! \brief Загрурзка/Установка настроек приложения из конфигурацинного файла
    void setupWindowSettings();

protected:
    void closeEvent(QCloseEvent *event) override;

private:

    QThread * repeaterThread = new QThread;

    QStackedWidget * centralWidget = new QStackedWidget;
    QWidget * mainScreen = new QWidget;
    QWidget * loadingScreen = new QWidget;
    QWidget * resultScreen = new QWidget;

    QComboBox * comboBox = new QComboBox;
    QLineEdit * lineEdit = new QLineEdit;

    QMovie * loadingGif = new QMovie(":/images/loader.gif");

    QTableWidget * tableWidget = new QTableWidget(0, 4);

    DatamuseAPI * datamuseAPI;
    SettingsWrapper * settings;

private slots:

    //! \brief Метод обработки введенного текста
    void processText();

};