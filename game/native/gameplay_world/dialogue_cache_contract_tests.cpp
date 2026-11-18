#include "cached_dialogue_presentation.hpp"
#include <iostream>
#include <stdexcept>
using namespace reo::native;
namespace {
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue cache contract");}
gameplay_world::Profile profile(){gameplay_world::Profile value;value.layouts.push_back({});return value;}
}
int main()try{
    namespace w=gameplay_world;namespace s=gameplay_scenario;
    w::World world(profile(),std::make_shared<w::Session>()),other(profile(),std::make_shared<w::Session>());
    s::TextCache cache;w::DialogueVisibilityInputs visibility;
    w::CachedDialoguePresentation presentation(world,cache,visibility);
    const std::array text{std::byte{'A'},std::byte{'B'}};
    check(presentation.bound_to(world)&&!presentation.bound_to(other));
    check(!presentation.draw(305,320,text,128)&&!presentation.erase(text));
    check(!presentation.suppressed());visibility.enabled=0;
    check(presentation.suppressed()==false);visibility.enabled=1;
    check(!presentation.suppressed());visibility.mode=2;world.session().inventory_owner=0;
    check(presentation.suppressed()==false);world.session().inventory_owner=1;
    check(presentation.suppressed()==true);visibility.mode=0;
    check(presentation.suppressed()==false);
    cache.reset();check(presentation.draw(305,321,text,91));
    const auto retained=cache.snapshot();check(retained&&(*retained)[0].active&&(*retained)[0].x==304&&(*retained)[0].y==320&&(*retained)[0].alpha==91);
    check(presentation.erase(text)&&!(*cache.snapshot())[0].active&&(*retained)[0].active);
    check(presentation.draw(17,320,text,33)&&(*cache.snapshot())[0].alpha==33);
    cache.reset();check(!(*cache.snapshot())[0].active&&(*retained)[0].alpha==91);
    check(world.close()==w::Status::completed);
    check(!presentation.bound_to(world)&&!presentation.draw(0,0,text,128)&&!presentation.erase(text)&&!presentation.suppressed());
    std::cout<<"Dialogue cache contract passed "<<checks<<" checks\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
