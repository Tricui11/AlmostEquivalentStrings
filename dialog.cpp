#include "dialog.h"
#include "ui_dialog.h"
#include <solvercreator.cpp>
#include <basestringsolvercreator.cpp>
#include <substringsolvercreator.cpp>
#include <subsequencesolvercreator.cpp>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("AlmostEquivalentStrings");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonCompareStrings_clicked()
{
    SolverCreator *creator = new BaseStringSolverCreator();
    SolveAndOutput(creator);
}

void Dialog::on_pushButton_FindSubstring_clicked()
{
    SolverCreator *creator = new SubStringSolverCreator();
    SolveAndOutput(creator);
}


void Dialog::on_pushButton_LongestCommonSubsequence_clicked()
{
    SolverCreator *creator = new SubsequenceSolverCreator();
    SolveAndOutput(creator);
}


void Dialog::on_pushButton_MaximumMonotonicSubsequence_clicked()
{
    SolverCreator *creator = new SubsequenceSolverCreator();
    SolveAndOutput(creator, true);
}

void Dialog::SolveAndOutput(SolverCreator *creator, bool isTargetArrayFromSource)
{
    QString sourceString = ' ' + ui->textEdit_SourceString->toPlainText();
    QByteArray sourceStringAsUtf8 = sourceString.toUtf8();
    int sourceSize = sourceString.size();
    char *sourceCharArray = new char[sourceSize];
    qstrcpy(sourceCharArray, sourceStringAsUtf8.data());

    int targetSize;
    char *targetCharArray;
    if (isTargetArrayFromSource)
    {
        targetCharArray = new char[sourceSize];
        for (int i = 0; i < sourceSize; i++)
        {
            targetCharArray[i] = sourceCharArray[i];
        }
        ArrayHelper *arrayHelper = new ArrayHelper();
        arrayHelper->heapSort(targetCharArray, sourceSize);
        targetSize = sourceSize;
        delete arrayHelper;
    }
    else
    {
        QString targetString = ' ' + ui->textEdit_TargetString->toPlainText();
        QByteArray targetStringAsUtf8 = targetString.toUtf8();
        targetSize = targetString.size();
        targetCharArray = new char[targetSize];
        qstrcpy(targetCharArray, targetStringAsUtf8.data());
    }

    BaseStringSolver *solver = creator->createSolver();
    QString res = solver->string_compare(sourceCharArray, targetCharArray, sourceSize, targetSize);
    ui->textEdit_Output->setText(res);
    delete creator;
    delete solver;
}
