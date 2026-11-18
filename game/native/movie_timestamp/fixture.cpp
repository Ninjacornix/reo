#include "timestamp.hpp"
#include <iostream>
namespace n=reo::native::movie_timestamp;
void emit(const n::State& s){std::cout<<' '<<s.baseline<<' '<<s.origin<<' '<<s.base<<' '<<s.maximum<<' '<<s.cached.value<<' '<<s.cached.begin<<' '<<s.cached.bytes;}
int main(){unsigned identity{},count{};while(std::cin>>identity){n::State state;std::cin>>state.baseline>>state.origin>>state.base>>state.maximum>>state.cached.value>>state.cached.begin>>state.cached.bytes>>count;
    std::cout<<"row "<<identity<<" -1 0";emit(state);std::cout<<'\n';
    for(unsigned i=0;i<count;++i){n::Input input;std::cin>>input.rate>>input.reference>>input.kind>>input.changed>>input.stamp.value>>input.stamp.begin>>input.stamp.bytes;const auto result=n::reconcile(state,input);if(!result.admitted)return 2;std::cout<<"row "<<identity<<' '<<i<<' '<<result.value;emit(state);std::cout<<'\n';}
}return std::cin.eof()?0:1;}
