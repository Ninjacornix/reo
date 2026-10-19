#pragma once
#include <cstdint>
#include <memory>
#include <functional>
namespace Vulkan {
class Device;
}
namespace ParallelGS {
class GSInterface;
}
namespace reo_movie_owner {
class Target;
}
namespace reo_gpu_movie {
std::shared_ptr<reo_movie_owner::Target>
makeMovieOwnerService(Vulkan::Device&, ParallelGS::GSInterface&, uint64_t epoch,
                      std::function<void(uint32_t)> imageConsumed = {});
}
