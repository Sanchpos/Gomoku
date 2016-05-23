#include "Field.hpp"

#include "Cell.hpp"
#include <QDebug>

Field::Field():
    QObject()
{
}

void Field::setSize(int width, int height)
{
    for (Cell *cell : m_cells) {
            delete cell;
        }
        m_cells.clear();

    m_width = width;
    m_height = height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Cell *cell = new Cell(x, y);
            connect(cell, SIGNAL(clicked(int,int)), this, SLOT(onCellClicked(int,int)));
            m_cells.append(cell);
        }
    }
}

Cell *Field::cellAt(int x, int y) const
{
    if (x < 0 || x >= m_width) {
        return 0;
    }
    if (y < 0 || y >= m_height) {
        return 0;
    }

    return m_cells.at(x + y * m_width);
}

void Field::winCheck()
{
    for (int i = 0; i < width() - 1; i++){
        for(int j = 0; j < height() - 1; j++){
            if(cellAt(i, j)->state() != Cell::StateIdle){
                if(cellAt(i, j)->state() == cellAt(i+1, j)->state() && cellAt(i+1, j)->state() == cellAt(i+2, j)->state() && cellAt(i+1, j)->state() == cellAt(i+3, j)->state() && cellAt(i+2, j)->state() == cellAt(i+4, j)->state()){
                    if(cellAt(i, j)->state() == Cell::StateX){
                        qDebug() << "win X!";
                    }
                    else {
                        qDebug() << "win 0!";
                    }
                }
                if(cellAt(i, j)->state() == cellAt(i, j+1)->state() && cellAt(i, j+1)->state() == cellAt(i, j+2)->state() && cellAt(i, j+1)->state() == cellAt(i, j+3)->state() && cellAt(i, j+2)->state() == cellAt(i, j+4)->state()){
                    if(cellAt(i, j)->state() == Cell::StateX){
                        qDebug() << "win X!";
                    }
                    else {
                        qDebug() << "win 0!";
                    }
                }
                if(cellAt(i, j)->state() == cellAt(i+1, j+1)->state() && cellAt(i+1, j+1)->state() == cellAt(i+2, j+2)->state() && cellAt(i+1, j+1)->state() == cellAt(i+3, j+3)->state() && cellAt(i+3, j+3)->state() == cellAt(i+4, j+4)->state()){
                    if(cellAt(i, j)->state() == Cell::StateX){
                        qDebug() << "win X!";
                    }
                    else {
                        qDebug() << "win 0!";
                    }
                }
                if(cellAt(i, j)->state() == cellAt(i-1, j+1)->state() && cellAt(i-1, j+1)->state() == cellAt(i-2, j+2)->state() && cellAt(i-1, j+1)->state() == cellAt(i-3, j+3)->state() && cellAt(i-3, j+3)->state() == cellAt(i-4, j+4)->state()){
                    if(cellAt(i, j)->state() == Cell::StateX){
                        qDebug() << "win X!";
                    }
                    else {
                        qDebug() << "win 0!";
                    }
                }
            }
        }
    }
}

void Field::onCellClicked(int x, int y)
{
    emit cellClicked(x, y);
    static bool Move = false;

    if(cellAt(x, y)->state() != Cell::State(0)) {
        return;
    }
    if (Move) {
        cellAt(x, y)->setState(Cell::State0);
        winCheck();
        Move = false;
    } else {
        cellAt(x, y)->setState(Cell::StateX);
        winCheck();
        Move = true;
    }
}


