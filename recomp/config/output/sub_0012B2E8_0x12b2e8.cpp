#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B2E8
// Address: 0x12b2e8 - 0x12b370
void sub_0012B2E8_0x12b2e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B2E8_0x12b2e8");
#endif

    switch (ctx->pc) {
        case 0x12b33cu: goto label_12b33c;
        case 0x12b350u: goto label_12b350;
        case 0x12b360u: goto label_12b360;
        default: break;
    }

    ctx->pc = 0x12b2e8u;

    // 0x12b2e8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b2e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b2ec: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12b2ecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12b2f0: 0x8c477d78  lw          $a3, 0x7D78($v0)
    ctx->pc = 0x12b2f0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32120)));
    // 0x12b2f4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x12b2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x12b2f8: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12b2f8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12b2fc: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b2fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b300: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b304: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12b304u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12b308: 0x24631d70  addiu       $v1, $v1, 0x1D70
    ctx->pc = 0x12b308u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7536));
    // 0x12b30c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12b30cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b310: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x12b310u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x12b314: 0x24a5ac90  addiu       $a1, $a1, -0x5370
    ctx->pc = 0x12b314u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945936));
    // 0x12b318: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x12b318u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x12b31c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12b31cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12b320: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x12b320u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x12b324: 0x261004e0  addiu       $s0, $s0, 0x4E0
    ctx->pc = 0x12b324u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1248));
    // 0x12b328: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x12b328u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x12b32c: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x12b32cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x12b330: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12b330u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12b334: 0xc045108  jal         func_114420
    ctx->pc = 0x12B334u;
    SET_GPR_U32(ctx, 31, 0x12B33Cu);
    ctx->pc = 0x12B338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B334u;
            // 0x12b338: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B33Cu; }
        if (ctx->pc != 0x12B33Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B33Cu; }
        if (ctx->pc != 0x12B33Cu) { return; }
    }
    ctx->pc = 0x12B33Cu;
label_12b33c:
    // 0x12b33c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12b33cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12b340: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12b340u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b344: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12b344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b348: 0xc045110  jal         func_114440
    ctx->pc = 0x12B348u;
    SET_GPR_U32(ctx, 31, 0x12B350u);
    ctx->pc = 0x12B34Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B348u;
            // 0x12b34c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B350u; }
        if (ctx->pc != 0x12B350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B350u; }
        if (ctx->pc != 0x12B350u) { return; }
    }
    ctx->pc = 0x12B350u;
label_12b350:
    // 0x12b350: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b350u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b354: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b354u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b358: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B358u;
    SET_GPR_U32(ctx, 31, 0x12B360u);
    ctx->pc = 0x12B35Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B358u;
            // 0x12b35c: 0x8c45046c  lw          $a1, 0x46C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1132)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B360u; }
        if (ctx->pc != 0x12B360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B360u; }
        if (ctx->pc != 0x12B360u) { return; }
    }
    ctx->pc = 0x12B360u;
label_12b360:
    // 0x12b360: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b360u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b364: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12b364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b368: 0x3e00008  jr          $ra
    ctx->pc = 0x12B368u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B368u;
            // 0x12b36c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B33Cu: goto label_12b33c;
            case 0x12B350u: goto label_12b350;
            case 0x12B360u: goto label_12b360;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B370u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
