#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <basestringsolver.h>
#include <arrayhelper.cpp>
#include <solvercreator.cpp>

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
    void on_pushButtonCompareStrings_clicked();

    void on_pushButton_FindSubstring_clicked();

    void on_pushButton_LongestCommonSubsequence_clicked();

    void on_pushButton_MaximumMonotonicSubsequence_clicked();

private:
    Ui::Dialog *ui;

    void SolveAndOutput(SolverCreator *creator, bool isTargetArrayFromSource = false);
};
#endif // DIALOG_H
