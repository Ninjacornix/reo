// Offline numerical comparison of real captured calls, never a live admission.
// Reuse the pinned fixture's cache identity and hardware context helpers.
#define main frozen_static_reference_main
#include "build-ninja/m2-gpu-static-parallel-agent/fixture-fast2/gpu.cpp"
#undef main
#include "build-ninja/m2-gpu-remaining-programs-agent/resident_aot.hpp"
#include <sstream>

static reo_gpu_aot::Echo capturedEcho(const Bytes& bank, uint32_t top, bool freshZero) {
    reo_gpu_aot::Echo echo{};
    if (freshZero)
        return echo;
    uint32_t tag[4]{};
    std::memcpy(tag, bank.data() + ((top + 1u) & 1023u) * 16u, 16);
    require((tag[0] & 0xffff8000u) == 32768u && ((tag[1] >> 26u) & 3u) == 0u,
            "Unclassified captured GIF tag");
    const auto nreg = (tag[1] >> 28u) & 15u;
    if (nreg == 3u && tag[2] == 0x412u) {
        echo.kindCountFlags = {1, 256, (tag[1] >> 15u) & 2047u, 0};
        std::memcpy(echo.qwords[0].data(), tag, 16);
    } else {
        require(nreg == 1u && tag[2] == 14u && (tag[0] & 32767u) == 6u,
                "Unclassified captured AD tag");
        echo.kindCountFlags = {2, 6, 0, 0};
        for (unsigned q = 0; q < 7; ++q)
            std::memcpy(echo.qwords[q].data(), bank.data() + ((top + 1u + q) & 1023u) * 16u, 16);
    }
    return echo;
}

