#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CBC8
// Address: 0x17cbc8 - 0x17cd18
void sub_0017CBC8_0x17cbc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CBC8_0x17cbc8");
#endif

    switch (ctx->pc) {
        case 0x17cc58u: goto label_17cc58;
        case 0x17cc94u: goto label_17cc94;
        case 0x17ccc8u: goto label_17ccc8;
        default: break;
    }

    ctx->pc = 0x17cbc8u;

    // 0x17cbc8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17cbc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17cbcc: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17cbccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17cbd0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17cbd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cbd4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17cbd4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cbd8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17cbd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17cbdc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17cbdcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cbe0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17cbe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17cbe4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17cbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17cbe8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x17cbe8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17cbec: 0x10620040  beq         $v1, $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x17CBECu;
    {
        const bool branch_taken_0x17cbec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17CBF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CBECu;
            // 0x17cbf0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cbec) {
            ctx->pc = 0x17CCF0u;
            goto label_17ccf0;
        }
    }
    ctx->pc = 0x17CBF4u;
    // 0x17cbf4: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17cbf4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17cbf8: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17CBF8u;
    {
        const bool branch_taken_0x17cbf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CBFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CBF8u;
            // 0x17cbfc: 0x24020101  addiu       $v0, $zero, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cbf8) {
            ctx->pc = 0x17CC28u;
            goto label_17cc28;
        }
    }
    ctx->pc = 0x17CC00u;
    // 0x17cc00: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17cc00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17cc04: 0x1062003a  beq         $v1, $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x17CC04u;
    {
        const bool branch_taken_0x17cc04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17CC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC04u;
            // 0x17cc08: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc04) {
            ctx->pc = 0x17CCF0u;
            goto label_17ccf0;
        }
    }
    ctx->pc = 0x17CC0Cu;
    // 0x17cc0c: 0x50400039  beql        $v0, $zero, . + 4 + (0x39 << 2)
    ctx->pc = 0x17CC0Cu;
    {
        const bool branch_taken_0x17cc0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17cc0c) {
            ctx->pc = 0x17CC10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC0Cu;
            // 0x17cc10: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC14u;
    // 0x17cc14: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17cc14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17cc18: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x17CC18u;
    {
        const bool branch_taken_0x17cc18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17cc18) {
            ctx->pc = 0x17CC50u;
            goto label_17cc50;
        }
    }
    ctx->pc = 0x17CC20u;
    // 0x17cc20: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x17CC20u;
    {
        const bool branch_taken_0x17cc20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CC24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC20u;
            // 0x17cc24: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc20) {
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC28u;
label_17cc28:
    // 0x17cc28: 0x10620031  beq         $v1, $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x17CC28u;
    {
        const bool branch_taken_0x17cc28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17CC2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC28u;
            // 0x17cc2c: 0x28620102  slti        $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)258) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc28) {
            ctx->pc = 0x17CCF0u;
            goto label_17ccf0;
        }
    }
    ctx->pc = 0x17CC30u;
    // 0x17cc30: 0x54400030  bnel        $v0, $zero, . + 4 + (0x30 << 2)
    ctx->pc = 0x17CC30u;
    {
        const bool branch_taken_0x17cc30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17cc30) {
            ctx->pc = 0x17CC34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC30u;
            // 0x17cc34: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC38u;
    // 0x17cc38: 0x24021001  addiu       $v0, $zero, 0x1001
    ctx->pc = 0x17cc38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4097));
    // 0x17cc3c: 0x10620020  beq         $v1, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x17CC3Cu;
    {
        const bool branch_taken_0x17cc3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17cc3c) {
            ctx->pc = 0x17CCC0u;
            goto label_17ccc0;
        }
    }
    ctx->pc = 0x17CC44u;
    // 0x17cc44: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x17CC44u;
    {
        const bool branch_taken_0x17cc44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CC48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC44u;
            // 0x17cc48: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc44) {
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC4Cu;
    // 0x17cc4c: 0x0  nop
    ctx->pc = 0x17cc4cu;
    // NOP
label_17cc50:
    // 0x17cc50: 0xc05f51a  jal         func_17D468
    ctx->pc = 0x17CC50u;
    SET_GPR_U32(ctx, 31, 0x17CC58u);
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC58u; }
        if (ctx->pc != 0x17CC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D468_0x17d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC58u; }
        if (ctx->pc != 0x17CC58u) { return; }
    }
    ctx->pc = 0x17CC58u;
