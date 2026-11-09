#include "entity.hpp"
#include <iostream>
#include <stdexcept>
namespace g=reo::native::gameplay_actors;
unsigned checks{};
void require(bool value){++checks;if(!value)throw std::runtime_error("Native entity ownership check "+std::to_string(checks));}
struct Actor final:g::Entity {
    unsigned* destroyed{};g::EntityStore* store{};g::EntityId self;bool check_unpublished{};
    explicit Actor(unsigned& count):destroyed(&count){}
    ~Actor()override{
        ++*destroyed;
        if(check_unpublished && store->acquire(self))std::terminate();
    }
};
int main()try{
    unsigned destroyed{};g::EntityId old;
    {
        g::EntityStore world({2,2}),foreign({2,2});
        require(world.create({}).status==g::EntityStatus::invalid);
        auto first=world.create(std::make_unique<Actor>(destroyed));old=first.id;
        require(first.status==g::EntityStatus::completed && bool(first.id));require(world.size()==1);
        require(!foreign.acquire(first.id));require(foreign.retire(first.id)==g::EntityStatus::foreign_or_stale);
        require(!world.acquire({}));
        auto lease=world.acquire(first.id);require(bool(lease));
        auto* actor=static_cast<Actor*>(lease.get());actor->store=&world;actor->self=first.id;actor->check_unpublished=true;
        require(world.retire(first.id)==g::EntityStatus::completed);require(!world.acquire(first.id));require(world.size()==0);require(destroyed==0);
        auto next=world.create(std::make_unique<Actor>(destroyed));require(next.status==g::EntityStatus::completed && next.id!=first.id);
        require(world.retire(first.id)==g::EntityStatus::foreign_or_stale);lease.reset();require(destroyed==1);
        require(world.retire(next.id)==g::EntityStatus::completed);require(destroyed==2);
        auto last=world.create(std::make_unique<Actor>(destroyed));require(last.status==g::EntityStatus::completed);
        require(world.retire(last.id)==g::EntityStatus::completed);
        auto final=world.create(std::make_unique<Actor>(destroyed));require(final.status==g::EntityStatus::completed);
        require(world.identities()==std::vector<g::EntityId>{final.id});
        auto full=world.create(std::make_unique<Actor>(destroyed));require(full.status==g::EntityStatus::full && !full.id);
        require(world.retire(final.id)==g::EntityStatus::completed);
        require(world.create(std::make_unique<Actor>(destroyed)).status==g::EntityStatus::full); // both slots exhausted
        auto alien=foreign.create(std::make_unique<Actor>(destroyed));require(!world.acquire(alien.id));
        auto held=foreign.acquire(alien.id);const auto before=destroyed;foreign.shutdown();require(foreign.size()==0 && foreign.identities().empty());
        require(!foreign.acquire(alien.id) && !world.acquire(alien.id));require(destroyed==before);
        require(foreign.retire(alien.id)==g::EntityStatus::closed);require(foreign.create(std::make_unique<Actor>(destroyed)).status==g::EntityStatus::closed);
        held.reset();require(destroyed==before+2);
    }
    g::EntityStore replacement({1,1});auto fresh=replacement.create(std::make_unique<Actor>(destroyed));
    require(!replacement.acquire(old) && old!=fresh.id);
    for(unsigned i=0;i<1024;++i){g::EntityStore another({1,1});require(!another.acquire(fresh.id));}
    bool invalid{};try{g::EntityStore bad({0,1});}catch(const std::invalid_argument&){invalid=true;}require(invalid);
    std::cout<<"{\"checks\":"<<checks<<",\"status\":\"passed\",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
