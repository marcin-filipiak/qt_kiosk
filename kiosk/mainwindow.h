#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString home_url;
    int ticks=0;
    int max_ticks=0;
    int position=0;
    int navigator=1;
    QWebEngineView *view2 = new QWebEngineView();
    void resizeEvent(QResizeEvent *event) override;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

     void ticke();

     void on_toolBack_clicked();

     void on_toolHome_clicked();

private:
    Ui::MainWindow *ui;
    int timerId;
};

#endif // MAINWINDOW_H
