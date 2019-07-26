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

#ifndef SECTION_H
#define SECTION_H

#include <QFrame>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QScrollArea>
#include <QToolButton>
#include <QWidget>

class Section : public QWidget {
    Q_OBJECT
private:
    static constexpr const char* const defaultTitle = "";
    static constexpr int defaultAnimDuration = 100;

    QGridLayout* m_mainLayout;
    QToolButton* m_toggleButton;
    QFrame* m_headerLine;
    QParallelAnimationGroup* m_toggleAnimation;
    QScrollArea* m_contentArea;
    int m_animationDuration;

public:
    explicit Section(const QString &title = defaultTitle, int animationDuration = defaultAnimDuration, QWidget *parent = nullptr);
    explicit Section(QWidget *parent = nullptr);

    void setContentLayout(QLayout *contentLayout);
    void setToggleButtonStyle(const QString& style);
    void setHeaderLineStyle(const QString& style);
    void setContentAreaStyle(const QString& style);
    void setContentAreaFrameShape(const QFrame::Shape &shape);
};

#endif // SECTION_H
