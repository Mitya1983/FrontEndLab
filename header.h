#ifndef HEADER_H
#define HEADER_H
#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WString>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>

namespace MT {

class Header : public Wt::WContainerWidget
{
private:
    int _font_scale_value;
    int _font_size;
    Wt::WText *_text;
    Wt::WVBoxLayout *_layout;
    Wt::WHBoxLayout *_text_layout;
public:
    //CONSTRUCTORS
    Header();
    Header(const Header&) = delete;
    Header(Header&&) = delete;
    //OPERATORS
    Header& operator=(const Header&) = delete;
    Header& operator=(Header&&) = delete;
    //SETTERS
    void setText(const Wt::WString &text);
    void setFontScaleValue(int newValue);
    //GETTERS
    int font_scale_value() const;
    int font_size() const;
    //FUNCTIONS
    void layoutSizeChanged(int width, int height) override;
    //DESTRUCTOR
    ~Header() = default;

};

} // namespace MT

#endif // HEADER_H
