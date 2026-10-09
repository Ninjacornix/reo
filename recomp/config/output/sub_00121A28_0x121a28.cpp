#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00121A28
// Address: 0x121a28 - 0x121ef0
void sub_00121A28_0x121a28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00121A28_0x121a28");
#endif

    switch (ctx->pc) {
        case 0x121aa8u: goto label_121aa8;
        case 0x121accu: goto label_121acc;
        case 0x121ae8u: goto label_121ae8;
        case 0x121afcu: goto label_121afc;
        case 0x121b3cu: goto label_121b3c;
        case 0x121b50u: goto label_121b50;
        case 0x121b70u: goto label_121b70;
        case 0x121bacu: goto label_121bac;
        case 0x121bc0u: goto label_121bc0;
        case 0x121bd8u: goto label_121bd8;
        case 0x121c00u: goto label_121c00;
        case 0x121c14u: goto label_121c14;
        case 0x121c50u: goto label_121c50;
        case 0x121c64u: goto label_121c64;
        case 0x121c78u: goto label_121c78;
        case 0x121c9cu: goto label_121c9c;
        case 0x121cb0u: goto label_121cb0;
        case 0x121cc4u: goto label_121cc4;
        case 0x121cd8u: goto label_121cd8;
        case 0x121ce8u: goto label_121ce8;
        case 0x121cf8u: goto label_121cf8;
        case 0x121d08u: goto label_121d08;
        case 0x121d18u: goto label_121d18;
        case 0x121d28u: goto label_121d28;
        case 0x121d38u: goto label_121d38;
        case 0x121d48u: goto label_121d48;
        case 0x121d58u: goto label_121d58;
        case 0x121d68u: goto label_121d68;
        case 0x121d78u: goto label_121d78;
        case 0x121d8cu: goto label_121d8c;
        case 0x121d9cu: goto label_121d9c;
        case 0x121dacu: goto label_121dac;
        case 0x121dbcu: goto label_121dbc;
        case 0x121dccu: goto label_121dcc;
        case 0x121ddcu: goto label_121ddc;
        case 0x121decu: goto label_121dec;
        case 0x121dfcu: goto label_121dfc;
        case 0x121e0cu: goto label_121e0c;
        case 0x121e24u: goto label_121e24;
        case 0x121e34u: goto label_121e34;
        case 0x121e44u: goto label_121e44;
        case 0x121e60u: goto label_121e60;
        case 0x121e70u: goto label_121e70;
        case 0x121e94u: goto label_121e94;
        case 0x121ea4u: goto label_121ea4;
        case 0x121eb4u: goto label_121eb4;
        case 0x121eccu: goto label_121ecc;
        default: break;
    }

    ctx->pc = 0x121a28u;

    // 0x121a28: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x121a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x121a2c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x121a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x121a30: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x121a30u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121a34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x121a34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x121a38: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x121a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x121a3c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x121a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x121a40: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x121a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x121a44: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x121a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x121a48: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x121a48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121a4c: 0x2a83f  dsra32      $s5, $v0, 0
    ctx->pc = 0x121a4cu;
    SET_GPR_S64(ctx, 21, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x121a50: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x121a50u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x121a54: 0x3c02440f  lui         $v0, 0x440F
    ctx->pc = 0x121a54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17423 << 16));
    // 0x121a58: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x121a58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x121a5c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x121a5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x121a60: 0x2a38024  and         $s0, $s5, $v1
    ctx->pc = 0x121a60u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 21) & GPR_U64(ctx, 3));
    // 0x121a64: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x121a64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x121a68: 0x10400027  beqz        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x121A68u;
    {
        const bool branch_taken_0x121a68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x121A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121A68u;
            // 0x121a6c: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121a68) {
            ctx->pc = 0x121B08u;
            goto label_121b08;
        }
    }
    ctx->pc = 0x121A70u;
    // 0x121a70: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x121a70u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121a74: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x121a74u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x121a78: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x121a78u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x121a7c: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x121a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x121a80: 0x70102a  slt         $v0, $v1, $s0
    ctx->pc = 0x121a80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x121a84: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x121A84u;
    {
        const bool branch_taken_0x121a84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x121a84) {
            ctx->pc = 0x121A9Cu;
            goto label_121a9c;
        }
    }
    ctx->pc = 0x121A8Cu;
    // 0x121a8c: 0x16030008  bne         $s0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x121A8Cu;
    {
        const bool branch_taken_0x121a8c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        if (branch_taken_0x121a8c) {
            ctx->pc = 0x121AB0u;
            goto label_121ab0;
        }
    }
    ctx->pc = 0x121A94u;
    // 0x121a94: 0x10a00006  beqz        $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x121A94u;
    {
        const bool branch_taken_0x121a94 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x121a94) {
            ctx->pc = 0x121AB0u;
            goto label_121ab0;
        }
    }
    ctx->pc = 0x121A9Cu;
