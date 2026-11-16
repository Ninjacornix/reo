#include "effect_assets_reference.hpp"
#include "effect_assets_declarations.hpp"
unsigned effect_asset_checks{},effect_asset_original_calls{},effect_asset_selectors{},actor_resource_cases{};
const char* effect_archive_path;
const char* effect_voice_path;
namespace {
struct EffectAssetReference {
    s::content::Bytes model,data;
    std::shared_ptr<const reo::native::gameplay_effects::Geometry> geometry;
    std::vector<std::pair<unsigned,unsigned>> selectors;
    unsigned releases{},imports{},reads{},copies{};
    std::shared_ptr<const reo::native::afs_source_range::Archive> sound;
    std::shared_ptr<const reo::assets::Source> file;
    std::vector<std::byte> sound_bytes;
    std::vector<unsigned> installed_ports;
    unsigned requested_member{};
};
EffectAssetReference* effect_asset_reference;
struct PreparedActorResourceCase {
    std::uint16_t content{};
    std::uint8_t template_index{},slot{},previous_selected{};
    s::SceneDescriptor descriptor;
};
std::optional<PreparedActorResourceCase> prepared_actor_resource_case;
void effect_asset_check(bool value,std::source_location at=std::source_location::current()){
    ++effect_asset_checks;if(!value)throw std::runtime_error("Scenario effect asset source comparison line "+std::to_string(at.line()));
}
}
void prepare_actor_resource_case(app::OfflineApplication& application){
    auto& host=application.session();auto& resources=*host.resources();
    // An explicitly warm logical resource bank is required for a positive
    // equipment branch. Its real591C50 importer establishes the template state;
    // no test-only template or sound bytes are substituted.
    effect_asset_check(host.initialize_resources().status==app::ResourceImportStatus::completed);
    const auto& templates=resources.templates();
    const auto bytes=host.archive().read_resource(41,"objS41.nbd");effect_asset_check(bool(bytes));
    const auto models=w::ResourceStaticAssets::import_nbd(*bytes);
    std::uint16_t content{};std::uint8_t template_index{};
    for(unsigned candidate=1;candidate<500;++candidate){
        const auto selected=std::bit_cast<std::uint8_t>(templates.selector(std::int16_t(candidate)));
        if(selected>=templates.state().templates.size())continue;
        const auto kind=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(templates.state().templates[selected].encoded[14]));
        if(kind==1&&models->find(std::int16_t(candidate))>=0){content=std::uint16_t(candidate);template_index=selected;break;}
    }
    effect_asset_check(content!=0);
    const auto allocated=resources.descriptors().allocate_owned(1,content,1,templates);effect_asset_check(allocated.status==s::SceneStatus::completed&&allocated.id);
    const auto descriptor=resources.descriptors().get(*allocated.id);effect_asset_check(descriptor&&descriptor->active&&descriptor->template_index==template_index);
    const auto actor=host.world().primary(0);effect_asset_check(bool(actor));
    prepared_actor_resource_case=PreparedActorResourceCase{content,template_index,allocated.slot,actor->selected_resource,*descriptor};
    actor->selected_resource=allocated.slot;
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime*){
    auto& state=*effect_asset_reference;++effect_asset_original_calls;
    const auto a=GPR_U32(context,4),b=GPR_U32(context,5),c=GPR_U32(context,6);
    switch(context->pc){
    case 0x1cd1c0:effect_asset_check(a==0x2000||a==0x2a00);++state.releases;break;
    case 0x1af780:state.selectors.emplace_back(a,b);++effect_asset_selectors;break;
    case 0x1b2a70:effect_asset_check((a==0x400&&b==4)||(a==0x240&&b==8));SET_GPR_U32(context,2,0x800000);break;
    case 0x1ce110:
        effect_asset_check(a==41&&b==UINT32_MAX&&c==0x3b85b0&&GPR_U32(context,7)==2);
        transform_write(memory,c+0x812,std::uint16_t(state.geometry->meshes().size()));++state.imports;break;
    case 0x1aaad0:
        if(c==0x2000){effect_asset_check(std::strcmp(reinterpret_cast<const char*>(memory+a),"ef41")==0&&b==0x3b85b0&&GPR_U32(context,7)==0x10002);
            transform_write(memory,b+0x812,std::uint16_t(state.geometry->meshes().size()));}
        else effect_asset_check(c==0x2a00&&b==0x3c9230&&std::strcmp(reinterpret_cast<const char*>(memory+a),"objS41")==0&&GPR_U32(context,7)==0x10003);
        ++state.imports;break;
    case 0x10a830:
        effect_asset_check(b==0x256300||b==0x256310||b==0x256330||b==0x256248||b==0x256648||b==0x256688||b==0x740c90);
        std::snprintf(reinterpret_cast<char*>(memory+a),32,reinterpret_cast<const char*>(memory+b),int(c));break;
    case 0x107c68:std::memset(memory+a,int(b&255),c);SET_GPR_U32(context,2,a);break;
    case 0x1cc8f0:
        if(c==0x10001){effect_asset_check(std::strcmp(reinterpret_cast<const char*>(memory+a),"efdata41.bin")==0&&GPR_U32(context,7)==0);
            std::memcpy(memory+b,state.data->data(),state.data->size());SET_GPR_U32(context,2,state.data->size());++state.reads;}
        else{
            effect_asset_check(c==1&&GPR_U32(context,7)==0);
            const auto root=reo::assets::table(*state.file,0,state.file->size);
            const auto common=std::find_if(root.entries.begin(),root.entries.end(),[](const auto& entry){return entry.name=="romdata_usa.afs";});effect_asset_check(common!=root.entries.end());
            const auto table=reo::assets::table(*state.file,common->offset,common->size);
            std::string name(reinterpret_cast<const char*>(memory+a));name=name.substr(name.find_last_of("/\\")+1);
            const auto file=std::find_if(table.entries.begin(),table.entries.end(),[&](const auto& entry){return entry.name==name;});
            effect_asset_check(file!=table.entries.end()&&file->size<=2048);state.file->read(common->offset+file->offset,file->size,memory+b);SET_GPR_U32(context,2,file->size);
        }break;
    case 0x107ab0:std::memcpy(memory+a,memory+b,c);SET_GPR_U32(context,2,a);++state.copies;break;
    case 0x10afc0:std::strcpy(reinterpret_cast<char*>(memory+a),reinterpret_cast<const char*>(memory+b));SET_GPR_U32(context,2,a);break;
    case 0x10abb8:std::strcat(reinterpret_cast<char*>(memory+a),reinterpret_cast<const char*>(memory+b));SET_GPR_U32(context,2,a);break;
    case 0x1ab310:{const auto member=reo::native::gameplay_bank_loading::sound_member(reinterpret_cast<const char*>(memory+a));SET_GPR_U32(context,2,member.value_or(UINT32_MAX));break;}
    case 0x129240:{effect_asset_check(a==3);state.requested_member=b;const auto member=state.sound->member(b);effect_asset_check(member.view&&member.entry.logical_bytes);
        state.sound_bytes.resize(member.view->size());const auto read=member.view->read(0,state.sound_bytes);effect_asset_check(read.status==reo::native::resources::Status::ok&&read.bytes==state.sound_bytes.size());SET_GPR_U32(context,2,1);break;}
    case 0x129c08:effect_asset_check(a==1);SET_GPR_U32(context,2,state.sound_bytes.size()/2048);break;
    case 0x1297a0:effect_asset_check(a==1&&std::uint64_t(b)*2048==state.sound_bytes.size()&&(c&63)==0);std::memcpy(memory+c,state.sound_bytes.data(),state.sound_bytes.size());break;
    case 0x129d48:SET_GPR_U32(context,2,3);break;
    case 0x129350:effect_asset_check(a==1);break;
    case 0x1ac730:effect_asset_check(!state.sound_bytes.empty()&&std::memcmp(memory+a,state.sound_bytes.data(),state.sound_bytes.size())==0);state.installed_ports.push_back(b);break;
    case 0x5b4ce0:{PS2Runtime runtime;o2_005B4CE0_0x5b4ce0(memory,context,&runtime);return;}
    case 0x6b4ae0:{PS2Runtime runtime;o2_006B4AE0_0x6b4ae0(memory,context,&runtime);return;}
    case 0x1d3dc0:{PS2Runtime runtime;sub_001D3DC0_0x1d3dc0(memory,context,&runtime);return;}
    default:throw std::runtime_error("Unexpected scenario effect original call "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void compare_original_scenario_effect_assets(app::OfflineApplication& application){
    auto& host=application.session();EffectAssetReference source;
    source.file=std::make_shared<const reo::assets::Source>(effect_archive_path);
    source.sound=s::ActorVoiceArchiveAssets(std::make_shared<reo::assets::Source>(effect_voice_path)).sound_archive();
    source.model=host.archive().read_resource(41,"ef41.nbd");source.data=host.archive().read_resource(41,"efdata41.bin");
    source.geometry=application.startup().scenario_effect_geometry();
    effect_asset_check(source.model&&source.data&&source.geometry&&application.startup().scenario_effect_bank());
    effect_asset_reference=&source;std::vector<std::uint8_t> memory(0x2000000);effect_assets_constants(memory.data());
    transform_write(memory.data(),0x3243d7,std::uint8_t(1));transform_write(memory.data(),0x3243da,std::uint16_t(41));
    transform_write(memory.data(),0x32440c,std::uint32_t(0x1000000));
    transform_write(memory.data(),0x392690,std::uint32_t(123));transform_write(memory.data(),0x392694,std::uint32_t(456));
    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xdeadbeef);
    sub_001D1030_0x1d1030(memory.data(),&context,&runtime);
    SET_GPR_U32(&context,4,41);sub_001D0B70_0x1d0b70(memory.data(),&context,&runtime);
    effect_asset_check(context.pc==0xdeadbeef&&source.releases==2&&source.imports==2&&source.reads==1&&source.copies==1);
    const std::vector<std::pair<unsigned,unsigned>> expected{{0x15,2},{1,0},{0x12,0},{0x62,1},{0xc,0},{0x66,0},{2,0},{0x12,0},{0,0},{0x15,2},{1,0x800},{0x12,0x8000},{0xc,0},{0x66,1},{0x62,1},{0,0x20},{2,0}};
    effect_asset_check(source.selectors==expected);
    const auto* graphics=application.graphics();effect_asset_check(graphics&&graphics->format_flags()==2&&graphics->model_color()==0x800&&graphics->option_12()==true);
    const auto& controls=graphics->frontend_draw_controls();effect_asset_check(controls&&controls->selector62==1&&controls->selector66==1&&controls->selector0c==0&&controls->selector02==0&&controls->selector00==0x20);
    effect_asset_check(transform_read<std::uint16_t>(memory.data(),0x3b85b0+0x812)==source.geometry->meshes().size());
    effect_asset_check(transform_read<std::uint32_t>(memory.data(),0x392690)==0&&transform_read<std::uint32_t>(memory.data(),0x392694)==0);
    for(std::size_t index=0;index<source.data->size();++index)effect_asset_check(memory[0x3926d0+index]==std::to_integer<unsigned char>((*source.data)[index]));
    const auto actor=host.world().primary(0);effect_asset_check(bool(actor));
    const auto vm_actor=0x4a5c30u;
    transform_write(memory.data(),vm_actor+3,std::uint8_t(actor->slot));transform_write(memory.data(),vm_actor+0xb98,std::uint8_t(actor->character));
    for(const auto selected:{255u,0u}){
        transform_write(memory.data(),vm_actor+0xc7c,std::uint8_t(selected));SET_GPR_U32(&context,4,vm_actor);
        const auto before=source.installed_ports.size();sub_001D3A70_0x1d3a70(memory.data(),&context,&runtime);
        effect_asset_check(context.pc==0xdeadbeef&&source.installed_ports.size()==before);++actor_resource_cases;
    }
    SET_GPR_U32(&context,4,vm_actor);sub_001D3CA0_0x1d3ca0(memory.data(),&context,&runtime);
    effect_asset_check(context.pc==0xdeadbeef&&source.installed_ports==std::vector<unsigned>{unsigned(actor->slot)+4});
    effect_asset_check(application.audio()&&application.audio()->owner()->state(unsigned(actor->slot)+4)==reo::native::gameplay_audio::Status::completed);++actor_resource_cases;

    // Actual positive1D3A70 through the enclosing startup caller. The controlled
    // logical descriptor is public native state; all WMD/SND bytes remain the
    // actual File1 archive contents and the real owners perform their reads.
    auto& resources=*host.resources();effect_asset_check(prepared_actor_resource_case.has_value());const auto& prepared=*prepared_actor_resource_case;
    const auto content=prepared.content;const auto template_index=prepared.template_index;
    effect_asset_check(actor->weapon_programs&&actor->selected_resource==prepared.slot);
    effect_asset_check(application.audio()->owner()->state(unsigned(actor->slot)+8)==reo::native::gameplay_audio::Status::completed);
    transform_write(memory.data(),vm_actor+0xc7c,prepared.slot);
    const auto vm_descriptor=0x3c5630u+60u*prepared.slot;
    transform_write(memory.data(),vm_descriptor,std::uint8_t(1));transform_write(memory.data(),vm_descriptor+0x2b,template_index);
    transform_write(memory.data(),0x74bb50u+24u*template_index+14,std::uint8_t(1));
    SET_GPR_U32(&context,4,vm_actor);sub_001D3A70_0x1d3a70(memory.data(),&context,&runtime);
    effect_asset_check(context.pc==0xdeadbeef&&source.installed_ports==std::vector<unsigned>{unsigned(actor->slot)+4,unsigned(actor->slot)+8});
    const auto original_program=reo::native::animation::WeaponProgramBank::import(std::as_bytes(std::span(memory).subspan(0x749180+2048*actor->slot,2048)));
    for(unsigned selection=0;selection<10;++selection){
        const auto& expected_program=original_program->selection(selection);const auto& actual_program=actor->weapon_programs->selection(selection);
        effect_asset_check(expected_program.kind==actual_program.kind);
        if(!expected_program.program)continue;
        effect_asset_check(bool(actual_program.program));
        for(unsigned part=0;part<6;++part){
            const auto& expected_part=expected_program.program->parts[part];const auto& actual_part=actual_program.program->parts[part];effect_asset_check(bool(expected_part)==bool(actual_part));
            if(!expected_part)continue;
            for(unsigned channel=0;channel<6;++channel){
                const auto& expected_curve=expected_part->curves[channel];const auto& actual_curve=actual_part->curves[channel];effect_asset_check(bool(expected_curve)==bool(actual_curve));
                if(!expected_curve)continue;
                effect_asset_check(expected_curve->keys().size()==actual_curve->keys().size());
                for(unsigned key=0;key<expected_curve->keys().size();++key)effect_asset_check(expected_curve->keys()[key].time==actual_curve->keys()[key].time&&std::bit_cast<std::uint32_t>(expected_curve->keys()[key].value)==std::bit_cast<std::uint32_t>(actual_curve->keys()[key].value));
            }
        }
    }
    // Link the real WMD selector consumer to a current concrete resource model.
    const auto model=resources.factory().create(content);effect_asset_check(model.status==w::ResourceModelStatus::completed&&model.model);
    auto attached=prepared.descriptor;attached.primary=model.model;attached.parameter=1;
    effect_asset_check(bool(resources.descriptors().load(prepared.slot,attached)));model.model->resource_slot=prepared.slot;
    w::WorldResourcePrograms programs(host.world(),resources.descriptors());programs.select(*actor,0);
    effect_asset_check(model.model->program.source==actor->weapon_programs&&model.model->program.selection_index.has_value());
    attached.primary.reset();effect_asset_check(bool(resources.descriptors().load(prepared.slot,attached)));
    effect_asset_check(resources.models().retire(model.id)==w::ResourceModelStatus::completed);actor->selected_resource=prepared.previous_selected;++actor_resource_cases;
    effect_asset_reference=nullptr;
}
