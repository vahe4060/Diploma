#ifndef LOGIC_OPERATOR_H
#define LOGIC_OPERATOR_H
#include <QGraphicsItemGroup>
#include "input_node.h"
#include "output_node.h"
#include "graphicspixmapitem.h"

class SceneItem: public QGraphicsItemGroup
{
public:
    enum TYPE{
        INPUT = UserType + 30,
        OUTPUT,
        NOT,
        AND,
        OR,
        XOR,
        NAND,
        NOR,
        XNOR
    };
    static QMap<TYPE, QString> types;

    explicit SceneItem(TYPE t, int x, int y, QGraphicsItem* parent=nullptr);
    explicit SceneItem(const int id, TYPE t, int x, int y, QGraphicsItem* parent=nullptr);

    virtual ~SceneItem();

    virtual void highlight(QPen& pen);
    virtual void setPos(QPointF pos);
    virtual int type() const override { return m_t; }
    virtual int id() const { return m_id; }
    virtual void execute() = 0;

protected:
    QVector<Input_Node*> m_inputs;
    QVector<Output_Node*> m_outputs;
    GraphicsPixmapItem* m_pixmap = nullptr;
    TYPE m_t;
    const int m_id;

    //static QMap<TYPE, QString> types;
};

#endif // LOGIC_OPERATOR_H
