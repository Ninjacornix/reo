#include "target_metrics.hpp"
#include "world.hpp"
#include "linked_models.hpp"
#include "auxiliary_actors.hpp"
#include "../animation/model.hpp"
#include "../transform_math/heading.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
namespace collision=gameplay_collision;
using Work=std::array<std::array<float,68>,68>;
using Point=collision::Vec3;
Point point(Position p){return {p.x,p.y,p.z};}
void finite(Point p){if(!std::isfinite(p.x)||!std::isfinite(p.y)||!std::isfinite(p.z))throw std::domain_error("Native target metric finite position required");}
float distance(Point a,Point b){
    finite(a);finite(b);const float x=a.x-b.x,y=a.y-b.y,z=a.z-b.z;
    const float xx=x*x,yy=y*y,zz=z*z,sum=xx+yy,total=sum+zz;
    const float result=std::sqrt(total);if(!std::isfinite(result))throw std::domain_error("Native target metric finite distance required");return result;
}
std::uint16_t bearing(Point from,Point to){finite(from);finite(to);return transform_math::direction_turn(to.x-from.x,to.z-from.z);}
Point model_point(const Actor& actor,std::size_t node){
    if(!actor.model||!actor.model->retain()||node>=actor.model->nodes().size())throw std::runtime_error("Native target metric model point unavailable");
    const auto result=actor.model->world_translation(node);const Point value{result.x,result.y,result.z};finite(value);return value;
}
Point linked_point(const Actor& actor){
    if(!actor.targeting)throw std::runtime_error("Native linked targeting state unavailable");
    return actor.targeting->selected_model_point?model_point(actor,actor.motion_style):point(actor.position);
}
template<class Rows>void reset_order(Rows& rows){for(auto& row:rows)row.fill(255);}
template<std::size_t N>void order(Work& work,unsigned row,unsigned count,std::array<std::uint8_t,N>& ids,TargetMetricReport& report){
    if(count>N||row>=work.size())throw std::logic_error("Native target sort capacity exceeded");
    ++report.sorts;
    for(unsigned i=0;i+1<count;++i)for(unsigned j=i+1;j<count;++j){++report.comparisons;if(work[row][i]<=work[row][j])continue;std::swap(work[row][i],work[row][j]);std::swap(ids[i],ids[j]);++report.swaps;}
}
template<std::size_t Sources,std::size_t Targets>void sort_family(Work& forward,Work& reverse,
    const std::array<unsigned,Sources>& counts,std::array<std::array<std::uint8_t,Targets>,Sources>& rows,
    std::array<std::array<std::uint8_t,Sources>,Targets>& inverse,TargetMetricReport& report,unsigned source_count=Sources){
    if(source_count>Sources)throw std::logic_error("Native target source capacity exceeded");
    unsigned maximum=0;
    for(unsigned i=0;i<source_count;++i){maximum=std::max(maximum,counts[i]);if(counts[i])order(forward,i,counts[i],rows[i],report);}
    // Complete6D6240 repeats each finite sort inside a per-target loop. Once a
    // row is sorted, later passes perform no swaps. No new distance writes
    // occur inside that loop; one pass per reached row preserves its result.
    for(unsigned i=0;i<maximum;++i)order(reverse,i,source_count,inverse[i],report);
}
}
const TargetMetricState* TargetMetricCache::state()const noexcept{return ready_&&!closed_&&!world_.closed()?&state_:nullptr;}
TargetMetricReport TargetMetricCache::rebuild(const TargetMetricRoom& room)noexcept{
    TargetMetricReport report;ready_=false;if(closed_||world_.closed()){report.status=TargetMetricStatus::closed;return report;}
    try{
        std::array<std::shared_ptr<Actor>,8> primary;
        std::array<std::shared_ptr<Actor>,10> auxiliary;
        std::array<std::shared_ptr<Actor>,50> linked;
        auto next=state_;
        for(unsigned i=0;i<primary.size();++i){next.primary_identity[i]=world_.identity(i);primary[i]=world_.primary(i);if(world_.mode==0&&!primary[i])return report;}
        auto& auxiliary_owner=world_.auxiliary_actors();auto& linked_owner=world_.linked_models();
        for(unsigned i=0;i<auxiliary.size();++i){const auto id=auxiliary_owner.identity_at(i);next.auxiliary_identity[i]=id;auxiliary[i]=world_.resolve(id);if(id&&!auxiliary[i])return report;}
        for(unsigned i=0;i<linked.size();++i){const auto id=linked_owner.identity_at(i);next.linked_identity[i]=id;linked[i]=world_.resolve(id);if(id&&!linked[i])return report;}
        // A cached value must never acquire a newly allocated actor identity.
        // Within the same identity, skipped source cells keep their old values.
        for(unsigned i=0;i<primary.size();++i){
            const bool same=next.primary_identity[i]==state_.primary_identity[i];
            for(unsigned j=0;j<primary.size();++j)if(!same||next.primary_identity[j]!=state_.primary_identity[j])next.primary_pairs[i][j].reset();
            for(unsigned j=0;j<linked.size();++j)if(!same||next.linked_identity[j]!=state_.linked_identity[j])next.primary_linked[i][j].reset();
            for(unsigned j=0;j<auxiliary.size();++j)if(!same||next.auxiliary_identity[j]!=state_.auxiliary_identity[j])next.primary_auxiliary[i][j].reset();
        }
        for(unsigned i=0;i<auxiliary.size();++i)for(unsigned j=0;j<linked.size();++j)
            if(next.auxiliary_identity[i]!=state_.auxiliary_identity[i]||next.linked_identity[j]!=state_.linked_identity[j])next.auxiliary_linked[i][j].reset();
        Work forward,reverse;
        for(auto& row:forward)row.fill(std::numeric_limits<float>::max());
        for(auto& row:reverse)row.fill(std::numeric_limits<float>::max());
        if(world_.mode==0)for(unsigned i=0;i<primary.size();++i)for(unsigned j=0;j<primary.size();++j){
            const auto from=point(primary[i]->position),to=point(primary[j]->position);
            next.primary_pairs[i][j]=TargetPairMetric{distance(from,to),bearing(from,to)};++report.pairs;
        }
        reset_order(next.primary_linked_order);reset_order(next.reverse_primary_order);
        std::array<unsigned,8> primary_counts{};
        for(unsigned i=0;i<primary.size();++i){
            const auto& actor=primary[i];if(!actor||!actor->active)continue;
            const auto root=model_point(*actor,11),origin=point(actor->position);
            for(unsigned j=0;j<linked.size();++j){
                const auto& target=linked[j];if(!target||actor->room!=target->room||!target->active)continue;
                if(!target->targeting)return report;
                if(target->targeting->flags&0x100u)continue;
                auto endpoint=linked_point(*target);TargetLinkedMetric metric;
                metric.pair={distance(origin,point(target->position)),bearing(root,endpoint)};
                auto& count=primary_counts[i];next.primary_linked_order[i][count]=std::uint8_t(j);next.reverse_primary_order[count][i]=std::uint8_t(i);
                forward[i][count]=reverse[count][i]=metric.pair.distance;
                if(metric.pair.distance>=3000.f)metric.wall=1;
                else{
                    auto filter=room.filter;filter.include=0x4ffff;filter.exclude=0;filter.dynamic_kind_gate=false;
                    const auto wall=collision::trace::any(room.walls,root,endpoint,filter,room.dynamic);++report.wall_queries;
                    if(wall.status!=collision::trace::SamplingStatus::complete)return report;
                    metric.wall=wall.hit?1:0;
                }
                endpoint.y=root.y<=endpoint.y?endpoint.y-1.f:endpoint.y+1.f;finite(endpoint);
                const auto floor=collision::trace::floor_any_checked(room.floors,root,endpoint,255,0x81);++report.floor_queries;
                if(floor.status!=collision::trace::SamplingStatus::complete)return report;
                metric.floor=floor.hit?1:0;
                next.primary_linked[i][j]=metric;++count;++report.pairs;
            }
        }
        sort_family(forward,reverse,primary_counts,next.primary_linked_order,next.reverse_primary_order,report);
        reset_order(next.auxiliary_linked_order);reset_order(next.reverse_auxiliary_order);
        std::array<unsigned,10> auxiliary_counts{};
        for(unsigned i=0;i<auxiliary.size();++i){
            const auto& actor=auxiliary[i];if(!actor||!actor->active)continue;
            const auto root=model_point(*actor,11),origin=point(actor->position);
            for(unsigned j=0;j<linked.size();++j){
                const auto& target=linked[j];if(!target||actor->room!=target->room||!target->active)continue;
                if(!target->targeting)return report;
                if(target->targeting->flags&0x100u)continue;
                TargetLinkedMetric metric;metric.pair={distance(origin,point(target->position)),bearing(root,linked_point(*target))};
                auto& count=auxiliary_counts[i];next.auxiliary_linked_order[i][count]=std::uint8_t(j);next.reverse_auxiliary_order[count][i]=std::uint8_t(i);
                forward[i][count]=reverse[count][i]=metric.pair.distance;
                next.auxiliary_linked[i][j]=metric;++count;++report.pairs;
            }
        }
        sort_family(forward,reverse,auxiliary_counts,next.auxiliary_linked_order,next.reverse_auxiliary_order,report);
        reset_order(next.primary_auxiliary_order);reset_order(next.auxiliary_primary_order);
        primary_counts.fill(0);next.primary_auxiliary_sources={};unsigned compact_sources=0;
        for(unsigned i=0;i<primary.size();++i){
            const auto& actor=primary[i];if(!actor||!actor->active)continue;
            const auto compact=compact_sources++;next.primary_auxiliary_sources[compact]=next.primary_identity[i];
            for(unsigned j=0;j<auxiliary.size();++j){
                const auto& target=auxiliary[j];if(!target||actor->room!=target->room||!target->active)continue;
                const auto angle=std::uint16_t(std::uint16_t(actor->orientation[1])-std::uint16_t(target->orientation[1]));
                TargetPairMetric metric{distance(point(actor->position),point(target->position)),angle};
                auto& count=primary_counts[i];next.primary_auxiliary_order[compact][count]=std::uint8_t(j);next.auxiliary_primary_order[count][compact]=std::uint8_t(i);
                forward[compact][count]=reverse[count][compact]=metric.distance;
                next.primary_auxiliary[i][j]=metric;++count;++report.pairs;
            }
        }
        // The source sort scans the physical count prefix with the compact
        // active count. Preserve that index asymmetry even with inactive holes.
        sort_family(forward,reverse,primary_counts,next.primary_auxiliary_order,next.auxiliary_primary_order,report,compact_sources);
        state_=std::move(next);ready_=true;report.status=TargetMetricStatus::completed;return report;
    }catch(const std::exception&){return report;}
}
}
