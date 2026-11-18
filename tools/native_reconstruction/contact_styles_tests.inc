#include "game/native/gameplay_effects/contact_styles.hpp"
#include "game/native/gameplay_world/contact_weapon_effects.hpp"
#include <algorithm>
unsigned contact_cases{},contact_frames{},contact_selectors{},contact_channels{},contact_refusals{};
namespace contact_fixture {
std::string general_context;
bool selector_capture{},channel_capture{true};unsigned selected_resource{},source_channels{};std::optional<m::Matrix> channel_basis;m::Vector channel_point;unsigned channel_mode{};
struct Capture final:e::WorkBackend {
    std::vector<e::WorkRequest> requests;
    bool bound_to(const reo::native::gameplay_session::Random&)const noexcept override{return true;}
    bool admitted()const noexcept override{return true;}
    e::WorkCreated create(const e::WorkRequest& request)noexcept override{requests.push_back(request);return{e::WorkStatus::resource_missing,{}};}
    e::WorkStatus refresh_companion()noexcept override{return e::WorkStatus::unavailable;}
};
struct Work final:e::WorkBackend {
    e::PeriodicVisuals& owner;std::vector<reo::native::gameplay_actors::EntityId> created;
    explicit Work(e::PeriodicVisuals& value):owner(value){}
    bool bound_to(const reo::native::gameplay_session::Random& random)const noexcept override{return owner.bound_to(random);}
    bool admitted()const noexcept override{return owner.admitted();}
    e::WorkCreated create(const e::WorkRequest& request)noexcept override{auto result=owner.create(request);if(result.edit)created.push_back(result.edit->identity());return result;}
    e::WorkStatus refresh_companion()noexcept override{return owner.refresh_companion();}
};
struct Channels final:e::ContactStyleChannels {
    unsigned count{},mode{},variant{};std::optional<m::Matrix> basis;m::Vector point;
    e::WorkStatus create(const std::optional<m::Matrix>& b,m::Vector p,std::uint32_t m,std::uint32_t v)override{++count;basis=b;point=p;mode=m;variant=v;return e::WorkStatus::completed;}
};
void compare_piece(const e::PieceOutput& piece,unsigned child,const std::uint8_t* memory,const e::EffectBank& bank){
    check(piece.visible);check(piece.flags==get<unsigned>(memory,child+4));check(piece.root==get<std::uint16_t>(memory,child+2)&&piece.material==memory[child+1]);
    check(std::memcmp(&piece.parameters.translation,memory+child+0x24,12)==0);
    check(std::memcmp(piece.parameters.rotation.data(),memory+child+0x30,6)==0);
    check(std::memcmp(&piece.parameters.scale,memory+child+0x38,12)==0);
    const auto* mesh=bank.geometry().material(piece.root,piece.material);check(mesh!=nullptr);
    for(std::size_t j=0;j<mesh->indices.size();++j)check(std::bit_cast<unsigned>(piece.material_values[j])==get<unsigned>(memory,child+0x50+unsigned(4*j)));
}
}
bool contact_style_port(std::uint8_t* memory,R5900Context* context){
    using namespace contact_fixture;
    if(context->pc==0x652390&&selector_capture){selected_resource=GPR_U32(context,4);SET_GPR_U32(context,2,0);return true;}
    if(context->pc!=0x571ec0||!channel_capture)return false;
    check(GPR_U32(context,4)==0x20000&&!GPR_U32(context,8));++source_channels;channel_mode=GPR_U32(context,7);
    const auto raw=GPR_U32(context,5);channel_basis=raw?std::optional(get<m::Matrix>(memory,raw)):std::nullopt;channel_point=get<m::Vector>(memory,GPR_U32(context,6));return true;
}
void compare_contact_styles(const std::vector<std::vector<std::byte>>& corpus,std::uint8_t* memory){
    using namespace contact_fixture;owned_constants(memory);
    // Exhaust the signed source discriminator through the complete constructor,
    // with only the allocation outcome controlled to a natural no-effect miss.
    selector_capture=true;
    for(unsigned raw=0;raw<65536;++raw){
        const auto discriminator=std::bit_cast<std::int16_t>(std::uint16_t(raw));put(memory,0x2000c,discriminator);selected_resource=0;
        call(memory,0x5dd270,{0x20000,0,0x21000,5});Capture capture;
        check(e::construct_contact_style(capture,{discriminator,nullptr},{},{},5)==e::WorkStatus::completed);
        check(capture.requests.size()==1&&capture.requests[0].effect==selected_resource);++contact_selectors;
    }
    selector_capture=false;
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        for(unsigned style=0;style<9;++style)for(unsigned pose=0;pose<4;++pose){
            general_context="contact asset="+std::to_string(asset)+" style="+std::to_string(style)+" pose="+std::to_string(pose);
            std::fill_n(memory,0x2000000,0);prepare(memory,corpus[asset],corpus[asset+1]);const auto identity=m::identity();put(memory,0x294e00,identity);
            auto basis=identity;basis[0]={.5f,.125f,-.25f,0};basis[1]={.25f,1.5f,.375f,0};basis[2]={-.125f,.25f,.75f,0};basis[3]={-13,7.25f,3.75f,1};
            const std::optional<m::Matrix> optional_basis=(pose&1)||style==6?std::optional(basis):std::nullopt;
            const m::Vector point{float(style*7)-31.f,-7.25f,float(pose)*3.5f};put(memory,0x21000,point);put(memory,0x22000,basis);put(memory,0x2000c,std::int16_t(pose<2?0:-3));
            reo::native::gameplay_session::Random random({std::uint16_t(style*19+pose),std::uint16_t(0x193b^pose),std::uint8_t(pose)});
            put(memory,0x3244b0,random.state().primary);put(memory,0x3244b8,random.state().secondary);memory[0x2b8de8]=random.state().observed;
            e::PeriodicVisuals owner(bank,random);Work work(owner);Channels channels;source_channels=0;
            call(memory,0x5dd270,{0x20000,optional_basis?0x22000u:0u,0x21000,style});
            check(e::construct_contact_style(work,{std::int16_t(pose<2?0:-3),&channels},optional_basis,point,style)==e::WorkStatus::completed);
            check(channels.count==source_channels);contact_channels+=channels.count;
            if(channels.count){check(channels.mode==channel_mode&&!channels.variant);check(channels.basis==channel_basis);check(std::memcmp(&channels.point,&channel_point,12)==0);}
            std::vector<unsigned> original;for(auto at=get<unsigned>(memory,0x3b5848);at;at=get<unsigned>(memory,at+0x20))original.push_back(at);
            check(original.size()==work.created.size()&&original.size()==owner.size());
            std::reverse(work.created.begin(),work.created.end());
            for(unsigned tick=0;tick<4096&&owner.size();++tick){
                for(auto at:original)if(memory[at])call(memory,0x653010,{at});
                const auto report=owner.update({12,-3,27});check(report.status==e::VisualStatus::completed);++contact_frames;
                const auto frame=owner.retain();check(bool(frame));std::size_t cursor{};
                for(std::size_t j=0;j<original.size();++j){const auto at=original[j];if(!memory[at])continue;
                    check(cursor<frame->visuals.size());const auto& output=frame->visuals[cursor++];check(output.id==work.created[j]&&output.visible==bool(memory[at+1])&&output.pieces.size()==memory[at+0x31]);
                    if(!output.visible)continue;
                    for(std::size_t i=0;i<output.pieces.size();++i){const auto& piece=output.pieces[i];check(piece.visible==bool(memory[at+0xf4+i]));if(piece.visible)compare_piece(piece,get<unsigned>(memory,at+0x134+unsigned(4*i)),memory,*bank);}
                }
                check(cursor==frame->visuals.size());check(random.state().primary==get<std::uint16_t>(memory,0x3244b0)&&random.state().secondary==get<std::uint16_t>(memory,0x3244b8)&&random.state().observed==memory[0x2b8de8]);check(tick+1<4096);
            }
            check(owner.size()==0&&owner.piece_count()==0);owner.close();++contact_cases;
        }
    }
    Capture capture;
    check(e::construct_contact_style(capture,{},m::identity(),{},5)==e::WorkStatus::unavailable);
    check(e::construct_contact_style(capture,{},m::identity(),{},3)==e::WorkStatus::unavailable);
    check(e::construct_contact_style(capture,{},m::identity(),{},7)==e::WorkStatus::unavailable);
    check(e::construct_contact_style(capture,{0,nullptr},{},{},6)==e::WorkStatus::unavailable);
    for(unsigned style:{9u,256u,0xffffffffu})check(e::construct_contact_style(capture,{},{},{},style)==e::WorkStatus::completed);
    check(capture.requests.empty());contact_refusals+=4;
    // Style6's first allocation may consume the last slot. Its second normal
    // effect is still attempted after a natural miss, with no rollback.
    for(unsigned asset=0;asset<corpus.size();asset+=2)for(unsigned free_slots:{0u,1u,2u}){
        const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        std::fill_n(memory,0x2000000,0);prepare(memory,corpus[asset],corpus[asset+1]);put(memory,0x294e00,m::identity());put(memory,0x22000,m::identity());put(memory,0x21000,m::Vector{});
        reo::native::gameplay_session::Random random;random.restore({});e::PeriodicVisuals owner(bank,random);Work work(owner);
        for(unsigned i=0;i<168-free_slots;++i){
            call(memory,0x6525c0,{0x22000,0x21000,1,36,0,0x1a193});check(owner.create({m::identity(),m::Vector{},0,36,1,0x1a193,e::WorkUpdate::ordinary}).status==e::WorkStatus::completed);
        }
        call(memory,0x5dd270,{0x20000,0x22000,0x21000,6});check(e::construct_contact_style(work,{},m::identity(),{},6)==e::WorkStatus::completed);
        const auto used=bank->geometry().resolve(14)?free_slots:0u;
        if(owner.size()!=168-free_slots+used||work.created.size()!=used||get<std::uint16_t>(memory,0x3b5828)!=free_slots-used)
            throw std::runtime_error("Contact capacity asset="+std::to_string(asset)+" free="+std::to_string(free_slots)+" native="+std::to_string(owner.size())+" new="+std::to_string(work.created.size())+" original_free="+std::to_string(get<std::uint16_t>(memory,0x3b5828)));
        check(random.state().primary==get<std::uint16_t>(memory,0x3244b0)&&random.state().secondary==get<std::uint16_t>(memory,0x3244b8)&&random.state().observed==memory[0x2b8de8]);owner.close();++contact_cases;
    }
}
