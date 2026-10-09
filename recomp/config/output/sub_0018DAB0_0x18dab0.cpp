#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DAB0
// Address: 0x18dab0 - 0x18db80
void sub_0018DAB0_0x18dab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DAB0_0x18dab0");
#endif

    switch (ctx->pc) {
        case 0x18dad4u: goto label_18dad4;
        case 0x18dadcu: goto label_18dadc;
        case 0x18daf0u: goto label_18daf0;
        case 0x18daf8u: goto label_18daf8;
        case 0x18db08u: goto label_18db08;
        case 0x18db10u: goto label_18db10;
        case 0x18db18u: goto label_18db18;
        case 0x18db24u: goto label_18db24;
        case 0x18db34u: goto label_18db34;
        case 0x18db4cu: goto label_18db4c;
        case 0x18db58u: goto label_18db58;
        case 0x18db60u: goto label_18db60;
        default: break;
    }

    ctx->pc = 0x18dab0u;

    // 0x18dab0: 0x27bdf7d0  addiu       $sp, $sp, -0x830
    ctx->pc = 0x18dab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294965200));
    // 0x18dab4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18dab4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18dab8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18dab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x18dabc: 0x24a51c68  addiu       $a1, $a1, 0x1C68
    ctx->pc = 0x18dabcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7272));
    // 0x18dac0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18dac0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18dac4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18dac4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18dac8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18dac8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dacc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18DACCu;
    SET_GPR_U32(ctx, 31, 0x18DAD4u);
    ctx->pc = 0x18DAD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DACCu;
            // 0x18dad0: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DAD4u; }
        if (ctx->pc != 0x18DAD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DAD4u; }
        if (ctx->pc != 0x18DAD4u) { return; }
    }
    ctx->pc = 0x18DAD4u;
label_18dad4:
    // 0x18dad4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x18DAD4u;
    SET_GPR_U32(ctx, 31, 0x18DADCu);
    ctx->pc = 0x18DAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DAD4u;
            // 0x18dad8: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DADCu; }
        if (ctx->pc != 0x18DADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DADCu; }
        if (ctx->pc != 0x18DADCu) { return; }
    }
    ctx->pc = 0x18DADCu;
label_18dadc:
    // 0x18dadc: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x18dadcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x18dae0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x18dae0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dae4: 0x24500030  addiu       $s0, $v0, 0x30
    ctx->pc = 0x18dae4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x18dae8: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18DAE8u;
    SET_GPR_U32(ctx, 31, 0x18DAF0u);
    ctx->pc = 0x18DAECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DAE8u;
            // 0x18daec: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DAF0u; }
        if (ctx->pc != 0x18DAF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DAF0u; }
        if (ctx->pc != 0x18DAF0u) { return; }
    }
    ctx->pc = 0x18DAF0u;
label_18daf0:
    // 0x18daf0: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x18DAF0u;
    SET_GPR_U32(ctx, 31, 0x18DAF8u);
    ctx->pc = 0x18DAF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DAF0u;
            // 0x18daf4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DAF8u; }
        if (ctx->pc != 0x18DAF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DAF8u; }
        if (ctx->pc != 0x18DAF8u) { return; }
    }
    ctx->pc = 0x18DAF8u;
label_18daf8:
    // 0x18daf8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18daf8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18dafc: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x18dafcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x18db00: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18DB00u;
    SET_GPR_U32(ctx, 31, 0x18DB08u);
    ctx->pc = 0x18DB04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB00u;
            // 0x18db04: 0x24a51c70  addiu       $a1, $a1, 0x1C70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB08u; }
        if (ctx->pc != 0x18DB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB08u; }
        if (ctx->pc != 0x18DB08u) { return; }
    }
    ctx->pc = 0x18DB08u;
label_18db08:
    // 0x18db08: 0xc0635d8  jal         func_18D760
    ctx->pc = 0x18DB08u;
    SET_GPR_U32(ctx, 31, 0x18DB10u);
    ctx->pc = 0x18DB0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB08u;
            // 0x18db0c: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18D760u;
    if (runtime->hasFunction(0x18D760u)) {
        auto targetFn = runtime->lookupFunction(0x18D760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB10u; }
        if (ctx->pc != 0x18DB10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D760_0x18d760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB10u; }
        if (ctx->pc != 0x18DB10u) { return; }
    }
    ctx->pc = 0x18DB10u;
label_18db10:
    // 0x18db10: 0xc04af5e  jal         func_12BD78
    ctx->pc = 0x18DB10u;
    SET_GPR_U32(ctx, 31, 0x18DB18u);
    ctx->pc = 0x12BD78u;
    if (runtime->hasFunction(0x12BD78u)) {
        auto targetFn = runtime->lookupFunction(0x12BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB18u; }
        if (ctx->pc != 0x18DB18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD78_0x12bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB18u; }
        if (ctx->pc != 0x18DB18u) { return; }
    }
    ctx->pc = 0x18DB18u;
