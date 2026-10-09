#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F970
// Address: 0x18f970 - 0x18fce0
void sub_0018F970_0x18f970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F970_0x18f970");
#endif

    switch (ctx->pc) {
        case 0x18f9fcu: goto label_18f9fc;
        case 0x18fab4u: goto label_18fab4;
        case 0x18fca0u: goto label_18fca0;
        default: break;
    }

    ctx->pc = 0x18f970u;

    // 0x18f970: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x18f970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x18f974: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x18f974u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x18f978: 0x7fb50070  sq          $s5, 0x70($sp)
    ctx->pc = 0x18f978u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 21));
    // 0x18f97c: 0x7fb40060  sq          $s4, 0x60($sp)
    ctx->pc = 0x18f97cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 20));
    // 0x18f980: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x18f980u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f984: 0x7fb30050  sq          $s3, 0x50($sp)
    ctx->pc = 0x18f984u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 19));
    // 0x18f988: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x18f988u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f98c: 0x7fb20040  sq          $s2, 0x40($sp)
    ctx->pc = 0x18f98cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 18));
    // 0x18f990: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x18f990u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f994: 0x7fb10030  sq          $s1, 0x30($sp)
    ctx->pc = 0x18f994u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 17));
    // 0x18f998: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x18f998u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f99c: 0x7fb00020  sq          $s0, 0x20($sp)
    ctx->pc = 0x18f99cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 16));
    // 0x18f9a0: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x18f9a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f9a4: 0xe7b80010  swc1        $f24, 0x10($sp)
    ctx->pc = 0x18f9a4u;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x18f9a8: 0x78043  sra         $s0, $a3, 1
    ctx->pc = 0x18f9a8u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 7), 1));
    // 0x18f9ac: 0xe7b7000c  swc1        $f23, 0xC($sp)
    ctx->pc = 0x18f9acu;
    { float f = ctx->f[23]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 12), bits); }
    // 0x18f9b0: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x18f9b0u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x18f9b4: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x18f9b4u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x18f9b8: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x18f9b8u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x18f9bc: 0x460065c6  mov.s       $f23, $f12
    ctx->pc = 0x18f9bcu;
    ctx->f[23] = FPU_MOV_S(ctx->f[12]);
    // 0x18f9c0: 0x6410003  bgez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x18F9C0u;
    {
        const bool branch_taken_0x18f9c0 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x18F9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F9C0u;
            // 0x18f9c4: 0x46006d86  mov.s       $f22, $f13 (Delay Slot)
        ctx->f[22] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f9c0) {
            ctx->pc = 0x18F9D0u;
            goto label_18f9d0;
        }
    }
    ctx->pc = 0x18F9C8u;
    // 0x18f9c8: 0x26420001  addiu       $v0, $s2, 0x1
    ctx->pc = 0x18f9c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x18f9cc: 0x28043  sra         $s0, $v0, 1
    ctx->pc = 0x18f9ccu;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), 1));
label_18f9d0:
    // 0x18f9d0: 0x44900000  mtc1        $s0, $f0
    ctx->pc = 0x18f9d0u;
    { uint32_t bits = GPR_U32(ctx, 16); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f9d4: 0x111043  sra         $v0, $s1, 1
    ctx->pc = 0x18f9d4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 17), 1));
    // 0x18f9d8: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18F9D8u;
    {
        const bool branch_taken_0x18f9d8 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x18F9DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F9D8u;
            // 0x18f9dc: 0x46800620  cvt.s.w     $f24, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[24] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f9d8) {
            ctx->pc = 0x18F9E8u;
            goto label_18f9e8;
        }
    }
    ctx->pc = 0x18F9E0u;
    // 0x18f9e0: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x18f9e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x18f9e4: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18f9e4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_18f9e8:
    // 0x18f9e8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18f9e8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f9ec: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18f9ecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x18f9f0: 0x24844dc0  addiu       $a0, $a0, 0x4DC0
    ctx->pc = 0x18f9f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19904));
    // 0x18f9f4: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x18F9F4u;
    SET_GPR_U32(ctx, 31, 0x18F9FCu);
    ctx->pc = 0x18F9F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F9F4u;
            // 0x18f9f8: 0x46800520  cvt.s.w     $f20, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[20] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F9FCu; }
        if (ctx->pc != 0x18F9FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F9FCu; }
        if (ctx->pc != 0x18F9FCu) { return; }
    }
    ctx->pc = 0x18F9FCu;
