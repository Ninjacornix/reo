#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174700
// Address: 0x174700 - 0x17475c
void sub_00174700_0x174700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174700_0x174700");
#endif

    switch (ctx->pc) {
        case 0x17471cu: goto label_17471c;
        default: break;
    }

    ctx->pc = 0x174700u;

    // 0x174700: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x174704: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174708: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x174708u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17470c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17470cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174710: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x174710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x174714: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174714u;
    SET_GPR_U32(ctx, 31, 0x17471Cu);
    ctx->pc = 0x174718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174714u;
            // 0x174718: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17471Cu; }
        if (ctx->pc != 0x17471Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17471Cu; }
        if (ctx->pc != 0x17471Cu) { return; }
    }
    ctx->pc = 0x17471Cu;
label_17471c:
    // 0x17471c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17471cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174720: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174720u;
    {
        const bool branch_taken_0x174720 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174720u;
            // 0x174724: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174720) {
            ctx->pc = 0x174740u;
            goto label_174740;
        }
    }
    ctx->pc = 0x174728u;
    // 0x174728: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174728u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17472c: 0x34a50152  ori         $a1, $a1, 0x152
    ctx->pc = 0x17472cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)338);
    // 0x174730: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174730u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174734: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174734u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174738: 0x805a704  j           func_169C10
    ctx->pc = 0x174738u;
    ctx->pc = 0x17473Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174738u;
            // 0x17473c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174740u;
label_174740:
    // 0x174740: 0x8e032ab0  lw          $v1, 0x2AB0($s0)
    ctx->pc = 0x174740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x174744: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174744u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174748: 0xac710dac  sw          $s1, 0xDAC($v1)
    ctx->pc = 0x174748u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 3500), GPR_U32(ctx, 17));
    // 0x17474c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17474cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174750: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174750u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174754: 0x3e00008  jr          $ra
    ctx->pc = 0x174754u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174754u;
            // 0x174758: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17471Cu: goto label_17471c;
            case 0x174740u: goto label_174740;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17475Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
