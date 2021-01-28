#include "laboratory.h"

#include "grimoire.h"

Laboratory::Laboratory()
{

}

void Laboratory::initTestCase()
{
    this->grimoire_ = new Grimoire{};
}
