#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BE80
// Address: 0x13be80 - 0x13bf98
void sub_0013BE80_0x13be80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BE80_0x13be80");
#endif

    switch (ctx->pc) {
        case 0x13bea4u: goto label_13bea4;
        case 0x13beb8u: goto label_13beb8;
        case 0x13bec0u: goto label_13bec0;
        case 0x13bee0u: goto label_13bee0;
        case 0x13bee8u: goto label_13bee8;
        case 0x13bf2cu: goto label_13bf2c;
        case 0x13bf38u: goto label_13bf38;
        case 0x13bf40u: goto label_13bf40;
        case 0x13bf58u: goto label_13bf58;
        default: break;
    }

    ctx->pc = 0x13be80u;

    // 0x13be80: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13be80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13be84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13be84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13be88: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x13be88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13be8c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13be8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13be90: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x13be90u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13be94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13be94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13be98: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13be98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13be9c: 0xc04ef6e  jal         func_13BDB8
    ctx->pc = 0x13BE9Cu;
    SET_GPR_U32(ctx, 31, 0x13BEA4u);
    ctx->pc = 0x13BEA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BE9Cu;
            // 0x13bea0: 0xa2200000  sb          $zero, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BDB8u;
    if (runtime->hasFunction(0x13BDB8u)) {
        auto targetFn = runtime->lookupFunction(0x13BDB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEA4u; }
        if (ctx->pc != 0x13BEA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BDB8_0x13bdb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEA4u; }
        if (ctx->pc != 0x13BEA4u) { return; }
    }
    ctx->pc = 0x13BEA4u;
label_13bea4:
    // 0x13bea4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13BEA4u;
    {
        const bool branch_taken_0x13bea4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13BEA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BEA4u;
            // 0x13bea8: 0x3c050022  lui         $a1, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bea4) {
            ctx->pc = 0x13BEB8u;
            goto label_13beb8;
        }
    }
    ctx->pc = 0x13BEACu;
    // 0x13beac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13beacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13beb0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x13BEB0u;
    SET_GPR_U32(ctx, 31, 0x13BEB8u);
    ctx->pc = 0x13BEB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BEB0u;
            // 0x13beb4: 0x24a5dfb0  addiu       $a1, $a1, -0x2050 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEB8u; }
        if (ctx->pc != 0x13BEB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEB8u; }
        if (ctx->pc != 0x13BEB8u) { return; }
    }
    ctx->pc = 0x13BEB8u;
label_13beb8:
    // 0x13beb8: 0xc04ef8a  jal         func_13BE28
    ctx->pc = 0x13BEB8u;
    SET_GPR_U32(ctx, 31, 0x13BEC0u);
    ctx->pc = 0x13BEBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BEB8u;
            // 0x13bebc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BE28u;
    if (runtime->hasFunction(0x13BE28u)) {
        auto targetFn = runtime->lookupFunction(0x13BE28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEC0u; }
        if (ctx->pc != 0x13BEC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE28_0x13be28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEC0u; }
        if (ctx->pc != 0x13BEC0u) { return; }
    }
    ctx->pc = 0x13BEC0u;
label_13bec0:
    // 0x13bec0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13bec0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13bec4: 0x5443001a  bnel        $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x13BEC4u;
    {
        const bool branch_taken_0x13bec4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x13bec4) {
            ctx->pc = 0x13BEC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13BEC4u;
            // 0x13bec8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13BF30u;
            goto label_13bf30;
        }
    }
    ctx->pc = 0x13BECCu;
    // 0x13becc: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13beccu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13bed0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13bed0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bed4: 0x2610dea8  addiu       $s0, $s0, -0x2158
    ctx->pc = 0x13bed4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294958760));
    // 0x13bed8: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x13BED8u;
    SET_GPR_U32(ctx, 31, 0x13BEE0u);
    ctx->pc = 0x13BEDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BED8u;
            // 0x13bedc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEE0u; }
        if (ctx->pc != 0x13BEE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEE0u; }
        if (ctx->pc != 0x13BEE0u) { return; }
    }
    ctx->pc = 0x13BEE0u;
label_13bee0:
    // 0x13bee0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13BEE0u;
    SET_GPR_U32(ctx, 31, 0x13BEE8u);
    ctx->pc = 0x13BEE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BEE0u;
            // 0x13bee4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEE8u; }
        if (ctx->pc != 0x13BEE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BEE8u; }
        if (ctx->pc != 0x13BEE8u) { return; }
    }
    ctx->pc = 0x13BEE8u;
