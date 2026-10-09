#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C72F0
// Address: 0x1c72f0 - 0x1c7400
void sub_001C72F0_0x1c72f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C72F0_0x1c72f0");
#endif

    switch (ctx->pc) {
        case 0x1c733cu: goto label_1c733c;
        case 0x1c7348u: goto label_1c7348;
        case 0x1c7354u: goto label_1c7354;
        case 0x1c7368u: goto label_1c7368;
        case 0x1c73c0u: goto label_1c73c0;
        case 0x1c73ccu: goto label_1c73cc;
        default: break;
    }

    ctx->pc = 0x1c72f0u;

    // 0x1c72f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c72f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c72f4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c72f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c72f8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c72f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c72fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c72fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c7300: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7300u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7304: 0xc42251e8  lwc1        $f2, 0x51E8($at)
    ctx->pc = 0x1c7304u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20968)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1c7308: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7308u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c730c: 0xc4215064  lwc1        $f1, 0x5064($at)
    ctx->pc = 0x1c730cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20580)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c7310: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c7310u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c7314: 0xc4205f60  lwc1        $f0, 0x5F60($at)
    ctx->pc = 0x1c7314u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 24416)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c7318: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1c7318u;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1c731c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c731cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7320: 0xe42151e8  swc1        $f1, 0x51E8($at)
    ctx->pc = 0x1c7320u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20968), bits); }
    // 0x1c7324: 0x46000846  mov.s       $f1, $f1
    ctx->pc = 0x1c7324u;
    ctx->f[1] = FPU_MOV_S(ctx->f[1]);
    // 0x1c7328: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1c7328u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c732c: 0x45000024  bc1f        . + 4 + (0x24 << 2)
    ctx->pc = 0x1C732Cu;
    {
        const bool branch_taken_0x1c732c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1C7330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C732Cu;
            // 0x1c7330: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c732c) {
            ctx->pc = 0x1C73C0u;
            goto label_1c73c0;
        }
    }
    ctx->pc = 0x1C7334u;
    // 0x1c7334: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1C7334u;
    {
        const bool branch_taken_0x1c7334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7334u;
            // 0x1c7338: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7334) {
            ctx->pc = 0x1C73E4u;
            goto label_1c73e4;
        }
    }
    ctx->pc = 0x1C733Cu;
label_1c733c:
    // 0x1c733c: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c733cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7340: 0xc071f30  jal         func_1C7CC0
    ctx->pc = 0x1C7340u;
    SET_GPR_U32(ctx, 31, 0x1C7348u);
    ctx->pc = 0x1C7344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7340u;
            // 0x1c7344: 0x24843bd0  addiu       $a0, $a0, 0x3BD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CC0u;
    if (runtime->hasFunction(0x1C7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7348u; }
        if (ctx->pc != 0x1C7348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CC0_0x1c7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7348u; }
        if (ctx->pc != 0x1C7348u) { return; }
    }
    ctx->pc = 0x1C7348u;
label_1c7348:
    // 0x1c7348: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1c7348u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c734c: 0xc072ef0  jal         func_1CBBC0
    ctx->pc = 0x1C734Cu;
    SET_GPR_U32(ctx, 31, 0x1C7354u);
    ctx->pc = 0x1C7350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C734Cu;
            // 0x1c7350: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBBC0u;
    if (runtime->hasFunction(0x1CBBC0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBBC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7354u; }
        if (ctx->pc != 0x1C7354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBBC0_0x1cbbc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7354u; }
        if (ctx->pc != 0x1C7354u) { return; }
    }
    ctx->pc = 0x1C7354u;
label_1c7354:
    // 0x1c7354: 0x4410014  bgez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1C7354u;
    {
        const bool branch_taken_0x1c7354 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1C7358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7354u;
            // 0x1c7358: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7354) {
            ctx->pc = 0x1C73A8u;
            goto label_1c73a8;
        }
    }
    ctx->pc = 0x1C735Cu;
    // 0x1c735c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1c735cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c7360: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C7360u;
    SET_GPR_U32(ctx, 31, 0x1C7368u);
    ctx->pc = 0x1C7364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7360u;
            // 0x1c7364: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7368u; }
        if (ctx->pc != 0x1C7368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7368u; }
        if (ctx->pc != 0x1C7368u) { return; }
    }
    ctx->pc = 0x1C7368u;