label_121a9c:
    // 0x121a9c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x121a9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121aa0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121AA0u;
    SET_GPR_U32(ctx, 31, 0x121AA8u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121AA8u; }
        if (ctx->pc != 0x121AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121AA8u; }
        if (ctx->pc != 0x121AA8u) { return; }
    }
    ctx->pc = 0x121AA8u;
label_121aa8:
    // 0x121aa8: 0x10000109  b           . + 4 + (0x109 << 2)
    ctx->pc = 0x121AA8u;
    {
        const bool branch_taken_0x121aa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121AA8u;
            // 0x121aac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121aa8) {
            ctx->pc = 0x121ED0u;
            goto label_121ed0;
        }
    }
    ctx->pc = 0x121AB0u;
label_121ab0:
    // 0x121ab0: 0x1aa00009  blez        $s5, . + 4 + (0x9 << 2)
    ctx->pc = 0x121AB0u;
    {
        const bool branch_taken_0x121ab0 = (GPR_S64(ctx, 21) <= 0);
        ctx->pc = 0x121AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121AB0u;
            // 0x121ab4: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121ab0) {
            ctx->pc = 0x121AD8u;
            goto label_121ad8;
        }
    }
    ctx->pc = 0x121AB8u;
    // 0x121ab8: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x121ab8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x121abc: 0xdc449210  ld          $a0, -0x6DF0($v0)
    ctx->pc = 0x121abcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 2), 4294939152)));
    // 0x121ac0: 0xdc659230  ld          $a1, -0x6DD0($v1)
    ctx->pc = 0x121ac0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 4294939184)));
    // 0x121ac4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121AC4u;
    SET_GPR_U32(ctx, 31, 0x121ACCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121ACCu; }
        if (ctx->pc != 0x121ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121ACCu; }
        if (ctx->pc != 0x121ACCu) { return; }
    }
    ctx->pc = 0x121ACCu;
label_121acc:
    // 0x121acc: 0x10000100  b           . + 4 + (0x100 << 2)
    ctx->pc = 0x121ACCu;
    {
        const bool branch_taken_0x121acc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121AD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121ACCu;
            // 0x121ad0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121acc) {
            ctx->pc = 0x121ED0u;
            goto label_121ed0;
        }
    }
    ctx->pc = 0x121AD4u;
    // 0x121ad4: 0x0  nop
    ctx->pc = 0x121ad4u;
    // NOP
label_121ad8:
    // 0x121ad8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x121ad8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121adc: 0xdc459210  ld          $a1, -0x6DF0($v0)
    ctx->pc = 0x121adcu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 2), 4294939152)));
    // 0x121ae0: 0xc044752  jal         func_111D48
    ctx->pc = 0x121AE0u;
    SET_GPR_U32(ctx, 31, 0x121AE8u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121AE8u; }
        if (ctx->pc != 0x121AE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121AE8u; }
        if (ctx->pc != 0x121AE8u) { return; }
    }
    ctx->pc = 0x121AE8u;
label_121ae8:
    // 0x121ae8: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x121ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x121aec: 0xdc659230  ld          $a1, -0x6DD0($v1)
    ctx->pc = 0x121aecu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 4294939184)));
    // 0x121af0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x121af0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121af4: 0xc044752  jal         func_111D48
    ctx->pc = 0x121AF4u;
    SET_GPR_U32(ctx, 31, 0x121AFCu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121AFCu; }
        if (ctx->pc != 0x121AFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121AFCu; }
        if (ctx->pc != 0x121AFCu) { return; }
    }
    ctx->pc = 0x121AFCu;
label_121afc:
    // 0x121afc: 0x100000f4  b           . + 4 + (0xF4 << 2)
    ctx->pc = 0x121AFCu;
    {
        const bool branch_taken_0x121afc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121AFCu;
            // 0x121b00: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121afc) {
            ctx->pc = 0x121ED0u;
            goto label_121ed0;
        }
    }
    ctx->pc = 0x121B04u;
    // 0x121b04: 0x0  nop
    ctx->pc = 0x121b04u;
    // NOP