label_13bee8:
    // 0x13bee8: 0x2404005c  addiu       $a0, $zero, 0x5C
    ctx->pc = 0x13bee8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x13beec: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x13beecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x13bef0: 0x8042ffff  lb          $v0, -0x1($v0)
    ctx->pc = 0x13bef0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x13bef4: 0x1044000d  beq         $v0, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x13BEF4u;
    {
        const bool branch_taken_0x13bef4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x13BEF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BEF4u;
            // 0x13bef8: 0x2403002f  addiu       $v1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bef4) {
            ctx->pc = 0x13BF2Cu;
            goto label_13bf2c;
        }
    }
    ctx->pc = 0x13BEFCu;
    // 0x13befc: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x13BEFCu;
    {
        const bool branch_taken_0x13befc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x13BF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BEFCu;
            // 0x13bf00: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13befc) {
            ctx->pc = 0x13BF30u;
            goto label_13bf30;
        }
    }
    ctx->pc = 0x13BF04u;
    // 0x13bf04: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13BF04u;
    {
        const bool branch_taken_0x13bf04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13bf04) {
            ctx->pc = 0x13BF30u;
            goto label_13bf30;
        }
    }
    ctx->pc = 0x13BF0Cu;
    // 0x13bf0c: 0x82420000  lb          $v0, 0x0($s2)
    ctx->pc = 0x13bf0cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x13bf10: 0x10440007  beq         $v0, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13BF10u;
    {
        const bool branch_taken_0x13bf10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x13bf10) {
            ctx->pc = 0x13BF30u;
            goto label_13bf30;
        }
    }
    ctx->pc = 0x13BF18u;
    // 0x13bf18: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x13BF18u;
    {
        const bool branch_taken_0x13bf18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x13BF1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF18u;
            // 0x13bf1c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bf18) {
            ctx->pc = 0x13BF2Cu;
            goto label_13bf2c;
        }
    }
    ctx->pc = 0x13BF20u;
    // 0x13bf20: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13bf20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bf24: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x13BF24u;
    SET_GPR_U32(ctx, 31, 0x13BF2Cu);
    ctx->pc = 0x13BF28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF24u;
            // 0x13bf28: 0x24a5d150  addiu       $a1, $a1, -0x2EB0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BF2Cu; }
        if (ctx->pc != 0x13BF2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BF2Cu; }
        if (ctx->pc != 0x13BF2Cu) { return; }
    }
    ctx->pc = 0x13BF2Cu;
label_13bf2c:
    // 0x13bf2c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x13bf2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_13bf30:
    // 0x13bf30: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x13BF30u;
    SET_GPR_U32(ctx, 31, 0x13BF38u);
    ctx->pc = 0x13BF34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF30u;
            // 0x13bf34: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BF38u; }
        if (ctx->pc != 0x13BF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BF38u; }
        if (ctx->pc != 0x13BF38u) { return; }
    }
    ctx->pc = 0x13BF38u;
label_13bf38:
    // 0x13bf38: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13BF38u;
    SET_GPR_U32(ctx, 31, 0x13BF40u);
    ctx->pc = 0x13BF3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF38u;
            // 0x13bf3c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BF40u; }
        if (ctx->pc != 0x13BF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BF40u; }
        if (ctx->pc != 0x13BF40u) { return; }
    }
    ctx->pc = 0x13BF40u;
label_13bf40:
    // 0x13bf40: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x13bf40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bf44: 0x18c0000d  blez        $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x13BF44u;
    {
        const bool branch_taken_0x13bf44 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x13BF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF44u;
            // 0x13bf48: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bf44) {
            ctx->pc = 0x13BF7Cu;
            goto label_13bf7c;
        }
    }
    ctx->pc = 0x13BF4Cu;
    // 0x13bf4c: 0x2408005c  addiu       $t0, $zero, 0x5C
    ctx->pc = 0x13bf4cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x13bf50: 0x2407002f  addiu       $a3, $zero, 0x2F
    ctx->pc = 0x13bf50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x13bf54: 0x2252021  addu        $a0, $s1, $a1
    ctx->pc = 0x13bf54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
label_13bf58:
    // 0x13bf58: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x13bf58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x13bf5c: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x13bf5cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13bf60: 0x14480002  bne         $v0, $t0, . + 4 + (0x2 << 2)
    ctx->pc = 0x13BF60u;
    {
        const bool branch_taken_0x13bf60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 8));
        ctx->pc = 0x13BF64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF60u;
            // 0x13bf64: 0xa6182a  slt         $v1, $a1, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bf60) {
            ctx->pc = 0x13BF6Cu;
            goto label_13bf6c;
        }
    }
    ctx->pc = 0x13BF68u;
    // 0x13bf68: 0xa0870000  sb          $a3, 0x0($a0)
    ctx->pc = 0x13bf68u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 7));
label_13bf6c:
    // 0x13bf6c: 0x0  nop
    ctx->pc = 0x13bf6cu;
    // NOP
    // 0x13bf70: 0x0  nop
    ctx->pc = 0x13bf70u;
    // NOP
    // 0x13bf74: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13BF74u;
    {
        const bool branch_taken_0x13bf74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13BF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF74u;
            // 0x13bf78: 0x2252021  addu        $a0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bf74) {
            ctx->pc = 0x13BF58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13bf58;
        }
    }
    ctx->pc = 0x13BF7Cu;
label_13bf7c:
    // 0x13bf7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13bf7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13bf80: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13bf80u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13bf84: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13bf84u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13bf88: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13bf88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13bf8c: 0x3e00008  jr          $ra
    ctx->pc = 0x13BF8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BF90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BF8Cu;
            // 0x13bf90: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13BEA4u: goto label_13bea4;
            case 0x13BEB8u: goto label_13beb8;
            case 0x13BEC0u: goto label_13bec0;
            case 0x13BEE0u: goto label_13bee0;
            case 0x13BEE8u: goto label_13bee8;
            case 0x13BF2Cu: goto label_13bf2c;
            case 0x13BF30u: goto label_13bf30;
            case 0x13BF38u: goto label_13bf38;
            case 0x13BF40u: goto label_13bf40;
            case 0x13BF58u: goto label_13bf58;
            case 0x13BF6Cu: goto label_13bf6c;
            case 0x13BF7Cu: goto label_13bf7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13BF94u;
    // 0x13bf94: 0x0  nop
    ctx->pc = 0x13bf94u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
