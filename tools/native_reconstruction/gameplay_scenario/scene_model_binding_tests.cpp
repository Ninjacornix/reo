#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_scenario/scene_model_bindings.hpp"
#include "original_models.cpp"
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace a=reo::native::gameplay_actors;
namespace r=reo::native::gameplay_collision::room_objects;
namespace {
std::size_t checks{},calls{},binding_cases{},lifetime_cases{};
void check(bool value,const std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Model binding check "+std::to_string(checks)+" "+at.file_name()+":"+std::to_string(at.line()));
}
std::uint32_t next(std::uint32_t& seed){seed=seed*1664525u+1013904223u;return seed;}
vm::ModelMatrix arbitrary(std::uint32_t& seed){vm::ModelMatrix m;for(auto& col:m)for(auto& f:col)f=std::bit_cast<float>(next(seed));return m;}
vm::SceneModelState initial(std::uint32_t seed){vm::SceneModelState s;for(auto& m:s.poses)m=arbitrary(seed);for(auto& w:s.styles)w=next(seed);for(auto& b:s.visibility)b=std::uint8_t(next(seed));return s;}
vm::ModelMatrix object_pose(const r::ObjectInstance& o){const auto& b=o.basis;const auto& w=o.pose_w;return {{{b.x.x,b.x.y,b.x.z,w[0]},{b.y.x,b.y.y,b.y.z,w[1]},{b.z.x,b.z.y,b.z.z,w[2]},{b.translation.x,b.translation.y,b.translation.z,w[3]}}};}
void call(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram,std::uint32_t slot,std::uint32_t target=0){R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,slot);SET_GPR_U32(&c,5,target);SET_GPR_U32(&c,31,0xdeadbeef);fn(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++calls;}
void compare_mask(const vm::SceneModelBindings& binding,const std::vector<std::uint8_t>& ram){const auto mask=binding.mask();check(std::memcmp(mask.data(),ram.data()+0x4a1b60,16)==0);}
}
void original_transform_port(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unexpected child of complete binding helper");}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);std::uint32_t seed=0x12345678;
    for(unsigned slot=0;slot<128;++slot)for(unsigned variant=0;variant<4;++variant){
        auto state=initial(next(seed));vm::RoomModelRemap remap{};remap[0]=std::uint8_t(slot);vm::SceneModels models(state,remap);a::EntityStore scene;vm::SceneModelBindings binding(models,scene);
        std::memset(ram.data()+0x4a1b60,0,16);std::memset(ram.data()+0x4a1b70,0,512);std::memcpy(ram.data()+0x49fa10,state.poses.data(),8192);const auto expected=state.poses[slot];
        auto object=std::make_unique<r::ObjectInstance>();const auto created=scene.create(std::move(object));check(bool(created.id));const auto live=std::dynamic_pointer_cast<r::ObjectInstance>(scene.acquire(created.id));
        call(o2_005D8280_0x5d8280,ram,slot,0x600000);binding.bind(std::uint8_t(slot),created.id);check(binding.healthy());check(binding.target(std::uint8_t(slot))==created.id);compare_mask(binding,ram);
        const auto copied=object_pose(*live);check(std::memcmp(copied.data(),ram.data()+0x600000,64)==0);check(std::memcmp(copied.data(),expected.data(),64)==0);
        live->basis.translation={float(slot+variant),-3.25f,999.5f};live->pose_w[variant]=std::bit_cast<float>(0x7fc01234u+slot);
        const auto changed=object_pose(*live);std::memcpy(ram.data()+0x600000,changed.data(),64);const auto view=binding.live_pose(std::uint8_t(slot));check(bool(view));check(std::memcmp(view->data(),ram.data()+0x600000,64)==0);
        check(std::memcmp(models.state().poses[slot].data(),expected.data(),64)==0);
        call(o2_005D8300_0x5d8300,ram,slot);binding.unbind(std::uint8_t(slot));compare_mask(binding,ram);check(!binding.target(std::uint8_t(slot)));check(transform_read<std::uint32_t>(ram.data(),0x4a1b70+4*slot)==0);
        binding.retain_pose_full(std::uint8_t(slot),live->basis,live->pose_w);check(binding.healthy());check(std::memcmp(models.state().poses[slot].data(),changed.data(),64)==0);
        auto matrix=std::make_shared<vm::ModelMatrix>();std::memcpy(ram.data()+0x49fa10+64*slot,changed.data(),64);
        call(o2_005D8280_0x5d8280,ram,slot,0x610000);check(binding.bind_pose(std::uint8_t(slot),matrix));compare_mask(binding,ram);check(std::memcmp(matrix->data(),ram.data()+0x610000,64)==0);
        (*matrix)[0][0]=std::bit_cast<float>(0x80000000u|slot);std::memcpy(ram.data()+0x610000,matrix->data(),64);const auto mutable_view=binding.live_pose(std::uint8_t(slot));check(mutable_view&&std::memcmp(mutable_view->data(),ram.data()+0x610000,64)==0);
        call(o2_005D8300_0x5d8300,ram,slot);binding.unbind(std::uint8_t(slot));compare_mask(binding,ram);check(binding.close()==vm::ModelBindingError::none);++binding_cases;
    }
    // Strong leases retain storage, while generation validation refuses an old
    // identity rather than reading a replacement in the same physical slot.
    {vm::RoomModelRemap remap{};vm::SceneModels models(initial(1),remap);a::EntityStore scene({1});vm::SceneModelBindings binding(models,scene);const auto id=scene.create(std::make_unique<r::ObjectInstance>()).id;
        std::weak_ptr<a::Entity> weak=scene.acquire(id);binding.bind(0,id);check(binding.healthy());check(scene.retire(id)==a::EntityStatus::completed);check(!weak.expired());
        const auto replacement=scene.create(std::make_unique<r::ObjectInstance>()).id;check(replacement&&replacement!=id);check(!binding.live_pose(0));check(binding.failure().code==vm::ModelBindingError::foreign_or_stale);binding.unbind(0);check(weak.expired());check(binding.mask()[0]==0);++lifetime_cases;
    }
    for(unsigned kind=0;kind<5;++kind){vm::RoomModelRemap remap{};vm::SceneModels models(initial(kind),remap);a::EntityStore scene,other;vm::SceneModelBindings binding(models,scene);const auto before=models.state();
        if(kind==0)binding.bind(0,other.create(std::make_unique<r::ObjectInstance>()).id);
        if(kind==1)binding.bind(0,scene.create(std::make_unique<a::Entity>()).id);
        if(kind==2)binding.bind(255,scene.create(std::make_unique<r::ObjectInstance>()).id);
        if(kind==3)check(!binding.bind_pose(0,{}));
        if(kind==4)binding.retain_pose(0,{});
        check(!binding.healthy());check(binding.mask()==std::array<std::uint32_t,4>{});check(std::memcmp(&before,&models.state(),sizeof before)==0);++lifetime_cases;
    }
    {vm::RoomModelRemap remap{};remap[3]=255;vm::SceneModels models(initial(7),remap);a::EntityStore scene;vm::SceneModelBindings binding(models,scene);
        check(binding.admit(3,r::ModelOperation::create));binding.mark(255);check(binding.healthy());check((models.state().styles[31]>>24)==1);check(!binding.admit(3,r::ModelOperation::retire));check(binding.failure().code==vm::ModelBindingError::invalid_slot);check(binding.mask()==std::array<std::uint32_t,4>{});++lifetime_cases;
    }
    {vm::RoomModelRemap remap{};vm::SceneModels models(initial(8),remap);a::EntityStore scene;vm::SceneModelBindings binding(models,scene);bool called=false,refused=false;
        std::shared_ptr<vm::ModelMatrix> old(new vm::ModelMatrix,[&](auto* p){called=true;refused=!binding.bind_pose(1,std::make_shared<vm::ModelMatrix>());delete p;});check(binding.bind_pose(0,old));old.reset();binding.unbind(0);check(called&&refused);check(binding.failure().code==vm::ModelBindingError::busy);check(binding.mask()==std::array<std::uint32_t,4>{});++lifetime_cases;
    }
    {vm::RoomModelRemap remap{};vm::SceneModels models(initial(9),remap);a::EntityStore scene;vm::SceneModelBindings binding(models,scene);bool sealed=false;
        std::shared_ptr<vm::ModelMatrix> old(new vm::ModelMatrix,[&](auto* p){sealed=binding.mask()==std::array<std::uint32_t,4>{}&&!binding.bind_pose(1,std::make_shared<vm::ModelMatrix>());delete p;});check(binding.bind_pose(0,old));old.reset();check(binding.close()==vm::ModelBindingError::closed);check(sealed);check(binding.mask()==std::array<std::uint32_t,4>{});++lifetime_cases;
    }
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<calls<<",\"binding_cases\":"<<binding_cases<<",\"lifetime_cases\":"<<lifetime_cases<<"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
