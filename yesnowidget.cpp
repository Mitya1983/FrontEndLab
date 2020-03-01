#include "yesnowidget.h"
#include "Wt/WCssDecorationStyle"
#include "bootstrap_config.h"

/**
 * @brief Function to emit yes clicked signal
 */
void MT::YesNoWidget::emit_yes()
{
    _yes_checked.emit();
}
/**
 * @brief Function to emit no clicked signal
 */
void MT::YesNoWidget::emit_no()
{
    _no_checked.emit();
}
/**
 * @class YesNoWidget
 * @brief Widget for getting user yes or no response
 */
MT::YesNoWidget::YesNoWidget() : Wt::WContainerWidget()
{
    setLayoutSizeAware(true);
    _yes = addWidget(std::make_unique<Wt::WRadioButton>());
    _yes->setPositionScheme(Wt::PositionScheme::Absolute);
    _yes_label = addWidget(std::make_unique<MT::Header>());
    _yes_label->setText("Yes");
    _yes_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _no = addWidget(std::make_unique<Wt::WRadioButton>());
    _no->setChecked(true);
    _no->setPositionScheme(Wt::PositionScheme::Absolute);
    _no_label = addWidget(std::make_unique<MT::Header>());
    _no_label->setText("No");
    _no_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _group = std::make_shared<Wt::WButtonGroup>();
    _group->addButton(_yes);
    _group->addButton(_no);
    setPadding(0);
    _yes->clicked().connect(this, &MT::YesNoWidget::emit_yes);
    _no->clicked().connect(this, &MT::YesNoWidget::emit_no);
}
/**
 * @brief MT::YesNoWidget::yes
 * @return Returns whether a yes button is checked
 */
bool MT::YesNoWidget::yes() const
{
    return _yes->isChecked();
}
/**
 * @brief MT::YesNoWidget::no
 * @return Returns whether a no button is checked
 */
bool MT::YesNoWidget::no() const
{
    return _no->isChecked();
}
/**
 * @brief Function to connect to yes_clicked signal
 * @return Returns reference to signal variable
 */
Wt::Signal<> &MT::YesNoWidget::yes_checked()
{
    return _yes_checked;
}
/**
 * @brief Function to connect to no_clicked signal
 * @return Returns reference to signal variable
 */
Wt::Signal<> &MT::YesNoWidget::no_checked()
{
    return _no_checked;
}
/**
 * @brief Thats an overriden function to resize content
 * @param width
 * @param height
 */
void MT::YesNoWidget::layoutSizeChanged(int width, int height)
{
    int button_width = width / 8;
    int label_width = button_width * 2;
    int first_column_pos = 10;
    _yes->setHeight(height);
    _yes->setOffsets(0, Wt::Side::Top);
    _yes->setOffsets(first_column_pos, Wt::Side::Left);
    _yes->setWidth(button_width);
    int second_column_pos = first_column_pos + button_width + 10;
    _yes_label->setHeight(height);
    _yes_label->setOffsets(0, Wt::Side::Top);
    _yes_label->setOffsets(second_column_pos, Wt::Side::Left);
    _yes_label->setWidth(label_width);
    _yes_label->setFontScaleValue(12);
    int third_column_pos = second_column_pos + label_width + 10;
    _no->setHeight(height);
    _no->setOffsets(0, Wt::Side::Top);
    _no->setOffsets(third_column_pos, Wt::Side::Left);
    _no->setWidth(button_width);
    int forth_column_pos = third_column_pos + button_width + 10;
    _no_label->setHeight(height);
    _no_label->setOffsets(0, Wt::Side::Top);
    _no_label->setOffsets(forth_column_pos, Wt::Side::Left);
    _no_label->setWidth(label_width);
    _no_label->setFontScaleValue(12);
}
