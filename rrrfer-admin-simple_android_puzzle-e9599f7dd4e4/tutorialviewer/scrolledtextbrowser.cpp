#include <QMouseEvent>
#include <QScrollBar>
#include "scrolledtextbrowser.h"

ScrolledTextBrowser::ScrolledTextBrowser(QWidget* parent)
   : QTextBrowser(parent), m_cursorPos_y(0), m_isMouseButtonPressed(false) {
}

void ScrolledTextBrowser::mousePressEvent(QMouseEvent* event) {
  m_cursorPos_y = event->pos().y();
  m_isMouseButtonPressed = true;
  QTextBrowser::mousePressEvent(event);
}

void ScrolledTextBrowser::mouseMoveEvent(QMouseEvent* event) {
  if (m_isMouseButtonPressed == false)
    return;

  int distance = event->pos().y() - m_cursorPos_y;

  QScrollBar* vScroll = this->verticalScrollBar();
  if (vScroll == nullptr)
    return;

  int scrollValue = vScroll->value();

  vScroll->setValue(scrollValue - distance);
  m_cursorPos_y = event->pos().y();
  QTextBrowser::mouseMoveEvent(event);
}

void ScrolledTextBrowser::mouseReleaseEvent(QMouseEvent* event) {
  m_isMouseButtonPressed = false;
  QTextBrowser::mouseReleaseEvent(event);
}
