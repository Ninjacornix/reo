#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018D6C0
// Address: 0x18d6c0 - 0x18d760
void sub_0018D6C0_0x18d6c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018D6C0_0x18d6c0");
#endif

    switch (ctx->pc) {
        case 0x18d6f4u: goto label_18d6f4;
        case 0x18d728u: goto label_18d728;
        case 0x18d730u: goto label_18d730;
        case 0x18d738u: goto label_18d738;
        default: break;
    }

    ctx->pc = 0x18d6c0u;

    // 0x18d6c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x18d6c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18d6c4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18d6c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18d6c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x18d6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x18d6cc: 0x8c22f704  lw          $v0, -0x8FC($at)
    ctx->pc = 0x18d6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294964996)));
    // 0x18d6d0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18D6D0u;
    {
        const bool branch_taken_0x18d6d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18D6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D6D0u;
            // 0x18d6d4: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d6d0) {
            ctx->pc = 0x18D6ECu;
            goto label_18d6ec;
        }
    }
    ctx->pc = 0x18D6D8u;
    // 0x18d6d8: 0x8c22f708  lw          $v0, -0x8F8($at)
    ctx->pc = 0x18d6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965000)));
    // 0x18d6dc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18D6DCu;
    {
        const bool branch_taken_0x18d6dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18D6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D6DCu;
            // 0x18d6e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d6dc) {
            ctx->pc = 0x18D6ECu;
            goto label_18d6ec;
        }
    }
    ctx->pc = 0x18D6E4u;
    // 0x18d6e4: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x18D6E4u;
    {
        const bool branch_taken_0x18d6e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D6E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D6E4u;
            // 0x18d6e8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d6e4) {
            ctx->pc = 0x18D74Cu;
            goto label_18d74c;
        }
    }
    ctx->pc = 0x18D6ECu;
label_18d6ec:
    // 0x18d6ec: 0xc063594  jal         func_18D650
    ctx->pc = 0x18D6ECu;
    SET_GPR_U32(ctx, 31, 0x18D6F4u);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D6F4u; }
        if (ctx->pc != 0x18D6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D6F4u; }
        if (ctx->pc != 0x18D6F4u) { return; }
    }
    ctx->pc = 0x18D6F4u;
label_18d6f4:
    // 0x18d6f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18d6f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18d6f8: 0x3c02002a  lui         $v0, 0x2A
    ctx->pc = 0x18d6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)42 << 16));
    // 0x18d6fc: 0x8c23fdb4  lw          $v1, -0x24C($at)
    ctx->pc = 0x18d6fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
    // 0x18d700: 0x2442f704  addiu       $v0, $v0, -0x8FC
    ctx->pc = 0x18d700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964996));
    // 0x18d704: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18d704u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18d708: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18d708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18d70c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18d70cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d710: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18D710u;
    {
        const bool branch_taken_0x18d710 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18D714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D710u;
            // 0x18d714: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d710) {
            ctx->pc = 0x18D720u;
            goto label_18d720;
        }
    }
    ctx->pc = 0x18D718u;
    // 0x18d718: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x18D718u;
    {
        const bool branch_taken_0x18d718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d718) {
            ctx->pc = 0x18D748u;
            goto label_18d748;
        }
    }
    ctx->pc = 0x18D720u;
label_18d720:
    // 0x18d720: 0xc06351c  jal         func_18D470
    ctx->pc = 0x18D720u;
    SET_GPR_U32(ctx, 31, 0x18D728u);
    ctx->pc = 0x18D470u;
    if (runtime->hasFunction(0x18D470u)) {
        auto targetFn = runtime->lookupFunction(0x18D470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D728u; }
        if (ctx->pc != 0x18D728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D470_0x18d470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D728u; }
        if (ctx->pc != 0x18D728u) { return; }
    }
    ctx->pc = 0x18D728u;
label_18d728:
    // 0x18d728: 0xc063594  jal         func_18D650
    ctx->pc = 0x18D728u;
    SET_GPR_U32(ctx, 31, 0x18D730u);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D730u; }
        if (ctx->pc != 0x18D730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D730u; }
        if (ctx->pc != 0x18D730u) { return; }
    }
    ctx->pc = 0x18D730u;
label_18d730:
    // 0x18d730: 0xc063750  jal         func_18DD40
    ctx->pc = 0x18D730u;
    SET_GPR_U32(ctx, 31, 0x18D738u);
    ctx->pc = 0x18DD40u;
    if (runtime->hasFunction(0x18DD40u)) {
        auto targetFn = runtime->lookupFunction(0x18DD40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D738u; }
        if (ctx->pc != 0x18D738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DD40_0x18dd40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D738u; }
        if (ctx->pc != 0x18D738u) { return; }
    }
    ctx->pc = 0x18D738u;
label_18d738:
    // 0x18d738: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18d738u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18d73c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d73cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d740: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18d740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18d744: 0xac234178  sw          $v1, 0x4178($at)
    ctx->pc = 0x18d744u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16760), GPR_U32(ctx, 3));
label_18d748:
    // 0x18d748: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x18d748u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_18d74c:
    // 0x18d74c: 0x3e00008  jr          $ra
    ctx->pc = 0x18D74Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D74Cu;
            // 0x18d750: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D6ECu: goto label_18d6ec;
            case 0x18D6F4u: goto label_18d6f4;
            case 0x18D720u: goto label_18d720;
            case 0x18D728u: goto label_18d728;
            case 0x18D730u: goto label_18d730;
            case 0x18D738u: goto label_18d738;
            case 0x18D748u: goto label_18d748;
            case 0x18D74Cu: goto label_18d74c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D754u;
    // 0x18d754: 0x0  nop
    ctx->pc = 0x18d754u;
    // NOP
    // 0x18d758: 0x0  nop
    ctx->pc = 0x18d758u;
    // NOP
    // 0x18d75c: 0x0  nop
    ctx->pc = 0x18d75cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
