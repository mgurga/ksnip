/*
 * Copyright (C) 2017 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef PAINTERBASEITEM_H
#define PAINTERBASEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>

class PainterBaseItem :  public QGraphicsItem
{
    static int mOrder;

public:
    enum {
        Type = UserType + 1
    };

    enum PaintItemShape {
        Path,
        Rect,
        Circle,
        Text
    };

public:
    PainterBaseItem(PaintItemShape shape, const QPen &attributes);
    ~PainterBaseItem();
    virtual int type() const override;
    virtual QRectF boundingRect() const override = 0;
    virtual void addPoint(const QPointF &pos, bool modifier = 0) = 0;
    virtual void moveTo(const QPointF &newPos) = 0;
    virtual bool containsRect(const QPointF &topLeft, const QSize &size) const = 0;
    virtual bool isValid() const;
    virtual QPointF position() const;
    virtual const QPen &attributes() const;
    virtual PaintItemShape ItemShape() const;
    virtual QPointF offset() const;
    virtual void setOffset(const QPointF &offset);
    virtual void setJoinStyle(Qt::PenJoinStyle join);
    virtual void setCapStyle(Qt::PenCapStyle cap);
    virtual void setOutlineStyle(Qt::PenStyle penStyle);
    virtual void setOutlineWidth(int width);
    virtual void setOutlineColor(const QColor &color);
    virtual bool selectable() const;
    virtual void setSelectable(bool enabled);
    virtual const QPen &selectColor() const;
    static int order();
    static void resetOrder();

protected:
    void paintDecoration(QPainter *painter);

private:
    PaintItemShape  mItemType;
    QPen            mAttributes;
    QPen            mSelectAttr;
    QPointF         mOffset;
};

#endif // PAINTERBASEITEM_H
