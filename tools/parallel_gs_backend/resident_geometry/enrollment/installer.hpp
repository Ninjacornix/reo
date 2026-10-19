#pragma once
#include <filesystem>
class PS2Runtime;
namespace reo_parallel_backend {
struct Config;
}
namespace reo_gpu_enrollment {
// Call after normal GPU Config setup and BEFORE registerFactory/initialize.
// This header contains no Vulkan/GS implementation or generated-TU changes.
void configureBeforeBoot(reo_parallel_backend::Config&,
                         const std::filesystem::path& applicationDirectory, const char* serial,
                         PS2Runtime* actualRuntime = nullptr);
} // namespace reo_gpu_enrollment
