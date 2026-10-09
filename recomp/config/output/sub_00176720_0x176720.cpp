#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176720
// Address: 0x176720 - 0x176778
void sub_00176720_0x176720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176720_0x176720");
#endif

    switch (ctx->pc) {
        case 0x17673cu: goto label_17673c;
        default: break;
    }

    ctx->pc = 0x176720u;

    // 0x176720: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176724: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176728: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x176728u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17672c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17672cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176730: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x176730u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x176734: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x176734u;
    SET_GPR_U32(ctx, 31, 0x17673Cu);
    ctx->pc = 0x176738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176734u;
            // 0x176738: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17673Cu; }
        if (ctx->pc != 0x17673Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17673Cu; }
        if (ctx->pc != 0x17673Cu) { return; }
    }
    ctx->pc = 0x17673Cu;
label_17673c:
    // 0x17673c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17673cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x176740: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x176740u;
    {
        const bool branch_taken_0x176740 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x176744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176740u;
            // 0x176744: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176740) {
            ctx->pc = 0x176760u;
            goto label_176760;
        }
    }
    ctx->pc = 0x176748u;
    // 0x176748: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176748u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17674c: 0x34a50124  ori         $a1, $a1, 0x124
    ctx->pc = 0x17674cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)292);
    // 0x176750: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176750u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176754: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176754u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176758: 0x805a704  j           func_169C10
    ctx->pc = 0x176758u;
    ctx->pc = 0x17675Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176758u;
            // 0x17675c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176760u;
label_176760:
    // 0x176760: 0xae110cd8  sw          $s1, 0xCD8($s0)
    ctx->pc = 0x176760u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3288), GPR_U32(ctx, 17));
    // 0x176764: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176764u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176768: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176768u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17676c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17676cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176770: 0x3e00008  jr          $ra
    ctx->pc = 0x176770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176770u;
            // 0x176774: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17673Cu: goto label_17673c;
            case 0x176760u: goto label_176760;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176778u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
