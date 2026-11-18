#include "policy.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>
namespace n=reo::native::movie_lifecycle;
struct Rule {std::vector<std::uint32_t> returns,snapshot;std::map<unsigned,std::uint32_t> current,saved;};
void emit(const n::State& s){for(auto v:{s.actual,s.requested,s.pending,s.pause,s.depth,s.reuse})std::cout<<' '<<v;for(const auto& group:{s.current,s.saved})for(auto v:group)std::cout<<' '<<v;for(auto v:s.registry)std::cout<<' '<<v;}
struct Event {unsigned kind;std::vector<std::uint32_t> args;n::State before;};
struct Ports final:n::Ports {
    std::map<std::string,Rule> rules;std::map<std::string,unsigned> count,ids;std::vector<Event> events;
    n::Reply call(std::string_view kind,std::span<const std::uint32_t> args,n::State& state)noexcept override {
        const std::string name(kind);events.push_back({ids.at(name),{args.begin(),args.end()},state});const auto occurrence=count[name]++;
        n::Reply reply;const auto found=rules.find(name);
        if(found!=rules.end()){
            const auto& rule=found->second;
            if(!rule.returns.empty())reply.status=rule.returns[std::min<std::size_t>(occurrence,rule.returns.size()-1)];
            for(auto [index,value]:rule.current)state.current.at(index)=value;
            for(auto [index,value]:rule.saved)state.saved.at(index)=value;
        }
        if(name.size()>=2 && name.ends_with("-9")){
            reply.snapshot_written=true;reply.snapshot=occurrence?456:123;
            if(found!=rules.end() && !found->second.snapshot.empty())reply.snapshot=found->second.snapshot[std::min<std::size_t>(occurrence,found->second.snapshot.size()-1)];
        }
        return reply;
    }
};
int main(){std::size_t names{};if(!(std::cin>>names))return 1;Ports ports;
    for(unsigned i=0;i<names;++i){std::string name;std::cin>>name;ports.ids[name]=i;}
    n::Construction construction;for(auto& value:construction.defaults)std::cin>>value;
    unsigned id{},operations{};while(std::cin>>id){n::State state;std::cin>>construction.source_available>>construction.workspace_bytes>>construction.components>>construction.hooks>>state.actual>>state.requested>>state.pending>>state.pause>>state.depth>>state.reuse;
        for(auto& group:{&state.current,&state.saved})for(auto& v:*group)std::cin>>v;
        for(auto& v:state.registry)std::cin>>v;
        state.components=construction.components;
        n::Policy policy(state,construction,ports);
        auto row=[&](int index,n::Result result){std::cout<<"row "<<id<<' '<<index<<' '<<result.returned<<' '<<result.defined;emit(policy.state());std::cout<<' '<<ports.events.size();for(auto& e:ports.events){std::cout<<' '<<e.kind<<' '<<e.args.size();for(auto v:e.args)std::cout<<' '<<v;emit(e.before);}std::cout<<'\n';};
        ports.events.clear();row(-1,{});std::cin>>operations;
        for(unsigned i=0;i<operations;++i){unsigned op{},rules{};std::cin>>op>>rules;ports.rules.clear();ports.count.clear();ports.events.clear();
            for(unsigned r=0;r<rules;++r){std::string name;unsigned count{};std::cin>>name;Rule rule;
                for(auto* values:{&rule.returns,&rule.snapshot}){std::cin>>count;values->resize(count);for(auto& v:*values)std::cin>>v;}
                for(auto* values:{&rule.current,&rule.saved}){std::cin>>count;for(unsigned v=0;v<count;++v){unsigned index{};std::uint32_t value{};std::cin>>index>>value;(*values)[index]=value;}}
                ports.rules.emplace(name,std::move(rule));}
            row(static_cast<int>(i),policy.execute(static_cast<n::Operation>(op)));
        }
    }
    return std::cin.eof()?0:2;
}
