#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QDesktopWidget>
#include "MainWindow.h"

MainWindow::MainWindow(SettingsWrapper *settings, DatamuseAPI *datamuseAPI) : settings(settings), datamuseAPI(datamuseAPI) {
    setWindowTitle(tr("Synonymizer"));

    centralWidget->setContentsMargins(10, 10, 10, 10);

    // Main screen setup

    QVBoxLayout * mainLayout = new QVBoxLayout();

    QHBoxLayout * onlineBox = new QHBoxLayout();
    QLabel * avaibl = new QLabel("Соединение с API сервером:");
    avaibl->setObjectName("info");
    QLabel * status = new QLabel("Оффлайн");
    status->setStyleSheet("color: rgb(224,157,171)");
    status->setObjectName("info");
//    qDebug() << QThread::currentThreadId();
    QTimer * repeater = new QTimer;
    repeater->moveToThread(repeaterThread);
    connect(repeater, &QTimer::timeout, [=]() {
//        qDebug() << QThread::currentThreadId();
        bool online = DatamuseAPI().checkServiceOnline();
        if (online) {
            QMetaObject::invokeMethod(status, "setText",
                                      Q_ARG(QString,"Онлайн"));
            QMetaObject::invokeMethod(status, "setStyleSheet",
                                      Q_ARG(QString,"color: rgb(145,212,166)"));
        }
        else {
            QMetaObject::invokeMethod(status, "setText",
                                      Q_ARG(QString,"Оффлайн"));
            QMetaObject::invokeMethod(status, "setStyleSheet",
                                      Q_ARG(QString,"color: rgb(224,157,171)"));
        }
    });
    repeater->setInterval(2000);
    repeater->connect(repeaterThread, SIGNAL(started()), SLOT(start()));
    onlineBox->addWidget(avaibl, 0, Qt::AlignLeft);
    onlineBox->addWidget(status, 0, Qt::AlignLeft);
    onlineBox->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));
    mainLayout->addLayout(onlineBox);

    QLabel * instruction = new QLabel("Введите слово или\nфразу на английском");
    instruction->setObjectName("instruction");
    instruction->setAlignment(Qt::AlignCenter);
    mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Maximum, QSizePolicy::MinimumExpanding));
    mainLayout->addWidget(instruction, 0, Qt::AlignCenter);

    QHBoxLayout * hBox = new QHBoxLayout();
    comboBox->addItem("Associations");
    comboBox->addItem("Triggers");
    comboBox->setObjectName("mode");
    comboBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    QPushButton * button = new QPushButton("GO");
    button->setObjectName("go");
    connect(lineEdit, SIGNAL(returnPressed()), button, SIGNAL(clicked()));
    connect(button, SIGNAL(clicked()), SLOT(processText()));
    lineEdit->setPlaceholderText("ENTER YOUR WORD HERE");
    QTimer::singleShot(0, lineEdit, SLOT(setFocus()));
    lineEdit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z|\\s]{0,}")));
    lineEdit->setClearButtonEnabled(true);
    lineEdit->setMinimumSize(100, 10);
    lineEdit->setObjectName("request");

    hBox->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    hBox->addWidget(comboBox);
    hBox->addWidget(lineEdit);
    hBox->addWidget(button);
    hBox->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    mainLayout->addLayout(hBox);

    mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Maximum, QSizePolicy::MinimumExpanding));

    QHBoxLayout * bottom = new QHBoxLayout();

    QLabel * signature = new QLabel("Братчиков Сергей БПМ-18-3");
    signature->setObjectName("info");

    QLabel * apiInfo = new QLabel("Based on DatamuseAPI v." + datamuseAPI->API_VERSION);
    apiInfo->setObjectName("info");

    bottom->addWidget(signature, 0, Qt::AlignLeft);
    bottom->addWidget(apiInfo, 0, Qt::AlignRight);
    mainLayout->addLayout(bottom);

    mainScreen->setLayout(mainLayout);
    centralWidget->addWidget(mainScreen);

    // Loading screen setup

    QVBoxLayout * loadingLayout = new QVBoxLayout;

    QLabel * loading = new QLabel();
    loading->setMovie(loadingGif);

    QLabel * search = new QLabel("Поиск ассоциаций...");
    search->setObjectName("search");

    loadingLayout->addWidget(search);
    loadingLayout->addWidget(loading);

    loadingLayout->setAlignment(search, Qt::AlignCenter);
    loadingLayout->setAlignment(loading, Qt::AlignCenter);

    loadingScreen->setLayout(loadingLayout);
    centralWidget->addWidget(loadingScreen);

    // Result screen setup

    QVBoxLayout * resultLayout = new QVBoxLayout();
    QHBoxLayout * headerBox = new QHBoxLayout();
    QLabel * results = new QLabel("Результаты");
    results->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    results->setObjectName("results");
    headerBox->setAlignment(results, Qt::AlignLeft);
    headerBox->addWidget(results);
    QPushButton * back = new QPushButton("ВЕРНУТЬСЯ");
    back->setObjectName("back");
    connect(back, &QPushButton::clicked, centralWidget, [=]() {
        centralWidget->setCurrentWidget(mainScreen);
    });
    headerBox->setAlignment(back, Qt::AlignRight);
    headerBox->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));
    headerBox->addWidget(back);
    resultLayout->addLayout(headerBox);

