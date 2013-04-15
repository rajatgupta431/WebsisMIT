#ifndef WEBSIS_H
#define WEBSIS_H
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QByteArray>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QObject>
#include <QEventLoop>
#include <QtNetwork/QNetworkCookieJar>
#include <QProgressBar>

class portal : public QObject
{
    Q_OBJECT
public:

    portal(QString,QString,QObject *parent = 0);


    QNetworkAccessManager *nam;
QUrl first;

QNetworkRequest req;

    QNetworkReply *reply;
    QString getName();
QString getGpa();
QString getSubs();
QString getBunks();
QString getAtten();
QString getDate();
QString getBranch();
QString getClasses();
int checkConnection();
int checkValidation();
public slots:

    void replyFinished(QNetworkReply*);
     void replyFinished2(QNetworkReply* );




};




#endif // WEBSIS_H
