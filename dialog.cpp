#include "dialog.h"
#include "ui_dialog.h"
#include "stringsolver.cpp"

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
    StringSolver *solver = new StringSolver();
    char p[] = " 243517698";
//    char t[] = " republican";  максимальная монотонная подпоследовательность


    int n = sizeof(p) / sizeof(p[0]) - 1;
    char t[n];
    for (int i = 0; i < n; i++) {
        t[i] = p[i];
    }
    heapSort(t, n);

    int res2 = solver->string_compare(p, t);
}

