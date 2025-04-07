#include <QApplication>
#include <QLabel>  //QT中的标签
#include <QString> // QT中的字符串

int main(int argc,char *argv[])
{
  QApplication app(argc,argv);
  QLabel* label = new QLabel();
  QString message = QString::fromStdString("Hello Qt!");
  label->setText(message);
  label->show();
  app.exec();//执行应用
  return 0;
}