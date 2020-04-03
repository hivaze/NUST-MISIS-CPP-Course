#pragma once

#include <cstddef>
#include <QtCore/QString>
#include <QtCore/QJsonArray>

/*!
	\brief Представление единицы ответа сервера Datamuse
    \author Сергей Братчиков
	\date 07/01/2020

    Экземплеры класа, по сути текст на английском языке, сопровождаемый дополнительными данными
*/
class WordRepresenter {

private:

    struct Data {

    private:

        bool mightSynonym_;
        bool mightAntonym_;

    public:

        Data(bool mightSynonym = false, bool mightAntonym = false) : mightSynonym_(mightSynonym), mightAntonym_(mightAntonym) {}

        bool isMightSynonym() const {
            return mightSynonym_;
        }

        bool isMightAntonym() const {
            return mightAntonym_;
        }

    };

private:

    size_t score_{0};
    QString word_{""};
    Data data_{false, false};
    bool haveData{false};

public:

    WordRepresenter(size_t score, const QString &word, const QJsonArray &tags) : score_(score), word_(word) {
        if (!tags.isEmpty()) {
            bool syn = tags.contains("syn");
            bool ant = tags.contains("ant");
            data_ = Data{syn, ant};
        }
        else haveData = false;
    }
    ~WordRepresenter()  = default;

    size_t score() const {
        return score_;
    }

    const QString & word() const {
        return word_;
    }

    const Data & data() const {
        return data_;
    }

    bool isHaveData() const {
        return haveData;
    }

};