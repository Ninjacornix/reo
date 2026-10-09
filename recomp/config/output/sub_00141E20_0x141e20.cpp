#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141E20
// Address: 0x141e20 - 0x141ee4
void sub_00141E20_0x141e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141E20_0x141e20");
#endif

    switch (ctx->pc) {
        case 0x141e78u: goto label_141e78;
        case 0x141e90u: goto label_141e90;
        default: break;
    }

    ctx->pc = 0x141e20u;

    // 0x141e20: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x141e20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x141e24: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x141e24u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x141e28: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x141e28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x141e2c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x141e2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x141e30: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x141e30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x141e34: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x141e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x141e38: 0x4a080  sll         $s4, $a0, 2
    ctx->pc = 0x141e38u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x141e3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141e40: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141e40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141e44: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x141e44u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x141e48: 0x2631a618  addiu       $s1, $s1, -0x59E8
    ctx->pc = 0x141e48u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294944280));
    // 0x141e4c: 0x2348821  addu        $s1, $s1, $s4
    ctx->pc = 0x141e4cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
    // 0x141e50: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x141e50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x141e54: 0x24120005  addiu       $s2, $zero, 0x5
    ctx->pc = 0x141e54u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x141e58: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x141e58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x141e5c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x141e5cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141e60: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x141e60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x141e64: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x141e64u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x141e68: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x141e68u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x141e6c: 0x26104820  addiu       $s0, $s0, 0x4820
    ctx->pc = 0x141e6cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18464));
    // 0x141e70: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x141e70u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x141e74: 0x0  nop
    ctx->pc = 0x141e74u;
    // NOP
label_141e78:
    // 0x141e78: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x141e78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x141e7c: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x141E7Cu;
    {
        const bool branch_taken_0x141e7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x141e7c) {
            ctx->pc = 0x141E80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141E7Cu;
            // 0x141e80: 0x2652ffff  addiu       $s2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141E9Cu;
            goto label_141e9c;
        }
    }
    ctx->pc = 0x141E84u;
    // 0x141e84: 0xae350000  sw          $s5, 0x0($s1)
    ctx->pc = 0x141e84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 21));
    // 0x141e88: 0x40f809  jalr        $v0
    ctx->pc = 0x141E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141E90u);
        ctx->pc = 0x141E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141E88u;
            // 0x141e8c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141E90u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141E78u: goto label_141e78;
            case 0x141E90u: goto label_141e90;
            case 0x141E9Cu: goto label_141e9c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141E90u; }
            if (ctx->pc != 0x141E90u) { return; }
        }
        }
    }
    ctx->pc = 0x141E90u;
label_141e90:
    // 0x141e90: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x141e90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x141e94: 0x2629825  or          $s3, $s3, $v0
    ctx->pc = 0x141e94u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x141e98: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x141e98u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
label_141e9c:
    // 0x141e9c: 0x641fff6  bgez        $s2, . + 4 + (-0xA << 2)
    ctx->pc = 0x141E9Cu;
    {
        const bool branch_taken_0x141e9c = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x141EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141E9Cu;
            // 0x141ea0: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141e9c) {
            ctx->pc = 0x141E78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141e78;
        }
    }
    ctx->pc = 0x141EA4u;
    // 0x141ea4: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x141ea4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x141ea8: 0x2484a5f8  addiu       $a0, $a0, -0x5A08
    ctx->pc = 0x141ea8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944248));
    // 0x141eac: 0x942021  addu        $a0, $a0, $s4
    ctx->pc = 0x141eacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 20)));
    // 0x141eb0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x141eb0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x141eb4: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x141eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x141eb8: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x141eb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141ebc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141ebcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141ec0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141ec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141ec4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x141ec4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x141ec8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x141ec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141ecc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x141eccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141ed0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x141ed0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x141ed4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x141ed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x141ed8: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x141ed8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x141edc: 0x3e00008  jr          $ra
    ctx->pc = 0x141EDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141EE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141EDCu;
            // 0x141ee0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141E78u: goto label_141e78;
            case 0x141E90u: goto label_141e90;
            case 0x141E9Cu: goto label_141e9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141EE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
