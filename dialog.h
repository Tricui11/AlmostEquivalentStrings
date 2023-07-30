#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <subsequencesolver.cpp>
#include "arrayhelper.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    SubsequenceSolver *solver = nullptr;
    ArrayHelper *arrayHelper = nullptr;
};
#endif // DIALOG_H
