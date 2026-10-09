#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001674A0
// Address: 0x1674a0 - 0x167508
void sub_001674A0_0x1674a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001674A0_0x1674a0");
#endif

    switch (ctx->pc) {
        case 0x1674e0u: goto label_1674e0;
        case 0x1674f0u: goto label_1674f0;
        default: break;
    }

    ctx->pc = 0x1674a0u;

    // 0x1674a0: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x1674a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1674a4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1674a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1674a8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1674a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1674ac: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1674acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1674b0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1674b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1674b4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1674b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1674b8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1674b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1674bc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1674bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1674c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1674c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1674c4: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1674c4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1674c8: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x1674c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1674cc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1674ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1674d0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1674d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1674d4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1674d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1674d8: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x1674D8u;
    SET_GPR_U32(ctx, 31, 0x1674E0u);
    ctx->pc = 0x1674DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1674D8u;
            // 0x1674dc: 0x26101168  addiu       $s0, $s0, 0x1168 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1674E0u; }
        if (ctx->pc != 0x1674E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1674E0u; }
        if (ctx->pc != 0x1674E0u) { return; }
    }
    ctx->pc = 0x1674E0u;
label_1674e0:
    // 0x1674e0: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x1674e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1674e4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1674e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1674e8: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1674E8u;
    SET_GPR_U32(ctx, 31, 0x1674F0u);
    ctx->pc = 0x1674ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1674E8u;
            // 0x1674ec: 0xae120000  sw          $s2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1674F0u; }
        if (ctx->pc != 0x1674F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1674F0u; }
        if (ctx->pc != 0x1674F0u) { return; }
    }
    ctx->pc = 0x1674F0u;
label_1674f0:
    // 0x1674f0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1674f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1674f4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1674f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1674f8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1674f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1674fc: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1674fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167500: 0x3e00008  jr          $ra
    ctx->pc = 0x167500u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167500u;
            // 0x167504: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1674E0u: goto label_1674e0;
            case 0x1674F0u: goto label_1674f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167508u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
