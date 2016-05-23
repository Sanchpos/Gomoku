#ifndef GOMOKUWINDOW_H
#define GOMOKUWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>

namespace Ui {
class GomokuWindow;
}

class QGraphicsScene;
class Field;
class QGraphicsSimpleTextItem;

class GomokuWindow : public QMainWindow
{
    Q_OBJECT

public:
    void newGame();

    void resizeField(int width, int height);

    explicit GomokuWindow(QWidget *parent = 0);
    ~GomokuWindow();

protected:
    void resizeEvent(QResizeEvent *event);

protected slots:
    void updateSceneScale();

private slots:
    void on_actionNewGame_triggered();

    void difficultyBeginner();
    void difficultyIntermediate();
    void difficultyExpert();

    void on_actionBeginner_triggered();

    void on_actionIntermediate_triggered();

    void on_actionExpert_triggered();


private:
    Ui::GomokuWindow *ui;
    QGraphicsScene *m_scene;
    Field *m_field;
    QGraphicsSimpleTextItem *m_gameStateText;
    QGraphicsRectItem *m_fieldItem;
    QGraphicsRectItem *m_gameStateRect;
};

#endif // GOMOKUWINDOW_H
