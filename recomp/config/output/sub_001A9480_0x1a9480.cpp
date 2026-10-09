#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9480
// Address: 0x1a9480 - 0x1a9500
void sub_001A9480_0x1a9480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9480_0x1a9480");
#endif

    switch (ctx->pc) {
        case 0x1a94d8u: goto label_1a94d8;
        case 0x1a94e4u: goto label_1a94e4;
        default: break;
    }

    ctx->pc = 0x1a9480u;

    // 0x1a9480: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a9480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a9484: 0x3c02006f  lui         $v0, 0x6F
    ctx->pc = 0x1a9484u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)111 << 16));
    // 0x1a9488: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a9488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a948c: 0x3442574d  ori         $v0, $v0, 0x574D
    ctx->pc = 0x1a948cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22349);
    // 0x1a9490: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a9490u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a9494: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a9494u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a9498: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1a9498u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a949c: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1a949cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1a94a0: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a94a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a94a4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A94A4u;
    {
        const bool branch_taken_0x1a94a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A94A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A94A4u;
            // 0x1a94a8: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a94a4) {
            ctx->pc = 0x1A94B4u;
            goto label_1a94b4;
        }
    }
    ctx->pc = 0x1A94ACu;
    // 0x1a94ac: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1A94ACu;
    {
        const bool branch_taken_0x1a94ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A94B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A94ACu;
            // 0x1a94b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a94ac) {
            ctx->pc = 0x1A94E8u;
            goto label_1a94e8;
        }
    }
    ctx->pc = 0x1A94B4u;
label_1a94b4:
    // 0x1a94b4: 0x8cb00008  lw          $s0, 0x8($a1)
    ctx->pc = 0x1a94b4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1a94b8: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x1a94b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x1a94bc: 0x508823  subu        $s1, $v0, $s0
    ctx->pc = 0x1a94bcu;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1a94c0: 0x1e200003  bgtz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A94C0u;
    {
        const bool branch_taken_0x1a94c0 = (GPR_S64(ctx, 17) > 0);
        ctx->pc = 0x1A94C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A94C0u;
            // 0x1a94c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a94c0) {
            ctx->pc = 0x1A94D0u;
            goto label_1a94d0;
        }
    }
    ctx->pc = 0x1A94C8u;
    // 0x1a94c8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A94C8u;
    {
        const bool branch_taken_0x1a94c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A94CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A94C8u;
            // 0x1a94cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a94c8) {
            ctx->pc = 0x1A94E8u;
            goto label_1a94e8;
        }
    }
    ctx->pc = 0x1A94D0u;
label_1a94d0:
    // 0x1a94d0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1A94D0u;
    SET_GPR_U32(ctx, 31, 0x1A94D8u);
    ctx->pc = 0x1A94D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A94D0u;
            // 0x1a94d4: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A94D8u; }
        if (ctx->pc != 0x1A94D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A94D8u; }
        if (ctx->pc != 0x1A94D8u) { return; }
    }
    ctx->pc = 0x1A94D8u;
label_1a94d8:
    // 0x1a94d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a94d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a94dc: 0xc060094  jal         func_180250
    ctx->pc = 0x1A94DCu;
    SET_GPR_U32(ctx, 31, 0x1A94E4u);
    ctx->pc = 0x1A94E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A94DCu;
            // 0x1a94e0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180250u;
    if (runtime->hasFunction(0x180250u)) {
        auto targetFn = runtime->lookupFunction(0x180250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A94E4u; }
        if (ctx->pc != 0x1A94E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180250_0x180250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A94E4u; }
        if (ctx->pc != 0x1A94E4u) { return; }
    }
    ctx->pc = 0x1A94E4u;
label_1a94e4:
    // 0x1a94e4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a94e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a94e8:
    // 0x1a94e8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a94e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a94ec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a94ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a94f0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a94f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a94f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A94F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A94F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A94F4u;
            // 0x1a94f8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A94B4u: goto label_1a94b4;
            case 0x1A94D0u: goto label_1a94d0;
            case 0x1A94D8u: goto label_1a94d8;
            case 0x1A94E4u: goto label_1a94e4;
            case 0x1A94E8u: goto label_1a94e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A94FCu;
    // 0x1a94fc: 0x0  nop
    ctx->pc = 0x1a94fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
