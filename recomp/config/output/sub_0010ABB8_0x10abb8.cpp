#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010ABB8
// Address: 0x10abb8 - 0x10ace8
void sub_0010ABB8_0x10abb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010ABB8_0x10abb8");
#endif

    switch (ctx->pc) {
        case 0x10ac3cu: goto label_10ac3c;
        case 0x10ac8cu: goto label_10ac8c;
        case 0x10acacu: goto label_10acac;
        case 0x10acd0u: goto label_10acd0;
        default: break;
    }

    ctx->pc = 0x10abb8u;

    // 0x10abb8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10abb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10abbc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x10abbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x10abc0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10abc0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10abc4: 0x32020007  andi        $v0, $s0, 0x7
    ctx->pc = 0x10abc4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)7);
    // 0x10abc8: 0x14400038  bnez        $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x10ABC8u;
    {
        const bool branch_taken_0x10abc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10ABCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ABC8u;
            // 0x10abcc: 0x7fbf0010  sq          $ra, 0x10($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10abc8) {
            ctx->pc = 0x10ACACu;
            goto label_10acac;
        }
    }
    ctx->pc = 0x10ABD0u;
    // 0x10abd0: 0x3202000f  andi        $v0, $s0, 0xF
    ctx->pc = 0x10abd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)15);
    // 0x10abd4: 0x3c030101  lui         $v1, 0x101
    ctx->pc = 0x10abd4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)257 << 16));
    // 0x10abd8: 0x34630101  ori         $v1, $v1, 0x101
    ctx->pc = 0x10abd8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)257);
    // 0x10abdc: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x10abdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x10abe0: 0x34630101  ori         $v1, $v1, 0x101
    ctx->pc = 0x10abe0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)257);
    // 0x10abe4: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x10abe4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x10abe8: 0x34630101  ori         $v1, $v1, 0x101
    ctx->pc = 0x10abe8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)257);
    // 0x10abec: 0x3c048080  lui         $a0, 0x8080
    ctx->pc = 0x10abecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32896 << 16));
    // 0x10abf0: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10abf0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10abf4: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10abf4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10abf8: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10abf8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10abfc: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10abfcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10ac00: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10ac00u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10ac04: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x10AC04u;
    {
        const bool branch_taken_0x10ac04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10AC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AC04u;
            // 0x10ac08: 0xde060000  ld          $a2, 0x0($s0) (Delay Slot)
        SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ac04) {
            ctx->pc = 0x10AC68u;
            goto label_10ac68;
        }
    }
    ctx->pc = 0x10AC0Cu;
    // 0x10ac0c: 0x7a020000  lq          $v0, 0x0($s0)
    ctx->pc = 0x10ac0cu;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x10ac10: 0x70633b89  pcpyld      $a3, $v1, $v1
    ctx->pc = 0x10ac10u;
    SET_GPR_VEC(ctx, 7, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 3)));
    // 0x10ac14: 0x70844389  pcpyld      $t0, $a0, $a0
    ctx->pc = 0x10ac14u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 4), GPR_VEC(ctx, 4)));
    // 0x10ac18: 0x70471a48  psubb       $v1, $v0, $a3
    ctx->pc = 0x10ac18u;
    SET_GPR_VEC(ctx, 3, PS2_PSUBB(GPR_VEC(ctx, 2), GPR_VEC(ctx, 7)));
    // 0x10ac1c: 0x700214e9  pnor        $v0, $zero, $v0
    ctx->pc = 0x10ac1cu;
    SET_GPR_VEC(ctx, 2, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x10ac20: 0x70621c89  pand        $v1, $v1, $v0
    ctx->pc = 0x10ac20u;
    SET_GPR_VEC(ctx, 3, PS2_PAND(GPR_VEC(ctx, 3), GPR_VEC(ctx, 2)));
    // 0x10ac24: 0x70681c89  pand        $v1, $v1, $t0
    ctx->pc = 0x10ac24u;
    SET_GPR_VEC(ctx, 3, PS2_PAND(GPR_VEC(ctx, 3), GPR_VEC(ctx, 8)));
    // 0x10ac28: 0x706313a9  pcpyud      $v0, $v1, $v1
    ctx->pc = 0x10ac28u;
    SET_GPR_VEC(ctx, 2, _mm_unpackhi_epi64(GPR_VEC(ctx, 3), GPR_VEC(ctx, 3)));
    // 0x10ac2c: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x10ac2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x10ac30: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x10AC30u;
    {
        const bool branch_taken_0x10ac30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10AC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AC30u;
            // 0x10ac34: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ac30) {
            ctx->pc = 0x10ACACu;
            goto label_10acac;
        }
    }
    ctx->pc = 0x10AC38u;
    // 0x10ac38: 0x24860010  addiu       $a2, $a0, 0x10
    ctx->pc = 0x10ac38u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