label_121b08:
    // 0x121b08: 0x3c023fdb  lui         $v0, 0x3FDB
    ctx->pc = 0x121b08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16347 << 16));
    // 0x121b0c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x121b0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x121b10: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x121b10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x121b14: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x121B14u;
    {
        const bool branch_taken_0x121b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x121B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121B14u;
            // 0x121b18: 0x3c023e1f  lui         $v0, 0x3E1F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15903 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121b14) {
            ctx->pc = 0x121B68u;
            goto label_121b68;
        }
    }
    ctx->pc = 0x121B1Cu;
    // 0x121b1c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x121b1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x121b20: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x121b20u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x121b24: 0x1440005e  bnez        $v0, . + 4 + (0x5E << 2)
    ctx->pc = 0x121B24u;
    {
        const bool branch_taken_0x121b24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x121B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121B24u;
            // 0x121b28: 0x2414ffff  addiu       $s4, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121b24) {
            ctx->pc = 0x121CA0u;
            goto label_121ca0;
        }
    }
    ctx->pc = 0x121B2Cu;
    // 0x121b2c: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x121b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x121b30: 0xdc4592a0  ld          $a1, -0x6D60($v0)
    ctx->pc = 0x121b30u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 2), 4294939296)));
    // 0x121b34: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121B34u;
    SET_GPR_U32(ctx, 31, 0x121B3Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121B3Cu; }
        if (ctx->pc != 0x121B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121B3Cu; }
        if (ctx->pc != 0x121B3Cu) { return; }
    }
    ctx->pc = 0x121B3Cu;
label_121b3c:
    // 0x121b3c: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x121b3cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x121b40: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x121b40u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x121b44: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x121b44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121b48: 0xc0448a6  jal         func_112298
    ctx->pc = 0x121B48u;
    SET_GPR_U32(ctx, 31, 0x121B50u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121B50u; }
        if (ctx->pc != 0x121B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121B50u; }
        if (ctx->pc != 0x121B50u) { return; }
    }
    ctx->pc = 0x121B50u;
label_121b50:
    // 0x121b50: 0x18400053  blez        $v0, . + 4 + (0x53 << 2)
    ctx->pc = 0x121B50u;
    {
        const bool branch_taken_0x121b50 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x121B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121B50u;
            // 0x121b54: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121b50) {
            ctx->pc = 0x121CA0u;
            goto label_121ca0;
        }
    }
    ctx->pc = 0x121B58u;
    // 0x121b58: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x121b58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121b5c: 0x100000dd  b           . + 4 + (0xDD << 2)
    ctx->pc = 0x121B5Cu;
    {
        const bool branch_taken_0x121b5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121B5Cu;
            // 0x121b60: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121b5c) {
            ctx->pc = 0x121ED4u;
            goto label_121ed4;
        }
    }
    ctx->pc = 0x121B64u;
    // 0x121b64: 0x0  nop
    ctx->pc = 0x121b64u;
    // NOP
label_121b68:
    // 0x121b68: 0xc0487bc  jal         func_121EF0
    ctx->pc = 0x121B68u;
    SET_GPR_U32(ctx, 31, 0x121B70u);
    ctx->pc = 0x121EF0u;
    if (runtime->hasFunction(0x121EF0u)) {
        auto targetFn = runtime->lookupFunction(0x121EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121B70u; }
        if (ctx->pc != 0x121B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121EF0_0x121ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121B70u; }
        if (ctx->pc != 0x121B70u) { return; }
    }
    ctx->pc = 0x121B70u;
label_121b70:
    // 0x121b70: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x121b70u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121b74: 0x3c023ff2  lui         $v0, 0x3FF2
    ctx->pc = 0x121b74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16370 << 16));
    // 0x121b78: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x121b78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x121b7c: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x121b7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x121b80: 0x14400029  bnez        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x121B80u;
    {
        const bool branch_taken_0x121b80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x121B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121B80u;
            // 0x121b84: 0x3c024003  lui         $v0, 0x4003 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16387 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121b80) {
            ctx->pc = 0x121C28u;
            goto label_121c28;
        }
    }
    ctx->pc = 0x121B88u;
    // 0x121b88: 0x3c023fe5  lui         $v0, 0x3FE5
    ctx->pc = 0x121b88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16357 << 16));
    // 0x121b8c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x121b8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x121b90: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x121b90u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x121b94: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x121B94u;
    {
        const bool branch_taken_0x121b94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x121b94) {
            ctx->pc = 0x121BE8u;
            goto label_121be8;
        }
    }
    ctx->pc = 0x121B9Cu;
    // 0x121b9c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x121b9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ba0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121ba0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ba4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121BA4u;
    SET_GPR_U32(ctx, 31, 0x121BACu);
    ctx->pc = 0x121BA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121BA4u;
            // 0x121ba8: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121BACu; }
        if (ctx->pc != 0x121BACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121BACu; }
        if (ctx->pc != 0x121BACu) { return; }
    }
    ctx->pc = 0x121BACu;
label_121bac:
    // 0x121bac: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x121bacu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x121bb0: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x121bb0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x121bb4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x121bb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121bb8: 0xc044752  jal         func_111D48
    ctx->pc = 0x121BB8u;
    SET_GPR_U32(ctx, 31, 0x121BC0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121BC0u; }
        if (ctx->pc != 0x121BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121BC0u; }
        if (ctx->pc != 0x121BC0u) { return; }
    }
    ctx->pc = 0x121BC0u;
