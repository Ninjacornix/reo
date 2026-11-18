#include "hierarchy.hpp"
#include <algorithm>
#include <stdexcept>

namespace reo::native::afs_hierarchy {
Tree::Tree(std::shared_ptr<const resources::ByteView> root,Config config):config_(config),root_(std::move(root)) {
    if(!root_ || !config.archives || config.archives>65536 || !config.entries || config.entries>1048576 ||
       !config.members_per_archive || config.members_per_archive>=65536)
        throw std::invalid_argument("Bounded immutable AFS hierarchy");
    cache_.reserve(config.archives);
}
Snapshot Tree::snapshot()const noexcept{return{static_cast<std::uint32_t>(cache_.size()),entries_,root_->size()};}
Resolved Tree::resolve(std::span<const std::uint32_t> indices)noexcept {
    Resolved result;if(indices.empty() || indices.size()>maximum_depth)return result;
    auto view=root_;std::uint64_t offset{};std::array<std::uint32_t,maximum_depth> path{};
    for(std::uint32_t depth=0;depth<indices.size();++depth){
        auto found=std::find_if(cache_.begin(),cache_.end(),[&](const Cached& c){return c.depth==depth && c.path==path;});
        std::shared_ptr<const afs_source_range::Archive> archive;
        if(found!=cache_.end())archive=found->archive;
        else {
            if(cache_.size()==config_.archives){result.status=Status::cache_capacity;return result;}
            if(entries_==config_.entries){result.status=Status::entry_capacity;return result;}
            const auto maximum=std::min(config_.members_per_archive,config_.entries-entries_);
            auto opened=afs_source_range::Archive::open(view,0,view->size(),maximum);
            if(opened.status!=afs_source_range::Status::completed){
                result.archive_status=opened.status;
                result.status=opened.status==afs_source_range::Status::no_memory?Status::no_memory:Status::archive_refused;return result;
            }
            // reserve() in construction makes cache publication nonallocating.
            // Accepted ancestor indices may stay cached after a deeper refusal.
            archive=std::move(opened.archive);entries_+=archive->count();
            cache_.push_back({path,depth,archive});
        }
        auto member=archive->member(indices[depth]);
        if(member.status!=afs_source_range::Status::completed){
            result.status=member.status==afs_source_range::Status::no_memory?Status::no_memory:Status::archive_refused;
            result.archive_status=member.status;return result;
        }
        const auto relative=std::uint64_t(member.entry.start_sector)*2048;
        if(offset>root_->size() || relative>root_->size()-offset || member.view->size()>root_->size()-offset-relative){
            result.status=Status::source_failure;return result;
        }
        offset+=relative;result.hops[depth]={indices[depth],member.entry,offset};result.depth=depth+1;
        result.logical_bytes=member.entry.logical_bytes;view=std::move(member.view);path[depth]=indices[depth];
    }
    result.status=Status::completed;result.view=std::move(view);return result;
}
} // namespace reo::native::afs_hierarchy
