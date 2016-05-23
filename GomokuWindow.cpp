#include "GomokuWindow.hpp"
#include "ui_GomokuWindow.h"

#include "Field.hpp"

#include "CellItem.hpp"
#include "Cell.hpp"

#include <QGLWidget>
#include <QGraphicsScene>
#include <QTimer>

static const int fieldBorderWidth = CellItem::cellSize / 2;

GomokuWindow::GomokuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GomokuWindow)
{
    ui->setupUi(this);

    m_fieldItem = new QGraphicsRectItem();

    m_gameStateText = new QGraphicsSimpleTextItem();
    QFont s = m_gameStateText->font();
    s.setPixelSize(32);
    m_gameStateText->setFont(s);
    m_gameStateText->setZValue(2);

    m_gameStateRect = new QGraphicsRectItem();
    m_gameStateRect->setZValue(1);
    m_gameStateRect->setOpacity(0.7);
    QLinearGradient gradient(0, 0, 200, m_gameStateRect->rect().height());
    gradient.setColorAt(0, QColor(00, 100, 0));
    gradient.setColorAt(1, QColor(200, 0, 150));
    m_gameStateRect->setBrush(gradient);


    m_scene = new QGraphicsScene();
    m_field = new Field();
    QGLFormat f = QGLFormat::defaultFormat();
    f.setSampleBuffers(true);
    f.setSamples(4);
    ui->graphicsView->setViewport(new QGLWidget(f));
    ui->graphicsView->setScene(m_scene);

    resizeField(8, 8);
    newGame();

    m_scene->addItem(m_fieldItem);
    m_scene->addItem(m_gameStateRect);
}

GomokuWindow::~GomokuWindow()
{
    delete ui;
}

void GomokuWindow::resizeEvent(QResizeEvent *event)
{
    QTimer::singleShot(0, this, SLOT(updateSceneScale()));
}

void GomokuWindow::updateSceneScale()
{
    ui->graphicsView->fitInView(m_scene->sceneRect(), Qt::KeepAspectRatio);
}

void GomokuWindow::newGame()
{
    m_scene->update();
}

void GomokuWindow::on_actionNewGame_triggered()
{
    newGame();
}

void GomokuWindow::resizeField(int width, int height)
{
    for (QGraphicsItem *cell : m_fieldItem->childItems()) {
        delete cell;
    }

    m_field->setSize(width, height);

    m_fieldItem->setRect(0, 0, width * CellItem::cellSize + fieldBorderWidth * 2, height * CellItem::cellSize + fieldBorderWidth * 2);

    for (int y = 0; y < m_field->height(); ++y) {
        for (int x = 0; x < m_field->width(); ++x) {
            CellItem *newItem = new CellItem(m_field->cellAt(x, y), m_fieldItem);
            newItem->setPos(x * CellItem::cellSize + fieldBorderWidth, y * CellItem::cellSize + fieldBorderWidth);
        }
    }
}

void GomokuWindow::difficultyBeginner()
{
    resizeField(8, 8);
    newGame();
    updateSceneScale();
}

void GomokuWindow::difficultyIntermediate()
{
    resizeField(16, 16);
    newGame();
    updateSceneScale();
}

void GomokuWindow::difficultyExpert()
{
    resizeField(30, 30);
    newGame();
    updateSceneScale();
}

void GomokuWindow::on_actionBeginner_triggered()
{
    difficultyBeginner();
}

void GomokuWindow::on_actionIntermediate_triggered()
{
    difficultyIntermediate();
}


void GomokuWindow::on_actionExpert_triggered()
{
    difficultyExpert();
}
