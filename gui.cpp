#include"gui.h"
#include<QEventLoop>
#include<QMovie>
int static t = 0;
int static b=0;
int static c=0;
//qApp->addLibraryPath("C:/Qt/4.8.4/plugins/imageformats");

makegui::makegui(QWidget *parent):QMainWindow(parent)
{
    QMenu *menu;


    menu = menuBar()->addMenu( tr("&About") );

    menu->setStyleSheet("color:white");
    QLabel *headlab = new QLabel("<font size=\"4\"><b>Get Your Attendance</b></font>");
    headlab->setStyleSheet("color:white");

headlab->setIndent(60);
    newaction = new QAction("Developer",this);
    newaction1 = new QAction("Qt",this);


    menu->addAction(newaction);
    menu->addAction(newaction1);

    connect(newaction,SIGNAL(triggered()),this,SLOT(developer()));
    connect(newaction1,SIGNAL(triggered()),this,SLOT(abqt()));
   QHBoxLayout *head= new QHBoxLayout;
   QHBoxLayout *boxlay= new QHBoxLayout;
   head->addWidget(headlab);
    hlay1 = new QHBoxLayout;
    hlay2 = new QHBoxLayout;
    hlay3 = new QHBoxLayout;

    box = new QCheckBox("Remember Me");


   box->setChecked(1);
   boxlay->addWidget(box);

    idline = new QLineEdit;
    bdayline = new QLineEdit;
     QSettings settings("set");
     QString aValue = settings.value("aKey","").toString();
     idline->setText(aValue);


     QString aValu = settings.value("bday","").toString();
     bdayline->setText(aValu);

    but = new QPushButton("Click Me");
    but->setFixedWidth(150);
    but->setStyleSheet("*{background-color:rgb(16,78,139);color:rgb(255,255,255)}");

    idline->setStyleSheet("color: blue;"
                            "background-color: white;"
                          "selection-color:red;"
                            "selection-background-color: grey;");

    bdayline->setStyleSheet("color: blue;"
                            "background-color: white;"
                            "selection-color:red;"
                            "selection-background-color: grey;");

    QValidator *val=new QIntValidator(1,999999999,this);
    idline->setValidator(val);

    idlab = new QLabel;
   // idvar = new QVariant;
    bdaylab  = new QLabel;
    idlab->setText("<font color=\"white\" >Student ID:</font>");
    bdaylab->setText("<font color=\"white\" >BDay(yyyy-mm-dd):</font>");



     bdaylab->setStyleSheet("font-size:12px");
     idlab->setStyleSheet("font-size:12px");
     this->setWindowTitle("Websis Desktop Application");



    hlay1->addWidget(idlab);
    hlay1->addSpacing(53);
    hlay1->addWidget(idline);



    hlay2->addWidget(bdaylab);


    hlay2->addSpacing(10);


    hlay2->addWidget(bdayline);





   hlay3->addWidget(but);
   hlay3->addSpacing(20);







   vlay = new QVBoxLayout;
  vlay->addLayout(head);
   vlay->addLayout(hlay1);
   vlay->addLayout(hlay2);
   vlay->addLayout(boxlay);
   vlay->addLayout(hlay3);


   wid = new QWidget;
   wid->setLayout(vlay);

   this->setStyleSheet("*{background-color:rgb(10,125,	200	)}");
   this->setCentralWidget(wid);
   this->setWindowOpacity(0.95);
   this->resize(300,130);

   this->show();


   connect(but,SIGNAL(clicked()),this,SLOT(getit()));



 }
