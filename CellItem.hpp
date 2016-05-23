#ifndef CELLITEM_HPP
#define CELLITEM_HPP

#include <QGraphicsItem>

class Cell;
class QGraphicsSimpleTextItem;

class CellItem : public QGraphicsItem
{
public:
    CellItem(Cell *cell, QGraphicsItem *parent = 0);

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    static const int cellSize;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Cell *m_cell;
    QGraphicsSimpleTextItem *m_text;


};

#endif // CELLITEM_HPP