label_1c7368:
    // 0x1c7368: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7368u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c736c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c736cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c7370: 0x942351b8  lhu         $v1, 0x51B8($at)
    ctx->pc = 0x1c7370u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c7374: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7374u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7378: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c7378u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
    // 0x1c737c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c737cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c7380: 0x8c225f58  lw          $v0, 0x5F58($at)
    ctx->pc = 0x1c7380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c7384: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1c7384u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c7388: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C7388u;
    {
        const bool branch_taken_0x1c7388 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C738Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7388u;
            // 0x1c738c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7388) {
            ctx->pc = 0x1C73A0u;
            goto label_1c73a0;
        }
    }
    ctx->pc = 0x1C7390u;
    // 0x1c7390: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1c7390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c7394: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7394u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7398: 0xac2251b0  sw          $v0, 0x51B0($at)
    ctx->pc = 0x1c7398u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 2));
    // 0x1c739c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c739cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1c73a0:
    // 0x1c73a0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1C73A0u;
    {
        const bool branch_taken_0x1c73a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C73A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C73A0u;
            // 0x1c73a4: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c73a0) {
            ctx->pc = 0x1C73E8u;
            goto label_1c73e8;
        }
    }
    ctx->pc = 0x1C73A8u;
label_1c73a8:
    // 0x1c73a8: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C73A8u;
    {
        const bool branch_taken_0x1c73a8 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1C73ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C73A8u;
            // 0x1c73ac: 0x3c040033  lui         $a0, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c73a8) {
            ctx->pc = 0x1C73D4u;
            goto label_1c73d4;
        }
    }
    ctx->pc = 0x1C73B0u;
    // 0x1c73b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c73b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c73b4: 0x24843bd0  addiu       $a0, $a0, 0x3BD0
    ctx->pc = 0x1c73b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15312));
    // 0x1c73b8: 0xc071f60  jal         func_1C7D80
    ctx->pc = 0x1C73B8u;
    SET_GPR_U32(ctx, 31, 0x1C73C0u);
    ctx->pc = 0x1C73BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C73B8u;
            // 0x1c73bc: 0x2118021  addu        $s0, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D80u;
    if (runtime->hasFunction(0x1C7D80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C73C0u; }
        if (ctx->pc != 0x1C73C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D80_0x1c7d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C73C0u; }
        if (ctx->pc != 0x1C73C0u) { return; }
    }
    ctx->pc = 0x1C73C0u;
label_1c73c0:
    // 0x1c73c0: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c73c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c73c4: 0xc071f24  jal         func_1C7C90
    ctx->pc = 0x1C73C4u;
    SET_GPR_U32(ctx, 31, 0x1C73CCu);
    ctx->pc = 0x1C73C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C73C4u;
            // 0x1c73c8: 0x24843bd0  addiu       $a0, $a0, 0x3BD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7C90u;
    if (runtime->hasFunction(0x1C7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C73CCu; }
        if (ctx->pc != 0x1C73CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7C90_0x1c7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C73CCu; }
        if (ctx->pc != 0x1C73CCu) { return; }
    }
    ctx->pc = 0x1C73CCu;
label_1c73cc:
    // 0x1c73cc: 0x1440ffdb  bnez        $v0, . + 4 + (-0x25 << 2)
    ctx->pc = 0x1C73CCu;
    {
        const bool branch_taken_0x1c73cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C73D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C73CCu;
            // 0x1c73d0: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c73cc) {
            ctx->pc = 0x1C733Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c733c;
        }
    }
    ctx->pc = 0x1C73D4u;
label_1c73d4:
    // 0x1c73d4: 0x1a000003  blez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C73D4u;
    {
        const bool branch_taken_0x1c73d4 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x1C73D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C73D4u;
            // 0x1c73d8: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c73d4) {
            ctx->pc = 0x1C73E4u;
            goto label_1c73e4;
        }
    }
    ctx->pc = 0x1C73DCu;
    // 0x1c73dc: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c73dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c73e0: 0xac2051e8  sw          $zero, 0x51E8($at)
    ctx->pc = 0x1c73e0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20968), GPR_U32(ctx, 0));
label_1c73e4:
    // 0x1c73e4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c73e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1c73e8:
    // 0x1c73e8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c73e8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c73ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c73ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c73f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C73F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C73F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C73F0u;
            // 0x1c73f4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C733Cu: goto label_1c733c;
            case 0x1C7348u: goto label_1c7348;
            case 0x1C7354u: goto label_1c7354;
            case 0x1C7368u: goto label_1c7368;
            case 0x1C73A0u: goto label_1c73a0;
            case 0x1C73A8u: goto label_1c73a8;
            case 0x1C73C0u: goto label_1c73c0;
            case 0x1C73CCu: goto label_1c73cc;
            case 0x1C73D4u: goto label_1c73d4;
            case 0x1C73E4u: goto label_1c73e4;
            case 0x1C73E8u: goto label_1c73e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C73F8u;
    // 0x1c73f8: 0x0  nop
    ctx->pc = 0x1c73f8u;
    // NOP
    // 0x1c73fc: 0x0  nop
    ctx->pc = 0x1c73fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
