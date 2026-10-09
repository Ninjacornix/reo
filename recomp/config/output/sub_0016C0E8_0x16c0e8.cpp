#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C0E8
// Address: 0x16c0e8 - 0x16c228
void sub_0016C0E8_0x16c0e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C0E8_0x16c0e8");
#endif

    switch (ctx->pc) {
        case 0x16c114u: goto label_16c114;
        case 0x16c164u: goto label_16c164;
        case 0x16c1d8u: goto label_16c1d8;
        default: break;
    }

    ctx->pc = 0x16c0e8u;

    // 0x16c0e8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16c0e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16c0ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16c0ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c0f0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16c0f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16c0f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16c0f8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16c0f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16c0fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16c100: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16c100u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c104: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16c104u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16c108: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16c108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16c10c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x16C10Cu;
    SET_GPR_U32(ctx, 31, 0x16C114u);
    ctx->pc = 0x16C110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C10Cu;
            // 0x16c110: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C114u; }
        if (ctx->pc != 0x16C114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C114u; }
        if (ctx->pc != 0x16C114u) { return; }
    }
    ctx->pc = 0x16C114u;
label_16c114:
    // 0x16c114: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16C114u;
    {
        const bool branch_taken_0x16c114 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C114u;
            // 0x16c118: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c114) {
            ctx->pc = 0x16C140u;
            goto label_16c140;
        }
    }
    ctx->pc = 0x16C11Cu;
    // 0x16c11c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16c11cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16c120: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c120u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c124: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c124u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c128: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16c128u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c12c: 0x34a50185  ori         $a1, $a1, 0x185
    ctx->pc = 0x16c12cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)389);
    // 0x16c130: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16c130u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c134: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16c134u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c138: 0x805a704  j           func_169C10
    ctx->pc = 0x16C138u;
    ctx->pc = 0x16C13Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C138u;
            // 0x16c13c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C140u;
label_16c140:
    // 0x16c140: 0x8e421b30  lw          $v0, 0x1B30($s2)
    ctx->pc = 0x16c140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 6960)));
    // 0x16c144: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16C144u;
    {
        const bool branch_taken_0x16c144 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C144u;
            // 0x16c148: 0x2444093c  addiu       $a0, $v0, 0x93C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 2364));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c144) {
            ctx->pc = 0x16C15Cu;
            goto label_16c15c;
        }
    }
    ctx->pc = 0x16C14Cu;
    // 0x16c14c: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x16C14Cu;
    {
        const bool branch_taken_0x16c14c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x16c14c) {
            ctx->pc = 0x16C15Cu;
            goto label_16c15c;
        }
    }
    ctx->pc = 0x16C154u;
    // 0x16c154: 0x56600006  bnel        $s3, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x16C154u;
    {
        const bool branch_taken_0x16c154 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x16c154) {
            ctx->pc = 0x16C158u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16C154u;
            // 0x16c158: 0x8e42002c  lw          $v0, 0x2C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16C170u;
            goto label_16c170;
        }
    }
    ctx->pc = 0x16C15Cu;
label_16c15c:
    // 0x16c15c: 0xc05bf28  jal         func_16FCA0
    ctx->pc = 0x16C15Cu;
    SET_GPR_U32(ctx, 31, 0x16C164u);
    ctx->pc = 0x16FCA0u;
    if (runtime->hasFunction(0x16FCA0u)) {
        auto targetFn = runtime->lookupFunction(0x16FCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C164u; }
        if (ctx->pc != 0x16C164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FCA0_0x16fca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C164u; }
        if (ctx->pc != 0x16C164u) { return; }
    }
    ctx->pc = 0x16C164u;
label_16c164:
    // 0x16c164: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x16C164u;
    {
        const bool branch_taken_0x16c164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C164u;
            // 0x16c168: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c164) {
            ctx->pc = 0x16C20Cu;
            goto label_16c20c;
        }
    }
    ctx->pc = 0x16C16Cu;
    // 0x16c16c: 0x0  nop
    ctx->pc = 0x16c16cu;
    // NOP
