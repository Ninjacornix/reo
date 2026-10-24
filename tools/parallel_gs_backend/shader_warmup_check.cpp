#include "runtime/gs/shader_warmup.h"
#include <cstdio>
#include <stdexcept>
static void require(bool value) { if (!value) throw std::runtime_error("Shader warmup policy check failed"); }
int main() try {
    using namespace reo::graphics;
    for (unsigned hardware : {0u,1u,2u,4u,12u,128u}) {
        for (std::size_t tasks : {0u,1u,2u,3u,17u,10003u}) {
            const auto workers=warmupWorkers(tasks,hardware);
            require(tasks ? workers>0 && workers<=2 && workers<=tasks : workers==0);
            std::size_t end=0;
            for (std::size_t worker=0;worker<workers;++worker) {
                auto range=warmupRange(tasks,worker,workers);
                require(range.begin==end && range.end>range.begin && range.end<=tasks);
                end=range.end;
            }
            require(end==tasks); // In particular, never drop a division remainder.
        }
    }
    for (unsigned samples : {1u,2u,4u,8u,16u}) {
        unsigned selected=0;
        for (unsigned x=0;x<=2;++x) for(unsigned y=0;y<=3;++y) {
            selected+=warmupSampling(samples,true,false,x,y);
            require(warmupSampling(samples,true,true,x,y));
            require(warmupSampling(samples,false,false,x,y));
        }
        require(selected==(samples==1?1u:2u));
    }
    require(warmupSampling(4,true,false,1,1) && !warmupSampling(4,true,false,2,2));
    require(warmupSampling(16,true,false,2,2) && !warmupSampling(16,true,false,1,1));
    std::puts("PASS shader warmup: sampling profiles, bounded workers, zero-core fallback, complete task coverage");
} catch (const std::exception& e) { std::fprintf(stderr,"%s\n",e.what());return 1; }
