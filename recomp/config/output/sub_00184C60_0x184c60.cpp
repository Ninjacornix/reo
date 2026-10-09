#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00184C60
// Address: 0x184c60 - 0x184d88
void sub_00184C60_0x184c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00184C60_0x184c60");
#endif

    switch (ctx->pc) {
        case 0x184cc0u: goto label_184cc0;
        case 0x184cd4u: goto label_184cd4;
        case 0x184cf0u: goto label_184cf0;
        case 0x184d38u: goto label_184d38;
        default: break;
    }

    ctx->pc = 0x184c60u;

    // 0x184c60: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x184c60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x184c64: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x184c64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x184c68: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x184c68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x184c6c: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x184c6cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184c70: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x184c70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x184c74: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x184c74u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184c78: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x184c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x184c7c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x184c7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184c80: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x184c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x184c84: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x184c84u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184c88: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x184c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x184c8c: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x184c8cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184c90: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x184c90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x184c94: 0x24556c80  addiu       $s5, $v0, 0x6C80
    ctx->pc = 0x184c94u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 27776));
    // 0x184c98: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x184c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x184c9c: 0x3c167fff  lui         $s6, 0x7FFF
    ctx->pc = 0x184c9cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)32767 << 16));
    // 0x184ca0: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x184ca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x184ca4: 0x3c178101  lui         $s7, 0x8101
    ctx->pc = 0x184ca4u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)33025 << 16));
    // 0x184ca8: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x184ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x184cac: 0x241effff  addiu       $fp, $zero, -0x1
    ctx->pc = 0x184cacu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x184cb0: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x184cb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x184cb4: 0x36f7006f  ori         $s7, $s7, 0x6F
    ctx->pc = 0x184cb4u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)111);
    // 0x184cb8: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x184cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x184cbc: 0x36d6ffff  ori         $s6, $s6, 0xFFFF
    ctx->pc = 0x184cbcu;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | (uint64_t)(uint16_t)65535);
label_184cc0:
    // 0x184cc0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x184cc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184cc4: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x184cc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184cc8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x184cc8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184ccc: 0xc061d1e  jal         func_187478
    ctx->pc = 0x184CCCu;
    SET_GPR_U32(ctx, 31, 0x184CD4u);
    ctx->pc = 0x184CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184CCCu;
            // 0x184cd0: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187478u;
    if (runtime->hasFunction(0x187478u)) {
        auto targetFn = runtime->lookupFunction(0x187478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184CD4u; }
        if (ctx->pc != 0x184CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187478_0x187478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184CD4u; }
        if (ctx->pc != 0x184CD4u) { return; }
    }
    ctx->pc = 0x184CD4u;
label_184cd4:
    // 0x184cd4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x184CD4u;
    {
        const bool branch_taken_0x184cd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184CD4u;
            // 0x184cd8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184cd4) {
            ctx->pc = 0x184CE8u;
            goto label_184ce8;
        }
    }
    ctx->pc = 0x184CDCu;
    // 0x184cdc: 0xae770000  sw          $s7, 0x0($s3)
    ctx->pc = 0x184cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 23));
    // 0x184ce0: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x184CE0u;
    {
        const bool branch_taken_0x184ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184CE0u;
            // 0x184ce4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184ce0) {
            ctx->pc = 0x184D58u;
            goto label_184d58;
        }
    }
    ctx->pc = 0x184CE8u;