label_18f9fc:
    // 0x18f9fc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f9fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fa00: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x18fa00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x18fa04: 0xe4384dc0  swc1        $f24, 0x4DC0($at)
    ctx->pc = 0x18fa04u;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19904), bits); }
    // 0x18fa08: 0x4600a007  neg.s       $f0, $f20
    ctx->pc = 0x18fa08u;
    ctx->f[0] = FPU_NEG_S(ctx->f[20]);
    // 0x18fa0c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fa0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fa10: 0xe4204dd4  swc1        $f0, 0x4DD4($at)
    ctx->pc = 0x18fa10u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19924), bits); }
    // 0x18fa14: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fa14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fa18: 0xe4374df8  swc1        $f23, 0x4DF8($at)
    ctx->pc = 0x18fa18u;
    { float f = ctx->f[23]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19960), bits); }
    // 0x18fa1c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fa1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fa20: 0x44940800  mtc1        $s4, $f1
    ctx->pc = 0x18fa20u;
    { uint32_t bits = GPR_U32(ctx, 20); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18fa24: 0xac224dfc  sw          $v0, 0x4DFC($at)
    ctx->pc = 0x18fa24u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 19964), GPR_U32(ctx, 2));
    // 0x18fa28: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18fa28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18fa2c: 0x44930000  mtc1        $s3, $f0
    ctx->pc = 0x18fa2cu;
    { uint32_t bits = GPR_U32(ctx, 19); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fa30: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x18fa30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x18fa34: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x18fa34u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x18fa38: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fa38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fa3c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18fa3cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18fa40: 0x4617b541  sub.s       $f21, $f22, $f23
    ctx->pc = 0x18fa40u;
    ctx->f[21] = FPU_SUB_S(ctx->f[22], ctx->f[23]);
    // 0x18fa44: 0xe4354de8  swc1        $f21, 0x4DE8($at)
    ctx->pc = 0x18fa44u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19944), bits); }
    // 0x18fa48: 0x46180840  add.s       $f1, $f1, $f24
    ctx->pc = 0x18fa48u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[24]);
    // 0x18fa4c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fa4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fa50: 0xe4214df0  swc1        $f1, 0x4DF0($at)
    ctx->pc = 0x18fa50u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19952), bits); }
    // 0x18fa54: 0x46140000  add.s       $f0, $f0, $f20
    ctx->pc = 0x18fa54u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[20]);
    // 0x18fa58: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fa58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fa5c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x18FA5Cu;
    {
        const bool branch_taken_0x18fa5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18FA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FA5Cu;
            // 0x18fa60: 0xe4204df4  swc1        $f0, 0x4DF4($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19956), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fa5c) {
            ctx->pc = 0x18FA8Cu;
            goto label_18fa8c;
        }
    }
    ctx->pc = 0x18FA64u;
    // 0x18fa64: 0x6610003  bgez        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x18FA64u;
    {
        const bool branch_taken_0x18fa64 = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x18FA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FA64u;
            // 0x18fa68: 0x131043  sra         $v0, $s3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fa64) {
            ctx->pc = 0x18FA74u;
            goto label_18fa74;
        }
    }
    ctx->pc = 0x18FA6Cu;
    // 0x18fa6c: 0x26620001  addiu       $v0, $s3, 0x1
    ctx->pc = 0x18fa6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x18fa70: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18fa70u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_18fa74:
    // 0x18fa74: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x18fa74u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fa78: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18FA78u;
    {
        const bool branch_taken_0x18fa78 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x18FA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FA78u;
            // 0x18fa7c: 0x111043  sra         $v0, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fa78) {
            ctx->pc = 0x18FA88u;
            goto label_18fa88;
        }
    }
    ctx->pc = 0x18FA80u;
    // 0x18fa80: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x18fa80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x18fa84: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18fa84u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_18fa88:
    // 0x18fa88: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x18fa88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_18fa8c:
    // 0x18fa8c: 0x44900000  mtc1        $s0, $f0
    ctx->pc = 0x18fa8cu;
    { uint32_t bits = GPR_U32(ctx, 16); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fa90: 0x111043  sra         $v0, $s1, 1
    ctx->pc = 0x18fa90u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 17), 1));
    // 0x18fa94: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18FA94u;
    {
        const bool branch_taken_0x18fa94 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x18FA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FA94u;
            // 0x18fa98: 0x46800620  cvt.s.w     $f24, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[24] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fa94) {
            ctx->pc = 0x18FAA4u;
            goto label_18faa4;
        }
    }
    ctx->pc = 0x18FA9Cu;
    // 0x18fa9c: 0x26220001  addiu       $v0, $s1, 0x1
    ctx->pc = 0x18fa9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x18faa0: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18faa0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_18faa4:
    // 0x18faa4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18faa4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18faa8: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x18faa8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18faac: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x18FAACu;
    SET_GPR_U32(ctx, 31, 0x18FAB4u);
    ctx->pc = 0x18FAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18FAACu;
            // 0x18fab0: 0x46800520  cvt.s.w     $f20, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[20] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FAB4u; }
        if (ctx->pc != 0x18FAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FAB4u; }
        if (ctx->pc != 0x18FAB4u) { return; }
    }
    ctx->pc = 0x18FAB4u;
