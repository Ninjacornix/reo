#include "world.hpp"
#include <iostream>
#include <stdexcept>
namespace g=reo::native::gameplay_world;
std::uint32_t checks{};
void require(bool condition){++checks;if(!condition)throw std::runtime_error("Native world check "+std::to_string(checks));}
g::Profile profile(){return{{{0x100,0x10,0x20}},1,{16,2}};}
std::unique_ptr<g::Actor> actor(std::uint8_t slot,std::int16_t health=100){
    auto a=std::make_unique<g::Actor>();a->active=true;a->slot=slot;a->current=a->maximum=health;return a;
}
struct Ports:g::Services {
    std::size_t behavior{},finished{},prepared{};bool reenter{},replace{},throw_behavior{},grid{};
    g::actors::EntityId old,replacement;std::weak_ptr<g::Actor> retired;
    void begin_offline_frame(g::World&)override{}
    void run(g::Stage stage,g::World& w,g::Actor& a)override{
        const auto index=w.executing_primary();require(bool(index));
        if(stage==g::Stage::prepare_contacts){
            ++prepared;
            if(reenter){require(w.update_primary(*this).status==g::Status::busy);require(w.close()==g::Status::busy);}
        }
        if(stage==g::Stage::update_behavior){
            ++behavior;if(throw_behavior)throw std::runtime_error("declared service failure");
            if(replace && *index==0){
                require(w.retire_primary(0)==g::actors::EntityStatus::completed);require(!w.resolve(old));
                auto born=w.spawn_primary(0,actor(0,900));require(born.status==g::actors::EntityStatus::completed);replacement=born.id;
                require(replacement!=old && bool(w.resolve(replacement)));require(!retired.expired());
                require(w.spawn_primary(7,actor(7,200)).status==g::actors::EntityStatus::completed);
                a.current=77; // Mutate the passed old generation, never its replacement slot.
            }else{
                if(replace && *index==7)require(retired.expired());
                require(g::actors::adjust_health(a,5,0)==0);
                require(w.resolve(w.identity(*index))->current==a.current);
            }
        }
        if(stage==g::Stage::finish_actor)++finished;
    }
    bool remote_motion(g::World&,g::Actor&)override{return false;}
    bool find_grid(g::World&,g::Actor&,std::int8_t& selected)override{selected=1;return grid;}
    void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
    float grid_response(g::World& w,std::uint8_t selected)override{
        require(selected==1);w.primary(*w.executing_primary())->grid_response=51.25f;return 2.5f;
    }
};
struct Reenter final:g::Actor {
    g::World* world{};g::actors::EntityId self;bool* passed{};
    ~Reenter()override{
        *passed=!world->resolve(self) && world->controllers().size()==1 && world->layouts().size()==1 &&
            world->session().options.brightness==128 && world->spawn_primary(0,std::make_unique<g::Actor>()).status==g::actors::EntityStatus::closed;
    }
};
int main()try{
    auto session=std::make_shared<g::Session>();session->options.brightness=128;
    {
        g::World w(profile(),session);w.mode=1;require(session->mode==1);session->paused=true;require(w.paused);w.paused=false;
        w.selected_actor=0;require(session->selected_actor==0);w.filter_nonselected_input=true;require(session->authority_filter);w.filter_nonselected_input=false;
        w.room=3;require(session->room==3);w.room=0;
        require(!w.scenario);w.scenario=0;require(session->scenario && *session->scenario==0);
        session->scenario=0x0102;require(*w.scenario==0x0102);
        auto made=w.spawn_primary(0,actor(0));require(made.status==g::actors::EntityStatus::completed);auto a=w.resolve(made.id);require(bool(a));
        require(w.spawn_primary(0,actor(0)).status==g::actors::EntityStatus::invalid);
        w.controllers()[0].held=0x110;w.controllers()[0].analog[0]=-127;Ports p;p.reenter=true;p.grid=true;
        const auto done=w.update_primary(p);require(done.status==g::Status::completed && done.visited==1 && done.updated==1);
        require(a->current==95 && a->input.held==0x110 && a->input.pressed==0x110 && a->input.analog[0]==-127);
        require(a->grid_response==53.75f && (a->contact_flags&1));require(p.behavior==1 && p.finished==1 && !w.executing_primary());
        g::World foreign(profile(),session);require(!foreign.resolve(made.id));
        require(w.close()==g::Status::completed);require(!w.resolve(made.id) && !w.primary(0));require(a->current==95);
        require(w.update_primary(p).status==g::Status::closed);require(w.spawn_primary(0,actor(0)).status==g::actors::EntityStatus::closed);
    }
    {
        auto s=std::make_shared<g::Session>();g::World w(profile(),s);auto made=w.spawn_primary(0,actor(0));
        Ports p;p.replace=true;p.old=made.id;p.retired=w.primary(0);
        const auto done=w.update_primary(p);require(done.status==g::Status::completed && done.visited==2 && done.updated==2);
        require(p.retired.expired() && !w.resolve(made.id));require(w.resolve(p.replacement)->current==900);
        require(w.primary(7)->current==195 && p.behavior==2);require(w.selected_actor==0);
    }
    {
        auto s=std::make_shared<g::Session>();g::World w(profile(),s);require(w.spawn_primary(2,actor(2)).status==g::actors::EntityStatus::completed);
        Ports p;p.throw_behavior=true;bool failed{};try{w.update_primary(p);}catch(const std::runtime_error&){failed=true;}
        require(failed && !w.executing_primary());require(w.selected_actor==2 && w.primary(2)->response_mask==0x1ffff); // Explicit partial frame.
        require(w.close()==g::Status::completed);
    }
    {
        auto s=std::make_shared<g::Session>();s->options.controller_profile=1;g::World w(profile(),s);w.mode=1;
        require(w.spawn_primary(0,actor(0)).status==g::actors::EntityStatus::completed);Ports p;
        const auto result=w.update_primary(p);require(result.status==g::Status::input_unavailable && result.visited==1 && result.updated==0);
        require(p.prepared==1 && p.behavior==0 && w.primary(0)->response_mask==0x1ffff && !w.executing_primary());
    }
    bool teardown{};
    {
        auto s=std::make_shared<g::Session>();s->options.brightness=128;g::World w(profile(),s);auto a=std::make_unique<Reenter>();a->world=&w;a->passed=&teardown;
        auto* raw=a.get();auto made=w.spawn_primary(0,std::move(a));require(made.status==g::actors::EntityStatus::completed);raw->self=made.id;
    }
    require(teardown);
    bool invalid{};try{g::World bad(profile(),{});}catch(const std::invalid_argument&){invalid=true;}require(invalid);
    std::cout<<"{\"checks\":"<<checks<<",\"status\":\"passed\",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
