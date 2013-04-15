#ifndef GUI_H
#define GUI_H
#include<QtGui>
#include<QAction>
#include"websis.h"
#include<QSettings>


class makegui:public QMainWindow
{

    Q_OBJECT
public:

    makegui(QWidget *parent = 0);
    QWidget *wid;
    QHBoxLayout *hlay1,*hlay2,*hlay3,*hlay5;
    QVBoxLayout *vlay;
    QLineEdit *idline,*bdayline;
    QLabel *idlab , *bdaylab;
    QPushButton *but;
QCheckBox *box;

    QLabel *label;

    QAction *newaction,*newaction1;
private:
    QMainWindow *wid1[50];
    QWidget  *wid2[50];

     QLabel *labhead[6];
     QHBoxLayout *hlay4;
     QVBoxLayout *vlay1;


public slots:
    void getit();

    void developer();
    void abqt();

};

#endif // GUI_H
