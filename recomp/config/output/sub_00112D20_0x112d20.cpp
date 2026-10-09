#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112D20
// Address: 0x112d20 - 0x112f08
void sub_00112D20_0x112d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112D20_0x112d20");
#endif

    switch (ctx->pc) {
        case 0x112db0u: goto label_112db0;
        case 0x112de4u: goto label_112de4;
        default: break;
    }

    ctx->pc = 0x112d20u;

    // 0x112d20: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x112d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x112d24: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x112d24u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x112d28: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x112d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x112d2c: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x112d2cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x112d30: 0x69403  sra         $s2, $a2, 16
    ctx->pc = 0x112d30u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 6), 16));
    // 0x112d34: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x112d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x112d38: 0x2642003f  addiu       $v0, $s2, 0x3F
    ctx->pc = 0x112d38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 63));
    // 0x112d3c: 0x5a403  sra         $s4, $a1, 16
    ctx->pc = 0x112d3cu;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 5), 16));
    // 0x112d40: 0x21183  sra         $v0, $v0, 6
    ctx->pc = 0x112d40u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 6));
    // 0x112d44: 0x3283000f  andi        $v1, $s4, 0xF
    ctx->pc = 0x112d44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)15);
    // 0x112d48: 0x3042003f  andi        $v0, $v0, 0x3F
    ctx->pc = 0x112d48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x112d4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x112d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x112d50: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x112d50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x112d54: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x112d54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x112d58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x112d58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112d5c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x112d5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x112d60: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x112d60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x112d64: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x112d64u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x112d68: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x112d68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x112d6c: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x112d6cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x112d70: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x112d70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x112d74: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x112d74u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x112d78: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x112d78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x112d7c: 0x2403004c  addiu       $v1, $zero, 0x4C
    ctx->pc = 0x112d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x112d80: 0x2404004e  addiu       $a0, $zero, 0x4E
    ctx->pc = 0x112d80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
    // 0x112d84: 0x78c03  sra         $s1, $a3, 16
    ctx->pc = 0x112d84u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 7), 16));
    // 0x112d88: 0x8ac03  sra         $s5, $t0, 16
    ctx->pc = 0x112d88u;
    SET_GPR_S32(ctx, 21, SRA32(GPR_S32(ctx, 8), 16));
    // 0x112d8c: 0x99c03  sra         $s3, $t1, 16
    ctx->pc = 0x112d8cu;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 9), 16));
    // 0x112d90: 0xfe030008  sd          $v1, 0x8($s0)
    ctx->pc = 0x112d90u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 8), GPR_U64(ctx, 3));
    // 0x112d94: 0xfe020000  sd          $v0, 0x0($s0)
    ctx->pc = 0x112d94u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 0), GPR_U64(ctx, 2));
    // 0x112d98: 0x16a0000e  bnez        $s5, . + 4 + (0xE << 2)
    ctx->pc = 0x112D98u;
    {
        const bool branch_taken_0x112d98 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        ctx->pc = 0x112D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112D98u;
            // 0x112d9c: 0xfe040018  sd          $a0, 0x18($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112d98) {
            ctx->pc = 0x112DD4u;
            goto label_112dd4;
        }
    }
    ctx->pc = 0x112DA0u;
    // 0x112da0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x112da0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112da4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x112da4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112da8: 0xc044b16  jal         func_112C58
    ctx->pc = 0x112DA8u;
    SET_GPR_U32(ctx, 31, 0x112DB0u);
    ctx->pc = 0x112DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112DA8u;
            // 0x112dac: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112C58u;
    if (runtime->hasFunction(0x112C58u)) {
        auto targetFn = runtime->lookupFunction(0x112C58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112DB0u; }
        if (ctx->pc != 0x112DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112C58_0x112c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112DB0u; }
        if (ctx->pc != 0x112DB0u) { return; }
    }
    ctx->pc = 0x112DB0u;
label_112db0:
    // 0x112db0: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x112db0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x112db4: 0x3263000f  andi        $v1, $s3, 0xF
    ctx->pc = 0x112db4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)15);
    // 0x112db8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x112db8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x112dbc: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x112dbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x112dc0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x112dc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x112dc4: 0x34048000  ori         $a0, $zero, 0x8000
    ctx->pc = 0x112dc4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x112dc8: 0x42478  dsll        $a0, $a0, 17
    ctx->pc = 0x112dc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 17);
    // 0x112dcc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x112DCCu;
    {
        const bool branch_taken_0x112dcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112DCCu;
            // 0x112dd0: 0x441025  or          $v0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112dcc) {
            ctx->pc = 0x112DF8u;
            goto label_112df8;
        }
    }
    ctx->pc = 0x112DD4u;
