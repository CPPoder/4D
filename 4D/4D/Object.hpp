#include "element.hpp"

#include "our4DVectors.hpp"


class Object : public Element
{
private:
    Vector4f mPosition;

public:
    Object();
    ~Object() override;

    void handleEvents() override;
    void update() override;
    void render() override;


};