label_121bc0:
    // 0x121bc0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121bc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121bc4: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x121bc4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x121bc8: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x121bc8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x121bcc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x121bccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121bd0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121BD0u;
    SET_GPR_U32(ctx, 31, 0x121BD8u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121BD8u; }
        if (ctx->pc != 0x121BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121BD8u; }
        if (ctx->pc != 0x121BD8u) { return; }
    }
    ctx->pc = 0x121BD8u;
label_121bd8:
    // 0x121bd8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x121bd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121bdc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121bdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121be0: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x121BE0u;
    {
        const bool branch_taken_0x121be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x121be0) {
            ctx->pc = 0x121C94u;
            goto label_121c94;
        }
    }
    ctx->pc = 0x121BE8u;
label_121be8:
    // 0x121be8: 0x3411ffc0  ori         $s1, $zero, 0xFFC0
    ctx->pc = 0x121be8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x121bec: 0x118bbc  dsll32      $s1, $s1, 14
    ctx->pc = 0x121becu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << (32 + 14));
    // 0x121bf0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121bf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121bf4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x121bf4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121bf8: 0xc044752  jal         func_111D48
    ctx->pc = 0x121BF8u;
    SET_GPR_U32(ctx, 31, 0x121C00u);
    ctx->pc = 0x121BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121BF8u;
            // 0x121bfc: 0x24140001  addiu       $s4, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C00u; }
        if (ctx->pc != 0x121C00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C00u; }
        if (ctx->pc != 0x121C00u) { return; }
    }
    ctx->pc = 0x121C00u;
label_121c00:
    // 0x121c00: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121c00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c04: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x121c04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c08: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x121c08u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c0c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121C0Cu;
    SET_GPR_U32(ctx, 31, 0x121C14u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C14u; }
        if (ctx->pc != 0x121C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C14u; }
        if (ctx->pc != 0x121C14u) { return; }
    }
    ctx->pc = 0x121C14u;
label_121c14:
    // 0x121c14: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x121c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c18: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121c18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c1c: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x121C1Cu;
    {
        const bool branch_taken_0x121c1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x121c1c) {
            ctx->pc = 0x121C94u;
            goto label_121c94;
        }
    }
    ctx->pc = 0x121C24u;
    // 0x121c24: 0x0  nop
    ctx->pc = 0x121c24u;
    // NOP
label_121c28:
    // 0x121c28: 0x34427fff  ori         $v0, $v0, 0x7FFF
    ctx->pc = 0x121c28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32767);
    // 0x121c2c: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x121c2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x121c30: 0x54400015  bnel        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x121C30u;
    {
        const bool branch_taken_0x121c30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x121c30) {
            ctx->pc = 0x121C34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x121C30u;
            // 0x121c34: 0x24140003  addiu       $s4, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x121C88u;
            goto label_121c88;
        }
    }
    ctx->pc = 0x121C38u;
    // 0x121c38: 0x3410ffe0  ori         $s0, $zero, 0xFFE0
    ctx->pc = 0x121c38u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65504);
    // 0x121c3c: 0x1083bc  dsll32      $s0, $s0, 14
    ctx->pc = 0x121c3cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 14));
    // 0x121c40: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121c40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c44: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x121c44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c48: 0xc044752  jal         func_111D48
    ctx->pc = 0x121C48u;
    SET_GPR_U32(ctx, 31, 0x121C50u);
    ctx->pc = 0x121C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121C48u;
            // 0x121c4c: 0x24140002  addiu       $s4, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C50u; }
        if (ctx->pc != 0x121C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C50u; }
        if (ctx->pc != 0x121C50u) { return; }
    }
    ctx->pc = 0x121C50u;
label_121c50:
    // 0x121c50: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121c50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c54: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x121c54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c58: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x121c58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c5c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121C5Cu;
    SET_GPR_U32(ctx, 31, 0x121C64u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C64u; }
        if (ctx->pc != 0x121C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C64u; }
        if (ctx->pc != 0x121C64u) { return; }
    }
    ctx->pc = 0x121C64u;
label_121c64:
    // 0x121c64: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x121c64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x121c68: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x121c68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x121c6c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x121c6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c70: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121C70u;
    SET_GPR_U32(ctx, 31, 0x121C78u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C78u; }
        if (ctx->pc != 0x121C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C78u; }
        if (ctx->pc != 0x121C78u) { return; }
    }
    ctx->pc = 0x121C78u;
label_121c78:
    // 0x121c78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121c78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c7c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121c7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121c80: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x121C80u;
    {
        const bool branch_taken_0x121c80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x121c80) {
            ctx->pc = 0x121C94u;
            goto label_121c94;
        }
    }
    ctx->pc = 0x121C88u;
