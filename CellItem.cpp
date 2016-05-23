#include "CellItem.hpp"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSimpleTextItem>
#include <QPainter>

#include "Cell.hpp"

const int CellItem::cellSize = 32;

CellItem::CellItem(Cell *cell, QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    m_cell = cell;
    m_text = new QGraphicsSimpleTextItem(this);
    QFont f = m_text->font();
    f.setPixelSize(cellSize - 4);
    m_text->setFont(f);
}

QRectF CellItem::boundingRect() const
{
    return QRectF(0, 0, cellSize, cellSize);
}

void CellItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    painter->drawRect(0, 0, cellSize, cellSize);
    switch (m_cell->state()) {
    case Cell::StateX:
        m_text->setText("X");
        m_text->setPos((cellSize - m_text->boundingRect().width())/2, (cellSize - m_text->boundingRect().height())/2);
        break;
    case Cell::State0:
        m_text->setText("0");
        m_text->setPos((cellSize - m_text->boundingRect().width())/2, (cellSize - m_text->boundingRect().height())/2);
        break;
    }
}

void CellItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
}

void CellItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_cell->open();
    update();
}
