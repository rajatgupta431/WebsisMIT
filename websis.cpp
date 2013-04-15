#include<websis.h>

#include<QDebug>
#include<iostream>


using namespace std;

int che=1;int chek =1;
int static v =1; int static n = 1;int static m=1;int static o = 1;int static q=1;
QString static arr2;
QString arr;
QString ch;

portal::portal(QString  id,QString bday,QObject *parent):QObject(parent)
{
    first = QUrl("http://websismit.manipal.edu/websis/control/createAnonSession");

    QByteArray postData;

  QString query;

      query= "idValue=" + id + "&" + "birthDate_i18n=" + bday + "&" + "birthDate=" + bday;
      qDebug()<<query;
     postData.append(query);



     nam = new QNetworkAccessManager(this);



     nam->setCookieJar(new QNetworkCookieJar(this));


     req.setUrl(first);

     req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant( "application/x-www-form-urlencoded"));


    reply =  nam->post(req, postData); // Request the data from the form



QEventLoop loop;
connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
loop.exec();

replyFinished(reply);

}

void portal::replyFinished(QNetworkReply* net1)
{
 ch = net1->readAll();
   che=1;
   if(ch=="")
       che=0;

//Saving the cookies obtained in a QList to pass on to next Link
    QList<QNetworkCookie> cokie =nam->cookieJar()->cookiesForUrl(first);
       QVariant var;
       var.setValue(cokie);
       req.setUrl(QUrl("http://websismit.manipal.edu/websis/control/StudentAcademicProfile"));
       req.setHeader(QNetworkRequest::CookieHeader,var);

       reply = nam->get(req);
       QEventLoop loop1;

       connect(reply,SIGNAL(finished()),&loop1,SLOT(quit()));
               loop1.exec();



       replyFinished2(reply);


}

void portal::replyFinished2(QNetworkReply* net2 )
{
    arr = net2->readAll();
    qDebug()<<arr.indexOf("MISSION STATEMENT");
    chek=1;
    if(arr.indexOf("MISSION STATEMENT")==4230&&arr.indexOf("MISSION STATEMENT")!=-1)
        chek=0;


}

int portal::checkConnection()
{
    return che;
}
int portal::checkValidation()
{
    return chek;
}
QString portal::getName()
{
   QString arrey = ch;
   int i =  arrey.indexOf("cc_ProfileTitle_name");

   //qDebug()<<p;

    arrey= arrey.mid(i);



   int t= arrey.indexOf(">");
   int r = arrey.indexOf("</span>");
    int x =r-(t+1);
    qDebug()<<x;
    QString yoho = arrey.mid(t+3,x-2);
    qDebug()<<yoho;


   return yoho;

}
QString portal::getBranch()
{
   QString arrey = arr;
   int i =  arrey.indexOf("<h2>");

   //qDebug()<<p;

   // arrey= arrey.mid(i);



   //int t= arrey.indexOf(">");
   int r = arrey.indexOf("</h2>");
    int x =r-(i+1);
    qDebug()<<x;
    QString yoho = arrey.mid(i+4,x-3);
    qDebug()<<yoho;


   return yoho;

}


QString portal::getGpa()
{
    QString arr1 = arr;

    int i =  arr1.indexOf("n class=\"l");

    QString yoho = arr1.mid(i+21,4);
    qDebug()<<yoho;


    return yoho;

}

QString portal::getSubs()
{
    QString btt;
        QString ci;

         arr2 = arr;
         if(n==11)
          n=1;
qDebug()<<n;
           ci="cc_ListAttendanceSummary_productName_"+QString::number(n);
          int p= arr2.indexOf(ci);
          //qDebug()<<p;

           arr2= arr2.mid(p);



          int t= arr2.indexOf(">");
          int r = arr2.indexOf("</span>");
           int x =r-(t+1);
           qDebug()<<x;
           btt = arr2.mid(t+1,x)+ ":";
           qDebug()<<btt.mid(1,1);
           if(btt.mid(1,1)=="<")
              { n++;
               return "";}

           n++;

            qDebug()<<"Subject: "<<btt;


            return btt;
}

QString portal::getBunks()
{   QString att;
    QString hi;
    arr2 =arr;
    if(v==11)
     v=1;

       hi="cc_ListAttendanceSummary_classesAbsent_"+QString::number(v);

     int c= arr2.indexOf(hi);
       arr2= arr2.mid(c);
       int t= arr2.indexOf(">");
       int r = arr2.indexOf("</span>");
        int x =r-(t+1);
        att =arr2.mid(t+1,x);
        v++;
        QString hey = att.mid(1,1);
        if(hey !="0"&&hey !="1"&&hey !="2"&&hey !="3"&&hey !="4"&&hey !="5"&&hey !="6"&&hey !="7"&&hey !="8"&&hey !="9")
            return "";


        qDebug()<<"Classes Bunked:"<<att;
         return att;


}


QString portal::getAtten()
{
    QString vtt;
    QString bi;

     arr2 = arr;
     if(m==11)
      m=1;
       bi="cc_ListAttendanceSummary_attendancePercentage_"+QString::number(m);
      int p= arr2.indexOf(bi);

       arr2= arr2.mid(p);



       int t= arr2.indexOf(">");
       int r = arr2.indexOf("</span>");
        int x =r-(t+1);

        vtt = arr2.mid(t+1,x);
        m++;
        QString hey = vtt.mid(1,1);
        if(hey !="0"&&hey !="1"&&hey !="2"&&hey !="3"&&hey !="4"&&hey !="5"&&hey !="6"&&hey !="7"&&hey !="8"&&hey !="9")
            return "";



        qDebug()<<"Attendance: "<<vtt;


       return vtt;

}
QString portal::getDate()
{   QString vtt;
    QString bi;

     arr2 = arr;
     if(o==11)
      o=1;

       bi="cc_ListAttendanceSummary_lastUpdatedStamp_"+QString::number(o);
      int p= arr2.indexOf(bi);

       arr2= arr2.mid(p);



       int t= arr2.indexOf(">");
       int r = arr2.indexOf("</span>");
        int x =r-(t+1);
        vtt = arr2.mid(t+1,x);
        o++;

        QString hey = vtt.mid(1,1);
        if(hey !="0"&&hey !="1"&&hey !="2"&&hey !="3"&&hey !="4"&&hey !="5"&&hey !="6"&&hey !="7"&&hey !="8"&&hey !="9")
            return "";


        qDebug()<<"Date: "<<vtt;


       return vtt;

}
QString portal ::getClasses()
{
    QString vtt;
        QString bi;

         arr2 = arr;
         if(q==11)
          q=1;


           bi="cc_ListAttendanceSummary_attendanceTaken_"+QString::number(q);
          int p= arr2.indexOf(bi);

           arr2= arr2.mid(p);



           int t= arr2.indexOf(">");
           int r = arr2.indexOf("</span>");
            int x =r-(t+1);
            vtt = arr2.mid(t+1,x);
            q++;
            QString hey = vtt.mid(1,1);
            if(hey !="0"&&hey !="1"&&hey !="2"&&hey !="3"&&hey !="4"&&hey !="5"&&hey !="6"&&hey !="7"&&hey !="8"&&hey !="9")
                return "";


            qDebug()<<"Classes: "<<vtt;


           return vtt;

}
