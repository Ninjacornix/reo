#include "reo_vu_native_geometry.h"
#include "vu_native_geometry_route.h"
#include "reo_vu_native_sha256.h"
#include "native_rigid_loop.h"
#include "native_geometry_collector.h"
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
#include "native_64e_mode1_loop.h"
#endif
#if defined(REO_HAVE_NATIVE_MULTIBONE_GEOMETRY)
#include "native_multibone_loop.h"
#endif
#if defined(REO_HAVE_NATIVE_STATIC_GEOMETRY)
#include "native_static_loop.h"
#endif
#if (defined(REO_HAVE_NATIVE_STATIC_HALFSPACE_GEOMETRY) ||                                         \
     defined(REO_HAVE_NATIVE_STATIC_PROJECTION_GEOMETRY)) &&                                       \
    !defined(REO_HAVE_NATIVE_STATIC_GEOMETRY)
#error "Optional clipped static bodies require the existing exact static program binding"
#endif
#if defined(REO_HAVE_NATIVE_STATIC_HALFSPACE_GEOMETRY)
#include "native_static_halfspace.h"
#endif
#if defined(REO_HAVE_NATIVE_STATIC_PROJECTION_GEOMETRY)
#include "native_static_projection.h"
#endif
#include <array>
#include <cstdlib>
#include <cstring>
namespace {
const uint8_t* weightedDiagnosticCode() noexcept;
bool disabled(const char* name) noexcept {
    const char* p = std::getenv(name);
    return p && std::strcmp(p, "0") == 0;
}
vu_native_geometry::Result rigid(vu_specialized::Invocation& invocation) {
    auto& diagnostic = reo_native_collector::collector();
    if (diagnostic.active() && diagnostic.begin(0, invocation, weightedDiagnosticCode())) {
        reo_native_rigid::Result result;
        reo_native_refusal::Event event;
        const bool accepted = reo_native_rigid::executeLoop(
            invocation.state, invocation.data, invocation.dataBytes, invocation.remainingPairs,
            invocation.branchPending, invocation.branchTarget, {true, true}, result, &event);
        diagnostic.finish(0, invocation, accepted, result.pairs, result.vertices, event);
        return accepted ? vu_native_geometry::Result{result.pairs, result.vertices}
                        : vu_native_geometry::Result{};
    }
    reo_native_rigid::Result result;
    if (!reo_native_rigid::executeLoop(invocation.state, invocation.data, invocation.dataBytes,
                                       invocation.remainingPairs, invocation.branchPending,
                                       invocation.branchTarget, {true, true}, result))
        return {};
    return {result.pairs, result.vertices};
}
const vu_native_geometry::DynamicLoop rigidLoop{0x348, 0x5c0, 80, rigid};
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
vu_native_geometry::Result rigid64e(vu_specialized::Invocation& invocation) {
    reo_native_64e_rigid::Result result;
    if (!reo_native_64e_rigid::executeLoop(invocation.state, invocation.data, invocation.dataBytes,
                                           invocation.remainingPairs, invocation.branchPending,
                                           invocation.branchTarget, {true, true}, result))
        return {};
    return {result.pairs, result.vertices};
}
const vu_native_geometry::DynamicLoop rigid64eLoop{0x298, 0x638, 117, rigid64e};
// Reached64e prefixes proved only mode1. NO mode2 descriptor is registered.
#endif
#if defined(REO_HAVE_NATIVE_MULTIBONE_GEOMETRY)
vu_native_geometry::Result multiBone(vu_specialized::Invocation& invocation) {
    auto& diagnostic = reo_native_collector::collector();
    if (diagnostic.active() && diagnostic.begin(1, invocation, weightedDiagnosticCode())) {
        reo_native_multibone::Result result;
        reo_native_refusal::Event event;
        const bool accepted = reo_native_multibone::executeLoop(
            invocation.state, invocation.data, invocation.dataBytes, invocation.remainingPairs,
            invocation.branchPending, invocation.branchTarget, {true, true}, result, &event);
        diagnostic.finish(1, invocation, accepted, result.pairs, result.vertices, event);
        return accepted ? vu_native_geometry::Result{result.pairs, result.vertices}
                        : vu_native_geometry::Result{};
    }
    reo_native_multibone::Result result;
    if (!reo_native_multibone::executeLoop(invocation.state, invocation.data, invocation.dataBytes,
                                           invocation.remainingPairs, invocation.branchPending,
                                           invocation.branchTarget, {true, true}, result))
        return {};
    return {result.pairs, result.vertices};
}
const vu_native_geometry::DynamicLoop multiBoneLoop{0x760, 0xb00, 117, multiBone};
#endif
#if defined(REO_HAVE_NATIVE_STATIC_GEOMETRY)
vu_native_geometry::Result staticRoom(vu_specialized::Invocation& invocation) {
    reo_native_static::Result result;
    if (!reo_native_static::executeLoop(invocation.state, invocation.data, invocation.dataBytes,
                                        invocation.remainingPairs, invocation.branchPending,
                                        invocation.branchTarget, {true, true}, result))
        return {};
    return {result.pairs, result.vertices};
}
const vu_native_geometry::DynamicLoop staticLoop{0x260, 0x4a0, 54, staticRoom};
#if defined(REO_HAVE_NATIVE_STATIC_HALFSPACE_GEOMETRY)
vu_native_geometry::Result staticHalfspace(vu_specialized::Invocation& invocation) {
    reo_native_static_halfspace::Result result;
    if (!reo_native_static_halfspace::executeLoop(
            invocation.state, invocation.data, invocation.dataBytes, invocation.remainingPairs,
            invocation.branchPending, invocation.branchTarget, {true, true}, result))
        return {};
    return {result.pairs, result.vertices};
}
// Game-owned exact return residues. Generic runtime contains none of these PCs.
constexpr vu_native_geometry::Exit halfspaceExits[] = {
    {0x720, 0xdf8}, {0x770, 0xdf8}, {0x7b0, 0xdf8}, {0x7f0, 0xdf8}, {0x830, 0xdf8}, {0x870, 0xdf8}};
const vu_native_geometry::DynamicLoop halfspaceLoop{
    0xc70,           0xf28,          25,
    staticHalfspace, halfspaceExits, uint32_t(sizeof(halfspaceExits) / sizeof(halfspaceExits[0]))};
#endif
#if defined(REO_HAVE_NATIVE_STATIC_PROJECTION_GEOMETRY)
vu_native_geometry::Result staticProjection(vu_specialized::Invocation& invocation) {
    reo_native_static_projection::Result result;
    if (!reo_native_static_projection::executeLoop(
            invocation.state, invocation.data, invocation.dataBytes, invocation.remainingPairs,
            invocation.branchPending, invocation.branchTarget, {true, true}, result))
        return {};
    return {result.pairs, result.vertices};
}
const vu_native_geometry::DynamicLoop projectionLoop{0x930, 0xac0, 51, staticProjection};
#endif
#endif
const reo_native_image_identity::Digest weightedDigest = {
    0x2e, 0xa0, 0x2b, 0x36, 0x28, 0x23, 0x1f, 0x11, 0x3e, 0xdc, 0x3f, 0xe5, 0x80, 0xf8, 0x0c, 0x1d,
    0x6e, 0xd4, 0x5c, 0x98, 0xa7, 0xc9, 0x8f, 0x9f, 0x83, 0x00, 0x56, 0x65, 0xf8, 0xad, 0x32, 0xce};
#if defined(REO_HAVE_NATIVE_STATIC_GEOMETRY)
const reo_native_image_identity::Digest staticDigest = {
    0x52, 0x73, 0xfa, 0x3e, 0x98, 0x93, 0xdf, 0x4b, 0x38, 0x33, 0xa2, 0x2b, 0x1d, 0x7d, 0xee, 0xc2,
    0xf9, 0x9a, 0x2d, 0x2a, 0xf0, 0xc1, 0x0f, 0x2a, 0xa0, 0xff, 0x5b, 0x43, 0xd3, 0xb2, 0xfc, 0x25};
#endif
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
const reo_native_image_identity::Digest rigid64eDigest = {
    0x64, 0xe4, 0xb3, 0x8e, 0x85, 0x33, 0x53, 0xc7, 0xc7, 0x8d, 0x73, 0x63, 0xb9, 0x8d, 0xca, 0x04,
    0xbd, 0xd8, 0xf5, 0xfe, 0x05, 0x04, 0x96, 0xf2, 0xe2, 0x3d, 0x86, 0x43, 0xbb, 0xba, 0x10, 0xd3};
#endif
struct OwnedBinding {
    const vu_specialized::ProgramTable* legacy = nullptr;
    std::array<const vu_native_geometry::DynamicLoop*, 2048> weightedEntries{}, staticEntries{};
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
    std::array<const vu_native_geometry::DynamicLoop*, 2048> rigid64eEntries{};
#endif
    std::array<vu_native_geometry::Program, 3> programs{};
    vu_native_geometry::ProgramTable table{programs.data(), 0};
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
    // Both views remain immutable after preparation; selective publication never
    // edits a table count that a VU launch could already have borrowed.
    vu_native_geometry::ProgramTable without64e{programs.data(), 0};
#endif
    bool prepared = false, valid = false;
};
OwnedBinding
    binding; // Preboot, immutable after the first preparation; no concurrent mutation promise.
const uint8_t* weightedDiagnosticCode() noexcept {
    if (!binding.prepared || !binding.valid)
        return nullptr;
    for (uint32_t n = 0; n < binding.table.count; ++n)
        if (binding.programs[n].entryLoops == binding.weightedEntries.data()) {
            const auto* legacy = binding.programs[n].legacyProgram;
            return legacy && legacy->codeBytes == 16384 ? legacy->exactCodeImage : nullptr;
        }
    return nullptr;
}
const vu_native_geometry::ProgramTable* selectedNativeTable() noexcept {
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
    if (disabled("REO_VU_NATIVE_64E_GEOMETRY"))
        return &binding.without64e;
#endif
    return &binding.table;
}
} // namespace
bool reoRegisterNativeGeometryPrograms(const vu_specialized::ProgramTable* legacy) noexcept {
    if (disabled("REO_VU_SPECIALIZED") || disabled("REO_VU_NATIVE_GEOMETRY") || !legacy)
        return vu_native_geometry::registerProgramTable(nullptr);
    if (binding.prepared) {
        // A replaced legacy table cannot reuse old native pointer identities.
        if (binding.legacy != legacy || !binding.valid) {
            vu_native_geometry::registerProgramTable(nullptr);
            return false;
        }
        return vu_native_geometry::registerProgramTable(selectedNativeTable());
    }
    binding.prepared = true;
    binding.legacy = legacy;
    if (!legacy->programs || !legacy->count || legacy->count > 64)
        return false;
    const vu_specialized::Program* weighted = nullptr;
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
    const vu_specialized::Program* geometry64e = nullptr;
#endif
#if defined(REO_HAVE_NATIVE_STATIC_GEOMETRY)
    const vu_specialized::Program* room = nullptr;
#endif
    for (uint32_t i = 0; i < legacy->count; ++i) {
        const auto& program = legacy->programs[i];
        if (!program.exactCodeImage || program.codeBytes != 16384 || program.dataBytes != 16384)
            continue;
        const auto digest =
            reo_native_image_identity::sha256(program.exactCodeImage, program.codeBytes);
        if (digest == weightedDigest) {
            if (weighted)
                return false;
            weighted = &program;
        }
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
        if (digest == rigid64eDigest) {
            if (geometry64e)
                return false;
            geometry64e = &program;
        }
#endif
#if defined(REO_HAVE_NATIVE_STATIC_GEOMETRY)
        if (digest == staticDigest) {
            if (room)
                return false;
            room = &program;
        }
#endif
    }
    if (!weighted)
        return false;
    binding.weightedEntries[0x348 / 8] = &rigidLoop;
#if defined(REO_HAVE_NATIVE_MULTIBONE_GEOMETRY)
    binding.weightedEntries[0x760 / 8] = &multiBoneLoop;
#endif
    binding.programs[binding.table.count++] = {weighted, binding.weightedEntries.data()};
#if defined(REO_HAVE_NATIVE_STATIC_GEOMETRY)
    if (!room)
        return false;
    binding.staticEntries[0x260 / 8] = &staticLoop;
#if defined(REO_HAVE_NATIVE_STATIC_HALFSPACE_GEOMETRY)
    binding.staticEntries[0xc70 / 8] = &halfspaceLoop;
#endif
#if defined(REO_HAVE_NATIVE_STATIC_PROJECTION_GEOMETRY)
    binding.staticEntries[0x930 / 8] = &projectionLoop;
#endif
    binding.programs[binding.table.count++] = {room, binding.staticEntries.data()};
#endif
#if defined(REO_HAVE_NATIVE_64E_RIGID_GEOMETRY)
    if (!geometry64e)
        return false;
    binding.without64e.count = binding.table.count;
    binding.rigid64eEntries[0x298 / 8] = &rigid64eLoop;
    binding.programs[binding.table.count++] = {geometry64e, binding.rigid64eEntries.data()};
#endif
    binding.valid = vu_native_geometry::registerProgramTable(selectedNativeTable());
    return binding.valid;
}
