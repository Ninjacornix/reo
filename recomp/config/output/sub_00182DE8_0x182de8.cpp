#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182DE8
// Address: 0x182de8 - 0x182f30
void sub_00182DE8_0x182de8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182DE8_0x182de8");
#endif

    switch (ctx->pc) {
        case 0x182e68u: goto label_182e68;
        case 0x182e90u: goto label_182e90;
        case 0x182e9cu: goto label_182e9c;
        default: break;
    }

    ctx->pc = 0x182de8u;

    // 0x182de8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x182de8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x182dec: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x182decu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x182df0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x182df0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x182df4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x182df4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182df8: 0x24040898  addiu       $a0, $zero, 0x898
    ctx->pc = 0x182df8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x182dfc: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x182dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x182e00: 0x2442018  mult        $a0, $s2, $a0
    ctx->pc = 0x182e00u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x182e04: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x182e04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x182e08: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x182e08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x182e0c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x182e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x182e10: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x182e10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x182e14: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x182e14u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182e18: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x182e18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x182e1c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x182e1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x182e20: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x182e20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x182e24: 0x3c140023  lui         $s4, 0x23
    ctx->pc = 0x182e24u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)35 << 16));
    // 0x182e28: 0x2694fa18  addiu       $s4, $s4, -0x5E8
    ctx->pc = 0x182e28u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294965784));
    // 0x182e2c: 0x282a021  addu        $s4, $s4, $v0
    ctx->pc = 0x182e2cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x182e30: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x182e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x182e34: 0x24775b48  addiu       $s7, $v1, 0x5B48
    ctx->pc = 0x182e34u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 3), 23368));
    // 0x182e38: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x182e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x182e3c: 0x24930890  addiu       $s3, $a0, 0x890
    ctx->pc = 0x182e3cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), 2192));
    // 0x182e40: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x182e40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x182e44: 0x2771021  addu        $v0, $s3, $s7
    ctx->pc = 0x182e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 23)));
    // 0x182e48: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x182e48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x182e4c: 0x260f02d  daddu       $fp, $s3, $zero
    ctx->pc = 0x182e4cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182e50: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x182e50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x182e54: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x182e54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x182e58: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x182e58u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x182e5c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x182e5cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x182e60: 0x8e830170  lw          $v1, 0x170($s4)
    ctx->pc = 0x182e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 368)));
    // 0x182e64: 0x0  nop
    ctx->pc = 0x182e64u;
    // NOP
label_182e68:
    // 0x182e68: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182e68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x182e6c: 0x8c500000  lw          $s0, 0x0($v0)
    ctx->pc = 0x182e6cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x182e70: 0x203102a  slt         $v0, $s0, $v1
    ctx->pc = 0x182e70u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x182e74: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x182E74u;
    {
        const bool branch_taken_0x182e74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182E74u;
            // 0x182e78: 0x2772021  addu        $a0, $s3, $s7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 23)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182e74) {
            ctx->pc = 0x182EDCu;
            goto label_182edc;
        }
    }
    ctx->pc = 0x182E7Cu;
    // 0x182e7c: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x182e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x182e80: 0x3c158000  lui         $s5, 0x8000
    ctx->pc = 0x182e80u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)32768 << 16));
    // 0x182e84: 0x24425b48  addiu       $v0, $v0, 0x5B48
    ctx->pc = 0x182e84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23368));
    // 0x182e88: 0x3c2b021  addu        $s6, $fp, $v0
    ctx->pc = 0x182e88u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
    // 0x182e8c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x182e8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_182e90:
    // 0x182e90: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x182e90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182e94: 0xc060aa6  jal         func_182A98
    ctx->pc = 0x182E94u;
    SET_GPR_U32(ctx, 31, 0x182E9Cu);
    ctx->pc = 0x182E98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182E94u;
            // 0x182e98: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182A98u;
    if (runtime->hasFunction(0x182A98u)) {
        auto targetFn = runtime->lookupFunction(0x182A98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182E9Cu; }
        if (ctx->pc != 0x182E9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182A98_0x182a98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182E9Cu; }
        if (ctx->pc != 0x182E9Cu) { return; }
    }
    ctx->pc = 0x182E9Cu;
