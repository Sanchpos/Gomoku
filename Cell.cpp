#include <QDebug>

#include "Cell.hpp"

#include "Field.hpp"

Cell::Cell(int x, int y):
    QObject()
{
    m_x = x;
    m_y = y;

    m_state = StateIdle;
}

void Cell::open()
{
    emit clicked(x(), y());
}

void Cell::setState(State newState)
{
    if (m_state == newState)
    {
        return;
    }
    m_state = newState;
}


