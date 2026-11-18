#include "session_presentation.hpp"
#include "actor_bind.hpp"
#include "../gameplay_application/session_frontend.hpp"
#include "../gameplay_application/session_resources.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif
namespace reo::native::gameplay_presentation {
namespace {
using Vector=transform_math::Vector;
Vector point(const transform_math::Matrix& m,Vector p){const auto v=transform_math::direction(m,p);return{v.x+m[3][0],v.y+m[3][1],v.z+m[3][2]};}
transform_math::Matrix resource_inverse_bind(const transform_math::Matrix& pose){
    // 191430's finite orthogonal-scaled inverse, corresponding to the second
    // static matrix bank produced by 1D3100 for the same resource root.
    auto result=transform_math::identity();
    for(unsigned row=0;row<3;++row){const auto& axis=pose[row];
        const float norm=(axis[0]*axis[0]+axis[1]*axis[1])+axis[2]*axis[2];
        if(!(norm>0)||!std::isfinite(norm))throw std::invalid_argument("Native resource inverse bind unavailable");
        const float length=1.f/std::sqrt(norm);
        for(unsigned column=0;column<3;++column)result[column][row]=(pose[row][column]*length)*length;
        result[3][row]=(((pose[row][0]*length)*(-pose[3][0])+(pose[row][1]*length)*(-pose[3][1]))+
                        (pose[row][2]*length)*(-pose[3][2]))*length;
    }
    for(const auto& column:result)for(float v:column)if(!std::isfinite(v))throw std::invalid_argument("Native resource inverse bind unavailable");
    return result;
}
transform_math::Matrix resource_transform(const gameplay_world::ResourceModel& model){
    if(!model.base_parts||!model.base_parts->count)throw std::invalid_argument("Native resource matrix bank unavailable");
    const auto& part=model.parts[0];auto result=transform_math::identity();
    for(unsigned i=0;i<3;++i){const auto v=transform_math::direction(model.pose,{part[i][0],part[i][1],part[i][2]});
        result[i][0]=v.x;result[i][1]=v.y;result[i][2]=v.z;}
    const auto translation=transform_math::direction(model.pose,{part[3][0]-model.pulse_distance,part[3][1],part[3][2]});
    result[3][0]=translation.x+model.position.x;result[3][1]=translation.y+model.position.y;result[3][2]=translation.z+model.position.z;
    auto inverse=resource_inverse_bind(model.base_parts->poses[0]);transform_math::concatenate_left(inverse,result);
    for(const auto& column:inverse)for(float v:column)if(!std::isfinite(v))throw std::invalid_argument("Native resource draw transform unavailable");
    return inverse;
}
void window_check(void* value){
#ifdef _WIN32
    const auto window=static_cast<HWND>(value);DWORD process{};
    if(!window||!IsWindow(window)||!GetWindowThreadProcessId(window,&process)||process!=GetCurrentProcessId())throw std::invalid_argument("Native presentation window unavailable");
#else
    (void)value;throw std::invalid_argument("Native presentation platform unavailable");
#endif
}
void require_color_profiles(const ModelMesh& mesh){
    for(const auto& part:mesh.parts)if(part.render_profile){
        const auto mode=part.render_profile->color_mode;
        // 18A260 uses normalized components for any nonzero color-mode field;
        // its zero-mode conversion has different scaling and is not admitted.
        if(mode==0)throw std::invalid_argument("Native model color profile unavailable");
    }
}
bool apply_fog(Raster& raster,const gameplay_scenario::Fog& fog,const GraphicsState* graphics,bool enabled){
    if(!enabled)return raster.fog(std::nullopt);
    if(!fog.ready()){
        if(!graphics||!graphics->frontend_fog())return false;
        const auto& initial=*graphics->frontend_fog();
        return raster.fog(RasterFog{initial.near_distance,initial.far_distance,initial.color});
    }
    const auto value=prepare_scene_fog(fog.state());return value&&raster.fog(value);
}
}
transform_math::Matrix resource_model_matrix(const gameplay_world::ResourceModel& model){return resource_transform(model);}
SessionPresentation::SessionPresentation(gameplay_application::NativeSession& session,gameplay_application::SessionRooms& rooms,void* window,
    const BackgroundState& background,gameplay_scenario::CameraProjectionContext context,std::int8_t mode,std::uint32_t width,std::uint32_t height,
    const GraphicsState* graphics,const FontFace* font,const FrontendTextGate* text_gate,
    const gameplay_scenario::DisplayFadeState* display_fade,const gameplay_application::FrontendLetterbox* letterbox):
    session_(session),background_(background),graphics_(graphics),font_(font),text_gate_(text_gate),display_fade_(display_fade),letterbox_(letterbox),window_(window),raster_(width,height),mode_(mode),context_(context),binding_(mode_,context_,display_state_,raster_){
    if(bool(font_)!=bool(text_gate_))throw std::invalid_argument("Native text presentation owner unavailable");
    window_check(window_);if(!session_.open()||!session_.room()||rooms.world().get()!=&session_.world())throw std::invalid_argument("Native presentation owner unavailable");
    room_asset_=session_.room_models().asset();if(!room_asset_||!room_asset_->bytes())throw std::invalid_argument("Native room model unavailable");
    room_input_=session_.room_scene_input();if(!room_input_)throw std::invalid_argument("Native room scene unavailable");
    room_mesh_=ModelMesh::import(*room_asset_->bytes());require_color_profiles(room_mesh_);
    room_textures_=room_textures(session_.archive(),session_.room()->scenario,*room_asset_->bytes());
    if(room_mesh_.parts.size()!=room_asset_->parts())throw std::invalid_argument("Native room part identity mismatch");
    for(const auto texture:room_mesh_.material_textures)if(texture>=room_textures_.size())throw std::invalid_argument("Native room texture identity mismatch");
    if(session_.bind_room_camera(rooms,binding_)!=gameplay_application::SessionStatus::completed)throw std::invalid_argument("Native room camera binding unavailable");
}
SessionPresentation::~SessionPresentation(){if(close()==gameplay_application::SessionStatus::busy)std::terminate();}
SessionPresentation::ActorResources& SessionPresentation::actor_resources(const std::shared_ptr<const gameplay_world::ActorModelAsset>& asset){
    if(const auto found=actor_cache_.find(asset.get());found!=actor_cache_.end())return found->second;
    if(!asset||!asset->skeleton())throw std::invalid_argument("Native actor model unavailable");
    ActorResources prepared;prepared.asset=asset;prepared.mesh=ModelMesh::import(asset->bytes());require_color_profiles(prepared.mesh);
    prepared.textures=character_textures(asset->bytes());
    if(prepared.mesh.parts.size()!=asset->part_count())throw std::invalid_argument("Native actor part identity mismatch");
    for(const auto texture:prepared.mesh.material_textures)if(texture>=prepared.textures.size())throw std::invalid_argument("Native actor texture identity mismatch");
    prepared.inverse_bind=actor_inverse_bind(asset->bytes());
    if(prepared.inverse_bind.size()!=asset->skeleton()->nodes().size())throw std::invalid_argument("Native actor bind hierarchy mismatch");
    for(const auto& part:prepared.mesh.parts)for(const auto& vertex:part.vertices){
        if(vertex.influences.empty())throw std::invalid_argument("Rigid actor geometry profile unavailable");
        for(const auto& influence:vertex.influences)if(influence.joint>=prepared.inverse_bind.size())throw std::invalid_argument("Native actor joint palette unavailable");
    }
    return actor_cache_.emplace(asset.get(),std::move(prepared)).first->second;
}
SessionPresentation::ResourceGeometry& SessionPresentation::resource_geometry(const std::shared_ptr<const gameplay_world::ResourceStaticAssets>& asset){
    if(const auto found=resource_cache_.find(asset.get());found!=resource_cache_.end())return found->second;
    if(!asset||!asset->nbd())throw std::invalid_argument("Native resource geometry owner unavailable");
    ResourceGeometry prepared;prepared.asset=asset;prepared.mesh=ModelMesh::import(*asset->nbd());prepared.textures=character_textures(*asset->nbd());
    for(const auto texture:prepared.mesh.material_textures)if(texture>=prepared.textures.size())throw std::invalid_argument("Native resource texture identity mismatch");
    return resource_cache_.emplace(asset.get(),std::move(prepared)).first->second;
}
bool SessionPresentation::present(){
    if(closed_||!session_.open()||session_.world().busy()||session_.update().busy()||!raster_.ready()||session_.room_models().asset()!=room_asset_||session_.room_scene_input()!=room_input_||!session_.room_camera_bound_to(binding_))return false;
    const auto background=background_.parameter14();if(!background)return false;
    if(graphics_&&(!graphics_->color()||graphics_->color_mode()!=GraphicsColorMode::normalized))return false;
    if(graphics_&&graphics_->frontend_draw_controls()&&!graphics_->frontend_draw_controls()->supported_by_cpu())return false;
    // 18A260's normalized-color draw path builds color and alpha from each
    // vertex, rather than applying the unrelated selector-0x0E color to the
    // entire frame. In particular the real startup initializes 0x0E to zero.
    if(!raster_.global_alpha(1.f))return false;
    window_check(window_);actor_parts_submitted_=0;resource_models_submitted_=0;raster_.clear(*background);const auto& states=session_.scene_models().state();
    auto room_fog=graphics_?graphics_->option_12():std::optional<bool>{};
    for(std::size_t i=0;i<room_mesh_.parts.size();++i){
        const auto& mesh=room_mesh_.parts[i];if(mesh.render_profile)room_fog=mesh.render_profile->option_12;
        if(states.visibility[i]&0x80)throw std::invalid_argument("Room script visibility rendering unavailable");
        if(!(states.visibility[i]&1))continue;
        if(!room_fog||!apply_fog(raster_,session_.fog(),graphics_,*room_fog))return false;
        const auto& pose=states.poses[i];
        for(const auto& face:mesh.triangles){const auto vertex=[&](std::uint32_t index){const auto& v=mesh.vertices[index];
                return SurfaceVertex{point(pose,v.position),v.uv.u,v.uv.v,v.color};};
            raster_.triangle(vertex(face.a),vertex(face.b),vertex(face.c),room_textures_[room_mesh_.material_textures[face.material]]);}
    }
    for(unsigned i=0;i<gameplay_world::World::primary_capacity;++i){
        const auto actor=session_.world().primary(i);if(!actor||!actor->active||!actor->visible||actor->room!=session_.world().room)continue;
        if(!actor->model_asset||!actor->model)throw std::invalid_argument("Native visible actor geometry unavailable");
        auto& resources=actor_resources(actor->model_asset);const auto nodes=actor->model->nodes();if(nodes.size()!=resources.inverse_bind.size())throw std::invalid_argument("Native actor pose identity mismatch");
        //373630 consults the live F4 visibility byte for each model part.
        // Both owners below are the canonical field written by their actual
        // actor construction and attachment paths; absence is not visibility.
        const auto* visibility=actor->primary_state?&actor->primary_state->part_visibility:
            actor->scripted?&actor->scripted->part_visibility:nullptr;
        if(!visibility||visibility->size()<resources.mesh.parts.size())throw std::invalid_argument("Native actor part visibility unavailable");
        auto actor_fog=graphics_?graphics_->option_12():std::optional<bool>{};
        for(std::size_t part_index=0;part_index<resources.mesh.parts.size();++part_index){
            const auto& part=resources.mesh.parts[part_index];
            if(part.render_profile)actor_fog=part.render_profile->option_12;
            if(!(*visibility)[part_index])continue;
            if(!actor_fog||!apply_fog(raster_,session_.fog(),graphics_,*actor_fog))return false;
            std::vector<SurfaceVertex> vertices;vertices.reserve(part.vertices.size());
            for(const auto& v:part.vertices){Vector position{};for(const auto& influence:v.influences){const auto local=point(resources.inverse_bind[influence.joint],v.position);const auto world=point(nodes[influence.joint].world,local);
                    position.x+=world.x*influence.weight;position.y+=world.y*influence.weight;position.z+=world.z*influence.weight;}
                vertices.push_back({position,v.uv.u,v.uv.v});}
            ++actor_parts_submitted_;
            for(const auto& face:part.triangles)raster_.triangle(vertices[face.a],vertices[face.b],vertices[face.c],resources.textures[resources.mesh.material_textures[face.material]]);
        }
    }
    if(auto* resources=session_.resources()){
        if(resources->busy()||!resources->models().open())return false;
        const auto asset=resources->static_models();auto& models=resources->models();
        for(auto id=models.head();id;id=models.next(id)){
            const auto model=models.retain(id);if(!model||!model->current())return false;
            if(!model->active||!model->visible)continue;
            if(model->category!=8||model->asset_index<0||!asset||std::size_t(model->asset_index)>=asset->roots().size()||
               model->base_parts!=asset->parts(model->asset_index))throw std::invalid_argument("Native resource model identity unavailable");
            auto& geometry=resource_geometry(asset);const auto ordinal=std::size_t(model->asset_index);
            if(ordinal>=geometry.mesh.parts.size())throw std::invalid_argument("Native resource render object unavailable");
            const auto& part=geometry.mesh.parts[ordinal];
            if(std::any_of(part.vertices.begin(),part.vertices.end(),[](const auto& vertex){return !vertex.influences.empty();}))
                throw std::invalid_argument("Native skinned resource rendering unavailable");
            // 1D27D0 imports objects in physical order; an absent F0000
            // record retains the last authored selector state at import.
            std::optional<MeshRenderProfile> profile;
            for(std::size_t index=0;index<=ordinal;++index)if(geometry.mesh.parts[index].render_profile)profile=geometry.mesh.parts[index].render_profile;
            if(!profile)throw std::invalid_argument("Native resource color profile unavailable");
            if(!profile->color_mode&&std::any_of(part.vertices.begin(),part.vertices.end(),[](const auto& vertex){
                return vertex.color!=std::array<float,4>{0.f,0.f,0.f,1.f};
            }))throw std::invalid_argument("Native raw resource color profile unavailable");
            // The owned DEF resource objects use raw black vertex colors and
            // receive dynamic 6B3280 lighting. Until that lighting consumer
            // is connected, use the same neutral-light approximation as actor
            // meshes; do not turn their authored black into invisible geometry.
            if(!apply_fog(raster_,session_.fog(),graphics_,profile->option_12))return false;
            const auto matrix=resource_model_matrix(*model);
            for(const auto& face:part.triangles){const auto vertex=[&](std::uint32_t index){const auto& v=part.vertices[index];return SurfaceVertex{point(matrix,v.position),v.uv.u,v.uv.v,{1.f,1.f,1.f,v.color[3]}};};
                raster_.triangle(vertex(face.a),vertex(face.b),vertex(face.c),geometry.textures[geometry.mesh.material_textures[face.material]]);}
            ++resource_models_submitted_;
        }
    }
    if(font_&&!text_gate_->suppressed()){
        auto& cache=session_.text_cache();
        if(cache.cull()!=gameplay_scenario::TextCacheStatus::completed)return false;
        const auto records=cache.snapshot();if(!records)return false;
        for(const auto& record:*records)if(record.active){
            const auto glyphs=font_->layout(record);if(!glyphs||!raster_.text(*font_,*glyphs))return false;
        }
    }
    //1BB6E0 follows the scene/text pass. The native rectangles use the same
    // canonical callback records; presentation itself never advances them.
    if(letterbox_&&letterbox_->phase){
        const auto draw=[&](const auto& r){raster_.rectangle(r.x,r.y,r.width,r.height,r.color);};
        draw(letterbox_->top);draw(letterbox_->bottom);
    }
    if(display_fade_&&display_fade_->status){
        const float value=255.f*display_fade_->alpha;
        if(!std::isfinite(value)||value<float(std::numeric_limits<std::int32_t>::min())||value>=2147483648.f)return false;
        const auto alpha=std::uint8_t(std::int32_t(value));
        const auto& r=display_fade_->rectangle;
        raster_.rectangle(r.x,r.y,r.width,r.height,(display_fade_->color&0xffffffu)|(std::uint32_t(alpha)<<24));
    }
#ifdef _WIN32
    const auto hwnd=static_cast<HWND>(window_);RECT rect{};if(IsIconic(hwnd)||!GetClientRect(hwnd,&rect)||rect.right<=rect.left||rect.bottom<=rect.top)return false;
    const auto dc=GetDC(hwnd);if(!dc)return false;BITMAPINFO info{};info.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);info.bmiHeader.biWidth=LONG(raster_.width());info.bmiHeader.biHeight=-LONG(raster_.height());
    info.bmiHeader.biPlanes=1;info.bmiHeader.biBitCount=32;info.bmiHeader.biCompression=BI_RGB;
    const auto result=StretchDIBits(dc,0,0,rect.right-rect.left,rect.bottom-rect.top,0,0,int(raster_.width()),int(raster_.height()),raster_.pixels().data(),&info,DIB_RGB_COLORS,SRCCOPY);
    ReleaseDC(hwnd,dc);return result!=-1&&result!=0;
#else
    return false;
#endif
}
gameplay_application::SessionStatus SessionPresentation::close()noexcept{
    using Status=gameplay_application::SessionStatus;
    if(closed_)return Status::completed;const auto status=session_.unbind_room_camera(&binding_);
    // A different current binding belongs to another display; our prior one
    // has already been retired and must not be released on that owner's behalf.
    if(status==Status::busy)return status;
    if(status==Status::frame_failure&&session_.room_camera_bound_to(binding_))return Status::busy;
    closed_=true;return status==Status::missing_providers||status==Status::closed?Status::completed:status;
}
}
