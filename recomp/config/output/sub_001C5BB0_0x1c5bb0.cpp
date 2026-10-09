#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5BB0
// Address: 0x1c5bb0 - 0x1c5c5c
void sub_001C5BB0_0x1c5bb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5BB0_0x1c5bb0");
#endif

    switch (ctx->pc) {
        case 0x1c5c04u: goto label_1c5c04;
        default: break;
    }

    ctx->pc = 0x1c5bb0u;

    // 0x1c5bb0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c5bb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c5bb4: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1c5bb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1c5bb8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c5bb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c5bbc: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1c5bbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1c5bc0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c5bc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c5bc4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5bc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5bc8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5BC8u;
    {
        const bool branch_taken_0x1c5bc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5BC8u;
            // 0x1c5bcc: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5bc8) {
            ctx->pc = 0x1C5BD8u;
            goto label_1c5bd8;
        }
    }
    ctx->pc = 0x1C5BD0u;
    // 0x1c5bd0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C5BD0u;
    {
        const bool branch_taken_0x1c5bd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5BD0u;
            // 0x1c5bd4: 0x24900018  addiu       $s0, $a0, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5bd0) {
            ctx->pc = 0x1C5BDCu;
            goto label_1c5bdc;
        }
    }
    ctx->pc = 0x1C5BD8u;
label_1c5bd8:
    // 0x1c5bd8: 0x24900008  addiu       $s0, $a0, 0x8
    ctx->pc = 0x1c5bd8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
label_1c5bdc:
    // 0x1c5bdc: 0x92020008  lbu         $v0, 0x8($s0)
    ctx->pc = 0x1c5bdcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1c5be0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5BE0u;
    {
        const bool branch_taken_0x1c5be0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5BE0u;
            // 0x1c5be4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5be0) {
            ctx->pc = 0x1C5BF0u;
            goto label_1c5bf0;
        }
    }
    ctx->pc = 0x1C5BE8u;
    // 0x1c5be8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1C5BE8u;
    {
        const bool branch_taken_0x1c5be8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5BE8u;
            // 0x1c5bec: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5be8) {
            ctx->pc = 0x1C5C4Cu;
            goto label_1c5c4c;
        }
    }
    ctx->pc = 0x1C5BF0u;
label_1c5bf0:
    // 0x1c5bf0: 0x9202000b  lbu         $v0, 0xB($s0)
    ctx->pc = 0x1c5bf0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 11)));
    // 0x1c5bf4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5BF4u;
    {
        const bool branch_taken_0x1c5bf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5BF4u;
            // 0x1c5bf8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5bf4) {
            ctx->pc = 0x1C5C08u;
            goto label_1c5c08;
        }
    }
    ctx->pc = 0x1C5BFCu;
    // 0x1c5bfc: 0xc071718  jal         func_1C5C60
    ctx->pc = 0x1C5BFCu;
    SET_GPR_U32(ctx, 31, 0x1C5C04u);
    ctx->pc = 0x1C5C60u;
    if (runtime->hasFunction(0x1C5C60u)) {
        auto targetFn = runtime->lookupFunction(0x1C5C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5C04u; }
        if (ctx->pc != 0x1C5C04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5C60_0x1c5c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5C04u; }
        if (ctx->pc != 0x1C5C04u) { return; }
    }
    ctx->pc = 0x1C5C04u;
label_1c5c04:
    // 0x1c5c04: 0xa200000b  sb          $zero, 0xB($s0)
    ctx->pc = 0x1c5c04u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 0));
label_1c5c08:
    // 0x1c5c08: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1c5c08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1c5c0c: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1c5c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1c5c10: 0x222082b  sltu        $at, $s1, $v0
    ctx->pc = 0x1c5c10u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1c5c14: 0x1420000c  bnez        $at, . + 4 + (0xC << 2)
    ctx->pc = 0x1C5C14u;
    {
        const bool branch_taken_0x1c5c14 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5C14u;
            // 0x1c5c18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5c14) {
            ctx->pc = 0x1C5C48u;
            goto label_1c5c48;
        }
    }
    ctx->pc = 0x1C5C1Cu;
    // 0x1c5c1c: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1c5c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c5c20: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x1c5c20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1c5c24: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1c5c24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1c5c28: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1c5c28u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1c5c2c: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x1c5c2cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1c5c30: 0x9083000f  lbu         $v1, 0xF($a0)
    ctx->pc = 0x1c5c30u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x1c5c34: 0x306300df  andi        $v1, $v1, 0xDF
    ctx->pc = 0x1c5c34u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)223);
    // 0x1c5c38: 0xa083000f  sb          $v1, 0xF($a0)
    ctx->pc = 0x1c5c38u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 15), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c5c3c: 0x92030008  lbu         $v1, 0x8($s0)
    ctx->pc = 0x1c5c3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1c5c40: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1c5c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1c5c44: 0xa2030008  sb          $v1, 0x8($s0)
    ctx->pc = 0x1c5c44u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 8), (uint8_t)GPR_U32(ctx, 3));
label_1c5c48:
    // 0x1c5c48: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c5c48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1c5c4c:
    // 0x1c5c4c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c5c4cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5c50: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5c50u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5c54: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5C54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5C54u;
            // 0x1c5c58: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5BD8u: goto label_1c5bd8;
            case 0x1C5BDCu: goto label_1c5bdc;
            case 0x1C5BF0u: goto label_1c5bf0;
            case 0x1C5C04u: goto label_1c5c04;
            case 0x1C5C08u: goto label_1c5c08;
            case 0x1C5C48u: goto label_1c5c48;
            case 0x1C5C4Cu: goto label_1c5c4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5C5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