label_121c88:
    // 0x121c88: 0x3404bff0  ori         $a0, $zero, 0xBFF0
    ctx->pc = 0x121c88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49136);
    // 0x121c8c: 0x4243c  dsll32      $a0, $a0, 16
    ctx->pc = 0x121c8cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 16));
    // 0x121c90: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x121c90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_121c94:
    // 0x121c94: 0xc04480e  jal         func_112038
    ctx->pc = 0x121C94u;
    SET_GPR_U32(ctx, 31, 0x121C9Cu);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C9Cu; }
        if (ctx->pc != 0x121C9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121C9Cu; }
        if (ctx->pc != 0x121C9Cu) { return; }
    }
    ctx->pc = 0x121C9Cu;
label_121c9c:
    // 0x121c9c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x121c9cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_121ca0:
    // 0x121ca0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121ca0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ca4: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x121ca4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ca8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121CA8u;
    SET_GPR_U32(ctx, 31, 0x121CB0u);
    ctx->pc = 0x121CACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121CA8u;
            // 0x121cac: 0x3c100024  lui         $s0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CB0u; }
        if (ctx->pc != 0x121CB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CB0u; }
        if (ctx->pc != 0x121CB0u) { return; }
    }
    ctx->pc = 0x121CB0u;
label_121cb0:
    // 0x121cb0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x121cb0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121cb4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x121cb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121cb8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x121cb8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121cbc: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121CBCu;
    SET_GPR_U32(ctx, 31, 0x121CC4u);
    ctx->pc = 0x121CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121CBCu;
            // 0x121cc0: 0x26109238  addiu       $s0, $s0, -0x6DC8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294939192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CC4u; }
        if (ctx->pc != 0x121CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CC4u; }
        if (ctx->pc != 0x121CC4u) { return; }
    }
    ctx->pc = 0x121CC4u;
label_121cc4:
    // 0x121cc4: 0xde050050  ld          $a1, 0x50($s0)
    ctx->pc = 0x121cc4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x121cc8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x121cc8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ccc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121cccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121cd0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121CD0u;
    SET_GPR_U32(ctx, 31, 0x121CD8u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CD8u; }
        if (ctx->pc != 0x121CD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CD8u; }
        if (ctx->pc != 0x121CD8u) { return; }
    }
    ctx->pc = 0x121CD8u;
label_121cd8:
    // 0x121cd8: 0xde040040  ld          $a0, 0x40($s0)
    ctx->pc = 0x121cd8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x121cdc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121cdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ce0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121CE0u;
    SET_GPR_U32(ctx, 31, 0x121CE8u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CE8u; }
        if (ctx->pc != 0x121CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CE8u; }
        if (ctx->pc != 0x121CE8u) { return; }
    }
    ctx->pc = 0x121CE8u;
label_121ce8:
    // 0x121ce8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121ce8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121cec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121cecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121cf0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121CF0u;
    SET_GPR_U32(ctx, 31, 0x121CF8u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CF8u; }
        if (ctx->pc != 0x121CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121CF8u; }
        if (ctx->pc != 0x121CF8u) { return; }
    }
    ctx->pc = 0x121CF8u;
label_121cf8:
    // 0x121cf8: 0xde040030  ld          $a0, 0x30($s0)
    ctx->pc = 0x121cf8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x121cfc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121cfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d00: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121D00u;
    SET_GPR_U32(ctx, 31, 0x121D08u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D08u; }
        if (ctx->pc != 0x121D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D08u; }
        if (ctx->pc != 0x121D08u) { return; }
    }
    ctx->pc = 0x121D08u;
label_121d08:
    // 0x121d08: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121d08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d0c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d10: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121D10u;
    SET_GPR_U32(ctx, 31, 0x121D18u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D18u; }
        if (ctx->pc != 0x121D18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D18u; }
        if (ctx->pc != 0x121D18u) { return; }
    }
    ctx->pc = 0x121D18u;
label_121d18:
    // 0x121d18: 0xde040020  ld          $a0, 0x20($s0)
    ctx->pc = 0x121d18u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x121d1c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d20: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121D20u;
    SET_GPR_U32(ctx, 31, 0x121D28u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D28u; }
        if (ctx->pc != 0x121D28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D28u; }
        if (ctx->pc != 0x121D28u) { return; }
    }
    ctx->pc = 0x121D28u;
label_121d28:
    // 0x121d28: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121d28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d2c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d30: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121D30u;
    SET_GPR_U32(ctx, 31, 0x121D38u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D38u; }
        if (ctx->pc != 0x121D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D38u; }
        if (ctx->pc != 0x121D38u) { return; }
    }
    ctx->pc = 0x121D38u;
