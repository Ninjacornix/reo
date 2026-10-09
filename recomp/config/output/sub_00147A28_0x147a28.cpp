#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147A28
// Address: 0x147a28 - 0x147ad8
void sub_00147A28_0x147a28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147A28_0x147a28");
#endif

    switch (ctx->pc) {
        case 0x147a38u: goto label_147a38;
        case 0x147aacu: goto label_147aac;
        case 0x147ac8u: goto label_147ac8;
        default: break;
    }

    ctx->pc = 0x147a28u;

    // 0x147a28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x147a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x147a2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x147a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x147a30: 0xc047598  jal         func_11D660
    ctx->pc = 0x147A30u;
    SET_GPR_U32(ctx, 31, 0x147A38u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147A38u; }
        if (ctx->pc != 0x147A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147A38u; }
        if (ctx->pc != 0x147A38u) { return; }
    }
    ctx->pc = 0x147A38u;
label_147a38:
    // 0x147a38: 0x3c091000  lui         $t1, 0x1000
    ctx->pc = 0x147a38u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)4096 << 16));
    // 0x147a3c: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x147a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x147a40: 0x3529f520  ori         $t1, $t1, 0xF520
    ctx->pc = 0x147a40u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)62752);
    // 0x147a44: 0x3c0a1000  lui         $t2, 0x1000
    ctx->pc = 0x147a44u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)4096 << 16));
    // 0x147a48: 0x8d230000  lw          $v1, 0x0($t1)
    ctx->pc = 0x147a48u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 9), 0))); // MMIO: 0x10000000
    // 0x147a4c: 0x354af590  ori         $t2, $t2, 0xF590
    ctx->pc = 0x147a4cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)62864);
    // 0x147a50: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x147a50u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x147a54: 0x3c08ffff  lui         $t0, 0xFFFF
    ctx->pc = 0x147a54u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)65535 << 16));
    // 0x147a58: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x147a58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x147a5c: 0x34c6b000  ori         $a2, $a2, 0xB000
    ctx->pc = 0x147a5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)45056);
    // 0x147a60: 0xad430000  sw          $v1, 0x0($t2)
    ctx->pc = 0x147a60u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 3));
    // 0x147a64: 0x3508feff  ori         $t0, $t0, 0xFEFF
    ctx->pc = 0x147a64u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65279);
    // 0x147a68: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x147a68u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x147a6c: 0x3c07fffe  lui         $a3, 0xFFFE
    ctx->pc = 0x147a6cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)65534 << 16));
    // 0x147a70: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x147a70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x147a74: 0x34a5b400  ori         $a1, $a1, 0xB400
    ctx->pc = 0x147a74u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)46080);
    // 0x147a78: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    ctx->pc = 0x147a78u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
    // 0x147a7c: 0x882024  and         $a0, $a0, $t0
    ctx->pc = 0x147a7cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 8));
    // 0x147a80: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x147a80u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x147a84: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x147a84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x147a88: 0x681824  and         $v1, $v1, $t0
    ctx->pc = 0x147a88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 8));
    // 0x147a8c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x147a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x147a90: 0x8d240000  lw          $a0, 0x0($t1)
    ctx->pc = 0x147a90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x147a94: 0x872024  and         $a0, $a0, $a3
    ctx->pc = 0x147a94u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 7));
    // 0x147a98: 0xad440000  sw          $a0, 0x0($t2)
    ctx->pc = 0x147a98u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 4));
    // 0x147a9c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x147A9Cu;
    {
        const bool branch_taken_0x147a9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x147AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147A9Cu;
            // 0x147aa0: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147a9c) {
            ctx->pc = 0x147AB0u;
            goto label_147ab0;
        }
    }
    ctx->pc = 0x147AA4u;
    // 0x147aa4: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x147AA4u;
    SET_GPR_U32(ctx, 31, 0x147AACu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147AACu; }
        if (ctx->pc != 0x147AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147AACu; }
        if (ctx->pc != 0x147AACu) { return; }
    }
    ctx->pc = 0x147AACu;
label_147aac:
    // 0x147aac: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147aacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
label_147ab0:
    // 0x147ab0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x147ab4: 0x3442b020  ori         $v0, $v0, 0xB020
    ctx->pc = 0x147ab4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45088);
    // 0x147ab8: 0x3463b420  ori         $v1, $v1, 0xB420
    ctx->pc = 0x147ab8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46112);
    // 0x147abc: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x147abcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x147ac0: 0xc044fec  jal         func_113FB0
    ctx->pc = 0x147AC0u;
    SET_GPR_U32(ctx, 31, 0x147AC8u);
    ctx->pc = 0x147AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147AC0u;
            // 0x147ac4: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113FB0u;
    if (runtime->hasFunction(0x113FB0u)) {
        auto targetFn = runtime->lookupFunction(0x113FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147AC8u; }
        if (ctx->pc != 0x147AC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113FB0_0x113fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147AC8u; }
        if (ctx->pc != 0x147AC8u) { return; }
    }
    ctx->pc = 0x147AC8u;
label_147ac8:
    // 0x147ac8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x147ac8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147acc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x147accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x147ad0: 0x3e00008  jr          $ra
    ctx->pc = 0x147AD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147AD0u;
            // 0x147ad4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147A38u: goto label_147a38;
            case 0x147AACu: goto label_147aac;
            case 0x147AB0u: goto label_147ab0;
            case 0x147AC8u: goto label_147ac8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147AD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
