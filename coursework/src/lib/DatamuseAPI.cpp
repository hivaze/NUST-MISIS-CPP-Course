#include <QtNetwork/QNetworkReply>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QThread>
#include <QtCore/QEventLoop>

#include "DatamuseAPI.h"

const QByteArray DatamuseAPI::makeRequest(const QUrl &url) const {
    QNetworkReply * reply = manager->get(QNetworkRequest(url));
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    QByteArray byteArray = reply->readAll();
    if (reply->error() != QNetworkReply::NoError) throw std::runtime_error("API error occurred: " + reply->errorString().toStdString());
    reply->deleteLater();
    return byteArray;
}

const QList<WordRepresenter> * DatamuseAPI::getAssociations(const QString & word, int maxCount) {
    QString requestString = API_URL + "?ml=" + word + "&max=" + QString::number(maxCount);
    QByteArray response = makeRequest(QUrl(requestString));
    return processReply(response);
}

const QList<WordRepresenter> * DatamuseAPI::getTriggers(const QString &word, int maxCount) {
    QByteArray response = makeRequest(QUrl(API_URL + "?rel_trg=" + word + "&max=" + QString::number(maxCount)));
    return processReply(response);
}

const QList<WordRepresenter> * DatamuseAPI::processReply(const QByteArray &array) const {
    auto * result = new QList<WordRepresenter>();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = jsonDocument.array();
    foreach (const QJsonValue & value, jsonArray) {
            QJsonObject object = value.toObject();
            QJsonArray tags = object["tags"].toArray();
            result->append(WordRepresenter(object["score"].toInt(), object["word"].toString(), tags));
    }
    return result;
}

const bool DatamuseAPI::checkServiceOnline() const {
    try {
        makeRequest(QUrl(API_URL));
        return true;
    }
    catch (std::runtime_error & e) {
//        qDebug() << e.what();
        return false;
    }
}