label_184ce8:
    // 0x184ce8: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x184ce8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184cec: 0x94820000  lhu         $v0, 0x0($a0)
    ctx->pc = 0x184cecu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_184cf0:
    // 0x184cf0: 0x24840200  addiu       $a0, $a0, 0x200
    ctx->pc = 0x184cf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 512));
    // 0x184cf4: 0x26430001  addiu       $v1, $s2, 0x1
    ctx->pc = 0x184cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x184cf8: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x184cf8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x184cfc: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x184cfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x184d00: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x184D00u;
    {
        const bool branch_taken_0x184d00 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x184D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184D00u;
            // 0x184d04: 0x62900a  movz        $s2, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184d00) {
            ctx->pc = 0x184D18u;
            goto label_184d18;
        }
    }
    ctx->pc = 0x184D08u;
    // 0x184d08: 0x26420001  addiu       $v0, $s2, 0x1
    ctx->pc = 0x184d08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x184d0c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x184D0Cu;
    {
        const bool branch_taken_0x184d0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184D0Cu;
            // 0x184d10: 0x245100b  movn        $v0, $s2, $a1 (Delay Slot)
        if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184d0c) {
            ctx->pc = 0x184D58u;
            goto label_184d58;
        }
    }
    ctx->pc = 0x184D14u;
    // 0x184d14: 0x0  nop
    ctx->pc = 0x184d14u;
    // NOP
label_184d18:
    // 0x184d18: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x184d18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x184d1c: 0x28a20002  slti        $v0, $a1, 0x2
    ctx->pc = 0x184d1cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x184d20: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x184D20u;
    {
        const bool branch_taken_0x184d20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x184d20) {
            ctx->pc = 0x184D24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184D20u;
            // 0x184d24: 0x94820000  lhu         $v0, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x184CF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184cf0;
        }
    }
    ctx->pc = 0x184D28u;
    // 0x184d28: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x184d28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184d2c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x184d2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184d30: 0xc060b02  jal         func_182C08
    ctx->pc = 0x184D30u;
    SET_GPR_U32(ctx, 31, 0x184D38u);
    ctx->pc = 0x184D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184D30u;
            // 0x184d34: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C08u;
    if (runtime->hasFunction(0x182C08u)) {
        auto targetFn = runtime->lookupFunction(0x182C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184D38u; }
        if (ctx->pc != 0x184D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C08_0x182c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184D38u; }
        if (ctx->pc != 0x184D38u) { return; }
    }
    ctx->pc = 0x184D38u;
label_184d38:
    // 0x184d38: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x184d38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x184d3c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x184d3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184d40: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x184D40u;
    {
        const bool branch_taken_0x184d40 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x184D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184D40u;
            // 0x184d44: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184d40) {
            ctx->pc = 0x184D58u;
            goto label_184d58;
        }
    }
    ctx->pc = 0x184D48u;
    // 0x184d48: 0x121e0003  beq         $s0, $fp, . + 4 + (0x3 << 2)
    ctx->pc = 0x184D48u;
    {
        const bool branch_taken_0x184d48 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 30));
        ctx->pc = 0x184D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184D48u;
            // 0x184d4c: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184d48) {
            ctx->pc = 0x184D58u;
            goto label_184d58;
        }
    }
    ctx->pc = 0x184D50u;
    // 0x184d50: 0x1000ffdb  b           . + 4 + (-0x25 << 2)
    ctx->pc = 0x184D50u;
    {
        const bool branch_taken_0x184d50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184D50u;
            // 0x184d54: 0x2168024  and         $s0, $s0, $s6 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184d50) {
            ctx->pc = 0x184CC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184cc0;
        }
    }
    ctx->pc = 0x184D58u;
label_184d58:
    // 0x184d58: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x184d58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x184d5c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x184d5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x184d60: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x184d60u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x184d64: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x184d64u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x184d68: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x184d68u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x184d6c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x184d6cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x184d70: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x184d70u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x184d74: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x184d74u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x184d78: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x184d78u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x184d7c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x184d7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x184d80: 0x3e00008  jr          $ra
    ctx->pc = 0x184D80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x184D84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184D80u;
            // 0x184d84: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x184CC0u: goto label_184cc0;
            case 0x184CD4u: goto label_184cd4;
            case 0x184CE8u: goto label_184ce8;
            case 0x184CF0u: goto label_184cf0;
            case 0x184D18u: goto label_184d18;
            case 0x184D38u: goto label_184d38;
            case 0x184D58u: goto label_184d58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x184D88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
