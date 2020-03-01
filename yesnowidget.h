#ifndef YESNOWIDGET_H
#define YESNOWIDGET_H

#include <Wt/WContainerWidget>
#include <Wt/WHBoxLayout>
#include <Wt/WRadioButton>
#include <Wt/WButtonGroup>
#include <Wt/WSignal>
#include "header.h"
namespace MT {
//Widget to hendle yes/no response
class YesNoWidget : public Wt::WContainerWidget
{
private:

    Wt::WRadioButton *_yes;
    Wt::WRadioButton *_no;
    Header *_yes_label;
    Header *_no_label;
    std::shared_ptr<Wt::WButtonGroup> _group;
    Wt::WContainerWidget *_spacer;
    Wt::Signal<> _yes_checked;
    Wt::Signal<> _no_checked;
    void emit_yes();
    void emit_no();
public:
    //CONSTRUCTORS
    YesNoWidget();
    YesNoWidget(const YesNoWidget&) = delete;
    YesNoWidget(YesNoWidget&&) = delete;
    //OPERATORS
    YesNoWidget& operator=(const YesNoWidget&) = delete;
    YesNoWidget& operator=(YesNoWidget&&) = delete;
    //SETTERS

    //GETTERS
    bool yes() const;
    bool no() const;
    //FUNCTIONS

    //SIGNALS
    Wt::Signal<> &yes_checked();
    Wt::Signal<> &no_checked();
    //DESTRUCTOR
    ~YesNoWidget() = default;

    // WWidget interface
protected:
    void layoutSizeChanged(int width, int height) override;
};

} // namespace MT

#endif // YESNOWIDGET_H
