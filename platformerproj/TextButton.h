#ifndef TEXTBUTTON_H_INCLUDED
#define TEXTBUTTON_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class TextButton{
private:
    sf::Text button;
    sf::FloatRect collision;
    sf::Color defaultColor;
    sf::Color hoverColor;
    bool mouseClicked;
public:
    TextButton(const sf::Vector2f& position,
               const sf::Color& defaultClr,
               const sf::Color& hoverClr,
               const wchar_t* text,
               const int& fontSize);

    bool pollClicked();
    bool isHovering();
    void draw();

    //setters:

    void setPosition(const float& x, const float& y);
    void setHoverColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& pos);
    void setColor(const sf::Color& color);
    void setFont(const sf::Font& font);
    void setText(const wchar_t* text);
    void setWasClicked(bool c);

    //getters:
    sf::FloatRect getCollision();
    sf::Color getDefaultColor();
    sf::Vector2f getPosition();
    sf::Color getHoverColor();
    const sf::Font* getFont();
    std::wstring getText();
    bool getWasClicked();
};

#endif // TEXTBUTTON_H_INCLUDED