label_10ac3c:
    // 0x10ac3c: 0x78c20000  lq          $v0, 0x0($a2)
    ctx->pc = 0x10ac3cu;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10ac40: 0x70021ce9  pnor        $v1, $zero, $v0
    ctx->pc = 0x10ac40u;
    SET_GPR_VEC(ctx, 3, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x10ac44: 0x70471248  psubb       $v0, $v0, $a3
    ctx->pc = 0x10ac44u;
    SET_GPR_VEC(ctx, 2, PS2_PSUBB(GPR_VEC(ctx, 2), GPR_VEC(ctx, 7)));
    // 0x10ac48: 0x70431489  pand        $v0, $v0, $v1
    ctx->pc = 0x10ac48u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 3)));
    // 0x10ac4c: 0x70481489  pand        $v0, $v0, $t0
    ctx->pc = 0x10ac4cu;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 8)));
    // 0x10ac50: 0x70421ba9  pcpyud      $v1, $v0, $v0
    ctx->pc = 0x10ac50u;
    SET_GPR_VEC(ctx, 3, _mm_unpackhi_epi64(GPR_VEC(ctx, 2), GPR_VEC(ctx, 2)));
    // 0x10ac54: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x10ac54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x10ac58: 0x5040fff8  beql        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10AC58u;
    {
        const bool branch_taken_0x10ac58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ac58) {
            ctx->pc = 0x10AC5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10AC58u;
            // 0x10ac5c: 0x24c60010  addiu       $a2, $a2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AC3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ac3c;
        }
    }
    ctx->pc = 0x10AC60u;
    // 0x10ac60: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x10AC60u;
    {
        const bool branch_taken_0x10ac60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AC64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AC60u;
            // 0x10ac64: 0xc0202d  daddu       $a0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ac60) {
            ctx->pc = 0x10ACACu;
            goto label_10acac;
        }
    }
    ctx->pc = 0x10AC68u;
label_10ac68:
    // 0x10ac68: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x10ac68u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ac6c: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x10ac6cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ac70: 0xc3182f  dsubu       $v1, $a2, $v1
    ctx->pc = 0x10ac70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) - GPR_U64(ctx, 3));
    // 0x10ac74: 0x61027  nor         $v0, $zero, $a2
    ctx->pc = 0x10ac74u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 6)));
    // 0x10ac78: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x10ac78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x10ac7c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x10ac7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x10ac80: 0x1460000a  bnez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x10AC80u;
    {
        const bool branch_taken_0x10ac80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10AC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AC80u;
            // 0x10ac84: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ac80) {
            ctx->pc = 0x10ACACu;
            goto label_10acac;
        }
    }
    ctx->pc = 0x10AC88u;
    // 0x10ac88: 0x26060008  addiu       $a2, $s0, 0x8
    ctx->pc = 0x10ac88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_10ac8c:
    // 0x10ac8c: 0xdcc20000  ld          $v0, 0x0($a2)
    ctx->pc = 0x10ac8cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10ac90: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x10ac90u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x10ac94: 0x47102f  dsubu       $v0, $v0, $a3
    ctx->pc = 0x10ac94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 7));
    // 0x10ac98: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10ac98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10ac9c: 0x481024  and         $v0, $v0, $t0
    ctx->pc = 0x10ac9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
    // 0x10aca0: 0x5040fffa  beql        $v0, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10ACA0u;
    {
        const bool branch_taken_0x10aca0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10aca0) {
            ctx->pc = 0x10ACA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10ACA0u;
            // 0x10aca4: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AC8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ac8c;
        }
    }
    ctx->pc = 0x10ACA8u;
    // 0x10aca8: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x10aca8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10acac:
    // 0x10acac: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x10acacu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10acb0: 0x0  nop
    ctx->pc = 0x10acb0u;
    // NOP
    // 0x10acb4: 0x0  nop
    ctx->pc = 0x10acb4u;
    // NOP
    // 0x10acb8: 0x0  nop
    ctx->pc = 0x10acb8u;
    // NOP
    // 0x10acbc: 0x0  nop
    ctx->pc = 0x10acbcu;
    // NOP
    // 0x10acc0: 0x5440fffa  bnel        $v0, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10ACC0u;
    {
        const bool branch_taken_0x10acc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10acc0) {
            ctx->pc = 0x10ACC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10ACC0u;
            // 0x10acc4: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10ACACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10acac;
        }
    }
    ctx->pc = 0x10ACC8u;
    // 0x10acc8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x10ACC8u;
    SET_GPR_U32(ctx, 31, 0x10ACD0u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10ACD0u; }
        if (ctx->pc != 0x10ACD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10ACD0u; }
        if (ctx->pc != 0x10ACD0u) { return; }
    }
    ctx->pc = 0x10ACD0u;
label_10acd0:
    // 0x10acd0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x10acd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10acd4: 0x7bbf0010  lq          $ra, 0x10($sp)
    ctx->pc = 0x10acd4u;
    SET_GPR_VEC(ctx, 31, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10acd8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x10acd8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10acdc: 0x3e00008  jr          $ra
    ctx->pc = 0x10ACDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10ACE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ACDCu;
            // 0x10ace0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10AC3Cu: goto label_10ac3c;
            case 0x10AC68u: goto label_10ac68;
            case 0x10AC8Cu: goto label_10ac8c;
            case 0x10ACACu: goto label_10acac;
            case 0x10ACD0u: goto label_10acd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10ACE4u;
    // 0x10ace4: 0x0  nop
    ctx->pc = 0x10ace4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
