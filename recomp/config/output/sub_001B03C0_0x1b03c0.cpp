#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B03C0
// Address: 0x1b03c0 - 0x1b041c
void sub_001B03C0_0x1b03c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B03C0_0x1b03c0");
#endif

    switch (ctx->pc) {
        case 0x1b03e8u: goto label_1b03e8;
        default: break;
    }

    ctx->pc = 0x1b03c0u;

    // 0x1b03c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b03c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b03c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b03c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b03c8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b03c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b03cc: 0x90820002  lbu         $v0, 0x2($a0)
    ctx->pc = 0x1b03ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b03d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B03D0u;
    {
        const bool branch_taken_0x1b03d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B03D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03D0u;
            // 0x1b03d4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b03d0) {
            ctx->pc = 0x1B03E0u;
            goto label_1b03e0;
        }
    }
    ctx->pc = 0x1B03D8u;
    // 0x1b03d8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1B03D8u;
    {
        const bool branch_taken_0x1b03d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B03DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03D8u;
            // 0x1b03dc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b03d8) {
            ctx->pc = 0x1B040Cu;
            goto label_1b040c;
        }
    }
    ctx->pc = 0x1B03E0u;
label_1b03e0:
    // 0x1b03e0: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1B03E0u;
    SET_GPR_U32(ctx, 31, 0x1B03E8u);
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B03E8u; }
        if (ctx->pc != 0x1B03E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B03E8u; }
        if (ctx->pc != 0x1B03E8u) { return; }
    }
    ctx->pc = 0x1B03E8u;
label_1b03e8:
    // 0x1b03e8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b03e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b03ec: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B03ECu;
    {
        const bool branch_taken_0x1b03ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b03ec) {
            ctx->pc = 0x1B0408u;
            goto label_1b0408;
        }
    }
    ctx->pc = 0x1B03F4u;
    // 0x1b03f4: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1b03f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b03f8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B03F8u;
    {
        const bool branch_taken_0x1b03f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B03FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03F8u;
            // 0x1b03fc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b03f8) {
            ctx->pc = 0x1B040Cu;
            goto label_1b040c;
        }
    }
    ctx->pc = 0x1B0400u;
    // 0x1b0400: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B0400u;
    {
        const bool branch_taken_0x1b0400 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0400u;
            // 0x1b0404: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0400) {
            ctx->pc = 0x1B040Cu;
            goto label_1b040c;
        }
    }
    ctx->pc = 0x1B0408u;
label_1b0408:
    // 0x1b0408: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b0408u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b040c:
    // 0x1b040c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b040cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0410: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0410u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0414: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0414u;
            // 0x1b0418: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B03E0u: goto label_1b03e0;
            case 0x1B03E8u: goto label_1b03e8;
            case 0x1B0408u: goto label_1b0408;
            case 0x1B040Cu: goto label_1b040c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B041Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
