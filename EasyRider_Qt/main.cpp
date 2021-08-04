#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsRectItem *item = new QGraphicsRectItem();
    item->setRect(0, 0, 30, 30);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(item);

    QGraphicsView *view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
