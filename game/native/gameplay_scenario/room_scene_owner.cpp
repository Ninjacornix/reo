#include "room_scene_owner.hpp"
#include <new>

namespace reo::native::gameplay_scenario {
namespace {
gameplay_collision::actors::Basis basis(const ModelMatrix &matrix) {
  return {{matrix[0][0], matrix[0][1], matrix[0][2]},
          {matrix[1][0], matrix[1][1], matrix[1][2]},
          {matrix[2][0], matrix[2][1], matrix[2][2]},
          {matrix[3][0], matrix[3][1], matrix[3][2]}};
}
} // namespace
RoomSceneOwner::RoomSceneOwner(std::shared_ptr<const RoomSceneInput> input,
                               std::shared_ptr<gameplay_scene::Records> records)
    : input_(std::move(input)), records_(std::move(records)) {}
RoomSceneOwner::~RoomSceneOwner() { close(); }
RoomSceneInstalled RoomSceneOwner::install(
    std::shared_ptr<const RoomSceneInput> input, SceneControls &controls,
    gameplay_collision::ownership::Proxies &proxies, SceneModels &models,
    SceneMatrixPrograms &programs, RoomSceneGlobals &globals,NoModelRepair repair) noexcept {
  using namespace gameplay_collision;
  if (!input || controls.records() != proxies.records() ||
      !programs.bound_to(controls, models))
    return {RoomSceneStatus::owner_mismatch, {}};
  if (controls.size())
    return {RoomSceneStatus::nonempty_pool, {}};
  try {
    struct Prepared {
      gameplay_scene::Record base;
      std::optional<Proxy> helper;
    };
    bool needs_absence=false;std::uint16_t absent_channels{};
    for(const auto& d:input->records())if(d.model&&d.model->slot.absent()&&(d.model->sound_resource||d.model->helper!=RoomProxyHelper::none))needs_absence=true;
    for(const auto& d:input->records())if(d.model&&d.model->slot.absent()&&(gameplay_scene::kind(d.initial.body)==0||gameplay_scene::kind(d.initial.body)==2)&&d.initial.authored_id<16)absent_channels|=std::uint16_t(std::uint16_t(1)<<d.initial.authored_id);
    if(needs_absence){
      if(repair!=NoModelRepair::authored_absent||!programs.authored_absence_reset_ready())return {RoomSceneStatus::unadmitted_model,{}};
      // The admitted stock cases cannot select alias channels9/10 through
      // either a route ID or the first-match model-to-channel mapping.
      for(const auto& d:input->records())if((gameplay_scene::kind(d.initial.body)==0||gameplay_scene::kind(d.initial.body)==2)&&(d.initial.authored_id==9||d.initial.authored_id==10))return {RoomSceneStatus::unadmitted_model,{}};
      const auto& map=input->mapping(0);
      for(unsigned i=9;i<=10;++i){bool earlier=false;for(unsigned j=0;j<i;++j)if(map[j]==map[i])earlier=true;if(!earlier)return {RoomSceneStatus::unadmitted_model,{}};}
    }
    std::vector<Prepared> prepared;
    prepared.reserve(input->records().size());
    std::size_t total = input->records().size();
    for (const auto &definition : input->records()) {
      Prepared p{definition.initial, {}};
      const auto kind = gameplay_scene::kind(p.base.body);
      if ((kind == 0 || kind == 2) &&
          (p.base.authored_id >= 16 || !programs.inspect(p.base.authored_id)))
        return {RoomSceneStatus::unadmitted_channel, {}};
      if (definition.model) {
        const auto &setup = *definition.model;
        const bool absent=setup.slot.absent()&&needs_absence;
        if(!setup.slot.slot()&&!absent&&(setup.sound_resource||setup.helper!=RoomProxyHelper::none))return {RoomSceneStatus::unadmitted_model,{}};
        if(setup.helper!=RoomProxyHelper::none){
          const auto geometry=gameplay_scene::collision_view(p.base);
          if(absent){
            if(setup.helper==RoomProxyHelper::reproject_middle){p.base.collision->bounds[1]={};p.base.collision->bounds[2]={};}
            else {Proxy empty;empty.bounds={};empty.lower=geometry.lower;empty.upper=geometry.upper;empty.kind=setup.helper==RoomProxyHelper::depth_extension?0x84:0x85;empty.query_class=1;empty.priority=geometry.priority;empty.active=setup.helper==RoomProxyHelper::depth_extension;p.helper=empty;++total;}
          }else{
            const auto pose=models.pose(setup.slot);if(!pose)return {RoomSceneStatus::unadmitted_model,{}};
            const auto b=basis(*pose);
            if(setup.helper==RoomProxyHelper::depth_extension)p.helper=ownership::depth_extension(geometry,b);
            else if(setup.helper==RoomProxyHelper::depth_sixty)p.helper=ownership::depth_sixty(geometry,b);
            else {const auto updated=ownership::reproject_middle(geometry.bounds,b);if(!updated)return {RoomSceneStatus::unsupported_numeric,{}};p.base.collision->bounds=*updated;}
            if(setup.helper!=RoomProxyHelper::reproject_middle){if(!p.helper)return {RoomSceneStatus::unsupported_numeric,{}};++total;}
          }
        }
      }
      prepared.push_back(std::move(p));
    }
    if (total > 128)
      return {RoomSceneStatus::pool_full, {}};
    auto owner = std::unique_ptr<RoomSceneOwner>(
        new RoomSceneOwner(input, controls.records()));
    if(needs_absence)owner->absent_lease_=std::shared_ptr<const AuthoredModelLease>(new AuthoredModelLease(input->model_domain_,input->mapping(1),absent_channels));
    owner->ids_.reserve(total);
    owner->definitions_.reserve(prepared.size());
    for (std::size_t i = 0; i < prepared.size(); ++i) {
      auto &p = prepared[i];
      const auto id = owner->records_->create(std::move(p.base));
      if (!id)
        return {RoomSceneStatus::pool_full, {}};
      owner->ids_.push_back(*id);
      owner->definitions_.emplace_back(*id, i);
      if (p.helper) {
        gameplay_scene::Record helper;
        helper.body = ControlOther{p.helper->kind};
        helper.counter = p.helper->priority;
        helper.enabled = p.helper->active ? 1 : 0;
        helper.source = *id;
        helper.other_content = 0;
        helper.collision = gameplay_scene::CollisionShape{
            p.helper->bounds,      p.helper->lower, p.helper->upper,
            p.helper->query_class, p.helper->busy,  p.helper->object};
        const auto child = owner->records_->create(std::move(helper));
        if (!child)
          return {RoomSceneStatus::pool_full, {}};
        owner->ids_.push_back(*child);
      }
    }
    // All native allocation, identity and arithmetic admission completed
    // before these nonthrowing side writes. The simulation owner serializes
    // the operation; no callbacks can close a borrowed owner mid-publish.
    models.authored_absence(owner->absent_lease_);
    models.room_remap(input->mapping(1));
    for (const auto &definition : input->records()) {
      const auto kind = gameplay_scene::kind(definition.initial.body);
      if (definition.model && definition.model->sound_resource)
        (void)models.sound_resource(definition.model->slot,
                                    *definition.model->sound_resource);
      if (kind == 0 || kind == 2)
        (void)programs.source_type(definition.initial.authored_id, kind);
      if (definition.room_height)
        globals.height = definition.room_height;
    }
    return {RoomSceneStatus::completed, std::move(owner)};
  } catch (const std::bad_alloc &) {
    return {RoomSceneStatus::no_memory, {}};
  } catch (const std::exception &) {
    return {RoomSceneStatus::unsupported_numeric, {}};
  }
}
const RoomProxyDefinition *
RoomSceneOwner::definition(const gameplay_scene::RecordId &id) const noexcept {
  if (!records_->acquire(id))
    return nullptr;
  for (const auto &[record, index] : definitions_)
    if (record == id)
      return &input_->records()[index];
  return nullptr;
}
bool RoomSceneOwner::bound_to(const RoomSceneInput& input,const SceneControls& controls)const noexcept {
  return input_.get()==&input&&records_==controls.records();
}
void RoomSceneOwner::close() noexcept {
  for (auto it = ids_.rbegin(); it != ids_.rend(); ++it)
    (void)records_->retire(*it);
  ids_.clear();
  definitions_.clear();
  absent_lease_.reset();
  input_.reset();
}
} // namespace reo::native::gameplay_scenario
