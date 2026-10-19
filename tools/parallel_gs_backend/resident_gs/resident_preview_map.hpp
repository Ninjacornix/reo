#pragma once
#include "intrusive_hash_map.hpp"
#include <memory>
#include <utility>
namespace ParallelGS {
// Stable map ownership allows architectural preview restoration without any
// allocation. Ordinary hash/map behavior stays in unmodified Granite.
template<class T> class ResidentRenderPassMap final {
 std::unique_ptr<Util::IntrusiveHashMap<T>> map_=std::make_unique<Util::IntrusiveHashMap<T>>();
public:
 void clear(){map_->clear();}
 T* find(Util::Hash hash)const{return map_->find(hash);}
 template<class... Args>T* emplace_replace(Util::Hash hash,Args&&...args){return map_->emplace_replace(hash,std::forward<Args>(args)...);}
 auto begin()const{return map_->begin();}auto end()const{return map_->end();}
 void swap(ResidentRenderPassMap& rhs)noexcept{map_.swap(rhs.map_);}
};
}
