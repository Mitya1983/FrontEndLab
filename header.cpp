#include "header.h"
#include <Wt/WCssDecorationStyle>
#include <Wt/WBorder>
#include <bootstrap_config.h>
/**
 * @brief MT::Header::Header
 */
MT::Header::Header() : Wt::WContainerWidget()
{
    setLayoutSizeAware(true);
    _font_scale_value = 15;
    _layout = setLayout(std::make_unique<Wt::WVBoxLayout>());
    _layout->setContentsMargins(0, 0, 0, 0);
    _text_layout = _layout->addLayout(std::make_unique<Wt::WHBoxLayout>(), 0, Wt::AlignmentFlag::Middle);
    _text_layout->setContentsMargins(0, 0, 0, 0);
    decorationStyle().setBackgroundColor(Wt::WColor(128, 128, 128));
    decorationStyle().setForegroundColor(Wt::WColor(255, 255, 255));
    setContentAlignment(Wt::AlignmentFlag::Center);
    _text = _text_layout->addWidget(std::make_unique<Wt::WText>());
}
/**
 * @brief MT::Header::setText
 * @param text
 */
void MT::Header::setText(const Wt::WString &text)
{
    _text->setText(text);
}
/**
 * @brief MT::Header::setFontScaleValue
 * @param int newValue
 */
void MT::Header::setFontScaleValue(int newValue)
{
    _font_scale_value = newValue;
}
/**
 * @brief MT::Header::font_scale_value
 * @return
 */
int MT::Header::font_scale_value() const
{
    return _font_scale_value;
}
/**
 * @brief MT::Header::font_size
 * @return
 */
int MT::Header::font_size() const
{
    return _font_size;
}
/**
 * @brief MT::Header::layoutSizeChanged
 * @param int w
 * @param int h
 */
void MT::Header::layoutSizeChanged(int width, [[maybe_unused]] int height)
{
    _font_size = width/_font_scale_value;
    _text->decorationStyle().font().setSize(_font_size);
}