label_18db18:
    // 0x18db18: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x18db18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x18db1c: 0xc04629c  jal         func_118A70
    ctx->pc = 0x18DB1Cu;
    SET_GPR_U32(ctx, 31, 0x18DB24u);
    ctx->pc = 0x18DB20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB1Cu;
            // 0x18db20: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB24u; }
        if (ctx->pc != 0x18DB24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB24u; }
        if (ctx->pc != 0x18DB24u) { return; }
    }
    ctx->pc = 0x18DB24u;
label_18db24:
    // 0x18db24: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18DB24u;
    {
        const bool branch_taken_0x18db24 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x18DB28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB24u;
            // 0x18db28: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18db24) {
            ctx->pc = 0x18DB3Cu;
            goto label_18db3c;
        }
    }
    ctx->pc = 0x18DB2Cu;
    // 0x18db2c: 0xc04af64  jal         func_12BD90
    ctx->pc = 0x18DB2Cu;
    SET_GPR_U32(ctx, 31, 0x18DB34u);
    ctx->pc = 0x12BD90u;
    if (runtime->hasFunction(0x12BD90u)) {
        auto targetFn = runtime->lookupFunction(0x12BD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB34u; }
        if (ctx->pc != 0x18DB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD90_0x12bd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB34u; }
        if (ctx->pc != 0x18DB34u) { return; }
    }
    ctx->pc = 0x18DB34u;
label_18db34:
    // 0x18db34: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x18DB34u;
    {
        const bool branch_taken_0x18db34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18DB38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB34u;
            // 0x18db38: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18db34) {
            ctx->pc = 0x18DB64u;
            goto label_18db64;
        }
    }
    ctx->pc = 0x18DB3Cu;
label_18db3c:
    // 0x18db3c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x18db3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18db40: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18db40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18db44: 0xc04639e  jal         func_118E78
    ctx->pc = 0x18DB44u;
    SET_GPR_U32(ctx, 31, 0x18DB4Cu);
    ctx->pc = 0x18DB48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB44u;
            // 0x18db48: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB4Cu; }
        if (ctx->pc != 0x18DB4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB4Cu; }
        if (ctx->pc != 0x18DB4Cu) { return; }
    }
    ctx->pc = 0x18DB4Cu;
label_18db4c:
    // 0x18db4c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x18db4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18db50: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x18DB50u;
    SET_GPR_U32(ctx, 31, 0x18DB58u);
    ctx->pc = 0x18DB54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB50u;
            // 0x18db54: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB58u; }
        if (ctx->pc != 0x18DB58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB58u; }
        if (ctx->pc != 0x18DB58u) { return; }
    }
    ctx->pc = 0x18DB58u;
label_18db58:
    // 0x18db58: 0xc04af64  jal         func_12BD90
    ctx->pc = 0x18DB58u;
    SET_GPR_U32(ctx, 31, 0x18DB60u);
    ctx->pc = 0x12BD90u;
    if (runtime->hasFunction(0x12BD90u)) {
        auto targetFn = runtime->lookupFunction(0x12BD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB60u; }
        if (ctx->pc != 0x18DB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD90_0x12bd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DB60u; }
        if (ctx->pc != 0x18DB60u) { return; }
    }
    ctx->pc = 0x18DB60u;
label_18db60:
    // 0x18db60: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x18db60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18db64:
    // 0x18db64: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18db64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18db68: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18db68u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18db6c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18db6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18db70: 0x3e00008  jr          $ra
    ctx->pc = 0x18DB70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DB74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DB70u;
            // 0x18db74: 0x27bd0830  addiu       $sp, $sp, 0x830 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 2096));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DAD4u: goto label_18dad4;
            case 0x18DADCu: goto label_18dadc;
            case 0x18DAF0u: goto label_18daf0;
            case 0x18DAF8u: goto label_18daf8;
            case 0x18DB08u: goto label_18db08;
            case 0x18DB10u: goto label_18db10;
            case 0x18DB18u: goto label_18db18;
            case 0x18DB24u: goto label_18db24;
            case 0x18DB34u: goto label_18db34;
            case 0x18DB3Cu: goto label_18db3c;
            case 0x18DB4Cu: goto label_18db4c;
            case 0x18DB58u: goto label_18db58;
            case 0x18DB60u: goto label_18db60;
            case 0x18DB64u: goto label_18db64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DB78u;
    // 0x18db78: 0x0  nop
    ctx->pc = 0x18db78u;
    // NOP
    // 0x18db7c: 0x0  nop
    ctx->pc = 0x18db7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
