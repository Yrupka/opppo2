#include "levelmodewidget.h"
#include <QLabel>
#include <QGridLayout>

LevelModeWidget::LevelModeWidget(QWidget* parent) : QWidget (parent) {
  QGridLayout *layer = new QGridLayout(this);
  setLayout(layer);

  std::vector<ModeButton*> m_buttons = {
    new ModeButton("2x2", Mode(2,2, true), this),
    new ModeButton("3x3", Mode(3,3, true), this),
    new ModeButton("5x5", Mode(5,5, true), this),
    new ModeButton("7x7", Mode(7,7, true), this),
    new ModeButton("9x9", Mode(9,9, true), this)
  };

  QLabel *label = new QLabel("Select mode: ", this);
  layer->addWidget(label, 0, 0, 1, 4);

  for (size_t i = 0; i < m_buttons.size(); ++i) {
    layer->addWidget(m_buttons[i], 1, i);

    for (size_t j = 0; j < m_buttons.size(); ++j) {
      if (i == j)
        continue;
      connect(m_buttons[i], SIGNAL(picked_true()), m_buttons[j], SLOT(unpick()));
    }
    connect(m_buttons[i], SIGNAL(picked_true()), this, SLOT(onPick()));
  }

  m_pickedButton = m_buttons[0];
  m_pickedButton->pick(true);

  m_rotatedButton = new PickedButton("rotated?", this);
  m_rotatedButton->setIcon(QIcon(":/icons/rotate.ico"));

  layer->addWidget(m_rotatedButton, 1, m_buttons.size(), 1, 1);
}

void LevelModeWidget::onPick() {
  m_pickedButton = static_cast<ModeButton*>(sender());
}

Mode LevelModeWidget::mode() {
  Mode mode = m_pickedButton->mode();
  mode.rotated = m_rotatedButton->picked();
  return mode;
}