label_121d38:
    // 0x121d38: 0xde040010  ld          $a0, 0x10($s0)
    ctx->pc = 0x121d38u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x121d3c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d40: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121D40u;
    SET_GPR_U32(ctx, 31, 0x121D48u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D48u; }
        if (ctx->pc != 0x121D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D48u; }
        if (ctx->pc != 0x121D48u) { return; }
    }
    ctx->pc = 0x121D48u;
label_121d48:
    // 0x121d48: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121d48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d4c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d50: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121D50u;
    SET_GPR_U32(ctx, 31, 0x121D58u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D58u; }
        if (ctx->pc != 0x121D58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D58u; }
        if (ctx->pc != 0x121D58u) { return; }
    }
    ctx->pc = 0x121D58u;
label_121d58:
    // 0x121d58: 0xde040000  ld          $a0, 0x0($s0)
    ctx->pc = 0x121d58u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x121d5c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d60: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121D60u;
    SET_GPR_U32(ctx, 31, 0x121D68u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D68u; }
        if (ctx->pc != 0x121D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D68u; }
        if (ctx->pc != 0x121D68u) { return; }
    }
    ctx->pc = 0x121D68u;
label_121d68:
    // 0x121d68: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x121d68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d6c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d70: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121D70u;
    SET_GPR_U32(ctx, 31, 0x121D78u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D78u; }
        if (ctx->pc != 0x121D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D78u; }
        if (ctx->pc != 0x121D78u) { return; }
    }
    ctx->pc = 0x121D78u;
label_121d78:
    // 0x121d78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121d78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d7c: 0xde050048  ld          $a1, 0x48($s0)
    ctx->pc = 0x121d7cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x121d80: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x121d80u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d84: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121D84u;
    SET_GPR_U32(ctx, 31, 0x121D8Cu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D8Cu; }
        if (ctx->pc != 0x121D8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D8Cu; }
        if (ctx->pc != 0x121D8Cu) { return; }
    }
    ctx->pc = 0x121D8Cu;
label_121d8c:
    // 0x121d8c: 0xde040038  ld          $a0, 0x38($s0)
    ctx->pc = 0x121d8cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x121d90: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121d90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121d94: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121D94u;
    SET_GPR_U32(ctx, 31, 0x121D9Cu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D9Cu; }
        if (ctx->pc != 0x121D9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121D9Cu; }
        if (ctx->pc != 0x121D9Cu) { return; }
    }
    ctx->pc = 0x121D9Cu;
label_121d9c:
    // 0x121d9c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121d9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121da0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121da0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121da4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121DA4u;
    SET_GPR_U32(ctx, 31, 0x121DACu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DACu; }
        if (ctx->pc != 0x121DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DACu; }
        if (ctx->pc != 0x121DACu) { return; }
    }
    ctx->pc = 0x121DACu;
label_121dac:
    // 0x121dac: 0xde040028  ld          $a0, 0x28($s0)
    ctx->pc = 0x121dacu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x121db0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121db0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121db4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121DB4u;
    SET_GPR_U32(ctx, 31, 0x121DBCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DBCu; }
        if (ctx->pc != 0x121DBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DBCu; }
        if (ctx->pc != 0x121DBCu) { return; }
    }
    ctx->pc = 0x121DBCu;
label_121dbc:
    // 0x121dbc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121dbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121dc0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121dc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121dc4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121DC4u;
    SET_GPR_U32(ctx, 31, 0x121DCCu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DCCu; }
        if (ctx->pc != 0x121DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DCCu; }
        if (ctx->pc != 0x121DCCu) { return; }
    }
    ctx->pc = 0x121DCCu;
label_121dcc:
    // 0x121dcc: 0xde040018  ld          $a0, 0x18($s0)
    ctx->pc = 0x121dccu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x121dd0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121dd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121dd4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121DD4u;
    SET_GPR_U32(ctx, 31, 0x121DDCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DDCu; }
        if (ctx->pc != 0x121DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DDCu; }
        if (ctx->pc != 0x121DDCu) { return; }
    }
    ctx->pc = 0x121DDCu;
label_121ddc:
    // 0x121ddc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121ddcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121de0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121de0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121de4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121DE4u;
    SET_GPR_U32(ctx, 31, 0x121DECu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DECu; }
        if (ctx->pc != 0x121DECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DECu; }
        if (ctx->pc != 0x121DECu) { return; }
    }
    ctx->pc = 0x121DECu;
label_121dec:
    // 0x121dec: 0xde040008  ld          $a0, 0x8($s0)
    ctx->pc = 0x121decu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x121df0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121df0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121df4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121DF4u;
    SET_GPR_U32(ctx, 31, 0x121DFCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DFCu; }
        if (ctx->pc != 0x121DFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121DFCu; }
        if (ctx->pc != 0x121DFCu) { return; }
    }
    ctx->pc = 0x121DFCu;
