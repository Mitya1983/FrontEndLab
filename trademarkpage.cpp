#include "trademarkpage.h"
#include "bootstrap_config.h"
#include <Wt/WCssDecorationStyle>
#include <Wt/WBreak>
#include <Wt/WPopupMenu>
#include "calculation.h"
#include "text_generators.h"
/**
 * @class TrademarkPage
 * @brief Main widget for Trademark calculation page
 */
MT::TrademarkPage::TrademarkPage() : Wt::WContainerWidget()
{
    setLayoutSizeAware(true);
    setPadding(20);
    setOverflow(Wt::Overflow::Scroll, Wt::Orientation::Vertical);
    setScrollVisibilityMargin(true);
    //Trademark identifier row
    _trademark_label = addWidget(std::make_unique<MT::Header>());
    _trademark_label->setText("Trademark identifier");
    _trademark_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _trademark_line_edit = addWidget(std::make_unique<Wt::WLineEdit>());
    _trademark_line_edit->setPositionScheme(Wt::PositionScheme::Absolute);
    _trademark_line_edit->setPlaceholderText("Enter trademark identifier (name, priority number, etc.)");
    //Number of classes row
    _number_of_classes_label = addWidget(std::make_unique<MT::Header>());
    _number_of_classes_label->setText("Number of classes");
    _number_of_classes_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _number_of_classes = addWidget(std::make_unique<Wt::WComboBox>());
    _number_of_classes->setPositionScheme(Wt::PositionScheme::Absolute);
    for (int i = 0; i < 45; ++i){
        _number_of_classes->addItem(std::to_string(i + 1));
    }
    //Should color be claimed row
    _color_label = addWidget(std::make_unique<MT::Header>());
    _color_label->setText("Should color be claimed?");
    _color_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _color_yes_no = addWidget(std::make_unique<MT::YesNoWidget>());
    _color_yes_no->setPositionScheme(Wt::PositionScheme::Absolute);
    //Number of applicants row
    _number_of_applicants_label = addWidget(std::make_unique<MT::Header>());
    _number_of_applicants_label->setText("Are there more than one applicant?");
    _number_of_applicants_label->setFontScaleValue(18);
    _number_of_applicants_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _number_applicants_yes_no = addWidget(std::make_unique<MT::YesNoWidget>());
    _number_applicants_yes_no->setPositionScheme(Wt::PositionScheme::Absolute);
    //Acceleration row
    _acceleration_label = addWidget(std::make_unique<MT::Header>());
    _acceleration_label->setText("Would you like to speedup registration process?");
    _acceleration_label->setFontScaleValue(22);
    _acceleration_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _acceleration_yes_no = addWidget(std::make_unique<MT::YesNoWidget>());
    _acceleration_yes_no->setPositionScheme(Wt::PositionScheme::Absolute);
    _acceleration = false;
    _acceleration_yes_no->yes_checked().connect(this, &MT::TrademarkPage::_show_graphic_row);
    _acceleration_yes_no->no_checked().connect(this, &MT::TrademarkPage::_hide_graphic_row);
    //Graphic row
    _graphic_label = nullptr;
    _graphic_yes_no = nullptr;
    //Currency rate row
    _currency_rate_label = addWidget(std::make_unique<MT::Header>());
    _currency_rate_label->setText("Indicate currency rate");
    _currency_rate_label->setPositionScheme(Wt::PositionScheme::Absolute);
    _currency_rate_line_edit = addWidget(std::make_unique<Wt::WLineEdit>());
    _currency_rate_line_edit->setPositionScheme(Wt::PositionScheme::Absolute);
    _currency_rate_line_edit->setInputMask("99.99");
    _currency_rate_line_edit->setText("27.00");
    //Calculation button
    _calculate = addWidget(std::make_unique<Wt::WPushButton>("Calculate"));
    _calculate->setPositionScheme(Wt::PositionScheme::Absolute);
    _calculate->setStyleClass(MT::Bootstrap_Styles::button_style);
    _calculate->clicked().connect(this, &MT::TrademarkPage::calculate);
    //Result field
    _calculation_result = addWidget(std::make_unique<Wt::WTextArea>());
    _calculation_result->setReadOnly(true);
    _calculation_result->setPositionScheme(Wt::PositionScheme::Absolute);
    _calculation_result->setId("result");
    //Clipboard button
    _copy_to_clipboard_button = addWidget(std::make_unique<Wt::WPushButton>("Copy to clipboard"));
    _copy_to_clipboard_button->setPositionScheme(Wt::PositionScheme::Absolute);
    _copy_to_clipboard_button->setStyleClass(MT::Bootstrap_Styles::button_style);
    _copy_to_clipboard_button->clicked().connect(this, &MT::TrademarkPage::_copy_to_clipboard);
}

