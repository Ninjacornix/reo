#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175050
// Address: 0x175050 - 0x1750c0
void sub_00175050_0x175050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175050_0x175050");
#endif

    switch (ctx->pc) {
        case 0x17506cu: goto label_17506c;
        case 0x1750a8u: goto label_1750a8;
        default: break;
    }

    ctx->pc = 0x175050u;

    // 0x175050: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x175050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x175054: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175058: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x175058u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17505c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17505cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175060: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x175060u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x175064: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x175064u;
    SET_GPR_U32(ctx, 31, 0x17506Cu);
    ctx->pc = 0x175068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175064u;
            // 0x175068: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17506Cu; }
        if (ctx->pc != 0x17506Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17506Cu; }
        if (ctx->pc != 0x17506Cu) { return; }
    }
    ctx->pc = 0x17506Cu;
label_17506c:
    // 0x17506c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17506cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x175070: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x175070u;
    {
        const bool branch_taken_0x175070 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175070u;
            // 0x175074: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175070) {
            ctx->pc = 0x175090u;
            goto label_175090;
        }
    }
    ctx->pc = 0x175078u;
    // 0x175078: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175078u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17507c: 0x34a5015b  ori         $a1, $a1, 0x15B
    ctx->pc = 0x17507cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)347);
    // 0x175080: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175080u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175084: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x175084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x175088: 0x805a704  j           func_169C10
    ctx->pc = 0x175088u;
    ctx->pc = 0x17508Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175088u;
            // 0x17508c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x175090u;
label_175090:
    // 0x175090: 0x8e032ab0  lw          $v1, 0x2AB0($s0)
    ctx->pc = 0x175090u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x175094: 0x50600006  beql        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x175094u;
    {
        const bool branch_taken_0x175094 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x175094) {
            ctx->pc = 0x175098u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x175094u;
            // 0x175098: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1750B0u;
            goto label_1750b0;
        }
    }
    ctx->pc = 0x17509Cu;
    // 0x17509c: 0xac710dbc  sw          $s1, 0xDBC($v1)
    ctx->pc = 0x17509cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 3516), GPR_U32(ctx, 17));
    // 0x1750a0: 0xc05d496  jal         func_175258
    ctx->pc = 0x1750A0u;
    SET_GPR_U32(ctx, 31, 0x1750A8u);
    ctx->pc = 0x1750A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1750A0u;
            // 0x1750a4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175258u;
    if (runtime->hasFunction(0x175258u)) {
        auto targetFn = runtime->lookupFunction(0x175258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1750A8u; }
        if (ctx->pc != 0x1750A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175258_0x175258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1750A8u; }
        if (ctx->pc != 0x1750A8u) { return; }
    }
    ctx->pc = 0x1750A8u;
label_1750a8:
    // 0x1750a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1750a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1750ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1750acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1750b0:
    // 0x1750b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1750b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1750b4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1750b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1750b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1750B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1750BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1750B8u;
            // 0x1750bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17506Cu: goto label_17506c;
            case 0x175090u: goto label_175090;
            case 0x1750A8u: goto label_1750a8;
            case 0x1750B0u: goto label_1750b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1750C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