label_182e9c:
    // 0x182e9c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x182e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x182ea0: 0x552024  and         $a0, $v0, $s5
    ctx->pc = 0x182ea0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & GPR_U64(ctx, 21));
    // 0x182ea4: 0x14600015  bnez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x182EA4u;
    {
        const bool branch_taken_0x182ea4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x182EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182EA4u;
            // 0x182ea8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182ea4) {
            ctx->pc = 0x182EFCu;
            goto label_182efc;
        }
    }
    ctx->pc = 0x182EACu;
    // 0x182eac: 0x54800006  bnel        $a0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x182EACu;
    {
        const bool branch_taken_0x182eac = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x182eac) {
            ctx->pc = 0x182EB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182EACu;
            // 0x182eb0: 0x8e830170  lw          $v1, 0x170($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 368)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182EC8u;
            goto label_182ec8;
        }
    }
    ctx->pc = 0x182EB4u;
    // 0x182eb4: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x182eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x182eb8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x182eb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182ebc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x182EBCu;
    {
        const bool branch_taken_0x182ebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182EBCu;
            // 0x182ec0: 0xaed00000  sw          $s0, 0x0($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182ebc) {
            ctx->pc = 0x182EFCu;
            goto label_182efc;
        }
    }
    ctx->pc = 0x182EC4u;
    // 0x182ec4: 0x0  nop
    ctx->pc = 0x182ec4u;
    // NOP
label_182ec8:
    // 0x182ec8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x182ec8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x182ecc: 0x203102a  slt         $v0, $s0, $v1
    ctx->pc = 0x182eccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x182ed0: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x182ED0u;
    {
        const bool branch_taken_0x182ed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182ED0u;
            // 0x182ed4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182ed0) {
            ctx->pc = 0x182E90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182e90;
        }
    }
    ctx->pc = 0x182ED8u;
    // 0x182ed8: 0x2772021  addu        $a0, $s3, $s7
    ctx->pc = 0x182ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 23)));
label_182edc:
    // 0x182edc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x182edcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x182ee0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x182EE0u;
    {
        const bool branch_taken_0x182ee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182EE0u;
            // 0x182ee4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182ee0) {
            ctx->pc = 0x182EF0u;
            goto label_182ef0;
        }
    }
    ctx->pc = 0x182EE8u;
    // 0x182ee8: 0x1000ffdf  b           . + 4 + (-0x21 << 2)
    ctx->pc = 0x182EE8u;
    {
        const bool branch_taken_0x182ee8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182EE8u;
            // 0x182eec: 0xac800000  sw          $zero, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182ee8) {
            ctx->pc = 0x182E68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182e68;
        }
    }
    ctx->pc = 0x182EF0u;
label_182ef0:
    // 0x182ef0: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x182ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x182ef4: 0x3463001c  ori         $v1, $v1, 0x1C
    ctx->pc = 0x182ef4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)28);
    // 0x182ef8: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x182ef8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_182efc:
    // 0x182efc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x182efcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x182f00: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x182f00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x182f04: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x182f04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x182f08: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x182f08u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x182f0c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x182f0cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x182f10: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x182f10u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x182f14: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x182f14u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x182f18: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x182f18u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x182f1c: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x182f1cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x182f20: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x182f20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x182f24: 0x3e00008  jr          $ra
    ctx->pc = 0x182F24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182F24u;
            // 0x182f28: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182E68u: goto label_182e68;
            case 0x182E90u: goto label_182e90;
            case 0x182E9Cu: goto label_182e9c;
            case 0x182EC8u: goto label_182ec8;
            case 0x182EDCu: goto label_182edc;
            case 0x182EF0u: goto label_182ef0;
            case 0x182EFCu: goto label_182efc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182F2Cu;
    // 0x182f2c: 0x0  nop
    ctx->pc = 0x182f2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