void MT::TrademarkPage::calculate()
{
    bool color = _color_yes_no->yes();
    bool more_then_one_applicant = _number_applicants_yes_no->yes();
    bool acceleration = _acceleration_yes_no->yes();
    bool combined = false;
    if (acceleration){
        combined = _graphic_yes_no->yes();
    }
    float currency_rate = std::stof(_currency_rate_line_edit->text());
    std::vector<int> calculation = MT::calculateTrademark(_number_of_classes->currentIndex() + 1, currency_rate,
                                                          color, more_then_one_applicant, acceleration, combined);
    Wt::WString result = MT::trademark_calculation_EN(_trademark_line_edit->text().toUTF8(), calculation);
    _calculation_result->setText(result);
}
/**
 * @brief Shows widget to get response about whether the trademark is combined or not
 */
void MT::TrademarkPage::_show_graphic_row()
{
    if (_graphic_label == nullptr){
        _graphic_label = addWidget(std::make_unique<MT::Header>());
        _graphic_label->setText("Does trademark include graphical elements?");
        _graphic_label->setFontScaleValue(22);
        _graphic_label->animateShow(Wt::WAnimation(Wt::AnimationEffect::SlideInFromLeft));
        _graphic_label->setPositionScheme(Wt::PositionScheme::Absolute);
        _graphic_yes_no = addWidget(std::make_unique<MT::YesNoWidget>());
        _graphic_yes_no->setPositionScheme(Wt::PositionScheme::Absolute);
        _graphic_yes_no->animateShow(Wt::WAnimation(Wt::AnimationEffect::SlideInFromRight));
        _acceleration = true;
        layoutSizeChanged(_width, _height);
    }
}
/**
 * @brief Hides widget to get response about whether the trademark is combined or not
 *        Widget is deleted
 */
void MT::TrademarkPage::_hide_graphic_row()
{
    removeWidget(_graphic_label);
    removeWidget(_graphic_yes_no);
    _graphic_label = nullptr;
    _graphic_yes_no = nullptr;
    _acceleration = false;
    layoutSizeChanged(_width, _height);
}

/**
 * @brief MT::TrademarkPage::_copy_to_clipboard
 *        Copies text from _calculation_result field to clipboard
 */
void MT::TrademarkPage::_copy_to_clipboard()
{
    doJavaScript("var copyText = document.getElementById(\"result\"); "
                 "copyText.select(); "
                 "copyText.setSelectionRange(0, 99999);"
                 "document.execCommand(\"copy\");"
                 "copyText.setSelectionRange(0, 0)");
}
/**
 * @brief MT::TrademarkPage::layoutSizeChanged
 * @param width
 * @param height
 */
