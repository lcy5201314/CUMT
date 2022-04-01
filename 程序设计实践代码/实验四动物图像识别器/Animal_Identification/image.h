#ifndef IMAGE_H
#define IMAGE_H
#include <QString>
#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <QTextCodec>



class Image
{
public:
    Image();

    static QByteArray imageToBase64(QString imgPath);
    void urlEncode();
};

#endif // IMAGE_H
