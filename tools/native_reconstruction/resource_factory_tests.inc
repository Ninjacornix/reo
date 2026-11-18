#include "game/native/gameplay_world/resource_factory.hpp"
#include <set>
unsigned factory_cases{},factory_visible{},factory_missing_geometry{},factory_passes{},factory_refusals{};
std::vector<std::vector<std::byte>> factory_load(const char* path,unsigned expected){
    std::ifstream input(path,std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);
                check(count==expected);std::vector<std::vector<std::byte>> result;
    for(unsigned i=0;i<count;++i){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);
                check(size&&size<0x400000);result.emplace_back(size);input.read(reinterpret_cast<char*>(result.back().data()),size);
                check(bool(input));}return result;
}
void compare_resource_factory(const char* static_path,const char* templates_path,std::vector<std::uint8_t>& ram){
    namespace g=reo::native::gameplay_world;
    auto assets=factory_load(static_path,16),template_banks=factory_load(templates_path,5);auto* memory=ram.data();
    // Controlled six-part root covers the shared part5/correction matrix; the
    // stock inputs above remain separately identified in the receipt.
    std::vector<std::byte> controlled(0x40+12+16+7*268);
    const auto write=[&]<class T>(std::vector<std::byte>& b,unsigned at,T value){std::memcpy(b.data()+at,&value,sizeof value);};
    write(controlled,0x24,0x40u);write(controlled,0x28,unsigned(controlled.size()-0x40));
    write(controlled,0x40,0xc0000000u);write(controlled,0x44,8u);write(controlled,0x48,unsigned(controlled.size()-0x40));
    write(controlled,0x50,1u);write(controlled,0x54,16u);
    for(unsigned i=0;i<7;++i){const unsigned at=0x40+28+268*i;write(controlled,at,i?0x40000002u:0x40000001u);write(controlled,at+4,1u);write(controlled,at+8,268u);const auto node=at+12;
        write(controlled,node,i);write(controlled,node+4,i?std::int32_t(i-1):-1);write(controlled,node+8,i<6?std::int32_t(i+1):-1);write(controlled,node+12,std::int32_t(-1));write(controlled,node+0x40,std::int32_t(-1));write(controlled,node+0x44,42u);write(controlled,node+0x80,m::identity());
        for(unsigned lane=0;lane<3;++lane){write(controlled,node+0x10+4*lane,1.f);write(controlled,node+0x30+4*lane,float(i*3+lane));}
    }
    assets.push_back(std::move(controlled));
    std::vector<std::byte> profiles(32+6*24);write(profiles,0,3u);write(profiles,4,6u);write(profiles,16,32u);
    for(unsigned i=0;i<6;++i){write(profiles,32+24*i+18,std::uint16_t(42+i));profiles[32+24*i+20]=std::byte(i<5?i:255);}
    template_banks.push_back(std::move(profiles));
    for(const auto& bytes:assets){
        const auto cache=g::ResourceStaticAssets::import_nbd(bytes);std::fill(ram.begin(),ram.end(),0);owned_constants(memory);put(memory,0x294e00,m::identity());unsigned offset{},length{};std::memcpy(&offset,bytes.data()+0x24,4);std::memcpy(&length,bytes.data()+0x28,4);std::memcpy(memory+0x100000,bytes.data()+offset,length);put(memory,0x32440c,0x400000u);call(memory,0x1d3100,{0x70000,0x100000});
                check(!allocated);
        for(const auto& template_bytes:template_banks){
            s::ResourceTemplates templates;
                check(templates.load(template_bytes));std::fill_n(memory+0x74bb50,129*24,0);std::fill_n(memory+0x74b940,129*4,0);std::fill_n(memory+0x74c770,128*4,0);std::fill_n(memory+0x74c970,384*2,0);std::fill_n(memory+0x74b6e0,600,255);put(memory,0x74ccf0,std::uint16_t(0));std::memcpy(memory+0x100000,template_bytes.data(),template_bytes.size());call(memory,0x5921d0,{0x100000});
            auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);s::SceneResources resources;g::ResourceModels models;g::ResourceFrames frames(world,resources,models,nullptr,{},&templates);g::ResourceFactory factory(models,frames,templates,cache);call(memory,0x590be0);
            std::set<std::uint16_t> contents;for(unsigned i=0;i<256;++i)contents.insert(std::uint16_t(i));for(const auto& root:cache->roots())contents.insert(std::bit_cast<std::uint16_t>(root.content));for(const auto& row:templates.state().templates){std::uint16_t content{};std::memcpy(&content,row.encoded.data()+18,2);contents.insert(content);}contents.insert(0x7fff);contents.insert(0xffff);contents.insert(0x1000);
            const auto admitted=[&](std::uint16_t content){const auto index=cache->find(std::bit_cast<std::int16_t>(content));if(index>=0&&!cache->roots()[unsigned(index)].admitted_parts)return false;switch(content){case 0x75:case 0x135:case 0x1d:case 0x1c:case 0x3200:case 0x72:return false;default:break;}const auto selector=std::bit_cast<std::uint8_t>(templates.selector(std::bit_cast<std::int16_t>(content)));const auto callback=selector==255?0:std::to_integer<unsigned>(templates.state().templates[selector].encoded[20]);return callback<=3;};
            const auto compare_model=[&](const g::ResourceModel& model,unsigned raw){
                const auto address=[&](const g::ResourceModelId& id){const auto slot=models.physical_slot(id);return slot?0x3f4010u+0x250u**slot:0u;};const auto id=models.identity_of(model);
                check(address(models.head())==get<unsigned>(memory,0x3b5708)&&address(models.tail())==get<unsigned>(memory,0x3b5710));
                check(address(models.previous(id))==get<unsigned>(memory,raw+0x1c)&&address(models.next(id))==get<unsigned>(memory,raw+0x20));
                if(model.active!=bool(memory[raw])||model.visible!=bool(memory[raw+1])||model.category!=memory[raw+2]||model.physical_slot!=memory[raw+6])throw std::runtime_error("Factory header content="+std::to_string(model.content_id)+" slot="+std::to_string(model.physical_slot)+" original_slot="+std::to_string(memory[raw+6])+" visible="+std::to_string(model.visible)+" original_visible="+std::to_string(memory[raw+1]));
                check(model.content_id==get<std::uint16_t>(memory,raw+0x36)&&model.draw_tag==get<std::uint16_t>(memory,raw+0x238)&&model.asset_index==get<std::int16_t>(memory,raw+0x242));
                check(model.flags==get<unsigned>(memory,raw+0x23c));
                check(std::memcmp(&model.pose,memory+raw+0x1c0,64)==0&&std::memcmp(&model.position,memory+raw+0x200,12)==0&&std::memcmp(&model.axis_scale,memory+raw+0x22c,12)==0&&std::memcmp(model.angles.data(),memory+raw+0x21c,6)==0);
                check(std::memcmp(model.parts.data(),memory+raw+0x40,6*64)==0&&std::memcmp(model.part_enabled.data(),memory+raw+0x30,6)==0&&(&model.correction==&model.parts[5]));
                const auto callback=get<unsigned>(memory,raw+0x14);
                check((callback==0x6b45c0&&bool(std::dynamic_pointer_cast<g::WeaponModelWork>(model.work)))||(callback==0x5932f0&&bool(std::dynamic_pointer_cast<g::CommonModelWork>(model.work)))||(callback==0x593550&&bool(std::dynamic_pointer_cast<g::DelayedResourceWork>(model.work))));
                check(get<unsigned>(memory,raw+0x18)==0x371ef0);
            };
            for(auto content:contents){
                if(!admitted(content)){const auto before=models.available();const auto refused=factory.create(content);
                check(refused.status==g::ResourceModelStatus::unavailable&&!refused.id&&!refused.model&&models.available()==before);++factory_refusals;continue;}
                const auto original=call(memory,0x591230,{std::uint32_t(content)|0xa5000000u,17});const auto native=factory.create(content,17);
                check(native.status==g::ResourceModelStatus::completed&&GPR_U32(&original,2));const auto raw=GPR_U32(&original,2);compare_model(*native.model,raw);
                check(get<std::uint16_t>(memory,0x3b5700)==models.available());if(native.model->asset_index<0)++factory_missing_geometry;else ++factory_visible;
                call(memory,0x590ea0);const auto pass=models.update(false);
                check(pass.status==g::ResourceModelStatus::completed&&pass.called==1);compare_model(*native.model,raw);++factory_passes;
                call(memory,0x590d80,{raw});
                check(models.retire(native.id)==g::ResourceModelStatus::completed&&!native.model->current());++factory_cases;
            }
            std::uint16_t supported{};bool found{};for(auto content:contents)if(admitted(content)){supported=content;found=true;break;}check(found);
            std::vector<g::ResourceModelCreated> filled;for(unsigned i=0;i<64;++i){const auto original=call(memory,0x591230,{supported});auto native=factory.create(supported);
                check(native.status==g::ResourceModelStatus::completed&&GPR_U32(&original,2));compare_model(*native.model,GPR_U32(&original,2));filled.push_back(std::move(native));++factory_cases;}
            const auto exhausted=call(memory,0x591230,{0x75});
                check(GPR_U32(&exhausted,2)==0&&factory.create(0x75).status==g::ResourceModelStatus::full);call(memory,0x590ea0);const auto pass=models.update(false);
                check(pass.status==g::ResourceModelStatus::completed&&pass.called==64);++factory_passes;
            check(models.close()==g::ResourceModelStatus::completed&&factory.create(supported).status==g::ResourceModelStatus::closed);for(const auto& item:filled)check(!item.model->current());
        }
    }
    const auto cache=g::ResourceStaticAssets::import_nbd(assets.back());s::ResourceTemplates templates,foreign_templates;s::SceneResources resources;g::ResourceModels models,foreign_models;
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);g::ResourceFrames frames(world,resources,models,nullptr,{},&templates);
    const auto rejected=[&](g::ResourceModels& owner,const s::ResourceTemplates& table,std::shared_ptr<const g::ResourceStaticAssets> bank){bool refused{};try{g::ResourceFactory invalid(owner,frames,table,std::move(bank));}catch(const std::invalid_argument&){refused=true;}check(refused);++factory_refusals;};
    rejected(models,templates,{});rejected(foreign_models,templates,cache);rejected(models,foreign_templates,cache);
    g::ResourceFactory factory(models,frames,templates,cache);const auto held=factory.create(42);
                check(held.status==g::ResourceModelStatus::completed);
                check(world.close()==g::Status::completed);
                check(factory.create(42).status==g::ResourceModelStatus::closed&&models.available()==63);rejected(models,templates,cache);
                check(models.close()==g::ResourceModelStatus::completed&&!held.model->current());
}
