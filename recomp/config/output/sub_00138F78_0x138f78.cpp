#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138F78
// Address: 0x138f78 - 0x139110
void sub_00138F78_0x138f78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138F78_0x138f78");
#endif

    switch (ctx->pc) {
        case 0x139004u: goto label_139004;
        case 0x139038u: goto label_139038;
        case 0x139050u: goto label_139050;
        case 0x139094u: goto label_139094;
        case 0x1390acu: goto label_1390ac;
        case 0x1390c4u: goto label_1390c4;
        default: break;
    }

    ctx->pc = 0x138f78u;

    // 0x138f78: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x138f78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x138f7c: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x138f7cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138f80: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x138f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x138f84: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x138f84u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138f88: 0x3242003f  andi        $v0, $s2, 0x3F
    ctx->pc = 0x138f88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)63);
    // 0x138f8c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x138f8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x138f90: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x138f90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x138f94: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x138f94u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138f98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138f9c: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x138f9cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138fa0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x138FA0u;
    {
        const bool branch_taken_0x138fa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x138FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138FA0u;
            // 0x138fa4: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138fa0) {
            ctx->pc = 0x138FB8u;
            goto label_138fb8;
        }
    }
    ctx->pc = 0x138FA8u;
    // 0x138fa8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138fa8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138fac: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x138FACu;
    {
        const bool branch_taken_0x138fac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x138FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138FACu;
            // 0x138fb0: 0x2484c968  addiu       $a0, $a0, -0x3698 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953320));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138fac) {
            ctx->pc = 0x139048u;
            goto label_139048;
        }
    }
    ctx->pc = 0x138FB4u;
    // 0x138fb4: 0x0  nop
    ctx->pc = 0x138fb4u;
    // NOP
label_138fb8:
    // 0x138fb8: 0x3262001f  andi        $v0, $s3, 0x1F
    ctx->pc = 0x138fb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)31);
    // 0x138fbc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x138FBCu;
    {
        const bool branch_taken_0x138fbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x138FC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138FBCu;
            // 0x138fc0: 0x3222003f  andi        $v0, $s1, 0x3F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
        ctx->in_delay_slot = false;
        if (branch_taken_0x138fbc) {
            ctx->pc = 0x138FD0u;
            goto label_138fd0;
        }
    }
    ctx->pc = 0x138FC4u;
    // 0x138fc4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138fc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138fc8: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x138FC8u;
    {
        const bool branch_taken_0x138fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x138FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138FC8u;
            // 0x138fcc: 0x2484c988  addiu       $a0, $a0, -0x3678 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953352));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138fc8) {
            ctx->pc = 0x139048u;
            goto label_139048;
        }
    }
    ctx->pc = 0x138FD0u;
label_138fd0:
    // 0x138fd0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x138FD0u;
    {
        const bool branch_taken_0x138fd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x138FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138FD0u;
            // 0x138fd4: 0x2d020008  sltiu       $v0, $t0, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x138fd0) {
            ctx->pc = 0x138FE8u;
            goto label_138fe8;
        }
    }
    ctx->pc = 0x138FD8u;
    // 0x138fd8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138fd8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138fdc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x138fdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138fe0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x138FE0u;
    {
        const bool branch_taken_0x138fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x138FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138FE0u;
            // 0x138fe4: 0x2484c9a8  addiu       $a0, $a0, -0x3658 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138fe0) {
            ctx->pc = 0x138FFCu;
            goto label_138ffc;
        }
    }
    ctx->pc = 0x138FE8u;
label_138fe8:
    // 0x138fe8: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x138FE8u;
    {
        const bool branch_taken_0x138fe8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x138FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138FE8u;
            // 0x138fec: 0x81900  sll         $v1, $t0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138fe8) {
            ctx->pc = 0x139010u;
            goto label_139010;
        }
    }
    ctx->pc = 0x138FF0u;
    // 0x138ff0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138ff4: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x138ff4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ff8: 0x2484c9c0  addiu       $a0, $a0, -0x3640
    ctx->pc = 0x138ff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953408));
