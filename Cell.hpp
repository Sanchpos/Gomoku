#ifndef CELL_HPP
#define CELL_HPP

#include <QVector>

//class Field;

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
public:
    enum State {
        StateIdle,
        StateX,
        State0,
        StateEnd
    };

    Cell(int x, int y);

    int x() const { return m_x; }
    int y() const { return m_y; }

    State state() const { return m_state; }

    void open();

    void setState(State newState);

signals:

    void clicked(int x, int y);

    void stateChanged(State newState);

private:

    int m_x;
    int m_y;
    State m_state;
};

#endif // CELL_HPP
