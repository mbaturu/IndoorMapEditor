#ifndef IMAGELAYER_H
#define IMAGELAYER_H

#include "../core/mapentity.h"

class QPixmap;

class ImageLayer : public MapEntity
{
    Q_OBJECT
public:
    explicit ImageLayer(QGraphicsItem *parent = 0);
    ~ImageLayer();

    bool setImage(const QString & fileName);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //io
    virtual bool load(const QJsonObject &jsonObject);
    virtual bool save(QJsonObject &jsonObject, double scale) const;
signals:

public slots:

private:
    QPixmap *m_image;
    QString m_fileName;
};

#endif // IMAGELAYER_H
