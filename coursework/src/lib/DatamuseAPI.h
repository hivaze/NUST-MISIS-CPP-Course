#pragma once

#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <ostream>
#include "WordRepresenter.hpp"

/*!
	\brief HTTP API-Клиент Datamuse
    \author Сергей Братчиков
	\date 22/12/2019

    \details Класс представляет из себя C++ API для подбора асоциаций и часто используемых слов к словам/фразам на английском языке
    \details В качестве API используется сайт datamuse.com
*/
class DatamuseAPI {

public:

    DatamuseAPI() : manager(new QNetworkAccessManager()) {};
    ~DatamuseAPI() { delete manager; }

    /*!
        \brief Осуществаляет http-запрос к Datamuse и возврщает список ассоциаций для слова word в английском языке
        \return Список английских слов/фраз, QList из объектов WordRepresenter
        \param word Входная слово/фраза на английском языке
        \param maxCount Максимальнй размер возвращаемого QList
        \throw std::runtime_error В случае ошибки соединения с сервером Datamuse
    */
    const QList<WordRepresenter> * getAssociations(const QString & word, int maxCount);

    /*!
        \brief Осуществаляет http-запрос к Datamuse и возврщает список часто используемых слов/выражений с выражением word в английском языке
        \return Список английских слов/фраз, QList из объектов WordRepresenter
        \param word Входная слово/фраза на английском языке
        \param maxCount Максимальнй размер возвращаемого QList
        \throw std::runtime_error В случае ошибки соединения с сервером Datamuse
    */
    const QList<WordRepresenter> * getTriggers(const QString & word, int maxCount);

    /*!
        \brief Проверка доступности HTTP сервера Datamuse
        \return true если соединение успешно установлено
        \return false если произшли любые ошибки при попытке
    */
    const bool checkServiceOnline() const;

    //! \brief Версия поддерживаемого протокола Datamuse
    const QString API_VERSION{"1.1"};

private:

    const QString API_URL{"http://api.datamuse.com/words"};
    QNetworkAccessManager * const manager;

    /*!
        \brief Реализация выполнения HTTP запроса
        \throw std::runtime_error В случае ошибки соединения с сервером Datamuse
    */
    const QByteArray makeRequest(const QUrl &url) const;

    //! \brief Обработка ответа сервера
    const QList<WordRepresenter> * processReply(const QByteArray & array) const;

};