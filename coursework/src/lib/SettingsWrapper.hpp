#pragma once

#include <QtCore/QDir>
#include <QtCore/QString>
#include <QtCore/QSettings>

/*!
	\brief Класс-обертка над QSettings
    \author Сергей Братчиков
	\date 22/12/2019

    \details Класс представляет из себя C++ API для подбора асоциаций и часто используемых слов к словам/фразам на английском языке
    \details В качестве API используется сайт datamuse.com
*/
class SettingsWrapper {

public:

    SettingsWrapper(const QDir & appDataDir);
    ~SettingsWrapper() { delete settings; }

    const QVariant getOrSetValue(const QString & key, const QVariant & value);
    const QVariant getValue(const QString & key);

    const QString getFileName() const {
        return settings->fileName();
    }

private:

    QSettings * settings;

};

inline SettingsWrapper::SettingsWrapper(const QDir & appDataDir) {
    settings = new QSettings(appDataDir.relativeFilePath("settings.ini"), QSettings::IniFormat);
}

inline const QVariant SettingsWrapper::getOrSetValue(const QString & key, const QVariant & value) {
    if (!settings->contains(key)) {
        settings->setValue(key, value);
        return value;
    }
    return settings->value(key, value);
}

inline const QVariant SettingsWrapper::getValue(const QString &key) {
    return settings->value(key);
}