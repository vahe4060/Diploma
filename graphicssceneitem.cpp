#include "graphicssceneitem.h"


QMap<SceneItem::TYPE, QString> SceneItem::types = {
    {SceneItem::TYPE::NOT,    "NOT"},
    {SceneItem::TYPE::AND,    "AND"},
    {SceneItem::TYPE::OR,     "OR"},
    {SceneItem::TYPE::XOR,    "XOR"},
    {SceneItem::TYPE::NAND,   "NAND"},
    {SceneItem::TYPE::NOR,    "NOR"},
    {SceneItem::TYPE::XNOR,   "XNOR"},
    {SceneItem::TYPE::INPUT,  "IN"},
    {SceneItem::TYPE::OUTPUT, "OUT"}
};


SceneItem::SceneItem(TYPE t, int x, int y, QGraphicsItem* parent) : QGraphicsItemGroup(parent)
   , m_t(t)
{
    QGraphicsItemGroup::setPos(x,y);
    setHandlesChildEvents(false);

    //m_pixmap = new GraphicsPixmapItem(QPixmap(":/LogicOperators/images/" + SceneItem::types[t] + ".png"), this);
}

SceneItem::~SceneItem()
{
    delete m_pixmap;

    for(Node* i : m_inputs)
    {
        delete i;
    }
    for(Node* i : m_outputs)
    {
        delete i;
    }
}

void SceneItem::highlight(QPen &pen)
{
    for(Node* i : m_inputs)
    {
        i->highlight(pen);
    }
    for(Node* i : m_outputs)
    {
        i->highlight(pen);
    }
}

void SceneItem::setPos(QPointF pos)
{
    QGraphicsItemGroup::setPos(pos);

    for(Node* i : m_inputs)
    {
        i->adjust();
    }
    for(Node* i : m_outputs)
    {
        i->adjust();
    }
}