label_18fab4:
    // 0x18fab4: 0x44911000  mtc1        $s1, $f2
    ctx->pc = 0x18fab4u;
    { uint32_t bits = GPR_U32(ctx, 17); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x18fab8: 0x3c043f00  lui         $a0, 0x3F00
    ctx->pc = 0x18fab8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16128 << 16));
    // 0x18fabc: 0x44940800  mtc1        $s4, $f1
    ctx->pc = 0x18fabcu;
    { uint32_t bits = GPR_U32(ctx, 20); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18fac0: 0x3c024500  lui         $v0, 0x4500
    ctx->pc = 0x18fac0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17664 << 16));
    // 0x18fac4: 0x44930000  mtc1        $s3, $f0
    ctx->pc = 0x18fac4u;
    { uint32_t bits = GPR_U32(ctx, 19); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fac8: 0x3c053f80  lui         $a1, 0x3F80
    ctx->pc = 0x18fac8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16256 << 16));
    // 0x18facc: 0x46801160  cvt.s.w     $f5, $f2
    ctx->pc = 0x18faccu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[5] = FPU_CVT_S_W(tmp); }
    // 0x18fad0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18fad0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18fad4: 0x24030800  addiu       $v1, $zero, 0x800
    ctx->pc = 0x18fad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x18fad8: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x18fad8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x18fadc: 0x44921800  mtc1        $s2, $f3
    ctx->pc = 0x18fadcu;
    { uint32_t bits = GPR_U32(ctx, 18); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x18fae0: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18fae0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18fae4: 0xe6b80000  swc1        $f24, 0x0($s5)
    ctx->pc = 0x18fae4u;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
    // 0x18fae8: 0x4600a087  neg.s       $f2, $f20
    ctx->pc = 0x18fae8u;
    ctx->f[2] = FPU_NEG_S(ctx->f[20]);
    // 0x18faec: 0xe6a20014  swc1        $f2, 0x14($s5)
    ctx->pc = 0x18faecu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 20), bits); }
    // 0x18faf0: 0x461809c0  add.s       $f7, $f1, $f24
    ctx->pc = 0x18faf0u;
    ctx->f[7] = FPU_ADD_S(ctx->f[1], ctx->f[24]);
    // 0x18faf4: 0xe6b50028  swc1        $f21, 0x28($s5)
    ctx->pc = 0x18faf4u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 40), bits); }
    // 0x18faf8: 0x46140080  add.s       $f2, $f0, $f20
    ctx->pc = 0x18faf8u;
    ctx->f[2] = FPU_ADD_S(ctx->f[0], ctx->f[20]);
    // 0x18fafc: 0xe6a70030  swc1        $f7, 0x30($s5)
    ctx->pc = 0x18fafcu;
    { float f = ctx->f[7]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 48), bits); }
    // 0x18fb00: 0xe6a20034  swc1        $f2, 0x34($s5)
    ctx->pc = 0x18fb00u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 52), bits); }
    // 0x18fb04: 0xaea5003c  sw          $a1, 0x3C($s5)
    ctx->pc = 0x18fb04u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 60), GPR_U32(ctx, 5));
    // 0x18fb08: 0x468019a0  cvt.s.w     $f6, $f3
    ctx->pc = 0x18fb08u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[6] = FPU_CVT_S_W(tmp); }
    // 0x18fb0c: 0xc427f9f4  lwc1        $f7, -0x60C($at)
    ctx->pc = 0x18fb0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x18fb10: 0x44844000  mtc1        $a0, $f8
    ctx->pc = 0x18fb10u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x18fb14: 0xc6a30028  lwc1        $f3, 0x28($s5)
    ctx->pc = 0x18fb14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18fb18: 0x44822000  mtc1        $v0, $f4
    ctx->pc = 0x18fb18u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[4], &bits, sizeof(bits)); }
    // 0x18fb1c: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x18fb1cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x18fb20: 0x460039c7  neg.s       $f7, $f7
    ctx->pc = 0x18fb20u;
    ctx->f[7] = FPU_NEG_S(ctx->f[7]);
    // 0x18fb24: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18fb24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18fb28: 0x460741c2  mul.s       $f7, $f8, $f7
    ctx->pc = 0x18fb28u;
    ctx->f[7] = FPU_MUL_S(ctx->f[8], ctx->f[7]);
    // 0x18fb2c: 0x460718c2  mul.s       $f3, $f3, $f7
    ctx->pc = 0x18fb2cu;
    ctx->f[3] = FPU_MUL_S(ctx->f[3], ctx->f[7]);
    // 0x18fb30: 0xe6a30028  swc1        $f3, 0x28($s5)
    ctx->pc = 0x18fb30u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 40), bits); }
    // 0x18fb34: 0x8c22fed8  lw          $v0, -0x128($at)
    ctx->pc = 0x18fb34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x18fb38: 0xc6a30030  lwc1        $f3, 0x30($s5)
    ctx->pc = 0x18fb38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18fb3c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18fb3cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x18fb40: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18fb40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18fb44: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x18fb44u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18fb48: 0x44823800  mtc1        $v0, $f7
    ctx->pc = 0x18fb48u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[7], &bits, sizeof(bits)); }
    // 0x18fb4c: 0x0  nop
    ctx->pc = 0x18fb4cu;
    // NOP
    // 0x18fb50: 0x468039e0  cvt.s.w     $f7, $f7
    ctx->pc = 0x18fb50u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[7], sizeof(tmp)); ctx->f[7] = FPU_CVT_S_W(tmp); }
    // 0x18fb54: 0x460718c0  add.s       $f3, $f3, $f7
    ctx->pc = 0x18fb54u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[7]);
    // 0x18fb58: 0xe6a30030  swc1        $f3, 0x30($s5)
    ctx->pc = 0x18fb58u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 48), bits); }
    // 0x18fb5c: 0x8c22fed0  lw          $v0, -0x130($at)
    ctx->pc = 0x18fb5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966992)));
    // 0x18fb60: 0xc6a30034  lwc1        $f3, 0x34($s5)
    ctx->pc = 0x18fb60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18fb64: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18fb64u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x18fb68: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18fb68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18fb6c: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x18fb6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18fb70: 0x44823800  mtc1        $v0, $f7
    ctx->pc = 0x18fb70u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[7], &bits, sizeof(bits)); }
    // 0x18fb74: 0x0  nop
    ctx->pc = 0x18fb74u;
    // NOP
    // 0x18fb78: 0x468039e0  cvt.s.w     $f7, $f7
    ctx->pc = 0x18fb78u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[7], sizeof(tmp)); ctx->f[7] = FPU_CVT_S_W(tmp); }
    // 0x18fb7c: 0x460718c0  add.s       $f3, $f3, $f7
    ctx->pc = 0x18fb7cu;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[7]);
    // 0x18fb80: 0xe6a30034  swc1        $f3, 0x34($s5)
    ctx->pc = 0x18fb80u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 52), bits); }
    // 0x18fb84: 0xc423f9f4  lwc1        $f3, -0x60C($at)
    ctx->pc = 0x18fb84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18fb88: 0x460340c2  mul.s       $f3, $f8, $f3
    ctx->pc = 0x18fb88u;
    ctx->f[3] = FPU_MUL_S(ctx->f[8], ctx->f[3]);
    // 0x18fb8c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fb8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fb90: 0xe6a30038  swc1        $f3, 0x38($s5)
    ctx->pc = 0x18fb90u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 56), bits); }
    // 0x18fb94: 0xc6a30030  lwc1        $f3, 0x30($s5)
    ctx->pc = 0x18fb94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18fb98: 0xe42341c0  swc1        $f3, 0x41C0($at)
    ctx->pc = 0x18fb98u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16832), bits); }
    // 0x18fb9c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fb9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fba0: 0xc42341c0  lwc1        $f3, 0x41C0($at)
    ctx->pc = 0x18fba0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16832)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18fba4: 0xc6a70034  lwc1        $f7, 0x34($s5)
    ctx->pc = 0x18fba4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x18fba8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fba8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fbac: 0xe42741b8  swc1        $f7, 0x41B8($at)
    ctx->pc = 0x18fbacu;
    { float f = ctx->f[7]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16824), bits); }
    // 0x18fbb0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fbb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fbb4: 0xe42141e0  swc1        $f1, 0x41E0($at)
    ctx->pc = 0x18fbb4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16864), bits); }
    // 0x18fbb8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fbb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fbbc: 0x460320c1  sub.s       $f3, $f4, $f3
    ctx->pc = 0x18fbbcu;
    ctx->f[3] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x18fbc0: 0xe42041d8  swc1        $f0, 0x41D8($at)
    ctx->pc = 0x18fbc0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16856), bits); }
    // 0x18fbc4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fbc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fbc8: 0xe42641d0  swc1        $f6, 0x41D0($at)
    ctx->pc = 0x18fbc8u;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16848), bits); }
    // 0x18fbcc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fbccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fbd0: 0xe42541c8  swc1        $f5, 0x41C8($at)
    ctx->pc = 0x18fbd0u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16840), bits); }
    // 0x18fbd4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fbd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fbd8: 0x46021834  c.lt.s      $f3, $f2
    ctx->pc = 0x18fbd8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[3], ctx->f[2])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18fbdc: 0x45000007  bc1f        . + 4 + (0x7 << 2)
    ctx->pc = 0x18FBDCu;
    {
        const bool branch_taken_0x18fbdc = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18FBE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FBDCu;
            // 0x18fbe0: 0xe42341b0  swc1        $f3, 0x41B0($at) (Delay Slot)
        { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16816), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fbdc) {
            ctx->pc = 0x18FBFCu;
            goto label_18fbfc;
        }
    }
    ctx->pc = 0x18FBE4u;
    // 0x18fbe4: 0x3c02bf80  lui         $v0, 0xBF80
    ctx->pc = 0x18fbe4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x18fbe8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fbe8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fbec: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18fbecu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fbf0: 0x0  nop
    ctx->pc = 0x18fbf0u;
    // NOP
    // 0x18fbf4: 0x46001802  mul.s       $f0, $f3, $f0
    ctx->pc = 0x18fbf4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[3], ctx->f[0]);
    // 0x18fbf8: 0xe42041b0  swc1        $f0, 0x41B0($at)
    ctx->pc = 0x18fbf8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16816), bits); }
