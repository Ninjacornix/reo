#pragma once
#include "upstream/first_entry_factory.hpp"
namespace reo_gpu_first_entry_selected {
inline constexpr bool BoundedAssetPackagePinned = true;
inline constexpr bool CompleteSelectionReady = false;
inline constexpr const char* packageDigest =
    "9b1d45e29c0f7f263b544ad529076fad84e27094903d63e08810a09819a9ca51";
inline reo_gpu_catalog::CatalogAssets catalogueAssets() {
    reo_gpu_catalog::CatalogAssets out;
    out.kernels[0].image = {
        "catalogue/image-2ea02b3628231f113edc3fe580f80c1d6ed45c98a7c98f9f83005665f8ad32ce.bin",
        "2ea02b3628231f113edc3fe580f80c1d6ed45c98a7c98f9f83005665f8ad32ce"};
    out.kernels[0].spirv = {"catalogue/vu_2ea02b362823.spv",
                            "c3ecbd822919cb3fb29173bb0aaccb759d63a8a30ac8e835e74afadcd7cf8a80"};
    out.kernels[0].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
    out.kernels[1].image = {
        "catalogue/image-479c350324b47c23879136a951911f6a448f4b627f52e34e220553a2f37c9c1c.bin",
        "479c350324b47c23879136a951911f6a448f4b627f52e34e220553a2f37c9c1c"};
    out.kernels[1].spirv = {"catalogue/vu_479c350324b4.spv",
                            "fbbbcc7ed4b393f67ec53be9b246a11837d6c9a6b17ec5a7b79d0f2953db4c97"};
    out.kernels[1].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
    out.kernels[2].image = {
        "catalogue/image-5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25.bin",
        "5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25"};
    out.kernels[2].spirv = {"catalogue/vu_5273fa3e9893.spv",
                            "96a5c431ebb432e8cc48e529a3a83250ea183b2e75abb55322df874b64f0828b"};
    out.kernels[2].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
    out.kernels[3].image = {
        "catalogue/image-57026e22a6bb47c66cff4b0e662a6ec200a06c92ce9fb31dc8187aa078e709d1.bin",
        "57026e22a6bb47c66cff4b0e662a6ec200a06c92ce9fb31dc8187aa078e709d1"};
    out.kernels[3].spirv = {"catalogue/vu_57026e22a6bb.spv",
                            "05a997e1deb5d63c5943c67674fb5e88c3c6b54e99fc6fdeecf37fcb6b534fa0"};
    out.kernels[3].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
    out.kernels[4].image = {
        "catalogue/image-64e4b38e853353c7c78d7363b98dca04bdd8f5fe050496f2e23d8643bbba10d3.bin",
        "64e4b38e853353c7c78d7363b98dca04bdd8f5fe050496f2e23d8643bbba10d3"};
    out.kernels[4].spirv = {"catalogue/vu_64e4b38e8533.spv",
                            "5cd43b5c763f1dd052ee7eae69b365fc97656940358776d0f439e450ee8e04b4"};
    out.kernels[4].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
    out.kernels[5].image = {
        "catalogue/image-65d42faf847a20b9df414f281d757b64c3932eccfe8cc18a59ed9edb527c3905.bin",
        "65d42faf847a20b9df414f281d757b64c3932eccfe8cc18a59ed9edb527c3905"};
    out.kernels[5].spirv = {"catalogue/vu_65d42faf847a.spv",
                            "e3f54666b22643971266254304eb4d057a0c01caba3f61cf7d750b30ff3b6cb9"};
    out.kernels[5].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
    out.kernels[6].image = {
        "catalogue/image-819696c9d5c0c9c5a7db85e6fa354f243a52851b0796fd01841181aeb9ae0bf7.bin",
        "819696c9d5c0c9c5a7db85e6fa354f243a52851b0796fd01841181aeb9ae0bf7"};
    out.kernels[6].spirv = {"catalogue/vu_819696c9d5c0.spv",
                            "10f89a6fbc058ab315596edf31246f9cd46361e8023666ade4666fb796be44e3"};
    out.kernels[6].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
    out.kernels[7].image = {
        "catalogue/image-81bb7caeca8aa1847edbe62fac2bd734e25bc0370b7d16243739355e6324f205.bin",
        "81bb7caeca8aa1847edbe62fac2bd734e25bc0370b7d16243739355e6324f205"};
    out.kernels[7].spirv = {"catalogue/vu_81bb7caeca8a.spv",
                            "0f4eb58ced3dd5c383feed4e1373d5a66de1821b50680eb251feb5147c91a468"};
    out.kernels[7].kind = reo_gpu_catalog::KernelKind::GenericV4Literal;
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
} // namespace reo_gpu_first_entry_selected
