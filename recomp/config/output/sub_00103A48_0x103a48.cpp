#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103A48
// Address: 0x103a48 - 0x103c78
void sub_00103A48_0x103a48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103A48_0x103a48");
#endif

    switch (ctx->pc) {
        case 0x103ad8u: goto label_103ad8;
        case 0x103b50u: goto label_103b50;
        case 0x103b84u: goto label_103b84;
        case 0x103ba0u: goto label_103ba0;
        case 0x103c20u: goto label_103c20;
        default: break;
    }

    ctx->pc = 0x103a48u;

    // 0x103a48: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x103a48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x103a4c: 0xa0702d  daddu       $t6, $a1, $zero
    ctx->pc = 0x103a4cu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a50: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x103a50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x103a54: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x103a54u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103a58: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x103a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x103a5c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x103a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x103a60: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x103a60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x103a64: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x103a64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x103a68: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x103a68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x103a6c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x103a6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x103a70: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x103a70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x103a74: 0x8dd00010  lw          $s0, 0x10($t6)
    ctx->pc = 0x103a74u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 16)));
    // 0x103a78: 0x8e830010  lw          $v1, 0x10($s4)
    ctx->pc = 0x103a78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 16)));
    // 0x103a7c: 0x70182a  slt         $v1, $v1, $s0
    ctx->pc = 0x103a7cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x103a80: 0x14600072  bnez        $v1, . + 4 + (0x72 << 2)
    ctx->pc = 0x103A80u;
    {
        const bool branch_taken_0x103a80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x103A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103A80u;
            // 0x103a84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103a80) {
            ctx->pc = 0x103C4Cu;
            goto label_103c4c;
        }
    }
    ctx->pc = 0x103A88u;
    // 0x103a88: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x103a88u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x103a8c: 0x25cb0014  addiu       $t3, $t6, 0x14
    ctx->pc = 0x103a8cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 14), 20));
    // 0x103a90: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x103a90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x103a94: 0x26910014  addiu       $s1, $s4, 0x14
    ctx->pc = 0x103a94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 20), 20));
    // 0x103a98: 0x1629821  addu        $s3, $t3, $v0
    ctx->pc = 0x103a98u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
    // 0x103a9c: 0x2224821  addu        $t1, $s1, $v0
    ctx->pc = 0x103a9cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x103aa0: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x103aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x103aa4: 0x160b02d  daddu       $s6, $t3, $zero
    ctx->pc = 0x103aa4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103aa8: 0x8d2d0000  lw          $t5, 0x0($t1)
    ctx->pc = 0x103aa8u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x103aac: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x103aacu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103ab0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x103ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x103ab4: 0x1a3001b  divu        $zero, $t5, $v1
    ctx->pc = 0x103ab4u;
    { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 13) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 13) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,13); } }
    // 0x103ab8: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x103AB8u;
    {
        const bool branch_taken_0x103ab8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x103ab8) {
            ctx->pc = 0x103ABCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103AB8u;
            // 0x103abc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x103AC0u;
            goto label_103ac0;
        }
    }
    ctx->pc = 0x103AC0u;
label_103ac0:
    // 0x103ac0: 0xa812  mflo        $s5
    ctx->pc = 0x103ac0u;
    SET_GPR_U64(ctx, 21, ctx->lo);
    // 0x103ac4: 0x2a0902d  daddu       $s2, $s5, $zero
    ctx->pc = 0x103ac4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103ac8: 0x1240002b  beqz        $s2, . + 4 + (0x2B << 2)
    ctx->pc = 0x103AC8u;
    {
        const bool branch_taken_0x103ac8 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x103ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103AC8u;
            // 0x103acc: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103ac8) {
            ctx->pc = 0x103B78u;
            goto label_103b78;
        }
    }
    ctx->pc = 0x103AD0u;
    // 0x103ad0: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x103ad0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103ad4: 0x0  nop
    ctx->pc = 0x103ad4u;
    // NOP