int main(int argc, char** argv) try {
    require(argc == 4 || argc == 5,
            "Usage captured_vu_numeric CASES_TSV NEW_OUT PRIVATE_CACHE [paired]");
    const bool paired = argc == 5;
    require(!paired || std::string(argv[4]) == "paired", "Unknown numerical proof mode");
    const fs::path out = argv[2];
    require(!fs::exists(out), "Preserve numerical proof artifacts");
    fs::create_directories(out);
    Util::register_thread_index(0);
    require(Vulkan::Context::init_loader(nullptr), "Vulkan loader unavailable");
    Vulkan::Context context;
    context.set_num_thread_indices(1);
    require(context.init_instance_and_device(nullptr, 0, nullptr, 0), "GPU initialization failed");
    require(context.get_gpu_props().deviceType != VK_PHYSICAL_DEVICE_TYPE_CPU,
            "Hardware GPU required");
    Vulkan::Device device;
    device.set_context(context);
    device.init_frame_contexts(2);
    FixtureCache cache(device, argv[3]);
    std::ifstream cases(argv[1]);
    require(bool(cases), "Missing numerical case list");
    std::ofstream report(out / "cases.tsv");
    report << "case\timage\tentryPC\tresume\tstatus\tsticky\tended\tevents\tstateDiff\tdataDiff\tpa"
              "cketDiff\tclassification\n";
    std::string line;
    unsigned passed = 0, refused = 0, mismatched = 0, classified = 0;
    while (std::getline(cases, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty())
            continue;
        std::istringstream fields(line);
        std::array<std::string, 8> values;
        for (auto& field : values)
            require(bool(std::getline(fields, field, '\t')), "Truncated case row");
        const fs::path folder = values[0];
        const auto pc = uint32_t(std::stoul(values[3])), top = uint32_t(std::stoul(values[4])),
                   itop = uint32_t(std::stoul(values[5]));
        const bool resume = std::stoul(values[6]) != 0;
        const auto packetCount = unsigned(std::stoul(values[7]));
        const auto state = read(folder / "input.state.bin"), bank = read(folder / "input.data.bin"),
                   raw = read(values[1]);
        require(state.size() == 632 && bank.size() == 16384 && raw.size() >= 20 &&
                    raw.size() % 4 == 0,
                "Invalid captured input sizes");
        require(reo_gpu_catalog::sha256(read(folder / "input.code.bin")) == values[2],
                "Captured image identity mismatch");
        std::vector<uint32_t> code(raw.size() / 4);
        std::memcpy(code.data(), raw.data(), raw.size());
        reo_gpu_aot::Echo echo{};
        try {
            echo = capturedEcho(bank, top, !resume && pc == 0u);
        } catch (const std::exception& e) {
            report << folder.filename().string() << '\t' << values[2] << '\t' << pc << '\t'
                   << resume << "\t0\t0\t0\t0\t0\t0\t0\tUNCLASSIFIED_ECHO\n";
            ++classified;
            continue;
        }
        reo_gpu_aot::ResidentAot owner(device, code, state.data(), bank.data(), echo);
        auto cmd = device.request_command_buffer();
        owner.enqueue(*cmd, {pc, 65536, top, itop, resume ? 4u : 0u, 256, 0, 0});
        std::array<Vulkan::BufferHandle, 4> host;
        for (unsigned b = 0; b < 4; ++b) {
            Vulkan::BufferCreateInfo ci{};
            ci.domain = Vulkan::BufferDomain::CachedHost;
            ci.size = reo_gpu_aot::ResidentAot::Sizes[b];
            ci.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            host[b] = device.create_buffer(ci);
            require(bool(host[b]), "Numerical readback allocation failed");
            cmd->buffer_barrier(owner.bank(b), VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT,
                                VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
            cmd->copy_buffer(*host[b], owner.bank(b));
            cmd->buffer_barrier(*host[b], VK_PIPELINE_STAGE_TRANSFER_BIT,
                                VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                VK_ACCESS_2_HOST_READ_BIT);
        }
        Vulkan::Fence fence;
        device.submit(cmd, &fence);
        fence->wait();
        std::array<Bytes, 4> result;
        for (unsigned b = 0; b < 4; ++b) {
            const auto* p = static_cast<const uint8_t*>(
                device.map_host_buffer(*host[b], Vulkan::MEMORY_ACCESS_READ_BIT));
            require(p != nullptr, "Numerical readback mapping failed");
            result[b].assign(p, p + reo_gpu_aot::ResidentAot::Sizes[b]);
            device.unmap_host_buffer(*host[b], Vulkan::MEMORY_ACCESS_READ_BIT);
        }
        const auto dest = out / folder.filename();
        fs::create_directories(dest);
        for (unsigned b = 0; b < 4; ++b)
            write(dest / ("bank" + std::to_string(b) + ".bin"), result[b]);
        const auto status = word(result[3], 0), sticky = word(result[3], 32),
                   ended = word(result[3], 20), events = word(result[3], 24);
        unsigned sd = 0, dd = 0, pd = 0;
        const char* classification = "REFUSED";
        if (status || sticky) {
            ++refused;
        } else {
            sd = diff(result[0], read(folder / "original/vu_final_state.bin"), "fullstate");
            dd = diff(result[1], read(folder / "original/vu_final_data.bin"), "fullbank");
            if (events != packetCount || word(result[2], 0) != packetCount || !ended ||
                packetCount > 1u)
                pd = 1;
            else if (packetCount) {
                const auto bytes = word(result[2], 12);
                const auto expected = read(folder / "original/vu_gif_0000.bin");
                if (bytes > 16384u || bytes != expected.size())
                    pd = 1;
                else
                    pd = diff(slice(result[2], 16, bytes), expected, "ordered_packet");
            }
            if (sd || dd || pd) {
                ++mismatched;
                classification = "MISMATCH";
            } else {
                ++passed;
                classification = "NUMERICAL_PASS_NOT_ADMISSION";
            }
        }
        report << folder.filename().string() << '\t' << values[2] << '\t' << pc << '\t' << resume
               << '\t' << status << '\t' << sticky << '\t' << ended << '\t' << events << '\t' << sd
               << '\t' << dd << '\t' << pd << '\t' << classification << '\n';
        report.flush();
        std::printf("%s %s status=%u sticky=%u events=%u\n", folder.filename().string().c_str(),
                    classification, status, sticky, events);
        std::fflush(stdout);
        // A second MSCNT on these SAME device banks. Derived CPU references
        // continue the first E-bit result without intervening VIF uploads.
        // Neither a bank re-upload nor a cold recreation substitutes for it.
        if (paired && classification == std::string("NUMERICAL_PASS_NOT_ADMISSION")) {
            std::string secondPath, secondCount;
            require(bool(std::getline(fields, secondPath, '\t')) &&
                        bool(std::getline(fields, secondCount, '\t')),
                    "Missing paired reference fields");
            if (secondPath == "-")
                continue;
            const fs::path second = secondPath;
            const auto expectedState = read(second / "input.state.bin"),
                       expectedData = read(second / "input.data.bin");
            require(result[0] == expectedState && result[1] == expectedData,
                    "Paired reference is not the first full-bank result");
            reo_gpu_aot::Echo nextEcho{};
            try {
                nextEcho = capturedEcho(expectedData, top, word(expectedState, 604) == 0u);
            } catch (const std::exception&) {
                ++classified;
                report << folder.filename().string() << "/MSCNT2\t" << values[2]
                       << "\t0\t1\t0\t0\t0\t0\t0\t0\t0\tUNCLASSIFIED_ECHO\n";
                continue;
            }
            auto next = device.request_command_buffer();
            next->buffer_barrier(owner.bank(6), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                 VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
            next->update_buffer_inline(owner.bank(6), 0, sizeof(nextEcho), &nextEcho);
            owner.enqueue(*next, {0x3ff8u, 65536, top, itop, 4, 256, 0, 0});
            for (unsigned b = 0; b < 4; ++b) {
                next->buffer_barrier(*host[b], VK_PIPELINE_STAGE_HOST_BIT,
                                     VK_ACCESS_2_HOST_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_ACCESS_2_TRANSFER_WRITE_BIT);
                next->buffer_barrier(owner.bank(b), VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                     VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                next->copy_buffer(*host[b], owner.bank(b));
                next->buffer_barrier(*host[b], VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                     VK_ACCESS_2_HOST_READ_BIT);
            }
            Vulkan::Fence nextFence;
            device.submit(next, &nextFence);
            nextFence->wait();
            for (unsigned b = 0; b < 4; ++b) {
                const auto* p = static_cast<const uint8_t*>(
                    device.map_host_buffer(*host[b], Vulkan::MEMORY_ACCESS_READ_BIT));
                require(p != nullptr, "Paired readback mapping failed");
                result[b].assign(p, p + reo_gpu_aot::ResidentAot::Sizes[b]);
                device.unmap_host_buffer(*host[b], Vulkan::MEMORY_ACCESS_READ_BIT);
                write(dest / ("continued-bank" + std::to_string(b) + ".bin"), result[b]);
            }
            const auto nextStatus = word(result[3], 0), nextSticky = word(result[3], 32),
                       nextEnded = word(result[3], 20), nextEvents = word(result[3], 24);
            unsigned nextSd = 0, nextDd = 0, nextPd = 0;
            const char* nextClassification = "REFUSED";
            if (nextStatus || nextSticky)
                ++refused;
            else {
                nextSd = diff(result[0], read(second / "original/vu_final_state.bin"),
                              "continued_fullstate");
                nextDd = diff(result[1], read(second / "original/vu_final_data.bin"),
                              "continued_fullbank");
                const auto expectedPackets = unsigned(std::stoul(secondCount));
                if (!nextEnded || nextEvents != expectedPackets ||
                    word(result[2], 0) != expectedPackets || expectedPackets > 1u)
                    nextPd = 1;
                else if (expectedPackets) {
                    const auto packet = read(second / "original/vu_gif_0000.bin");
                    const auto bytes = word(result[2], 12);
                    if (bytes > 16384u || bytes != packet.size())
                        nextPd = 1;
                    else
                        nextPd =
                            diff(slice(result[2], 16, bytes), packet, "continued_ordered_packet");
                }
                if (nextSd || nextDd || nextPd) {
                    ++mismatched;
                    nextClassification = "MISMATCH";
                } else {
                    ++passed;
                    nextClassification = "SAME_BANK_PASS_NOT_ADMISSION";
                }
            }
            report << folder.filename().string() << "/MSCNT2\t" << values[2] << "\t16376\t1\t"
                   << nextStatus << '\t' << nextSticky << '\t' << nextEnded << '\t' << nextEvents
                   << '\t' << nextSd << '\t' << nextDd << '\t' << nextPd << '\t'
                   << nextClassification << '\n';
            report.flush();
            std::printf("%s MSCNT2 %s\n", folder.filename().string().c_str(), nextClassification);
            std::fflush(stdout);
        }
    }
    device.wait_idle();
    cache.save(out / "pipeline-cache.json");
    std::ofstream summary(out / "summary.json");
    summary << "{\"scope\":\"captured generic modules, numerical only, no admission or live "
               "handoff proof\",\"passed\":"
            << passed << ",\"refused\":" << refused << ",\"mismatched\":" << mismatched
            << ",\"unclassified\":" << classified << "}\n";
    require(bool(summary), "Numerical report failed");
    return mismatched ? 1 : 0;
} catch (const std::exception& e) {
    std::fprintf(stderr, "ERROR %s\n", e.what());
    return 2;
}
