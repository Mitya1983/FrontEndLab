#include "feescalculation.h"
#include <Wt/WBootstrapTheme>
#include <Wt/WEnvironment>
#include <Wt/WSignal>
/**
 * @class FeesCalculation
 * @brief Main class for web application
 * @param const Wt::WEnvironment &env
 */
MT::FeesCalculation::FeesCalculation(const Wt::WEnvironment &env) : Wt::WApplication(env)
{
    auto theme = std::make_shared<Wt::WBootstrapTheme>();
    theme->setVersion(Wt::BootstrapVersion::v3);
    wApp->setTheme(theme);
    setTitle("Fees Calculator");
    _layout = root()->setLayout(std::make_unique<Wt::WBorderLayout>());
    _layout->setSpacing(10);
    _layout->setContentsMargins(0, 0, 0, 0);
    _header = _layout->addWidget(std::make_unique<MT::Header>(), Wt::LayoutPosition::North);
    _header->setText("Choose object to calculate");
    _main_page = _layout->addWidget(std::make_unique<MT::MainPage>(), Wt::LayoutPosition::Center);
    _main_page->_trademark->clicked().connect(this, &MT::FeesCalculation::show_trademark_widget);
}
/**
 * @brief MT::FeesCalculation::show_trademark_widget
 */
void MT::FeesCalculation::show_trademark_widget()
{
    _layout->removeWidget(_main_page);
    _header->setText("Trademark");
    _trademark_page = _layout->addWidget(std::make_unique<MT::TrademarkPage>(), Wt::LayoutPosition::Center);
}
/**
 * @brief MT::FeesCalculation::show_invention_widget
 */
void MT::FeesCalculation::show_invention_widget()
{

}
/**
 * @brief MT::FeesCalculation::show_utility_model_widget
 */
void MT::FeesCalculation::show_utility_model_widget()
{

}
/**
 * @brief MT::FeesCalculation::show_industrial_design_widget
 */
void MT::FeesCalculation::show_industrial_design_widget()
{

}
