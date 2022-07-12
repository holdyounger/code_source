﻿#ifndef QFLOATWIDGET_H
#define QFLOATWIDGET_H

#include <QWidget>

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
    #pragma execution_character_set("utf-8")
#endif

const int SHADOW_WIDTH = 30;                 // 窗口阴影宽度;
const int TRIANGLE_WIDTH = 30;               // 小三角的宽度;
const int TRIANGLE_HEIGHT = 10;              // 小三角的高度;
const int BORDER_RADIUS = 15;                 // 窗口边角的弧度;


namespace Ui {
class qFloatWidget;
}

class qFloatWidget : public QWidget
{
    Q_OBJECT

public:
    qFloatWidget(QWidget *parent = nullptr);
    ~qFloatWidget();

    enum Derection{
        left,
        right,
        up,
        down
    };

    // 设置小三角起始位置;
    void setStartPos(int startX);
    // 设置小三角宽和高;
    void setTriangleInfo(int width, int height);
    // 设置小三角的位置
    void setDerection(Derection d);
    // 比起左上角的位置  用户更关心小三角的尖尖的位置 重载move以便用户更容易定位气泡框的位置
    // x,y 是气泡窗口小贱贱的坐标
    void myMove(int x, int y);

    void setWidgetIndex(int i);

protected:
    void paintEvent(QPaintEvent *);

private:
    // 小三角的偏移量;
    int m_offset;
    // 小三角的宽度;
    int m_triangleWidth;
    // 小三角高度;
    int m_triangleHeight;
    Derection derect;

    Ui::qFloatWidget *ui;
};

#endif // QFLOATWIDGET_H