label_18fbfc:
    // 0x18fbfc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fbfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc00: 0x3c024500  lui         $v0, 0x4500
    ctx->pc = 0x18fc00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17664 << 16));
    // 0x18fc04: 0xc42241b0  lwc1        $f2, 0x41B0($at)
    ctx->pc = 0x18fc04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16816)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x18fc08: 0x44821800  mtc1        $v0, $f3
    ctx->pc = 0x18fc08u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x18fc0c: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x18fc0cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fc10: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc14: 0xc42141b8  lwc1        $f1, 0x41B8($at)
    ctx->pc = 0x18fc14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16824)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18fc18: 0x46021881  sub.s       $f2, $f3, $f2
    ctx->pc = 0x18fc18u;
    ctx->f[2] = FPU_SUB_S(ctx->f[3], ctx->f[2]);
    // 0x18fc1c: 0x46011841  sub.s       $f1, $f3, $f1
    ctx->pc = 0x18fc1cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[3], ctx->f[1]);
    // 0x18fc20: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc24: 0xe42241b0  swc1        $f2, 0x41B0($at)
    ctx->pc = 0x18fc24u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16816), bits); }
    // 0x18fc28: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc2c: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x18fc2cu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18fc30: 0x45000007  bc1f        . + 4 + (0x7 << 2)
    ctx->pc = 0x18FC30u;
    {
        const bool branch_taken_0x18fc30 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18FC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FC30u;
            // 0x18fc34: 0xe42141a8  swc1        $f1, 0x41A8($at) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16808), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18fc30) {
            ctx->pc = 0x18FC50u;
            goto label_18fc50;
        }
    }
    ctx->pc = 0x18FC38u;
    // 0x18fc38: 0x3c02bf80  lui         $v0, 0xBF80
    ctx->pc = 0x18fc38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x18fc3c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc40: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18fc40u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18fc44: 0x0  nop
    ctx->pc = 0x18fc44u;
    // NOP
    // 0x18fc48: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18fc48u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18fc4c: 0xe42041a8  swc1        $f0, 0x41A8($at)
    ctx->pc = 0x18fc4cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16808), bits); }