label_103ad8:
    // 0x103ad8: 0x8d640000  lw          $a0, 0x0($t3)
    ctx->pc = 0x103ad8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x103adc: 0x256b0004  addiu       $t3, $t3, 0x4
    ctx->pc = 0x103adcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
    // 0x103ae0: 0x8d460000  lw          $a2, 0x0($t2)
    ctx->pc = 0x103ae0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x103ae4: 0x26b382b  sltu        $a3, $s3, $t3
    ctx->pc = 0x103ae4u;
    SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
    // 0x103ae8: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x103ae8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x103aec: 0x42402  srl         $a0, $a0, 16
    ctx->pc = 0x103aecu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x103af0: 0x522818  mult        $a1, $v0, $s2
    ctx->pc = 0x103af0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x103af4: 0x922018  mult        $a0, $a0, $s2
    ctx->pc = 0x103af4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x103af8: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x103af8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x103afc: 0x30c3ffff  andi        $v1, $a2, 0xFFFF
    ctx->pc = 0x103afcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x103b00: 0x3045ffff  andi        $a1, $v0, 0xFFFF
    ctx->pc = 0x103b00u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x103b04: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x103b04u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x103b08: 0x824021  addu        $t0, $a0, $v0
    ctx->pc = 0x103b08u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x103b0c: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x103b0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x103b10: 0x6c1821  addu        $v1, $v1, $t4
    ctx->pc = 0x103b10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x103b14: 0x63402  srl         $a2, $a2, 16
    ctx->pc = 0x103b14u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 16));
    // 0x103b18: 0x3102ffff  andi        $v0, $t0, 0xFFFF
    ctx->pc = 0x103b18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65535);
    // 0x103b1c: 0x36403  sra         $t4, $v1, 16
    ctx->pc = 0x103b1cu;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 3), 16));
    // 0x103b20: 0xc23023  subu        $a2, $a2, $v0
    ctx->pc = 0x103b20u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x103b24: 0xa5430000  sh          $v1, 0x0($t2)
    ctx->pc = 0x103b24u;
    WRITE16(ADD32(GPR_U32(ctx, 10), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x103b28: 0xcc2821  addu        $a1, $a2, $t4
    ctx->pc = 0x103b28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 12)));
    // 0x103b2c: 0x81c02  srl         $v1, $t0, 16
    ctx->pc = 0x103b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 16));
    // 0x103b30: 0xa5450002  sh          $a1, 0x2($t2)
    ctx->pc = 0x103b30u;
    WRITE16(ADD32(GPR_U32(ctx, 10), 2), (uint16_t)GPR_U32(ctx, 5));
    // 0x103b34: 0x254a0004  addiu       $t2, $t2, 0x4
    ctx->pc = 0x103b34u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
    // 0x103b38: 0x10e0ffe7  beqz        $a3, . + 4 + (-0x19 << 2)
    ctx->pc = 0x103B38u;
    {
        const bool branch_taken_0x103b38 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x103B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103B38u;
            // 0x103b3c: 0x56403  sra         $t4, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103b38) {
            ctx->pc = 0x103AD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_103ad8;
        }
    }
    ctx->pc = 0x103B40u;
    // 0x103b40: 0x55a0000e  bnel        $t5, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x103B40u;
    {
        const bool branch_taken_0x103b40 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 0));
        if (branch_taken_0x103b40) {
            ctx->pc = 0x103B44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103B40u;
            // 0x103b44: 0x1c0282d  daddu       $a1, $t6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103B7Cu;
            goto label_103b7c;
        }
    }
    ctx->pc = 0x103B48u;
    // 0x103b48: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x103B48u;
    {
        const bool branch_taken_0x103b48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103B48u;
            // 0x103b4c: 0x2529fffc  addiu       $t1, $t1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103b48) {
            ctx->pc = 0x103B54u;
            goto label_103b54;
        }
    }
    ctx->pc = 0x103B50u;
