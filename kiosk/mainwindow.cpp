#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSettings>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //wczytanie ustawien
    QSettings* settings = new QSettings("/etc/kiosk/config.ini", QSettings::IniFormat);
    settings->beginGroup("page");
    home_url = settings->value("home").toString();
    settings->endGroup();
    settings->beginGroup("config");
    max_ticks = settings->value("ticks").toInt();
    settings->endGroup();
    navigator = settings->value("navigator").toInt();
    settings->endGroup();

    //timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ticke()));
    //wywolanie ticke() co 10 sekund
    timer->start(10000);


    ui->setupUi(this);
    view2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->ui->verticalLayout->addWidget(view2);
    view2->show();
    view2->load(QUrl(home_url));
    view2->page()->setZoomFactor(1);

    if (navigator == 0){
        //ui->horizontalLayout->s
    }

    //ui->label->setText(QVariant(max_ticks).toString());

}


//skalowanie okna
void MainWindow::resizeEvent(QResizeEvent *event){

    QMainWindow::resizeEvent(event);

    QRect rect = ui->centralWidget->geometry();
    ui->verticalLayoutWidget->setGeometry(10, 50, (rect.width()-20), (rect.height()-20));

}


MainWindow::~MainWindow()
{
    delete ui;
}


//odczytanie pozycji myszy wywolane przez timer i po wykryciu braku aktywnosci przejscie na strone glowna
void MainWindow::ticke(){
    int x = QCursor:: pos().x();
    QString tmp = QString::number(x);

    view2->page()->setZoomFactor(1);

    //nic sie nie ruszylo od ostatniego razu
    if (this->position==x){
        //doliczenie ticks
        this->ticks++;
    }

    //jesli wieksze od 0 to znaczy ze automatyczny powrot do strony glownej jest wlaczony
    if (max_ticks != 0){
        //jesli nie ruszylo sie okreslona liczbe tickow to oznacza brak aktywnosci uzytkownika - wracamy na strone start
        if (this->ticks==max_ticks){
            this->ticks = 0;
            view2->load(QUrl(home_url));
        }
    }

    //wpisanie pozycji kursora do pamieci
    this->position = x;



}

void MainWindow::on_toolBack_clicked()
{
    view2->back();
}

void MainWindow::on_toolHome_clicked()
{
    view2->load(QUrl(home_url));
}
