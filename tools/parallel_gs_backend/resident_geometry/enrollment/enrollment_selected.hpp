#pragma once
#include "catalogue_enrollment.hpp"
// Incremental live-plumbing package (trial stage 2, mixed execution). Root
// packager record: build-ninja/m2-gpu-incremental-launch-agent/ (package
// assembly receipt, original header backup, live run evidence). All 8 reached
// VU images are registered; exactly ONE program (527-static, image
// 5273fa3e...) is admitted for GPU launches via perProgramAdmission with
// device-oracle entry coverage {0x58,0x128,0x528}; every other program keeps
// all proofs FALSE and falls back to CPU from coherent dual-written banks.
// incrementalEnrollment still selects the record-only session + owner upload
// processing for anything not admitted. ownerProtocolCertified is asserted
// FOR THIS TRIAL: the plumbing run exercises ParallelWhole2eaOwner
// enqueue/retire on launch-less batches; revert on any divergence from
// CPU-only behavior.
namespace reo_gpu_enrollment_selected {
inline constexpr bool ready = true;
inline constexpr bool usesLiteralReuse = false;
inline constexpr const char* packageDigest =
    "11ad6d9dfa0ccc25bf5d3dca7b8b5c17d3fd0d0707f0e3cbbba532d5e3262e33";
inline constexpr const char* evidenceDigest =
    "ebd8d3203c9c0eecdc2031ab0b421cc00f618b20d6504088acc50ba816c41400";
inline constexpr const char* reviewDigest =
    "2b22e94f201561b8b61a14e429b6b8edd8d064bc14d25dbe1939734c022cb9fd";
inline reo_gpu_catalog::CatalogAssets assets() {
    reo_gpu_catalog::CatalogAssets out;
    out.kernels[0].image = {
        "catalogue/image-2ea02b3628231f113edc3fe580f80c1d6ed45c98a7c98f9f83005665f8ad32ce.bin",
        "2ea02b3628231f113edc3fe580f80c1d6ed45c98a7c98f9f83005665f8ad32ce"};
    out.kernels[0].spirv = {"catalogue/vu_2ea02b362823.spv",
                            "c3ecbd822919cb3fb29173bb0aaccb759d63a8a30ac8e835e74afadcd7cf8a80"};
    out.kernels[0].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.kernels[1].image = {
        "catalogue/image-479c350324b47c23879136a951911f6a448f4b627f52e34e220553a2f37c9c1c.bin",
        "479c350324b47c23879136a951911f6a448f4b627f52e34e220553a2f37c9c1c"};
    out.kernels[1].spirv = {"catalogue/vu_479c350324b4.spv",
                            "fbbbcc7ed4b393f67ec53be9b246a11837d6c9a6b17ec5a7b79d0f2953db4c97"};
    out.kernels[1].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.kernels[2].image = {
        "catalogue/image-5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25.bin",
        "5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25"};
    out.kernels[2].spirv = {"catalogue/vu_5273fa3e9893.spv",
                            "96a5c431ebb432e8cc48e529a3a83250ea183b2e75abb55322df874b64f0828b"};
    out.kernels[2].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.kernels[3].image = {
        "catalogue/image-57026e22a6bb47c66cff4b0e662a6ec200a06c92ce9fb31dc8187aa078e709d1.bin",
        "57026e22a6bb47c66cff4b0e662a6ec200a06c92ce9fb31dc8187aa078e709d1"};
    out.kernels[3].spirv = {"catalogue/vu_57026e22a6bb.spv",
                            "05a997e1deb5d63c5943c67674fb5e88c3c6b54e99fc6fdeecf37fcb6b534fa0"};
    out.kernels[3].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.kernels[4].image = {
        "catalogue/image-64e4b38e853353c7c78d7363b98dca04bdd8f5fe050496f2e23d8643bbba10d3.bin",
        "64e4b38e853353c7c78d7363b98dca04bdd8f5fe050496f2e23d8643bbba10d3"};
    out.kernels[4].spirv = {"catalogue/vu_64e4b38e8533.spv",
                            "5cd43b5c763f1dd052ee7eae69b365fc97656940358776d0f439e450ee8e04b4"};
    out.kernels[4].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.kernels[5].image = {
        "catalogue/image-65d42faf847a20b9df414f281d757b64c3932eccfe8cc18a59ed9edb527c3905.bin",
        "65d42faf847a20b9df414f281d757b64c3932eccfe8cc18a59ed9edb527c3905"};
    out.kernels[5].spirv = {"catalogue/vu_65d42faf847a.spv",
                            "e3f54666b22643971266254304eb4d057a0c01caba3f61cf7d750b30ff3b6cb9"};
    out.kernels[5].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.kernels[6].image = {
        "catalogue/image-819696c9d5c0c9c5a7db85e6fa354f243a52851b0796fd01841181aeb9ae0bf7.bin",
        "819696c9d5c0c9c5a7db85e6fa354f243a52851b0796fd01841181aeb9ae0bf7"};
    out.kernels[6].spirv = {"catalogue/vu_819696c9d5c0.spv",
                            "10f89a6fbc058ab315596edf31246f9cd46361e8023666ade4666fb796be44e3"};
    out.kernels[6].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.kernels[7].image = {
        "catalogue/image-81bb7caeca8aa1847edbe62fac2bd734e25bc0370b7d16243739355e6324f205.bin",
        "81bb7caeca8aa1847edbe62fac2bd734e25bc0370b7d16243739355e6324f205"};
    out.kernels[7].spirv = {"catalogue/vu_81bb7caeca8a.spv",
                            "0f4eb58ced3dd5c383feed4e1373d5a66de1821b50680eb251feb5147c91a468"};
    out.kernels[7].kind = reo_gpu_catalog::KernelKind::GenericV3;
    out.auxiliary[0] = {"aux/strip.spv",
                        "d546670d1c37a7fefd6b2ad6701c4ae51c1cc8268c840bd329cb0216f4a75407"};
    out.auxiliary[1] = {"aux/unpack.spv",
                        "a8a74f3017d22f15bf0a8e346bcecefe8037271642c02ce4571db0ec6d96c396"};
    out.auxiliary[2] = {"aux/effects.spv",
                        "325f18fc19e879b58f4f27cbd48aa07025a7a87d1de148c37829b82bc2883d02"};
    out.auxiliary[3] = {"aux/patch.spv",
                        "ebc78d18b21ee4c251b888eb045de2918710e686e6e8d98432ac4dd0287a340e"};
    return out;
}
inline reo_gpu_catalog::Proofs proofs() {
    reo_gpu_catalog::Proofs out;
    for (auto& p : out.programs)
        p = reo_gpu_catalog::ProgramProof{};
    // Per-program launch admission (packager opt-in): EXACTLY one program — the
    // 527-static image 5273fa3e... — is admitted for GPU launches, and only for
    // the boundaries the same-SPIR-V device oracle actually covered:
    // m2-gpu-literal-reuse-agent/reuse-fixture validation-proof1 (GPU-all +
    // prefault + postfault, summaries PASS, accepted14, mismatch_bytes 0, pairs
    // 30890, 14 ordered packets; root log m2-gpu-literal-reuse-proof1-root.log):
    // for static-PC0128 (296) and static-PC0528 (1320), each case ran a FULL
    // actual-GPU MSCAL at that fresh entry and then a REAL operation4 MSCNT
    // continuation on the SAME GPU bank (natural + ITOP-changed variants, plus
    // transactional source-corruption prefault/postfault PASS), all compared for
    // full 632-state + 16384-data + completion + ordered-packet parity against
    // the original CPU gold. The oracle loaded the EXACT selected bytes
    // (literal-source-proof3/vu_5273fa3e9893.spv, artifact sha256 96a5c431... =
    // the catalogue pin) — one byte chain from gold-compared device runs to the
    // live owner bank; no recompilation in between. Entry PCs 0x58 (88) and 0x0
    // have NO device case for THIS binary and stay on CPU fallback. Every other
    // registered image keeps all proofs FALSE (its catalogue binaries were only
    // ever prewarmed on device, never numerically executed) and never launches.
    out.programs[2].completeSetup = true;
    out.programs[2].completeGeometry = true;
    out.programs[2].completeClipping = true;
    out.programs[2].completeCarry = true;
    out.programs[2].orderedEffects = true;
    out.programs[2].exactTermination = true;
    out.programs[2].retainedFullCallParity = true;
    out.programs[2].liveFreshEntryCoverage = true;
    // Continuation parity was proven by the SAME-oracle same-bank operation4
    // runs (retained E-bit boundaries, no header reupload), so the admitted
    // program's MSCNT may also take the GPU path.
    out.programs[2].residentResumeParity = true;
    out.programs[2].gpuLaunchAdmitted = true;
    out.programs[2].admittedFreshPCs = {296u, 1320u};
    out.fullReachedRegistry = false;
    out.mappedBankCoherence = false;
    out.gpuLiteralEffects = false;
    out.literalPoliciesCertified = false;
    out.ownerProtocolCertified = true;
    out.incrementalEnrollment = true;
    out.perProgramAdmission = true;
    return out;
}
} // namespace reo_gpu_enrollment_selected
