#include "body.hpp"


Body::Body(float x, float y, float width, float height)
    : x(x)
    , y(y)
    , width(width)
    , height(height)
{}
Body::~Body() {

}

//SDL_FPoint Body::getPosition() const {
//    return SDL_FPoint{ m_x, m_y };
//};

 
//float Body::width() {
//    return m_width;
//}
//
//float Body::hieght() {
//    return m_height;
//}
//
//float Body::posX() {
//    return m_x;
//}
//
//float Body::posY() {
//    return m_y;
//}
//
//void Body::posX(float _x) {
//    m_x += _x;
//}
//
//void Body::updatePosY(float _y) {
//    m_y += _y;
//}
//
//
//void Body::posX(float _x) {
//    m_x = _x;
//}
//
//void Body::posY(float _y) {
//    m_y = _y;
//}

/*void Body::updatePosX(float _x) {
    m_x += _x;
}

void Body::updatePosY(float _y) {
    m_y += _y;
}


void Body::setPosX(float _x) {
    m_x = _x;
}

void Body::setPosY(float _y) {
    m_y = _y;
}
*/