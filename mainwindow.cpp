#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_num;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*
    QWidget* pCentralWidget=new QWidget;
    setCentralWidget(pCentralWidget);
    QVBoxLayout* pVBoxLayout=new QVBoxLayout;
    pCentralWidget->setLayout(pVBoxLayout);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->setStyleSheet(StyleHelper::getWindowStyleSheet());

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(9);
    shadowEffect->setOffset(0);
    */
    ui->setupUi(this);

    //digits
    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::OnPress);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::OnPress);

    connect(ui->pushButton_dot, &QPushButton::clicked, this, &MainWindow::Dot);

    //math operations
    connect(ui->pushButton_C, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_CE, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_plus_minus, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_sqrt, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton1x, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_sqr, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_delete, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_percent, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_plus, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_minus, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_on, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_by, &QPushButton::clicked, this, &MainWindow::Operations);
    connect(ui->pushButton_equal, &QPushButton::clicked, this, &MainWindow::Operations);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnPress()
{
    QPushButton *button = (QPushButton *)sender();
    QString value(button->text());
    if (ui->label_2->text() == '0')
    {
        ui->label_2->setText(value);
    }
    else
    {
        ui->label_2->setText(ui->label_2->text() + value);
    }
}

void MainWindow::Operations()
{
    QPushButton *button = (QPushButton *)sender();
    QString value(ui->label_2->text());
    double result = value.toDouble();
    if(button->text() == "C")
    {
        ui->label_2->setText("0");
    }
    else if(button->text() == "CE")
    {
        first_num = 0;
        ui->label->setText("");
        ui->label_2->setText("0");
    }
    else if(button->text() == "+/-")
    {
        result *= -1;
        ui->label_2->setText(value.setNum(result));
    }
    else if(button->text() == "√x")
    {
        result = sqrt(result);
        ui->label_2->setText(value.setNum(result));
    }
    else if(button->text() == "1/x")
    {
        result = 1/result;
        ui->label_2->setText(value.setNum(result));
    }
    else if(button->text() == "x^2")
    {
        result = result*result;
        ui->label_2->setText(value.setNum(result));
    }
    else if(button->text() == "←")
    {
        if(ui->label_2->text() != "0")
        {
            ui->label_2->setText(ui->label_2->text().remove(ui->label_2->text().size() - 1, 1));
        }
    }
    else if(button->text() == "%")
    {
        result = result/100;
        ui->label_2->setText(value.setNum(result));
    }
    else if(button->text() == "+")
    {
        if(ui->label->text() == "")
        {
            first_num = result;
            ui->label->setText(value.setNum(result) + " + ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("+"))
        {
            first_num = result + first_num;
            ui->label->setText(value.setNum(first_num) + " + ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("÷"))
        {
            first_num = first_num/result;
            ui->label->setText(value.setNum(first_num) + " + ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("×"))
        {
            first_num = first_num * result;
            ui->label->setText(value.setNum(first_num) + " + ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("-"))
        {
            first_num = first_num - result;
            ui->label->setText(value.setNum(first_num) + " + ");
            ui->label_2->setText("0");
        }
    }
    else if(button->text() == "-")
    {
        if(ui->label->text() == "")
        {
            first_num = result;
            ui->label->setText(value.setNum(result) + " - ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("+"))
        {
            first_num = result + first_num;
            ui->label->setText(value.setNum(first_num) + " - ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("÷"))
        {
            first_num = first_num/result;
            ui->label->setText(value.setNum(first_num) + " - ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("×"))
        {
            first_num = first_num * result;
            ui->label->setText(value.setNum(first_num) + " - ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("-"))
        {
            first_num = first_num - result;
            ui->label->setText(value.setNum(first_num) + " - ");
            ui->label_2->setText("0");
        }
    }
    else if(button->text() == "÷")
    {
        if(ui->label->text() == "")
        {
            first_num = result;
            ui->label->setText(value.setNum(result) + " ÷ ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("+"))
        {
            first_num = result + first_num;
            ui->label->setText(value.setNum(first_num) + " ÷ ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("÷"))
        {
            first_num = first_num/result;
            ui->label->setText(value.setNum(first_num) + " ÷ ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("×"))
        {
            first_num = first_num * result;
            ui->label->setText(value.setNum(first_num) + " ÷ ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("-"))
        {
            first_num = first_num - result;
            ui->label->setText(value.setNum(first_num) + " ÷ ");
            ui->label_2->setText("0");
        }
    }
    else if(button->text() == "×")
    {
        if(ui->label->text() == "")
        {
            first_num = result;
            ui->label->setText(value.setNum(result) + " × ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("+"))
        {
            first_num = result + first_num;
            ui->label->setText(value.setNum(first_num) + " × ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("÷"))
        {
            first_num = first_num/result;
            ui->label->setText(value.setNum(first_num) + " × ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("×"))
        {
            first_num = first_num * result;
            ui->label->setText(value.setNum(first_num) + " × ");
            ui->label_2->setText("0");
        }
        else if(ui->label->text().contains("-"))
        {
            first_num = first_num - result;
            ui->label->setText(value.setNum(first_num) + " × ");
            ui->label_2->setText("0");
        }
    }
    else if(button->text() == "=")
    {
        if(ui->label->text().contains("+"))
        {
            result = first_num + result;
        }
        else if(ui->label->text().contains("×"))
        {
            result = first_num * result;
        }
        else if(ui->label->text().contains("÷"))
        {
            result = first_num / result;
        }
        else if(ui->label->text().contains("-"))
        {
            result = first_num - result;
        }


        ui->label->setText("");
        ui->label_2->setText(value.setNum(result));
    }
}


void MainWindow::Dot()
{
    QPushButton *button = (QPushButton*)sender();
    QString value;
    if(button->text() == ".")
    {
        if(!ui->label_2->text().contains('.'))
        {
            value = (ui->label_2->text() + '.');
            ui->label_2->setText(value);
        }
    }
}
