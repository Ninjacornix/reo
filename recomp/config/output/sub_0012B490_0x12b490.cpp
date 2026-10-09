#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B490
// Address: 0x12b490 - 0x12b530
void sub_0012B490_0x12b490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B490_0x12b490");
#endif

    switch (ctx->pc) {
        case 0x12b4e4u: goto label_12b4e4;
        case 0x12b4f8u: goto label_12b4f8;
        case 0x12b508u: goto label_12b508;
        case 0x12b514u: goto label_12b514;
        default: break;
    }

    ctx->pc = 0x12b490u;

    // 0x12b490: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b490u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b494: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12b494u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12b498: 0x8c477d78  lw          $a3, 0x7D78($v0)
    ctx->pc = 0x12b498u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32120)));
    // 0x12b49c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x12b49cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x12b4a0: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12b4a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12b4a4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b4a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b4a8: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b4a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b4ac: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12b4acu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12b4b0: 0x24635d70  addiu       $v1, $v1, 0x5D70
    ctx->pc = 0x12b4b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 23920));
    // 0x12b4b4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12b4b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b4b8: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x12b4b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x12b4bc: 0x24a5af60  addiu       $a1, $a1, -0x50A0
    ctx->pc = 0x12b4bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946656));
    // 0x12b4c0: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x12b4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x12b4c4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12b4c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12b4c8: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x12b4c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x12b4cc: 0x261004f0  addiu       $s0, $s0, 0x4F0
    ctx->pc = 0x12b4ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1264));
    // 0x12b4d0: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x12b4d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x12b4d4: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x12b4d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x12b4d8: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12b4d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12b4dc: 0xc045108  jal         func_114420
    ctx->pc = 0x12B4DCu;
    SET_GPR_U32(ctx, 31, 0x12B4E4u);
    ctx->pc = 0x12B4E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B4DCu;
            // 0x12b4e0: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B4E4u; }
        if (ctx->pc != 0x12B4E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B4E4u; }
        if (ctx->pc != 0x12B4E4u) { return; }
    }
    ctx->pc = 0x12B4E4u;
label_12b4e4:
    // 0x12b4e4: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12b4e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12b4e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12b4e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b4ec: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12b4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b4f0: 0xc045110  jal         func_114440
    ctx->pc = 0x12B4F0u;
    SET_GPR_U32(ctx, 31, 0x12B4F8u);
    ctx->pc = 0x12B4F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B4F0u;
            // 0x12b4f4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B4F8u; }
        if (ctx->pc != 0x12B4F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B4F8u; }
        if (ctx->pc != 0x12B4F8u) { return; }
    }
    ctx->pc = 0x12B4F8u;
label_12b4f8:
    // 0x12b4f8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b4fc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b4fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b500: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B500u;
    SET_GPR_U32(ctx, 31, 0x12B508u);
    ctx->pc = 0x12B504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B500u;
            // 0x12b504: 0x8c45047c  lw          $a1, 0x47C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1148)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B508u; }
        if (ctx->pc != 0x12B508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B508u; }
        if (ctx->pc != 0x12B508u) { return; }
    }
    ctx->pc = 0x12B508u;
label_12b508:
    // 0x12b508: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b508u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b50c: 0xc04ac56  jal         func_12B158
    ctx->pc = 0x12B50Cu;
    SET_GPR_U32(ctx, 31, 0x12B514u);
    ctx->pc = 0x12B158u;
    if (runtime->hasFunction(0x12B158u)) {
        auto targetFn = runtime->lookupFunction(0x12B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B514u; }
        if (ctx->pc != 0x12B514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B514u; }
        if (ctx->pc != 0x12B514u) { return; }
    }
    ctx->pc = 0x12B514u;
label_12b514:
    // 0x12b514: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b514u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b518: 0x246304ec  addiu       $v1, $v1, 0x4EC
    ctx->pc = 0x12b518u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1260));
    // 0x12b51c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b51cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b520: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12b520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12b524: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12b524u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b528: 0x3e00008  jr          $ra
    ctx->pc = 0x12B528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B528u;
            // 0x12b52c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B4E4u: goto label_12b4e4;
            case 0x12B4F8u: goto label_12b4f8;
            case 0x12B508u: goto label_12b508;
            case 0x12B514u: goto label_12b514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B530u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