void MT::TrademarkPage::layoutSizeChanged(int width, int height)
{
    _width = width;
    _height = height;
    int line_height = (height - spacing * 8) / 12;
    int first_column_width = (width - spacing * 3) / 4;
    int second_column_width = (width - spacing * 3) - first_column_width;
    int first_column_pos = spacing;
    int second_column_pos = first_column_width + spacing * 2;
    int first_row_pos = spacing;
    int font_size = width / 80;
    _trademark_label->setOffsets(first_row_pos, Wt::Side::Top);
    _trademark_label->setOffsets(first_column_pos, Wt::Side::Left);
    _trademark_label->setHeight(line_height);
    _trademark_label->setWidth(first_column_width);
    _trademark_line_edit->setOffsets(padding(Wt::Side::Top), Wt::Side::Top);
    _trademark_line_edit->setOffsets(second_column_pos, Wt::Side::Left);
    _trademark_line_edit->setHeight(line_height);
    _trademark_line_edit->setWidth(second_column_width);
    _trademark_line_edit->decorationStyle().font().setSize(font_size);
    int second_row_pos = first_row_pos + line_height + spacing;
    _number_of_classes_label->setOffsets(first_column_pos, Wt::Side::Left);
    _number_of_classes_label->setOffsets(second_row_pos, Wt::Side::Top);
    _number_of_classes_label->setHeight(line_height);
    _number_of_classes_label->setWidth(first_column_width);
    _number_of_classes->setOffsets(second_column_pos, Wt::Side::Left);
    _number_of_classes->setOffsets(second_row_pos, Wt::Side::Top);
    _number_of_classes->setHeight(line_height);
    _number_of_classes->setWidth(second_column_width);
    _number_of_classes->decorationStyle().font().setSize(font_size);
    int third_row_pos = second_row_pos + line_height + spacing;
    _color_label->setOffsets(first_column_pos, Wt::Side::Left);
    _color_label->setOffsets(third_row_pos, Wt::Side::Top);
    _color_label->setHeight(line_height);
    _color_label->setWidth(first_column_width);
    _color_yes_no->setOffsets(second_column_pos, Wt::Side::Left);
    _color_yes_no->setOffsets(third_row_pos, Wt::Side::Top);
    _color_yes_no->setHeight(line_height);
    _color_yes_no->setWidth(second_column_width);
    int fourth_row_pos = third_row_pos + line_height + spacing;
    _number_of_applicants_label->setOffsets(first_column_pos, Wt::Side::Left);
    _number_of_applicants_label->setOffsets(fourth_row_pos, Wt::Side::Top);
    _number_of_applicants_label->setHeight(line_height);
    _number_of_applicants_label->setWidth(first_column_width);
    _number_applicants_yes_no->setOffsets(second_column_pos, Wt::Side::Left);
    _number_applicants_yes_no->setOffsets(fourth_row_pos, Wt::Side::Top);
    _number_applicants_yes_no->setHeight(line_height);
    _number_applicants_yes_no->setWidth(second_column_width);
    int fifth_row_pos = fourth_row_pos + line_height + spacing;
    _acceleration_label->setOffsets(first_column_pos, Wt::Side::Left);
    _acceleration_label->setOffsets(fifth_row_pos, Wt::Side::Top);
    _acceleration_label->setHeight(line_height);
    _acceleration_label->setWidth(first_column_width);
    _acceleration_yes_no->setOffsets(second_column_pos, Wt::Side::Left);
    _acceleration_yes_no->setOffsets(fifth_row_pos, Wt::Side::Top);
    _acceleration_yes_no->setHeight(line_height);
    _acceleration_yes_no->setWidth(second_column_width);
    int six_row_pos = fifth_row_pos + line_height + spacing;
    _currency_rate_label->setOffsets(first_column_pos, Wt::Side::Left);
    _currency_rate_label->setOffsets(six_row_pos, Wt::Side::Top);
    _currency_rate_label->setHeight(line_height);
    _currency_rate_label->setWidth(first_column_width);
    _currency_rate_line_edit->setOffsets(second_column_pos, Wt::Side::Left);
    _currency_rate_line_edit->setOffsets(six_row_pos, Wt::Side::Top);
    _currency_rate_line_edit->setHeight(line_height);
    _currency_rate_line_edit->setWidth(second_column_width);
    _currency_rate_line_edit->decorationStyle().font().setSize(font_size);
    int button_row_pos = six_row_pos + line_height + spacing;
    if (_acceleration){
        int sixth_row_pos = button_row_pos;
        _graphic_label->setOffsets(first_column_pos, Wt::Side::Left);
        _graphic_label->setOffsets(sixth_row_pos, Wt::Side::Top);
        _graphic_label->setHeight(line_height);
        _graphic_label->setWidth(first_column_width);
        _graphic_yes_no->setOffsets(second_column_pos, Wt::Side::Left);
        _graphic_yes_no->setOffsets(sixth_row_pos, Wt::Side::Top);
        _graphic_yes_no->setHeight(line_height);
        _graphic_yes_no->setWidth(second_column_width);
        button_row_pos = sixth_row_pos + line_height + spacing;
    }
    _calculate->setOffsets(button_row_pos, Wt::Side::Top);
    _calculate->setHeight(line_height);
    _calculate->setWidth(width - spacing * 2);
    int result_row_pos = button_row_pos + line_height + spacing;
    int result_width = width - first_column_width - spacing * 2;
    int result_height = 200;
    _calculation_result->setOffsets(first_column_pos, Wt::Side::Left);
    _calculation_result->setOffsets(result_row_pos, Wt::Side::Top);
    _calculation_result->setWidth(result_width);
    _calculation_result->setHeight(result_height);
    _copy_to_clipboard_button->setOffsets(result_width + spacing * 2, Wt::Side::Left);
    _copy_to_clipboard_button->setOffsets(result_row_pos, Wt::Side::Top);
    _copy_to_clipboard_button->setHeight(result_height);
    _copy_to_clipboard_button->setWidth(width - result_width - spacing * 3);
}
