#ifndef FIELD_HPP
#define FIELD_HPP

#include <QVector>


class Cell;

#include <QObject>


class Field : public QObject
{
    Q_OBJECT
public:

    Field();

    void setSize(int width, int height);

    void winCheck();

    int width() const { return m_width; }
    int height() const { return m_height; }

    Cell *cellAt(int x, int y) const;

public slots:

    void onCellClicked(int x, int y);

signals:

    void cellClicked(int x, int y);

private:

    QVector<Cell*> m_cells;
    int m_width;
    int m_height;
};

#endif // FIELD_HPP
