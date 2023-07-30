#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
    if (solver != nullptr)
    {
        delete solver;
    }
    if (arrayHelper != nullptr)
    {
        delete arrayHelper;
    }
}

void Dialog::on_pushButton_clicked()
{
    QString sourceString = ' ' + ui->textEdit_SourceString->toPlainText();
    QByteArray sourceStringAs8Bit = sourceString.toLocal8Bit();
    int sourceSize = sourceStringAs8Bit.size();
    char sourceCharArray[sourceSize];
    qstrcpy(sourceCharArray, sourceStringAs8Bit.data());

    QString targetString = ' ' + ui->textEdit_TargetString->toPlainText();
    QByteArray targetStringAs8Bit = targetString.toLocal8Bit();
    int targetSize = targetStringAs8Bit.size();
    char targetCharArray[targetSize];
    qstrcpy(targetCharArray, targetStringAs8Bit.data());

    //максимальная монотонная подпоследовательность
    char t[sourceSize];
    for (int i = 0; i < sourceSize; i++) {
        t[i] = sourceCharArray[i];
    }
    if (arrayHelper == nullptr)
    {
        arrayHelper = new ArrayHelper();
    }
    arrayHelper->heapSort(t, sourceSize);

    if (solver == nullptr)
    {
        solver = new SubsequenceSolver();
    }
   // QString res = solver->string_compare(sourceCharArray, targetCharArray, sourceSize, targetSize);
    QString res = solver->string_compare(sourceCharArray, t, sourceSize, sourceSize);
    ui->textEdit_Output->setText(res);
}
