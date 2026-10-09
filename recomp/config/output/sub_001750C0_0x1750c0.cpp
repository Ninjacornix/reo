#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001750C0
// Address: 0x1750c0 - 0x175120
void sub_001750C0_0x1750c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001750C0_0x1750c0");
#endif

    switch (ctx->pc) {
        case 0x1750dcu: goto label_1750dc;
        default: break;
    }

    ctx->pc = 0x1750c0u;

    // 0x1750c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1750c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1750c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1750c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1750c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1750c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1750cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1750ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1750d0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1750d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1750d4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1750D4u;
    SET_GPR_U32(ctx, 31, 0x1750DCu);
    ctx->pc = 0x1750D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1750D4u;
            // 0x1750d8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1750DCu; }
        if (ctx->pc != 0x1750DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1750DCu; }
        if (ctx->pc != 0x1750DCu) { return; }
    }
    ctx->pc = 0x1750DCu;
label_1750dc:
    // 0x1750dc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1750dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1750e0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1750E0u;
    {
        const bool branch_taken_0x1750e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1750E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1750E0u;
            // 0x1750e4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1750e0) {
            ctx->pc = 0x175100u;
            goto label_175100;
        }
    }
    ctx->pc = 0x1750E8u;
    // 0x1750e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1750e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1750ec: 0x34a5015c  ori         $a1, $a1, 0x15C
    ctx->pc = 0x1750ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)348);
    // 0x1750f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1750f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1750f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1750f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1750f8: 0x805a704  j           func_169C10
    ctx->pc = 0x1750F8u;
    ctx->pc = 0x1750FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1750F8u;
            // 0x1750fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x175100u;
label_175100:
    // 0x175100: 0x8e042ab0  lw          $a0, 0x2AB0($s0)
    ctx->pc = 0x175100u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x175104: 0x54800001  bnel        $a0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x175104u;
    {
        const bool branch_taken_0x175104 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x175104) {
            ctx->pc = 0x175108u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x175104u;
            // 0x175108: 0xac910dc0  sw          $s1, 0xDC0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 3520), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17510Cu;
            goto label_17510c;
        }
    }
    ctx->pc = 0x17510Cu;
label_17510c:
    // 0x17510c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17510cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175110: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175110u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175114: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x175114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175118: 0x3e00008  jr          $ra
    ctx->pc = 0x175118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17511Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175118u;
            // 0x17511c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1750DCu: goto label_1750dc;
            case 0x175100u: goto label_175100;
            case 0x17510Cu: goto label_17510c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