label_18fc50:
    // 0x18fc50: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc54: 0x3c024500  lui         $v0, 0x4500
    ctx->pc = 0x18fc54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17664 << 16));
    // 0x18fc58: 0xc42141a8  lwc1        $f1, 0x41A8($at)
    ctx->pc = 0x18fc58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16808)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18fc5c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18fc5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fc60: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x18fc60u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x18fc64: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18fc64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fc68: 0x4600bb06  mov.s       $f12, $f23
    ctx->pc = 0x18fc68u;
    ctx->f[12] = FPU_MOV_S(ctx->f[23]);
    // 0x18fc6c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc70: 0xc42041b0  lwc1        $f0, 0x41B0($at)
    ctx->pc = 0x18fc70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16816)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18fc74: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x18fc74u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x18fc78: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc7c: 0xe42141a8  swc1        $f1, 0x41A8($at)
    ctx->pc = 0x18fc7cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 16808), bits); }
    // 0x18fc80: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x18fc80u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x18fc84: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18fc84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18fc88: 0xc42041a8  lwc1        $f0, 0x41A8($at)
    ctx->pc = 0x18fc88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16808)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18fc8c: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x18fc8cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x18fc90: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x18fc90u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x18fc94: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x18fc94u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x18fc98: 0xc063f38  jal         func_18FCE0
    ctx->pc = 0x18FC98u;
    SET_GPR_U32(ctx, 31, 0x18FCA0u);
    ctx->pc = 0x18FC9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18FC98u;
            // 0x18fc9c: 0x4600b346  mov.s       $f13, $f22 (Delay Slot)
        ctx->f[13] = FPU_MOV_S(ctx->f[22]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FCE0u;
    if (runtime->hasFunction(0x18FCE0u)) {
        auto targetFn = runtime->lookupFunction(0x18FCE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FCA0u; }
        if (ctx->pc != 0x18FCA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FCE0_0x18fce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FCA0u; }
        if (ctx->pc != 0x18FCA0u) { return; }
    }
    ctx->pc = 0x18FCA0u;
label_18fca0:
    // 0x18fca0: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x18fca0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x18fca4: 0xc7b80010  lwc1        $f24, 0x10($sp)
    ctx->pc = 0x18fca4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[24] = f; }
    // 0x18fca8: 0x7bb50070  lq          $s5, 0x70($sp)
    ctx->pc = 0x18fca8u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x18fcac: 0xc7b7000c  lwc1        $f23, 0xC($sp)
    ctx->pc = 0x18fcacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[23] = f; }
    // 0x18fcb0: 0x7bb40060  lq          $s4, 0x60($sp)
    ctx->pc = 0x18fcb0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x18fcb4: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x18fcb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x18fcb8: 0x7bb30050  lq          $s3, 0x50($sp)
    ctx->pc = 0x18fcb8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18fcbc: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x18fcbcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x18fcc0: 0x7bb20040  lq          $s2, 0x40($sp)
    ctx->pc = 0x18fcc0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18fcc4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x18fcc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x18fcc8: 0x7bb10030  lq          $s1, 0x30($sp)
    ctx->pc = 0x18fcc8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18fccc: 0x7bb00020  lq          $s0, 0x20($sp)
    ctx->pc = 0x18fcccu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18fcd0: 0x3e00008  jr          $ra
    ctx->pc = 0x18FCD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FCD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FCD0u;
            // 0x18fcd4: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F9D0u: goto label_18f9d0;
            case 0x18F9E8u: goto label_18f9e8;
            case 0x18F9FCu: goto label_18f9fc;
            case 0x18FA74u: goto label_18fa74;
            case 0x18FA88u: goto label_18fa88;
            case 0x18FA8Cu: goto label_18fa8c;
            case 0x18FAA4u: goto label_18faa4;
            case 0x18FAB4u: goto label_18fab4;
            case 0x18FBFCu: goto label_18fbfc;
            case 0x18FC50u: goto label_18fc50;
            case 0x18FCA0u: goto label_18fca0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18FCD8u;
    // 0x18fcd8: 0x0  nop
    ctx->pc = 0x18fcd8u;
    // NOP
    // 0x18fcdc: 0x0  nop
    ctx->pc = 0x18fcdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
