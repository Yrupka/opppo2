#include <QGridLayout>
#include "menu/style_button/mainmenubutton.h"
#include "scrolledtextbrowser.h"
#include "helpviewer.h"

HelpViewer::HelpViewer(QWidget *parent):
  QWidget(parent) {

  QGridLayout *layer = new QGridLayout(this);
  setLayout(layer);

  ScrolledTextBrowser *helpViewer = new ScrolledTextBrowser;
  helpViewer->setSource(QUrl("qrc:/f1-help.html"));
  helpViewer->setOpenExternalLinks(true);

  MainMenuButton *backButton = new MainMenuButton("back", this);
  backButton->setIcon(QIcon(":/icons/back.ico"));

  layer->addWidget(backButton, 1, 1);
  layer->addWidget(helpViewer, 0, 0, 1, 3);

  connect(backButton, SIGNAL(clicked(bool)), SIGNAL(back()));
}