void makegui::getit()
{

    but->setDisabled(1);

    if(idline->text()==""||bdayline->text()=="")
       { QMessageBox::warning(this,"No Data!!","<b>Please Enter Id and Birthdate</b>");
        but->setEnabled(1);
        }
    else
    {

     QMovie *movie = new QMovie(":/images/wait.gif");

     label = new QLabel;
     label->setMovie(movie);

     hlay3->addWidget(label);

     movie->start();

    wid1[b]= new QMainWindow;
    wid2[c] = new QWidget;
    portal lol(idline->text(),bdayline->text());
    int flag = lol.checkConnection();
     int flag2 = lol.checkValidation();
    if(flag==0)

        {
          movie->stop();
          QMessageBox::warning(this,"ERROR","<p><b>No Internet Connection </b><br><b>Please Try Again</b></p>");

          idline->setText("");

          bdayline->setText("");
          but->setEnabled(1);

          delete label;


    }

   else if(flag2==0)
    {
        movie->stop();
        QMessageBox::warning(this,"ERROR","<p><b>Data Entered is Invalid</b><br><b>Please Try Again</b></p>");

        idline->setText("");

        bdayline->setText("");
        but->setEnabled(1);

        delete label;

    }


else{
        QLabel *name = new QLabel;

        name->setText(lol.getName() + "   " + lol.getBranch() );
       /* QLabel *branch = new QLabel;

        branch->setText(lol.getBranch());*/

        name->setStyleSheet("*{color:rgb(151	,255	,255	);font-size:25px}");
       // branch->setStyleSheet("*{color:rgb(151	,255	,255	);font-size:25px}");
                hlay5 = new QHBoxLayout;
        hlay5->addWidget(name);
       // hlay5->addSpacing(60);
      //  hlay5->addWidget(branch);
    QLabel *labhead[5];

    labhead[0] =new QLabel;
    labhead[0]->setText("CGPA : " + lol.getGpa());

    labhead[1]= new QLabel("Total Classes");
    labhead[2]= new QLabel("Bunks");
    labhead[3]= new QLabel("Attendance");
    labhead[4]= new QLabel("Last Updated");
    labhead[0]->setStyleSheet("*{color:rgb(151	,255	,255	);font-size:25px}");
    labhead[1]->setStyleSheet("*{color:rgb(255	,228	,225	);font-size:18px}");
    labhead[2]->setStyleSheet("*{color:rgb(255	,228	,225	);font-size:18px}");
    labhead[3]->setStyleSheet("*{color:rgb(255	,228	,225	);font-size:18px}");
    labhead[4]->setStyleSheet("*{color:rgb(255	,228	,225	);font-size:18px}");


    hlay4 = new QHBoxLayout;
    hlay4->addWidget(labhead[0]);
    hlay4->addWidget(labhead[1]);
    hlay4->addSpacing(30);
    hlay4->addWidget(labhead[2]);
    hlay4->addSpacing(30);
    hlay4->addWidget(labhead[3]);
    hlay4->addSpacing(30);
    hlay4->addWidget(labhead[4]);

    vlay1 = new QVBoxLayout;
    vlay1->addLayout(hlay5);
    vlay1->addLayout(hlay4);




    QLabel *lab1[100];
    QHBoxLayout *hlay[20];


    if(t!=0)//Setting The Index For Label To 0
        t=0;

   for(int x =0; x<10; x++)
   {



           lab1[t] = new QLabel;

           lab1[t]->setText(lol.getSubs());
           lab1[t]->setStyleSheet("*{color:rgb(255	,255	,255);font-size:15px;font-style:italic;}");
           lab1[t]->setMaximumWidth(224);



           hlay[x] = new QHBoxLayout;
           hlay[x]->addWidget(lab1[t]);

           t++;  //incrementing the Index For label




   }

   for(int x =0; x<10; x++)
    {



           lab1[t] = new QLabel;
           lab1[t]->setText(lol.getClasses());
           lab1[t]->setStyleSheet("*{color:rgb(250,250,250);font-size:15px;font-style:oblique;}");

           lab1[t]->setIndent(25);

           hlay[x]->addWidget(lab1[t]);

           t++;

    }



      for(int x =0; x<10; x++)
        {



                lab1[t] = new QLabel;
                lab1[t]->setText(lol.getBunks());
                lab1[t]->setStyleSheet("*{color:rgb(250,250,250);font-size:15px;font-style:oblique;}");


                lab1[t]->setIndent(25);



                hlay[x]->addWidget(lab1[t]);
                t++;


        }

      for(int x =0; x<10; x++)
        {



                lab1[t] = new QLabel;
                QString atten = lol.getAtten();
                if(atten!=QString(""))
               { QString atn = atten + "%";
                lab1[t]->setText(atn);}
                else
                    lab1[t]->setText(atten);
                if(atten.toInt()<75)

                lab1[t]->setStyleSheet("*{color:red; font-size:15px;font-style:oblique;}");


                else
                    lab1[t]->setStyleSheet("*{color:rgb(202,	255,	112); font-size:15px;font-style:oblique;}");

                     lab1[t]->setIndent(25);



               hlay[x]->addWidget(lab1[t]);
                t++;

        }

      for(int x =0; x<10; x++)
        {



                lab1[t] = new QLabel;
                lab1[t]->setText(lol.getDate());
                lab1[t]->setStyleSheet("*{color:rgb(250,250,250);font-size:15px;font-style:normal;}");

                lab1[t]->setIndent(25);



               hlay[x]->addWidget(lab1[t]);
               t++;

        }




       for(int x= 0 ; x<10;x++)
       {
           vlay1->addLayout(hlay[x]);
       }

       t=0;

       wid2[c]->setLayout(vlay1);

       wid1[b]->setCentralWidget(wid2[c]);

       wid1[b]->resize(1200,400);

       wid1[b]->setStyleSheet("background-color:rgb(0,0,0)");

       wid1[b]->setWindowOpacity(1);

       wid1[b]->setWindowTitle("Your CGPA And Attendance");



       wid1[b]->show();
       if(box->isChecked())
       {
           QSettings settings("set");

       QString somevalue=idline->text();

       settings.setValue("aKey",somevalue);
       }
       else
       {
           QSettings settings("set");

           QString somevalue="";

       settings.setValue("aKey",somevalue);
       }
       if(box->isChecked())
       {
           QSettings settings("set");

         QString bday=bdayline->text();

         settings.setValue("bday",bday);
       }
       else
       {
           QSettings settings("set");

             QString bday="";

            settings.setValue("bday",bday);
       }


       but->setEnabled(1);
       delete label;

        b++;
        c++;

      }

    }

}







void makegui::developer()
{


   QWidget *devel = new QWidget;
   QLabel *lab = new QLabel;
   QLabel *labb = new QLabel;
   labb->setIndent(50);
   lab->setText("<p><b>Developed By:</b><br><b> RAJAT GUPTA</b><br><b>MIT Manipal</b><br>""<br><b>rajatgupta431@gmail.com</b><br><b><font color=\"white\">www.facebook.com/LUGManipal</font></b></p>");
   labb->setText("<img src=':/images/lug.jpg'>");
   QVBoxLayout lay;
   lay.addWidget(labb);
   lay.addWidget(lab);
   devel->setLayout(&lay);
   devel->setStyleSheet("*{background-color:rgb(10,125,	200	)}");
   devel->setWindowTitle("LUG Manipal");
   devel->show();

}

void makegui::abqt()
{
    QMessageBox::aboutQt(this);

}