//    tableWidget->setShowGrid(false);
    tableWidget->setObjectName("table");
    tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeMode::Stretch);
    tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeMode::Fixed);
    tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeMode::Fixed);
    tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeMode::Fixed);
    tableWidget->horizontalHeader()->resizeSection(1, 150);
    tableWidget->horizontalHeader()->resizeSection(2, 100);
    tableWidget->horizontalHeader()->resizeSection(3, 100);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
    tableWidget->verticalHeader()->setDefaultSectionSize(40);

    tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Текст"));
    tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Употребления"));
    tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Синоним"));
    tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Антоним"));

    tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar {height:0px;}");
    tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");

    resultLayout->addWidget(tableWidget);

    resultLayout->setAlignment(results, Qt::AlignLeft);
    resultScreen->setLayout(resultLayout);
    centralWidget->addWidget(resultScreen);

    centralWidget->setCurrentWidget(mainScreen);
    setCentralWidget(centralWidget);

    repeaterThread->start(); //! \brief Start ping
}

//MainWindow::~MainWindow() {
//    delete datamuseAPI;
//    delete settings;
//}

void MainWindow::processText() {
    if (lineEdit->text().isEmpty()) return;
    centralWidget->setCurrentWidget(loadingScreen);
    loadingGif->start();
    try {
        const QList<WordRepresenter> * words;
        if (comboBox->currentText() == "Associations") {
            words = datamuseAPI->getAssociations(lineEdit->text(), settings->getOrSetValue("Search/max-results-count", 100).toInt());
        }
        else {
            words = datamuseAPI->getTriggers(lineEdit->text(), settings->getOrSetValue("Search/max-results-count", 100).toInt());
        }
        if (words->isEmpty()) {
            QMessageBox::information(this, tr("Empty"), tr("No results found!"));
            centralWidget->setCurrentWidget(mainScreen);
        } else {
            tableWidget->setRowCount(words->size());
            for (int i = 0; i < words->size(); i++) {
                WordRepresenter word = words->operator[](i);

                tableWidget->setItem(i, 0, new QTableWidgetItem(word.word()));
                tableWidget->item(i, 0)->setFlags(tableWidget->item(i, 0)->flags() & ~Qt::ItemIsEditable);

                tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(word.score())));
                tableWidget->item(i, 1)->setFlags(tableWidget->item(i, 1)->flags() & ~Qt::ItemIsEditable);

                tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(word.data().isMightSynonym())));
                tableWidget->item(i, 2)->setFlags(tableWidget->item(i, 2)->flags() & ~Qt::ItemIsEditable);

                tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(word.data().isMightAntonym())));
                tableWidget->item(i, 3)->setFlags(tableWidget->item(i, 3)->flags() & ~Qt::ItemIsEditable);
            }
            tableWidget->verticalScrollBar()->setValue(0);
            tableWidget->horizontalScrollBar()->setValue(0);
            tableWidget->setCurrentItem(nullptr);
            centralWidget->setCurrentWidget(resultScreen);
        }
        delete words;
    } catch (std::runtime_error & e) {
        QMessageBox::information(this, tr("Error"), e.what());
        centralWidget->setCurrentWidget(mainScreen);
    }
    loadingGif->stop();
}

void MainWindow::setupWindowSettings() {
    QDesktopWidget *desktop = QApplication::desktop();

    const int MIN_WINDOW_WIDTH = settings->getOrSetValue("Window/min-width", 900).toInt();
    const int MIN_WINDOW_HEIGHT = settings->getOrSetValue("Window/min-height", 600).toInt();
    const int x = (desktop->width() - MIN_WINDOW_WIDTH) / 2;
    const int y = (desktop->height() - MIN_WINDOW_HEIGHT) / 2;
    setMinimumSize(MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT);
    resize(MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT);
    move( x, y );

    QString style = settings->getOrSetValue("Style/theme", "light").toString();
    QFile * stylesFile;
    if (style == "night") {
        stylesFile = new QFile(":/styles/night.qss");
    }
    else {
        stylesFile = new QFile(":/styles/light.qss");
    }
    stylesFile->open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(stylesFile->readAll());
    setStyleSheet(stylesheet);
    stylesFile->close();
    delete stylesFile;
}

void MainWindow::closeEvent(QCloseEvent *event) {
//    repeaterThread->killTimer(0);
    repeaterThread->exit(0);
    QWidget::closeEvent(event);
}