label_138ffc:
    // 0x138ffc: 0xc045a12  jal         func_116848
    ctx->pc = 0x138FFCu;
    SET_GPR_U32(ctx, 31, 0x139004u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139004u; }
        if (ctx->pc != 0x139004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139004u; }
        if (ctx->pc != 0x139004u) { return; }
    }
    ctx->pc = 0x139004u;
label_139004:
    // 0x139004: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x139004u;
    {
        const bool branch_taken_0x139004 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139004u;
            // 0x139008: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139004) {
            ctx->pc = 0x1390F4u;
            goto label_1390f4;
        }
    }
    ctx->pc = 0x13900Cu;
    // 0x13900c: 0x0  nop
    ctx->pc = 0x13900cu;
    // NOP
label_139010:
    // 0x139010: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x139010u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x139014: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x139014u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x139018: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x139018u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13901c: 0x2610c430  addiu       $s0, $s0, -0x3BD0
    ctx->pc = 0x13901cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294951984));
    // 0x139020: 0x2038021  addu        $s0, $s0, $v1
    ctx->pc = 0x139020u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x139024: 0x82080000  lb          $t0, 0x0($s0)
    ctx->pc = 0x139024u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x139028: 0x15000032  bnez        $t0, . + 4 + (0x32 << 2)
    ctx->pc = 0x139028u;
    {
        const bool branch_taken_0x139028 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x13902Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139028u;
            // 0x13902c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139028) {
            ctx->pc = 0x1390F4u;
            goto label_1390f4;
        }
    }
    ctx->pc = 0x139030u;
    // 0x139030: 0xc04e37a  jal         func_138DE8
    ctx->pc = 0x139030u;
    SET_GPR_U32(ctx, 31, 0x139038u);
    ctx->pc = 0x138DE8u;
    if (runtime->hasFunction(0x138DE8u)) {
        auto targetFn = runtime->lookupFunction(0x138DE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139038u; }
        if (ctx->pc != 0x139038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138DE8_0x138de8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139038u; }
        if (ctx->pc != 0x139038u) { return; }
    }
    ctx->pc = 0x139038u;
label_139038:
    // 0x139038: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x139038u;
    {
        const bool branch_taken_0x139038 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13903Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139038u;
            // 0x13903c: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139038) {
            ctx->pc = 0x139058u;
            goto label_139058;
        }
    }
    ctx->pc = 0x139040u;
    // 0x139040: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x139040u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x139044: 0x2484c9d8  addiu       $a0, $a0, -0x3628
    ctx->pc = 0x139044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953432));
label_139048:
    // 0x139048: 0xc045a12  jal         func_116848
    ctx->pc = 0x139048u;
    SET_GPR_U32(ctx, 31, 0x139050u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139050u; }
        if (ctx->pc != 0x139050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139050u; }
        if (ctx->pc != 0x139050u) { return; }
    }
    ctx->pc = 0x139050u;
label_139050:
    // 0x139050: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x139050u;
    {
        const bool branch_taken_0x139050 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139050u;
            // 0x139054: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139050) {
            ctx->pc = 0x1390F4u;
            goto label_1390f4;
        }
    }
    ctx->pc = 0x139058u;