label_112dd4:
    // 0x112dd4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x112dd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112dd8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x112dd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112ddc: 0xc044b16  jal         func_112C58
    ctx->pc = 0x112DDCu;
    SET_GPR_U32(ctx, 31, 0x112DE4u);
    ctx->pc = 0x112DE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112DDCu;
            // 0x112de0: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112C58u;
    if (runtime->hasFunction(0x112C58u)) {
        auto targetFn = runtime->lookupFunction(0x112C58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112DE4u; }
        if (ctx->pc != 0x112DE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112C58_0x112c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112DE4u; }
        if (ctx->pc != 0x112DE4u) { return; }
    }
    ctx->pc = 0x112DE4u;
label_112de4:
    // 0x112de4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x112de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x112de8: 0x3263000f  andi        $v1, $s3, 0xF
    ctx->pc = 0x112de8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)15);
    // 0x112dec: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x112decu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x112df0: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x112df0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x112df4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x112df4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
label_112df8:
    // 0x112df8: 0xfe020010  sd          $v0, 0x10($s0)
    ctx->pc = 0x112df8u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 16), GPR_U64(ctx, 2));
    // 0x112dfc: 0x111043  sra         $v0, $s1, 1
    ctx->pc = 0x112dfcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 17), 1));
    // 0x112e00: 0x121843  sra         $v1, $s2, 1
    ctx->pc = 0x112e00u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 18), 1));
    // 0x112e04: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x112e04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x112e08: 0x24040800  addiu       $a0, $zero, 0x800
    ctx->pc = 0x112e08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x112e0c: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x112e0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x112e10: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x112e10u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x112e14: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x112e14u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x112e18: 0x82102f  dsubu       $v0, $a0, $v0
    ctx->pc = 0x112e18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) - GPR_U64(ctx, 2));
    // 0x112e1c: 0x83202f  dsubu       $a0, $a0, $v1
    ctx->pc = 0x112e1cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) - GPR_U64(ctx, 3));
    // 0x112e20: 0x2113c  dsll32      $v0, $v0, 4
    ctx->pc = 0x112e20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 4));
    // 0x112e24: 0x2646ffff  addiu       $a2, $s2, -0x1
    ctx->pc = 0x112e24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x112e28: 0x2625ffff  addiu       $a1, $s1, -0x1
    ctx->pc = 0x112e28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x112e2c: 0x42138  dsll        $a0, $a0, 4
    ctx->pc = 0x112e2cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 4);
    // 0x112e30: 0xde030040  ld          $v1, 0x40($s0)
    ctx->pc = 0x112e30u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x112e34: 0xde070050  ld          $a3, 0x50($s0)
    ctx->pc = 0x112e34u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x112e38: 0x52c3c  dsll32      $a1, $a1, 16
    ctx->pc = 0x112e38u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 16));
    // 0x112e3c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x112e3cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x112e40: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x112e40u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x112e44: 0x240b0001  addiu       $t3, $zero, 0x1
    ctx->pc = 0x112e44u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112e48: 0xc53025  or          $a2, $a2, $a1
    ctx->pc = 0x112e48u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x112e4c: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x112e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x112e50: 0x6b1825  or          $v1, $v1, $t3
    ctx->pc = 0x112e50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 11));
    // 0x112e54: 0xeb3825  or          $a3, $a3, $t3
    ctx->pc = 0x112e54u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 11));
    // 0x112e58: 0x24050040  addiu       $a1, $zero, 0x40
    ctx->pc = 0x112e58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x112e5c: 0x2408001a  addiu       $t0, $zero, 0x1A
    ctx->pc = 0x112e5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x112e60: 0x24090046  addiu       $t1, $zero, 0x46
    ctx->pc = 0x112e60u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x112e64: 0x240a0045  addiu       $t2, $zero, 0x45
    ctx->pc = 0x112e64u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x112e68: 0xfe020028  sd          $v0, 0x28($s0)
    ctx->pc = 0x112e68u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 40), GPR_U64(ctx, 2));
    // 0x112e6c: 0xfe040020  sd          $a0, 0x20($s0)
    ctx->pc = 0x112e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 4));
    // 0x112e70: 0x32820002  andi        $v0, $s4, 0x2
    ctx->pc = 0x112e70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)2);
    // 0x112e74: 0xfe050038  sd          $a1, 0x38($s0)
    ctx->pc = 0x112e74u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 56), GPR_U64(ctx, 5));
    // 0x112e78: 0xfe060030  sd          $a2, 0x30($s0)
    ctx->pc = 0x112e78u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 6));
    // 0x112e7c: 0xfe080048  sd          $t0, 0x48($s0)
    ctx->pc = 0x112e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 8));
    // 0x112e80: 0xfe030040  sd          $v1, 0x40($s0)
    ctx->pc = 0x112e80u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 64), GPR_U64(ctx, 3));
    // 0x112e84: 0xfe090058  sd          $t1, 0x58($s0)
    ctx->pc = 0x112e84u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 88), GPR_U64(ctx, 9));
    // 0x112e88: 0xfe070050  sd          $a3, 0x50($s0)
    ctx->pc = 0x112e88u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 80), GPR_U64(ctx, 7));
    // 0x112e8c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x112E8Cu;
    {
        const bool branch_taken_0x112e8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x112E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112E8Cu;
            // 0x112e90: 0xfe0a0068  sd          $t2, 0x68($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 104), GPR_U64(ctx, 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112e8c) {
            ctx->pc = 0x112EA0u;
            goto label_112ea0;
        }
    }
    ctx->pc = 0x112E94u;
    // 0x112e94: 0xde020060  ld          $v0, 0x60($s0)
    ctx->pc = 0x112e94u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x112e98: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x112E98u;
    {
        const bool branch_taken_0x112e98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112E9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112E98u;
            // 0x112e9c: 0x4b1025  or          $v0, $v0, $t3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112e98) {
            ctx->pc = 0x112EACu;
            goto label_112eac;
        }
    }
    ctx->pc = 0x112EA0u;