label_17cc58:
    // 0x17cc58: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17cc58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cc5c: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17CC5Cu;
    {
        const bool branch_taken_0x17cc5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17CC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC5Cu;
            // 0x17cc60: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc5c) {
            ctx->pc = 0x17CC88u;
            goto label_17cc88;
        }
    }
    ctx->pc = 0x17CC64u;
    // 0x17cc64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cc64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cc68: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17cc68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17cc6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cc70: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17cc70u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc74: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cc74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cc78: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17cc78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cc7c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17cc7cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc80: 0x805f346  j           func_17CD18
    ctx->pc = 0x17CC80u;
    ctx->pc = 0x17CC84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC80u;
            // 0x17cc84: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CD18u;
    if (runtime->hasFunction(0x17CD18u)) {
        auto targetFn = runtime->lookupFunction(0x17CD18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017CD18_0x17cd18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CC88u;
label_17cc88:
    // 0x17cc88: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17cc88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc8c: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17CC8Cu;
    SET_GPR_U32(ctx, 31, 0x17CC94u);
    ctx->pc = 0x17CC90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC8Cu;
            // 0x17cc90: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC94u; }
        if (ctx->pc != 0x17CC94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC94u; }
        if (ctx->pc != 0x17CC94u) { return; }
    }
    ctx->pc = 0x17CC94u;
label_17cc94:
    // 0x17cc94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17cc94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc98: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17cc98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc9c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17cc9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cca0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17cca0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cca4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cca4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cca8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cca8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ccac: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17ccacu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17ccb0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ccb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ccb4: 0x805f346  j           func_17CD18
    ctx->pc = 0x17CCB4u;
    ctx->pc = 0x17CCB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CCB4u;
            // 0x17ccb8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CD18u;
    if (runtime->hasFunction(0x17CD18u)) {
        auto targetFn = runtime->lookupFunction(0x17CD18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017CD18_0x17cd18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CCBCu;
    // 0x17ccbc: 0x0  nop
    ctx->pc = 0x17ccbcu;
    // NOP
label_17ccc0:
    // 0x17ccc0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17CCC0u;
    SET_GPR_U32(ctx, 31, 0x17CCC8u);
    ctx->pc = 0x17CCC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CCC0u;
            // 0x17ccc4: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CCC8u; }
        if (ctx->pc != 0x17CCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CCC8u; }
        if (ctx->pc != 0x17CCC8u) { return; }
    }
    ctx->pc = 0x17CCC8u;
label_17ccc8:
    // 0x17ccc8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ccc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cccc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ccccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ccd0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ccd0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ccd4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17ccd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ccd8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ccd8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ccdc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ccdcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cce0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17cce0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cce4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17cce4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cce8: 0x805f346  j           func_17CD18
    ctx->pc = 0x17CCE8u;
    ctx->pc = 0x17CCECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CCE8u;
            // 0x17ccec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CD18u;
    if (runtime->hasFunction(0x17CD18u)) {
        auto targetFn = runtime->lookupFunction(0x17CD18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017CD18_0x17cd18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CCF0u;
label_17ccf0:
    // 0x17ccf0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ccf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_17ccf4:
    // 0x17ccf4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ccf4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ccf8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ccf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ccfc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ccfcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cd00: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17cd00u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17cd04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cd04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cd08: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17cd08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cd0c: 0x24c61360  addiu       $a2, $a2, 0x1360
    ctx->pc = 0x17cd0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4960));
    // 0x17cd10: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17CD10u;
    ctx->pc = 0x17CD14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CD10u;
            // 0x17cd14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CD18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
