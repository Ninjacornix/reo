#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180480
// Address: 0x180480 - 0x1804d8
void sub_00180480_0x180480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180480_0x180480");
#endif

    switch (ctx->pc) {
        case 0x180494u: goto label_180494;
        default: break;
    }

    ctx->pc = 0x180480u;

    // 0x180480: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x180480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x180484: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x180484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x180488: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x180488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18048c: 0xc062342  jal         func_188D08
    ctx->pc = 0x18048Cu;
    SET_GPR_U32(ctx, 31, 0x180494u);
    ctx->pc = 0x180490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18048Cu;
            // 0x180490: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188D08u;
    if (runtime->hasFunction(0x188D08u)) {
        auto targetFn = runtime->lookupFunction(0x188D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180494u; }
        if (ctx->pc != 0x180494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188D08_0x188d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180494u; }
        if (ctx->pc != 0x180494u) { return; }
    }
    ctx->pc = 0x180494u;
label_180494:
    // 0x180494: 0x440000b  bltz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x180494u;
    {
        const bool branch_taken_0x180494 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x180498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180494u;
            // 0x180498: 0x24040334  addiu       $a0, $zero, 0x334 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180494) {
            ctx->pc = 0x1804C4u;
            goto label_1804c4;
        }
    }
    ctx->pc = 0x18049Cu;
    // 0x18049c: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x18049cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1804a0: 0x2042018  mult        $a0, $s0, $a0
    ctx->pc = 0x1804a0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1804a4: 0x24636188  addiu       $v1, $v1, 0x6188
    ctx->pc = 0x1804a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24968));
    // 0x1804a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1804a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1804ac: 0x832821  addu        $a1, $a0, $v1
    ctx->pc = 0x1804acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1804b0: 0x643021  addu        $a2, $v1, $a0
    ctx->pc = 0x1804b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1804b4: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x1804b4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x1804b8: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x1804b8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1804bc: 0xacc00004  sw          $zero, 0x4($a2)
    ctx->pc = 0x1804bcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 0));
    // 0x1804c0: 0xac60000c  sw          $zero, 0xC($v1)
    ctx->pc = 0x1804c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
label_1804c4:
    // 0x1804c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1804c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1804c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1804c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1804cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1804CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1804D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1804CCu;
            // 0x1804d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180494u: goto label_180494;
            case 0x1804C4u: goto label_1804c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1804D4u;
    // 0x1804d4: 0x0  nop
    ctx->pc = 0x1804d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
