#ifndef FEESCALCULATION_H
#define FEESCALCULATION_H

#include <Wt/WApplication.h>
#include <Wt/WBorderLayout.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLabel.h>
#include <Wt/WEvent>
#include "mainpage.h"
#include "header.h"
#include "trademarkpage.h"
namespace MT {

class FeesCalculation : public Wt::WApplication
{
private:
    Wt::WBorderLayout *_layout;
    Header *_header;
    MainPage *_main_page;
    TrademarkPage *_trademark_page;
public:
    //CONSTRUCTORS
    FeesCalculation(const Wt::WEnvironment &env);
    FeesCalculation(const FeesCalculation&) = delete;
    FeesCalculation(FeesCalculation&&) = delete;
    //OPERATORS
    FeesCalculation& operator=(const FeesCalculation&) = delete;
    FeesCalculation& operator=(FeesCalculation&&) = delete;
    //SETTERS

    //GETTERS

    //FUNCTIONS
    void show_trademark_widget();
    void show_invention_widget();
    void show_utility_model_widget();
    void show_industrial_design_widget();
    //DESTRUCTOR
    ~FeesCalculation() = default;
};

} // namespace MT


#endif // FEESCALCULATION_H