label_103b50:
    // 0x103b50: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x103b50u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_103b54:
    // 0x103b54: 0x229102b  sltu        $v0, $s1, $t1
    ctx->pc = 0x103b54u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x103b58: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x103B58u;
    {
        const bool branch_taken_0x103b58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x103b58) {
            ctx->pc = 0x103B5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103B58u;
            // 0x103b5c: 0xae900010  sw          $s0, 0x10($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 16), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103B78u;
            goto label_103b78;
        }
    }
    ctx->pc = 0x103B60u;
    // 0x103b60: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x103b60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x103b64: 0x0  nop
    ctx->pc = 0x103b64u;
    // NOP
    // 0x103b68: 0x0  nop
    ctx->pc = 0x103b68u;
    // NOP
    // 0x103b6c: 0x5040fff8  beql        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x103B6Cu;
    {
        const bool branch_taken_0x103b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x103b6c) {
            ctx->pc = 0x103B70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103B6Cu;
            // 0x103b70: 0x2529fffc  addiu       $t1, $t1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967292));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103B50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_103b50;
        }
    }
    ctx->pc = 0x103B74u;
    // 0x103b74: 0xae900010  sw          $s0, 0x10($s4)
    ctx->pc = 0x103b74u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 16), GPR_U32(ctx, 16));
label_103b78:
    // 0x103b78: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x103b78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
label_103b7c:
    // 0x103b7c: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x103B7Cu;
    SET_GPR_U32(ctx, 31, 0x103B84u);
    ctx->pc = 0x103B80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103B7Cu;
            // 0x103b80: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103B84u; }
        if (ctx->pc != 0x103B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103B84u; }
        if (ctx->pc != 0x103B84u) { return; }
    }
    ctx->pc = 0x103B84u;
label_103b84:
    // 0x103b84: 0x4400030  bltz        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x103B84u;
    {
        const bool branch_taken_0x103b84 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x103B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103B84u;
            // 0x103b88: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103b84) {
            ctx->pc = 0x103C48u;
            goto label_103c48;
        }
    }
    ctx->pc = 0x103B8Cu;
    // 0x103b8c: 0x26b20001  addiu       $s2, $s5, 0x1
    ctx->pc = 0x103b8cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x103b90: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x103b90u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103b94: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x103b94u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103b98: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x103b98u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103b9c: 0x0  nop
    ctx->pc = 0x103b9cu;
    // NOP
label_103ba0:
    // 0x103ba0: 0x8d640000  lw          $a0, 0x0($t3)
    ctx->pc = 0x103ba0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x103ba4: 0x256b0004  addiu       $t3, $t3, 0x4
    ctx->pc = 0x103ba4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
    // 0x103ba8: 0x8d450000  lw          $a1, 0x0($t2)
    ctx->pc = 0x103ba8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x103bac: 0x26b382b  sltu        $a3, $s3, $t3
    ctx->pc = 0x103bacu;
    SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 11)) ? 1 : 0);
    // 0x103bb0: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x103bb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x103bb4: 0x43402  srl         $a2, $a0, 16
    ctx->pc = 0x103bb4u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x103bb8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x103bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x103bbc: 0x30a3ffff  andi        $v1, $a1, 0xFFFF
    ctx->pc = 0x103bbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x103bc0: 0x3044ffff  andi        $a0, $v0, 0xFFFF
    ctx->pc = 0x103bc0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x103bc4: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x103bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x103bc8: 0xc24021  addu        $t0, $a2, $v0
    ctx->pc = 0x103bc8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x103bcc: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x103bccu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x103bd0: 0x6c1821  addu        $v1, $v1, $t4
    ctx->pc = 0x103bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x103bd4: 0x52c02  srl         $a1, $a1, 16
    ctx->pc = 0x103bd4u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x103bd8: 0x3102ffff  andi        $v0, $t0, 0xFFFF
    ctx->pc = 0x103bd8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65535);
    // 0x103bdc: 0x36403  sra         $t4, $v1, 16
    ctx->pc = 0x103bdcu;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 3), 16));
    // 0x103be0: 0xa22823  subu        $a1, $a1, $v0
    ctx->pc = 0x103be0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x103be4: 0xa5430000  sh          $v1, 0x0($t2)
    ctx->pc = 0x103be4u;
    WRITE16(ADD32(GPR_U32(ctx, 10), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x103be8: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x103be8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x103bec: 0x81c02  srl         $v1, $t0, 16
    ctx->pc = 0x103becu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 16));
    // 0x103bf0: 0xa5450002  sh          $a1, 0x2($t2)
    ctx->pc = 0x103bf0u;
    WRITE16(ADD32(GPR_U32(ctx, 10), 2), (uint16_t)GPR_U32(ctx, 5));
    // 0x103bf4: 0x254a0004  addiu       $t2, $t2, 0x4
    ctx->pc = 0x103bf4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
    // 0x103bf8: 0x10e0ffe9  beqz        $a3, . + 4 + (-0x17 << 2)
    ctx->pc = 0x103BF8u;
    {
        const bool branch_taken_0x103bf8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x103BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103BF8u;
            // 0x103bfc: 0x56403  sra         $t4, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103bf8) {
            ctx->pc = 0x103BA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_103ba0;
        }
    }
    ctx->pc = 0x103C00u;
    // 0x103c00: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x103c00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x103c04: 0x2224821  addu        $t1, $s1, $v0
    ctx->pc = 0x103c04u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x103c08: 0x8d230000  lw          $v1, 0x0($t1)
    ctx->pc = 0x103c08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x103c0c: 0x1460000f  bnez        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x103C0Cu;
    {
        const bool branch_taken_0x103c0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x103C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103C0Cu;
            // 0x103c10: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103c0c) {
            ctx->pc = 0x103C4Cu;
            goto label_103c4c;
        }
    }
    ctx->pc = 0x103C14u;
    // 0x103c14: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x103C14u;
    {
        const bool branch_taken_0x103c14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103C14u;
            // 0x103c18: 0x2529fffc  addiu       $t1, $t1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103c14) {
            ctx->pc = 0x103C24u;
            goto label_103c24;
        }
    }
    ctx->pc = 0x103C1Cu;
    // 0x103c1c: 0x0  nop
    ctx->pc = 0x103c1cu;
    // NOP
