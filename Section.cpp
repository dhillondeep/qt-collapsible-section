/*
    dhillondeep/qt-collapsible-section
    (c) 2016 Michael A. Voelkel - michael.alexander.voelkel@gmail.com
    (c) 2019 Deep Dhillon - deep@dhillon.io

    This file is part of dhillondeep/qt-collapsible-section.

    dhillondeep/qt-collapsible-section is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    dhillondeep/qt-collapsible-section is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with dhillondeep/qt-collapsible-section. If not, see <http://www.gnu.org/licenses/>.
*/

#include <QPropertyAnimation>

#include "Section.h"

static constexpr const char* const toggleButtonStylesheet = "QToolButton {border: none;}";

Section::Section(const QString & title, const int animationDuration, QWidget* parent)
    : QWidget(parent), m_animationDuration(animationDuration) {
    m_toggleButton = new QToolButton(this);
    m_headerLine = new QFrame(this);
    m_toggleAnimation = new QParallelAnimationGroup(this);
    m_contentArea = new QScrollArea(this);
    m_mainLayout = new QGridLayout(this);

    m_toggleButton->setStyleSheet(toggleButtonStylesheet);
    m_toggleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_toggleButton->setArrowType(Qt::ArrowType::RightArrow);
    m_toggleButton->setText(" " + title);
    m_toggleButton->setCheckable(true);
    m_toggleButton->setChecked(false);

    m_headerLine->setFrameShape(QFrame::HLine);
    m_headerLine->setFrameShadow(QFrame::Sunken);
    m_headerLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    m_contentArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // start out collapsed
    m_contentArea->setMaximumHeight(0);
    m_contentArea->setMinimumHeight(0);

    // let the entire widget grow and shrink with its content
    m_toggleAnimation->addAnimation(new QPropertyAnimation(this, "minimumHeight"));
    m_toggleAnimation->addAnimation(new QPropertyAnimation(this, "maximumHeight"));
    m_toggleAnimation->addAnimation(new QPropertyAnimation(m_contentArea, "maximumHeight"));

    m_mainLayout->setVerticalSpacing(0);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);

    int row = 0;
    m_mainLayout->addWidget(m_toggleButton, row, 0, 1, 1, Qt::AlignLeft);
    m_mainLayout->addWidget(m_headerLine, ++row, 2, 1, 1);
    m_mainLayout->addWidget(m_contentArea, row, 0, 1, 3);
    setLayout(m_mainLayout);

    QObject::connect(m_toggleButton, &QToolButton::toggled, [this](const bool checked) {
        m_toggleButton->setArrowType(checked ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);
        m_toggleAnimation->setDirection(checked ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
        m_toggleAnimation->start();
    });
}

Section::Section(QWidget *parent) : Section(defaultTitle, defaultAnimDuration, parent) {}

void Section::setContentLayout(QLayout *contentLayout) {
    delete m_contentArea->layout();
    m_contentArea->setLayout(contentLayout);

    const auto collapsedHeight = sizeHint().height() - m_contentArea->maximumHeight();
    auto contentHeight = contentLayout->sizeHint().height();

    for (int i = 0; i < m_toggleAnimation->animationCount() - 1; ++i) {
        auto sectionAnimation = dynamic_cast<QPropertyAnimation *>(m_toggleAnimation->animationAt(i));
        sectionAnimation->setDuration(m_animationDuration);
        sectionAnimation->setStartValue(collapsedHeight);
        sectionAnimation->setEndValue(collapsedHeight + contentHeight);
    }

    auto contentAnimation = dynamic_cast<QPropertyAnimation *>(m_toggleAnimation->animationAt(m_toggleAnimation->animationCount() - 1));
    contentAnimation->setDuration(m_animationDuration);
    contentAnimation->setStartValue(0);
    contentAnimation->setEndValue(contentHeight);
}

void Section::setToggleButtonStyle(const QString &style) {
    QString combined = QString(toggleButtonStylesheet) + " " + style;
    m_toggleButton->setStyleSheet(combined);
}
void Section::setHeaderLineStyle(const QString &style) {
    m_headerLine->setStyleSheet(style);
}
void Section::setContentAreaStyle(const QString &style) {
    m_contentArea->setStyleSheet(style);
}

void Section::setContentAreaFrameShape(const QFrame::Shape &shape) {
  m_contentArea->setFrameShape(shape);
}
