// This include starts and ends inside the comparison fixture's anonymous
// namespace; original dependency definitions between them have external linkage.
constexpr std::uint32_t scene_at=0x3c5630+60*100,scene_live=0x500000;
std::vector<std::tuple<unsigned,std::uint32_t>> scene_effects;
struct SceneEntity final:reo::native::gameplay_actors::Entity {};
struct SceneLive final:vm::SceneFlagAttachment{
    std::uint32_t flags{0xa5a50000};void flag(std::uint32_t mask,bool set)noexcept override{flags=set?flags|mask:flags&~mask;}
};
struct SceneFixture final:vm::SceneEffects,vm::SceneOwners{
    vm::SceneResources resources;reo::native::gameplay_actors::EntityStore actors;
    reo::native::gameplay_actors::EntityId entity;
    vm::SceneResourceId id;std::shared_ptr<SceneLive> primary;
    std::vector<std::tuple<unsigned,std::uint32_t>> effects;
    explicit SceneFixture(unsigned profile){
        entity=actors.create(std::make_unique<SceneEntity>()).id;check(bool(entity));primary=std::make_shared<SceneLive>();
        vm::SceneDescriptor d;d.authored_id=42;d.attachment_id=19;d.active=(profile&1)?0:128;d.kind=(profile&2)?0:1;d.room=(profile&4)?10:9;
        d.instance_index=201;d.flags=0x20000001;d.parameter=-7;d.ownership_tag=(profile&8)?5:0;d.primary=(profile&8)?primary:nullptr;id=*resources.load(100,d);effects.reserve(100);
    }
    void export_original(std::vector<std::uint8_t>& ram){const auto d=*resources.get(id);
        ram[scene_at]=d.active;ram[scene_at+1]=d.room;ram[scene_at+2]=d.instance_index;ram[scene_at+3]=d.kind;
        fixture_write(ram.data(),scene_at+4,d.authored_id);fixture_write(ram.data(),scene_at+6,d.attachment_id);fixture_write(ram.data(),scene_at+24,d.flags);
        fixture_write(ram.data(),scene_at+28,d.primary?scene_live:0u);fixture_write(ram.data(),scene_at+40,d.ownership_tag);fixture_write(ram.data(),scene_at+36,d.parameter);
        fixture_write(ram.data(),scene_live+0x23c,primary->flags);scene_effects.clear();scene_effects.reserve(100);
    }
    void compare_original(const std::vector<std::uint8_t>& ram){check(resources.get(id)->flags==fixture_read<std::uint32_t>(ram.data(),scene_at+24));check(primary->flags==fixture_read<std::uint32_t>(ram.data(),scene_live+0x23c));check(effects==scene_effects);}
    vm::SceneStatus apply(vm::SceneResources&,const vm::SceneResourceId& resource,vm::SceneEffect effect,std::uint8_t index)noexcept override{
        if(resource!=id)std::terminate();
        effects.emplace_back(unsigned(effect),index);
        return vm::SceneStatus::completed;
    }
    std::optional<reo::native::gameplay_actors::EntityId> resolve(vm::SceneOwnerReference owner)noexcept override{
        if(owner.family==vm::SceneOwnerFamily::extended)effects.emplace_back(4,owner.index);
        return entity;
    }
    vm::SceneStatus detach(vm::SceneResources&,const reo::native::gameplay_actors::EntityId& actor,std::uint8_t index)noexcept override{if(actor!=entity)std::terminate();effects.emplace_back(5,index);return vm::SceneStatus::completed;}
    vm::SceneStatus refresh(vm::SceneResources&,const reo::native::gameplay_actors::EntityId& actor)noexcept override{if(actor!=entity)std::terminate();effects.emplace_back(6,0);return vm::SceneStatus::completed;}
};
} // namespace
void o2_00591620_0x591620(std::uint8_t* r,R5900Context* c,PS2Runtime*){scene_effects.emplace_back(0,r[GPR_U32(c,4)+2]);done(c);}
void o2_00591860_0x591860(std::uint8_t* r,R5900Context* c,PS2Runtime*){scene_effects.emplace_back(1,r[GPR_U32(c,4)+2]);done(c);}
void o2_005B1850_0x5b1850(std::uint8_t*,R5900Context* c,PS2Runtime*){scene_effects.emplace_back(2,GPR_U32(c,4));done(c);}
void o2_00591BE0_0x591be0(std::uint8_t*,R5900Context* c,PS2Runtime*){scene_effects.emplace_back(3,GPR_U32(c,4));done(c);}
void o2_00682F80_0x682f80(std::uint8_t*,R5900Context* c,PS2Runtime*){scene_effects.emplace_back(4,GPR_U32(c,4));SET_GPR_U32(c,2,0x600000);done(c);}
void o2_005F2180_0x5f2180(std::uint8_t*,R5900Context* c,PS2Runtime*){scene_effects.emplace_back(5,GPR_U32(c,5));done(c);}
void o2_005F2330_0x5f2330(std::uint8_t*,R5900Context* c,PS2Runtime*){scene_effects.emplace_back(6,0);done(c);}
namespace {