label_121dfc:
    // 0x121dfc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x121dfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e00: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121e00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e04: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121E04u;
    SET_GPR_U32(ctx, 31, 0x121E0Cu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E0Cu; }
        if (ctx->pc != 0x121E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E0Cu; }
        if (ctx->pc != 0x121E0Cu) { return; }
    }
    ctx->pc = 0x121E0Cu;
label_121e0c:
    // 0x121e0c: 0x6810010  bgez        $s4, . + 4 + (0x10 << 2)
    ctx->pc = 0x121E0Cu;
    {
        const bool branch_taken_0x121e0c = (GPR_S64(ctx, 20) >= 0);
        if (branch_taken_0x121e0c) {
            ctx->pc = 0x121E50u;
            goto label_121e50;
        }
    }
    ctx->pc = 0x121E14u;
    // 0x121e14: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x121e14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e18: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121e18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e1c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121E1Cu;
    SET_GPR_U32(ctx, 31, 0x121E24u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E24u; }
        if (ctx->pc != 0x121E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E24u; }
        if (ctx->pc != 0x121E24u) { return; }
    }
    ctx->pc = 0x121E24u;
label_121e24:
    // 0x121e24: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121e24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e28: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121e28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e2c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121E2Cu;
    SET_GPR_U32(ctx, 31, 0x121E34u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E34u; }
        if (ctx->pc != 0x121E34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E34u; }
        if (ctx->pc != 0x121E34u) { return; }
    }
    ctx->pc = 0x121E34u;
label_121e34:
    // 0x121e34: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121e34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e38: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121e38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e3c: 0xc044752  jal         func_111D48
    ctx->pc = 0x121E3Cu;
    SET_GPR_U32(ctx, 31, 0x121E44u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E44u; }
        if (ctx->pc != 0x121E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E44u; }
        if (ctx->pc != 0x121E44u) { return; }
    }
    ctx->pc = 0x121E44u;
label_121e44:
    // 0x121e44: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x121E44u;
    {
        const bool branch_taken_0x121e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x121E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121E44u;
            // 0x121e48: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121e44) {
            ctx->pc = 0x121ED0u;
            goto label_121ed0;
        }
    }
    ctx->pc = 0x121E4Cu;
    // 0x121e4c: 0x0  nop
    ctx->pc = 0x121e4cu;
    // NOP
label_121e50:
    // 0x121e50: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x121e50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e54: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121e54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e58: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x121E58u;
    SET_GPR_U32(ctx, 31, 0x121E60u);
    ctx->pc = 0x121E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x121E58u;
            // 0x121e5c: 0x1480c0  sll         $s0, $s4, 3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E60u; }
        if (ctx->pc != 0x121E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E60u; }
        if (ctx->pc != 0x121E60u) { return; }
    }
    ctx->pc = 0x121E60u;
label_121e60:
    // 0x121e60: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x121e60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e64: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121e64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e68: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x121E68u;
    SET_GPR_U32(ctx, 31, 0x121E70u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E70u; }
        if (ctx->pc != 0x121E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E70u; }
        if (ctx->pc != 0x121E70u) { return; }
    }
    ctx->pc = 0x121E70u;
label_121e70:
    // 0x121e70: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x121e70u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x121e74: 0xb02821  addu        $a1, $a1, $s0
    ctx->pc = 0x121e74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x121e78: 0xdca59218  ld          $a1, -0x6DE8($a1)
    ctx->pc = 0x121e78u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 5), 4294939160)));
    // 0x121e7c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x121e7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e80: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x121e80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x121e84: 0x242191f8  addiu       $at, $at, -0x6E08
    ctx->pc = 0x121e84u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294939128));
    // 0x121e88: 0x308021  addu        $s0, $at, $s0
    ctx->pc = 0x121e88u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0x121e8c: 0xc044752  jal         func_111D48
    ctx->pc = 0x121E8Cu;
    SET_GPR_U32(ctx, 31, 0x121E94u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E94u; }
        if (ctx->pc != 0x121E94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121E94u; }
        if (ctx->pc != 0x121E94u) { return; }
    }
    ctx->pc = 0x121E94u;
label_121e94:
    // 0x121e94: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x121e94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e98: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x121e98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121e9c: 0xc044752  jal         func_111D48
    ctx->pc = 0x121E9Cu;
    SET_GPR_U32(ctx, 31, 0x121EA4u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121EA4u; }
        if (ctx->pc != 0x121EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121EA4u; }
        if (ctx->pc != 0x121EA4u) { return; }
    }
    ctx->pc = 0x121EA4u;
