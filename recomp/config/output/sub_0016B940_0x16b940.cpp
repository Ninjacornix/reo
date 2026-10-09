#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B940
// Address: 0x16b940 - 0x16b990
void sub_0016B940_0x16b940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B940_0x16b940");
#endif

    switch (ctx->pc) {
        case 0x16b95cu: goto label_16b95c;
        default: break;
    }

    ctx->pc = 0x16b940u;

    // 0x16b940: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16b940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16b944: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b948: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b948u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b94c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16b94cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16b950: 0x8e021aec  lw          $v0, 0x1AEC($s0)
    ctx->pc = 0x16b950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6892)));
    // 0x16b954: 0xc05ae64  jal         func_16B990
    ctx->pc = 0x16B954u;
    SET_GPR_U32(ctx, 31, 0x16B95Cu);
    ctx->pc = 0x16B958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B954u;
            // 0x16b958: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B990u;
    if (runtime->hasFunction(0x16B990u)) {
        auto targetFn = runtime->lookupFunction(0x16B990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B95Cu; }
        if (ctx->pc != 0x16B95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B990_0x16b990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B95Cu; }
        if (ctx->pc != 0x16B95Cu) { return; }
    }
    ctx->pc = 0x16B95Cu;
label_16b95c:
    // 0x16b95c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16b95cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16b960: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16B960u;
    {
        const bool branch_taken_0x16b960 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B960u;
            // 0x16b964: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b960) {
            ctx->pc = 0x16B980u;
            goto label_16b980;
        }
    }
    ctx->pc = 0x16B968u;
    // 0x16b968: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b968u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b96c: 0x34a50d0a  ori         $a1, $a1, 0xD0A
    ctx->pc = 0x16b96cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3338);
    // 0x16b970: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16b970u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b974: 0x805a704  j           func_169C10
    ctx->pc = 0x16B974u;
    ctx->pc = 0x16B978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B974u;
            // 0x16b978: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B97Cu;
    // 0x16b97c: 0x0  nop
    ctx->pc = 0x16b97cu;
    // NOP
label_16b980:
    // 0x16b980: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b980u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b984: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16b984u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b988: 0x3e00008  jr          $ra
    ctx->pc = 0x16B988u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B988u;
            // 0x16b98c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B95Cu: goto label_16b95c;
            case 0x16B980u: goto label_16b980;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B990u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