label_16c170:
    // 0x16c170: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x16c170u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x16c174: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x16c174u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16c178: 0x5040000b  beql        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x16C178u;
    {
        const bool branch_taken_0x16c178 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16c178) {
            ctx->pc = 0x16C17Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16C178u;
            // 0x16c17c: 0xac900000  sw          $s0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16C1A8u;
            goto label_16c1a8;
        }
    }
    ctx->pc = 0x16C180u;
    // 0x16c180: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16c180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c184: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16c184u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c188: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16c188u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16c18c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c18cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c190: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c190u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c194: 0x34a50f1d  ori         $a1, $a1, 0xF1D
    ctx->pc = 0x16c194u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3869);
    // 0x16c198: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16c198u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c19c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16c19cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c1a0: 0x805a704  j           func_169C10
    ctx->pc = 0x16C1A0u;
    ctx->pc = 0x16C1A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C1A0u;
            // 0x16c1a4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C1A8u;
label_16c1a8:
    // 0x16c1a8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16c1a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c1ac: 0xac90000c  sw          $s0, 0xC($a0)
    ctx->pc = 0x16c1acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 16));
    // 0x16c1b0: 0x2138021  addu        $s0, $s0, $s3
    ctx->pc = 0x16c1b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x16c1b4: 0xac910004  sw          $s1, 0x4($a0)
    ctx->pc = 0x16c1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 17));
    // 0x16c1b8: 0x2631fffe  addiu       $s1, $s1, -0x2
    ctx->pc = 0x16c1b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967294));
    // 0x16c1bc: 0xac900014  sw          $s0, 0x14($a0)
    ctx->pc = 0x16c1bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 16));
    // 0x16c1c0: 0x2138021  addu        $s0, $s0, $s3
    ctx->pc = 0x16c1c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x16c1c4: 0xac930008  sw          $s3, 0x8($a0)
    ctx->pc = 0x16c1c4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 19));
    // 0x16c1c8: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x16c1c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x16c1cc: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x16c1ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x16c1d0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x16C1D0u;
    {
        const bool branch_taken_0x16c1d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C1D0u;
            // 0x16c1d4: 0x2a260011  slti        $a2, $s1, 0x11 (Delay Slot)
        SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)17) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c1d0) {
            ctx->pc = 0x16C1F4u;
            goto label_16c1f4;
        }
    }
    ctx->pc = 0x16C1D8u;
label_16c1d8:
    // 0x16c1d8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x16c1d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x16c1dc: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x16c1dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x16c1e0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x16c1e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x16c1e4: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x16c1e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c1e8: 0xac600010  sw          $zero, 0x10($v1)
    ctx->pc = 0x16c1e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x16c1ec: 0xac50000c  sw          $s0, 0xC($v0)
    ctx->pc = 0x16c1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 16));
    // 0x16c1f0: 0x2138021  addu        $s0, $s0, $s3
    ctx->pc = 0x16c1f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
label_16c1f4:
    // 0x16c1f4: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x16c1f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x16c1f8: 0x226100b  movn        $v0, $s1, $a2
    ctx->pc = 0x16c1f8u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 17));
    // 0x16c1fc: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x16c1fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16c200: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x16C200u;
    {
        const bool branch_taken_0x16c200 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16C204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C200u;
            // 0x16c204: 0x510c0  sll         $v0, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c200) {
            ctx->pc = 0x16C1D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16c1d8;
        }
    }
    ctx->pc = 0x16C208u;
    // 0x16c208: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16c208u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16c20c:
    // 0x16c20c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c20cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c210: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c210u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c214: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16c214u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c218: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16c218u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c21c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16c21cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c220: 0x3e00008  jr          $ra
    ctx->pc = 0x16C220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C220u;
            // 0x16c224: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C114u: goto label_16c114;
            case 0x16C140u: goto label_16c140;
            case 0x16C15Cu: goto label_16c15c;
            case 0x16C164u: goto label_16c164;
            case 0x16C170u: goto label_16c170;
            case 0x16C1A8u: goto label_16c1a8;
            case 0x16C1D8u: goto label_16c1d8;
            case 0x16C1F4u: goto label_16c1f4;
            case 0x16C20Cu: goto label_16c20c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C228u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