label_121ea4:
    // 0x121ea4: 0xde040000  ld          $a0, 0x0($s0)
    ctx->pc = 0x121ea4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x121ea8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121ea8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121eac: 0xc044752  jal         func_111D48
    ctx->pc = 0x121EACu;
    SET_GPR_U32(ctx, 31, 0x121EB4u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121EB4u; }
        if (ctx->pc != 0x121EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121EB4u; }
        if (ctx->pc != 0x121EB4u) { return; }
    }
    ctx->pc = 0x121EB4u;
label_121eb4:
    // 0x121eb4: 0x6a10006  bgez        $s5, . + 4 + (0x6 << 2)
    ctx->pc = 0x121EB4u;
    {
        const bool branch_taken_0x121eb4 = (GPR_S64(ctx, 21) >= 0);
        ctx->pc = 0x121EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121EB4u;
            // 0x121eb8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x121eb4) {
            ctx->pc = 0x121ED0u;
            goto label_121ed0;
        }
    }
    ctx->pc = 0x121EBCu;
    // 0x121ebc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x121ebcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ec0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x121ec0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ec4: 0xc044752  jal         func_111D48
    ctx->pc = 0x121EC4u;
    SET_GPR_U32(ctx, 31, 0x121ECCu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121ECCu; }
        if (ctx->pc != 0x121ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x121ECCu; }
        if (ctx->pc != 0x121ECCu) { return; }
    }
    ctx->pc = 0x121ECCu;
label_121ecc:
    // 0x121ecc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x121eccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_121ed0:
    // 0x121ed0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x121ed0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_121ed4:
    // 0x121ed4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x121ed4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x121ed8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x121ed8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x121edc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x121edcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x121ee0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x121ee0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x121ee4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x121ee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x121ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x121EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x121EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x121EE8u;
            // 0x121eec: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x121A9Cu: goto label_121a9c;
            case 0x121AA8u: goto label_121aa8;
            case 0x121AB0u: goto label_121ab0;
            case 0x121ACCu: goto label_121acc;
            case 0x121AD8u: goto label_121ad8;
            case 0x121AE8u: goto label_121ae8;
            case 0x121AFCu: goto label_121afc;
            case 0x121B08u: goto label_121b08;
            case 0x121B3Cu: goto label_121b3c;
            case 0x121B50u: goto label_121b50;
            case 0x121B68u: goto label_121b68;
            case 0x121B70u: goto label_121b70;
            case 0x121BACu: goto label_121bac;
            case 0x121BC0u: goto label_121bc0;
            case 0x121BD8u: goto label_121bd8;
            case 0x121BE8u: goto label_121be8;
            case 0x121C00u: goto label_121c00;
            case 0x121C14u: goto label_121c14;
            case 0x121C28u: goto label_121c28;
            case 0x121C50u: goto label_121c50;
            case 0x121C64u: goto label_121c64;
            case 0x121C78u: goto label_121c78;
            case 0x121C88u: goto label_121c88;
            case 0x121C94u: goto label_121c94;
            case 0x121C9Cu: goto label_121c9c;
            case 0x121CA0u: goto label_121ca0;
            case 0x121CB0u: goto label_121cb0;
            case 0x121CC4u: goto label_121cc4;
            case 0x121CD8u: goto label_121cd8;
            case 0x121CE8u: goto label_121ce8;
            case 0x121CF8u: goto label_121cf8;
            case 0x121D08u: goto label_121d08;
            case 0x121D18u: goto label_121d18;
            case 0x121D28u: goto label_121d28;
            case 0x121D38u: goto label_121d38;
            case 0x121D48u: goto label_121d48;
            case 0x121D58u: goto label_121d58;
            case 0x121D68u: goto label_121d68;
            case 0x121D78u: goto label_121d78;
            case 0x121D8Cu: goto label_121d8c;
            case 0x121D9Cu: goto label_121d9c;
            case 0x121DACu: goto label_121dac;
            case 0x121DBCu: goto label_121dbc;
            case 0x121DCCu: goto label_121dcc;
            case 0x121DDCu: goto label_121ddc;
            case 0x121DECu: goto label_121dec;
            case 0x121DFCu: goto label_121dfc;
            case 0x121E0Cu: goto label_121e0c;
            case 0x121E24u: goto label_121e24;
            case 0x121E34u: goto label_121e34;
            case 0x121E44u: goto label_121e44;
            case 0x121E50u: goto label_121e50;
            case 0x121E60u: goto label_121e60;
            case 0x121E70u: goto label_121e70;
            case 0x121E94u: goto label_121e94;
            case 0x121EA4u: goto label_121ea4;
            case 0x121EB4u: goto label_121eb4;
            case 0x121ECCu: goto label_121ecc;
            case 0x121ED0u: goto label_121ed0;
            case 0x121ED4u: goto label_121ed4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x121EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