label_139058:
    // 0x139058: 0x2623ffc0  addiu       $v1, $s1, -0x40
    ctx->pc = 0x139058u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967232));
    // 0x13905c: 0x3c042000  lui         $a0, 0x2000
    ctx->pc = 0x13905cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8192 << 16));
    // 0x139060: 0x2431021  addu        $v0, $s2, $v1
    ctx->pc = 0x139060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x139064: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x139064u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139068: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x139068u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x13906c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13906cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139070: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x139070u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139074: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x139074u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x139078: 0xae11001c  sw          $s1, 0x1C($s0)
    ctx->pc = 0x139078u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
    // 0x13907c: 0xae130018  sw          $s3, 0x18($s0)
    ctx->pc = 0x13907cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 19));
    // 0x139080: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x139080u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x139084: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x139084u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x139088: 0xae12000c  sw          $s2, 0xC($s0)
    ctx->pc = 0x139088u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 18));
    // 0x13908c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13908Cu;
    SET_GPR_U32(ctx, 31, 0x139094u);
    ctx->pc = 0x139090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13908Cu;
            // 0x139090: 0xa2000001  sb          $zero, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139094u; }
        if (ctx->pc != 0x139094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139094u; }
        if (ctx->pc != 0x139094u) { return; }
    }
    ctx->pc = 0x139094u;
label_139094:
    // 0x139094: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x139094u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139098: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x139098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x13909c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x13909cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1390a0: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1390a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1390a4: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x1390A4u;
    SET_GPR_U32(ctx, 31, 0x1390ACu);
    ctx->pc = 0x1390A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1390A4u;
            // 0x1390a8: 0x24a5003f  addiu       $a1, $a1, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 63));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1390ACu; }
        if (ctx->pc != 0x1390ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1390ACu; }
        if (ctx->pc != 0x1390ACu) { return; }
    }
    ctx->pc = 0x1390ACu;
label_1390ac:
    // 0x1390ac: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x1390acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1390b0: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1390b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1390b4: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1390b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1390b8: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1390b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1390bc: 0xc045416  jal         func_115058
    ctx->pc = 0x1390BCu;
    SET_GPR_U32(ctx, 31, 0x1390C4u);
    ctx->pc = 0x1390C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1390BCu;
            // 0x1390c0: 0x24a5003f  addiu       $a1, $a1, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 63));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115058u;
    if (runtime->hasFunction(0x115058u)) {
        auto targetFn = runtime->lookupFunction(0x115058u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1390C4u; }
        if (ctx->pc != 0x1390C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115058_0x115058(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1390C4u; }
        if (ctx->pc != 0x1390C4u) { return; }
    }
    ctx->pc = 0x1390C4u;
label_1390c4:
    // 0x1390c4: 0x3c020014  lui         $v0, 0x14
    ctx->pc = 0x1390c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20 << 16));
    // 0x1390c8: 0x3c030014  lui         $v1, 0x14
    ctx->pc = 0x1390c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20 << 16));
    // 0x1390cc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1390ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1390d0: 0x24638ec0  addiu       $v1, $v1, -0x7140
    ctx->pc = 0x1390d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938304));
    // 0x1390d4: 0x24428ea8  addiu       $v0, $v0, -0x7158
    ctx->pc = 0x1390d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938280));
    // 0x1390d8: 0xae030028  sw          $v1, 0x28($s0)
    ctx->pc = 0x1390d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
    // 0x1390dc: 0xa2040000  sb          $a0, 0x0($s0)
    ctx->pc = 0x1390dcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1390e0: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x1390e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x1390e4: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1390e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1390e8: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1390e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1390ec: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x1390ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x1390f0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1390f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1390f4:
    // 0x1390f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1390f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1390f8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1390f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1390fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1390fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139100: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x139100u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139104: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x139104u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139108: 0x3e00008  jr          $ra
    ctx->pc = 0x139108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13910Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139108u;
            // 0x13910c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138FB8u: goto label_138fb8;
            case 0x138FD0u: goto label_138fd0;
            case 0x138FE8u: goto label_138fe8;
            case 0x138FFCu: goto label_138ffc;
            case 0x139004u: goto label_139004;
            case 0x139010u: goto label_139010;
            case 0x139038u: goto label_139038;
            case 0x139048u: goto label_139048;
            case 0x139050u: goto label_139050;
            case 0x139058u: goto label_139058;
            case 0x139094u: goto label_139094;
            case 0x1390ACu: goto label_1390ac;
            case 0x1390C4u: goto label_1390c4;
            case 0x1390F4u: goto label_1390f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139110u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
