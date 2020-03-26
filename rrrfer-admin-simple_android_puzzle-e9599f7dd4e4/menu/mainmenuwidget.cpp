#include "mainmenuwidget.h"
#include <QGridLayout>
#include "menu/style_button/mainmenubutton.h"
#include <QSpacerItem>

MainMenuWidget::MainMenuWidget(QWidget* parent) : QWidget(parent),
  m_modeWidget(new LevelModeWidget(this)) {

  QGridLayout *layer = new QGridLayout(this);
  setLayout(layer);

  MainMenuButton *about = new MainMenuButton("About", this);
  MainMenuButton *select = new MainMenuButton("Select image", this);
  MainMenuButton *exit = new MainMenuButton("Exit", this);

  select->setIcon(QIcon(":/icons/play.ico"));
  about->setIcon(QIcon(":/icons/help.ico"));
  exit->setIcon(QIcon(":/icons/back.ico"));

  about->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  select->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  exit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 5, 0);
  layer->addWidget(m_modeWidget, 10, 0);
  layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 15, 0);
  layer->addWidget(select, 20, 0);
  layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 25, 0);
  layer->addWidget(about, 30, 0);
  layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 40, 0);
  layer->addWidget(exit, 50, 0);
  layer->addItem(new QSpacerItem(10, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 60, 0);

  layer->setSpacing(10);

  connect(about, SIGNAL(clicked()), this, SIGNAL(helpSelected()));
  connect(select, SIGNAL(clicked()), &m_imagePicker, SLOT(getImage()));
  connect(exit, SIGNAL(clicked()), this, SIGNAL(back()));
  connect(&m_imagePicker, SIGNAL(imageSelected(QImage)),
          this, SIGNAL(imageSelected(QImage)));
}

Mode MainMenuWidget::mode() {
  return m_modeWidget->mode();
}
