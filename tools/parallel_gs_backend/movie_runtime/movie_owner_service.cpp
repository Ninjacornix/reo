#include "movie_owner_service.h"
#include "movie_owner_service_fwd.h"
namespace reo_gpu_movie {
std::shared_ptr<reo_movie_owner::Target>
makeMovieOwnerService(Vulkan::Device& device, ParallelGS::GSInterface& renderer, uint64_t epoch,
                      std::function<void(uint32_t)> imageConsumed) {
    return std::make_shared<MovieOwnerServiceTarget>(device, renderer, epoch,
                                                     std::move(imageConsumed));
}
} // namespace reo_gpu_movie
