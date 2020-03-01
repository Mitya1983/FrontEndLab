#include "mainpage.h"
#include <Wt/WColor>
#include <Wt/WCssDecorationStyle>
#include <Wt/WEnvironment>
#include "bootstrap_config.h"
/**
 * @class MainPage
 * @brief Main page layout
 */
MT::MainPage::MainPage() : Wt::WContainerWidget()
{
    setLayoutSizeAware(true);
    _layout = setLayout(std::make_unique<Wt::WGridLayout>());
    _trademark = _layout->addWidget(std::make_unique<Wt::WPushButton>("Trademark"), 0, 0);
    _trademark->setStyleClass(MT::Bootstrap_Styles::button_style);
    _invention = _layout->addWidget(std::make_unique<Wt::WPushButton>("Invention"), 0, 1);
    _invention->setStyleClass(MT::Bootstrap_Styles::button_style);
    _utility_model = _layout->addWidget(std::make_unique<Wt::WPushButton>("Utility\nmodel"), 1, 0);
    _utility_model->setStyleClass(MT::Bootstrap_Styles::button_style);
    _industrial_design = _layout->addWidget(std::make_unique<Wt::WPushButton>("Industrial\ndesign"), 1, 1);
    _industrial_design->setStyleClass(MT::Bootstrap_Styles::button_style);
}
/**
 * @brief MT::MainPage::layoutSizeChanged
 * @param width
 * @param height
 */
void MT::MainPage::layoutSizeChanged(int width, int height)
{
    int size_for_font_calculation = height / 20;
    int button_width = width / 2;
    int button_height = height / 2;
    _trademark->decorationStyle().font().setSize(size_for_font_calculation);
    _trademark->setWidth(button_width);
    _trademark->setHeight(button_height);
    _invention->decorationStyle().font().setSize(size_for_font_calculation);
    _invention->setWidth(button_width);
    _invention->setHeight(button_height);
    _utility_model->decorationStyle().font().setSize(size_for_font_calculation);
    _utility_model->setWidth(button_width);
    _utility_model->setHeight(button_height);
    _industrial_design->decorationStyle().font().setSize(size_for_font_calculation);
    _industrial_design->setWidth(button_width);
    _industrial_design->setHeight(button_height);
}
