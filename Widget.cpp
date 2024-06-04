// widget.cpp
#include "widget.h"
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    this->setFixedSize(500, 300);
    this->setWindowFlag(Qt::WindowMaximizeButtonHint, false);

    m_player = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);
    m_videoWidget = new QVideoWidget(this);
    m_videoWidget->resize(500, 260);
    m_player->setAudioOutput(m_audioOutput);
    m_player->setVideoOutput(m_videoWidget);

    QPushButton* btn1 = new QPushButton(this);
    btn1->move(200, 270);
    btn1->setText("play");
    connect(btn1, &QPushButton::clicked, [=]() {
        QString str = QFileDialog::getOpenFileName();
        m_player->setSource(QUrl(str));
        //m_player->setSource(QUrl("qrc:/pear_snow.mp3"));
        //m_player->setSource(QUrl("qrc:/output.mp4"));
        m_player->play();
        });
}

Widget::~Widget()
{

}