label_103c20:
    // 0x103c20: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x103c20u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_103c24:
    // 0x103c24: 0x229102b  sltu        $v0, $s1, $t1
    ctx->pc = 0x103c24u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x103c28: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x103C28u;
    {
        const bool branch_taken_0x103c28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x103c28) {
            ctx->pc = 0x103C2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103C28u;
            // 0x103c2c: 0xae900010  sw          $s0, 0x10($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 16), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103C48u;
            goto label_103c48;
        }
    }
    ctx->pc = 0x103C30u;
    // 0x103c30: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x103c30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x103c34: 0x0  nop
    ctx->pc = 0x103c34u;
    // NOP
    // 0x103c38: 0x0  nop
    ctx->pc = 0x103c38u;
    // NOP
    // 0x103c3c: 0x5040fff8  beql        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x103C3Cu;
    {
        const bool branch_taken_0x103c3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x103c3c) {
            ctx->pc = 0x103C40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x103C3Cu;
            // 0x103c40: 0x2529fffc  addiu       $t1, $t1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967292));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103C20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_103c20;
        }
    }
    ctx->pc = 0x103C44u;
    // 0x103c44: 0xae900010  sw          $s0, 0x10($s4)
    ctx->pc = 0x103c44u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 16), GPR_U32(ctx, 16));
label_103c48:
    // 0x103c48: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x103c48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_103c4c:
    // 0x103c4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103c4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103c50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x103c50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x103c54: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x103c54u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103c58: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x103c58u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x103c5c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x103c5cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x103c60: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x103c60u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x103c64: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x103c64u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x103c68: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x103c68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x103c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x103C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103C6Cu;
            // 0x103c70: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103AC0u: goto label_103ac0;
            case 0x103AD8u: goto label_103ad8;
            case 0x103B50u: goto label_103b50;
            case 0x103B54u: goto label_103b54;
            case 0x103B78u: goto label_103b78;
            case 0x103B7Cu: goto label_103b7c;
            case 0x103B84u: goto label_103b84;
            case 0x103BA0u: goto label_103ba0;
            case 0x103C20u: goto label_103c20;
            case 0x103C24u: goto label_103c24;
            case 0x103C48u: goto label_103c48;
            case 0x103C4Cu: goto label_103c4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103C74u;
    // 0x103c74: 0x0  nop
    ctx->pc = 0x103c74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
