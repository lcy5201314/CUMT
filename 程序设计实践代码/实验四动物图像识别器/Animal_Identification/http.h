#ifndef HTTP_H
#define HTTP_H

#include <QString>
#include <qnetwork.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QEventLoop>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QObject>


const QString BaiduTokenUrl = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2";
const QString client_id = "VCVHPjKsbbcUuYRjBQ4ZGHK8";
const QString secret_id = "lGK0ocvMR5nhhj6DMsB53vjMSFU6HrZ0";
const QString baiduImageUrl = "https://aip.baidubce.com/rest/2.0/image-classify/v1/animal?access_token=";



class Http : public QObject
{
    Q_OBJECT
public:
    Http();
    static bool post_sync(QString Url, QMap<QString, QString> header, QByteArray &requestData, QByteArray &replyData);
};

#endif // HTTP_H
