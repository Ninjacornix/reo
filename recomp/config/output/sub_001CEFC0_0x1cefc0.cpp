#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CEFC0
// Address: 0x1cefc0 - 0x1cf088
void sub_001CEFC0_0x1cefc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CEFC0_0x1cefc0");
#endif

    switch (ctx->pc) {
        case 0x1cefecu: goto label_1cefec;
        case 0x1cf038u: goto label_1cf038;
        default: break;
    }

    ctx->pc = 0x1cefc0u;

    // 0x1cefc0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1cefc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1cefc4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1cefc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1cefc8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cefc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cefcc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cefccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cefd0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1cefd0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cefd4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cefd4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cefd8: 0x3c120034  lui         $s2, 0x34
    ctx->pc = 0x1cefd8u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)52 << 16));
    // 0x1cefdc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cefdcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cefe0: 0x26521430  addiu       $s2, $s2, 0x1430
    ctx->pc = 0x1cefe0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 5168));
    // 0x1cefe4: 0x808027  not         $s0, $a0
    ctx->pc = 0x1cefe4u;
    SET_GPR_U64(ctx, 16, ~(GPR_U64(ctx, 4) | GPR_U64(ctx, 0)));
    // 0x1cefe8: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1cefe8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cefec:
    // 0x1cefec: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1cefecu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ceff0: 0x1060001a  beqz        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1CEFF0u;
    {
        const bool branch_taken_0x1ceff0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEFF0u;
            // 0x1ceff4: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ceff0) {
            ctx->pc = 0x1CF05Cu;
            goto label_1cf05c;
        }
    }
    ctx->pc = 0x1CEFF8u;
    // 0x1ceff8: 0x12630004  beq         $s3, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CEFF8u;
    {
        const bool branch_taken_0x1ceff8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ceff8) {
            ctx->pc = 0x1CF00Cu;
            goto label_1cf00c;
        }
    }
    ctx->pc = 0x1CF000u;
    // 0x1cf000: 0x92430008  lbu         $v1, 0x8($s2)
    ctx->pc = 0x1cf000u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1cf004: 0x14730015  bne         $v1, $s3, . + 4 + (0x15 << 2)
    ctx->pc = 0x1CF004u;
    {
        const bool branch_taken_0x1cf004 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        if (branch_taken_0x1cf004) {
            ctx->pc = 0x1CF05Cu;
            goto label_1cf05c;
        }
    }
    ctx->pc = 0x1CF00Cu;
label_1cf00c:
    // 0x1cf00c: 0x92430003  lbu         $v1, 0x3($s2)
    ctx->pc = 0x1cf00cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
    // 0x1cf010: 0x320400ff  andi        $a0, $s0, 0xFF
    ctx->pc = 0x1cf010u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1cf014: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x1cf014u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1cf018: 0xa2430003  sb          $v1, 0x3($s2)
    ctx->pc = 0x1cf018u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cf01c: 0x92430003  lbu         $v1, 0x3($s2)
    ctx->pc = 0x1cf01cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
    // 0x1cf020: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CF020u;
    {
        const bool branch_taken_0x1cf020 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf020) {
            ctx->pc = 0x1CF040u;
            goto label_1cf040;
        }
    }
    ctx->pc = 0x1CF028u;
    // 0x1cf028: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cf028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cf02c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1cf02cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf030: 0xc073b90  jal         func_1CEE40
    ctx->pc = 0x1CF030u;
    SET_GPR_U32(ctx, 31, 0x1CF038u);
    ctx->pc = 0x1CF034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF030u;
            // 0x1cf034: 0xa2420000  sb          $v0, 0x0($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CEE40u;
    if (runtime->hasFunction(0x1CEE40u)) {
        auto targetFn = runtime->lookupFunction(0x1CEE40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF038u; }
        if (ctx->pc != 0x1CF038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CEE40_0x1cee40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF038u; }
        if (ctx->pc != 0x1CF038u) { return; }
    }
    ctx->pc = 0x1CF038u;
label_1cf038:
    // 0x1cf038: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1CF038u;
    {
        const bool branch_taken_0x1cf038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF038u;
            // 0x1cf03c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf038) {
            ctx->pc = 0x1CF060u;
            goto label_1cf060;
        }
    }
    ctx->pc = 0x1CF040u;
label_1cf040:
    // 0x1cf040: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1cf040u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1cf044: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1cf044u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1cf048: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x1cf048u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cf04c: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1cf04cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1cf050: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF050u;
    {
        const bool branch_taken_0x1cf050 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF050u;
            // 0x1cf054: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf050) {
            ctx->pc = 0x1CF05Cu;
            goto label_1cf05c;
        }
    }
    ctx->pc = 0x1CF058u;
    // 0x1cf058: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x1cf058u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
label_1cf05c:
    // 0x1cf05c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1cf05cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1cf060:
    // 0x1cf060: 0x2a230010  slti        $v1, $s1, 0x10
    ctx->pc = 0x1cf060u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1cf064: 0x1460ffe1  bnez        $v1, . + 4 + (-0x1F << 2)
    ctx->pc = 0x1CF064u;
    {
        const bool branch_taken_0x1cf064 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF064u;
            // 0x1cf068: 0x2652000c  addiu       $s2, $s2, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf064) {
            ctx->pc = 0x1CEFECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cefec;
        }
    }
    ctx->pc = 0x1CF06Cu;
    // 0x1cf06c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1cf06cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cf070: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cf070u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cf074: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cf074u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cf078: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cf078u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cf07c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cf07cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf080: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF080u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF080u;
            // 0x1cf084: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CEFECu: goto label_1cefec;
            case 0x1CF00Cu: goto label_1cf00c;
            case 0x1CF038u: goto label_1cf038;
            case 0x1CF040u: goto label_1cf040;
            case 0x1CF05Cu: goto label_1cf05c;
            case 0x1CF060u: goto label_1cf060;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF088u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
