#include "image.h"

Image::Image()
{

}


QByteArray Image::imageToBase64(QString imgPath)
{
    QImage img(imgPath);
    QByteArray ba;
    //用QByterArray构造QBuffer
    QBuffer buf(&ba);
    buf.open(QIODevice::WriteOnly);
    //把img写入QBuffer
    img.save(&buf,"JPG");
    //对图片做base64编码，不包含编码头
    QByteArray base64 = ba.toBase64();

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QByteArray imgDate = codec->fromUnicode(base64).toPercentEncoding();

    return imgDate;

}
