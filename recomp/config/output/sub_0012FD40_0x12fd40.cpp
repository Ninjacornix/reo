#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FD40
// Address: 0x12fd40 - 0x12fda4
void sub_0012FD40_0x12fd40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FD40_0x12fd40");
#endif

    switch (ctx->pc) {
        case 0x12fd60u: goto label_12fd60;
        case 0x12fd78u: goto label_12fd78;
        default: break;
    }

    ctx->pc = 0x12fd40u;

    // 0x12fd40: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12fd40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12fd44: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12fd44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12fd48: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x12fd48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd4c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12fd4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12fd50: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12fd50u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd54: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x12fd54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x12fd58: 0xc042c56  jal         func_10B158
    ctx->pc = 0x12FD58u;
    SET_GPR_U32(ctx, 31, 0x12FD60u);
    ctx->pc = 0x12FD5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD58u;
            // 0x12fd5c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD60u; }
        if (ctx->pc != 0x12FD60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD60u; }
        if (ctx->pc != 0x12FD60u) { return; }
    }
    ctx->pc = 0x12FD60u;
label_12fd60:
    // 0x12fd60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12fd60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd64: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12fd64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd68: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12fd68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fd6c: 0x27a70002  addiu       $a3, $sp, 0x2
    ctx->pc = 0x12fd6cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 2));
    // 0x12fd70: 0xc04b6c0  jal         func_12DB00
    ctx->pc = 0x12FD70u;
    SET_GPR_U32(ctx, 31, 0x12FD78u);
    ctx->pc = 0x12FD74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD70u;
            // 0x12fd74: 0x27a80004  addiu       $t0, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DB00u;
    if (runtime->hasFunction(0x12DB00u)) {
        auto targetFn = runtime->lookupFunction(0x12DB00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD78u; }
        if (ctx->pc != 0x12FD78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DB00_0x12db00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FD78u; }
        if (ctx->pc != 0x12FD78u) { return; }
    }
    ctx->pc = 0x12FD78u;
label_12fd78:
    // 0x12fd78: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x12fd78u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fd7c: 0x97a40002  lhu         $a0, 0x2($sp)
    ctx->pc = 0x12fd7cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 2)));
    // 0x12fd80: 0x97a20004  lhu         $v0, 0x4($sp)
    ctx->pc = 0x12fd80u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12fd84: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12fd84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12fd88: 0xa62302d0  sh          $v1, 0x2D0($s1)
    ctx->pc = 0x12fd88u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 720), (uint16_t)GPR_U32(ctx, 3));
    // 0x12fd8c: 0xa62202d4  sh          $v0, 0x2D4($s1)
    ctx->pc = 0x12fd8cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 724), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fd90: 0xa62402d2  sh          $a0, 0x2D2($s1)
    ctx->pc = 0x12fd90u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 722), (uint16_t)GPR_U32(ctx, 4));
    // 0x12fd94: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12fd94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12fd98: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12fd98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12fd9c: 0x3e00008  jr          $ra
    ctx->pc = 0x12FD9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FD9Cu;
            // 0x12fda0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FD60u: goto label_12fd60;
            case 0x12FD78u: goto label_12fd78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
