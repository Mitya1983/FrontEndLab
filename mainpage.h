#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <Wt/WContainerWidget>
#include <Wt/WLabel>
#include <Wt/WGridLayout>
#include <Wt/WPushButton>

namespace MT {

class MainPage : public Wt::WContainerWidget
{
private:
    Wt::WGridLayout *_layout;
    Wt::WPushButton *_trademark;
    Wt::WPushButton *_invention;
    Wt::WPushButton *_utility_model;
    Wt::WPushButton *_industrial_design;

    friend class FeesCalculation;
public:
    //CONSTRUCTORS
    MainPage();
    MainPage(const MainPage&) = delete;
    MainPage(MainPage&&) = delete;
    //OPERATORS
    MainPage& operator=(const MainPage&) = delete;
    MainPage& operator=(MainPage&&) = delete;
    //SETTERS

    //GETTERS

    //FUNCTIONS
    void layoutSizeChanged(int width, int height) override;
    //DESTRUCTOR
    ~MainPage() = default;
};

} // namespace MT



#endif // MAINPAGE_H
