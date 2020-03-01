#ifndef TRADEMARKPAGE_H
#define TRADEMARKPAGE_H
#include <Wt/WContainerWidget>
#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WComboBox>
#include <Wt/WPushButton>
#include <Wt/WRadioButton>
#include <Wt/WButtonGroup>
#include <Wt/WTextArea>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WDialog>
#include "header.h"
#include "yesnowidget.h"
namespace MT {

class TrademarkPage : public Wt::WContainerWidget
{
private:
    int spacing = 20;
    int _width;
    int _height;
    Header *_trademark_label;
    Wt::WLineEdit *_trademark_line_edit;
    Header *_number_of_classes_label;
    Wt::WComboBox *_number_of_classes;
    Header *_color_label;
    YesNoWidget *_color_yes_no;
    Header *_number_of_applicants_label;
    YesNoWidget *_number_applicants_yes_no;
    Header *_acceleration_label;
    YesNoWidget *_acceleration_yes_no;
    //Optional layout - if _acceleration_yes is set to true
    bool _acceleration;
    Header *_graphic_label;
    YesNoWidget *_graphic_yes_no;
    Header *_currency_rate_label;
    Wt::WLineEdit *_currency_rate_line_edit;
    Wt::WPushButton *_calculate;
    Wt::WTextArea *_calculation_result;
    Wt::WPushButton *_copy_to_clipboard_button;

    void _show_graphic_row();
    void _hide_graphic_row();
    void _copy_to_clipboard();

protected:
    void layoutSizeChanged(int width, int height) override;
public:
    //CONSTRUCTORS
    TrademarkPage();
    TrademarkPage(const TrademarkPage&) = delete;
    TrademarkPage(TrademarkPage&&) = delete;
    //OPERATORS
    TrademarkPage& operator=(const TrademarkPage&) = delete;
    TrademarkPage& operator=(TrademarkPage&&) = delete;
    //SETTERS

    //GETTERS

    //FUNCTIONS
    void calculate();
    //DESTRUCTOR
    ~TrademarkPage() = default;
};

} // namespace MT





#endif // TRADEMARKPAGE_H