label_112ea0:
    // 0x112ea0: 0xde020060  ld          $v0, 0x60($s0)
    ctx->pc = 0x112ea0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x112ea4: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x112ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x112ea8: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x112ea8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_112eac:
    // 0x112eac: 0xfe020060  sd          $v0, 0x60($s0)
    ctx->pc = 0x112eacu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 2));
    // 0x112eb0: 0x24020047  addiu       $v0, $zero, 0x47
    ctx->pc = 0x112eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x112eb4: 0x12a00006  beqz        $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x112EB4u;
    {
        const bool branch_taken_0x112eb4 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        ctx->pc = 0x112EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112EB4u;
            // 0x112eb8: 0xfe020078  sd          $v0, 0x78($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 120), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112eb4) {
            ctx->pc = 0x112ED0u;
            goto label_112ed0;
        }
    }
    ctx->pc = 0x112EBCu;
    // 0x112ebc: 0x32a20003  andi        $v0, $s5, 0x3
    ctx->pc = 0x112ebcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)3);
    // 0x112ec0: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x112ec0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x112ec4: 0x21478  dsll        $v0, $v0, 17
    ctx->pc = 0x112ec4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 17);
    // 0x112ec8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x112EC8u;
    {
        const bool branch_taken_0x112ec8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112EC8u;
            // 0x112ecc: 0x431025  or          $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112ec8) {
            ctx->pc = 0x112ED4u;
            goto label_112ed4;
        }
    }
    ctx->pc = 0x112ED0u;
label_112ed0:
    // 0x112ed0: 0x3c020003  lui         $v0, 0x3
    ctx->pc = 0x112ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3 << 16));
label_112ed4:
    // 0x112ed4: 0xfe020070  sd          $v0, 0x70($s0)
    ctx->pc = 0x112ed4u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 2));
    // 0x112ed8: 0xf  sync
    ctx->pc = 0x112ed8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x112edc: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x112edcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x112ee0: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x112ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x112ee4: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x112ee4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x112ee8: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x112ee8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x112eec: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x112eecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x112ef0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x112ef0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x112ef4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x112ef4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112ef8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x112ef8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112efc: 0x3e00008  jr          $ra
    ctx->pc = 0x112EFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112F00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112EFCu;
            // 0x112f00: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112DB0u: goto label_112db0;
            case 0x112DD4u: goto label_112dd4;
            case 0x112DE4u: goto label_112de4;
            case 0x112DF8u: goto label_112df8;
            case 0x112EA0u: goto label_112ea0;
            case 0x112EACu: goto label_112eac;
            case 0x112ED0u: goto label_112ed0;
            case 0x112ED4u: goto label_112ed4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112F04u;
    // 0x112f04: 0x0  nop
    ctx->pc = 0x112f04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
