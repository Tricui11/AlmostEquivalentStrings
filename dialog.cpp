#include "dialog.h"
#include "ui_dialog.h"
#include "basestringsolver.h"
#include "subsequencesolver.cpp"
#include "substringsolver.cpp"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}




void swap(char& a, char& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void heapify(char *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(char *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(t, sourceSize);


    BaseStringSolver *solver = new BaseStringSolver();
    QString res = solver->string_compare(sourceCharArray, targetCharArray, sourceSize, targetSize);
//    QString res = solver->string_compare(sourceCharArray, t, sourceSize, sourceSize);
    ui->textEdit_Output->setText(res);
}

