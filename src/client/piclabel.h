/**
* QLabel的子类，重写后实现鼠标点击即打开指定路径文件
*/

#ifndef PICLABEL_H
#define PICLABEL_H

#include <QWidget>
#include <QLabel>

class PicLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PicLabel(QWidget *parent, QString path);
private:
    QString path_;//图片路径
protected:
    virtual void mousePressEvent(QMouseEvent *ev) override;
signals:

};

#endif // PICLABEL_H
