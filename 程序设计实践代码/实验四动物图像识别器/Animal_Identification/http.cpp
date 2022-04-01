#include "http.h"

Http::Http()
{

}


bool Http::post_sync(QString Url, QMap<QString, QString> header, QByteArray &requestData, QByteArray &replyData)
{
    QNetworkAccessManager manager;           //发送请求的动作

    QNetworkRequest request;                 //请求内容（包含url和头）
    request.setUrl(Url);
    QMapIterator<QString, QString> it(header);
    while (it.hasNext())
    {
        it.next();
        request.setRawHeader(it.key().toLatin1(),it.value().toLatin1());

    }

    //发起请求
    QNetworkReply *replay = manager.post(request, requestData);
    QEventLoop l;

    connect(replay,&QNetworkReply::finished, &l, &QEventLoop::quit);

    l.exec();

    if(replay != nullptr && replay->error() == QNetworkReply::NoError)
    {
        replyData = replay->readAll();
        return  true;
    }
    else
    {
        return  false;
    }
}
