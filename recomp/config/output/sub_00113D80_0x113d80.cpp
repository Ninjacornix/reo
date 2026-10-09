#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00113D80
// Address: 0x113d80 - 0x113ed0
void sub_00113D80_0x113d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00113D80_0x113d80");
#endif

    switch (ctx->pc) {
        case 0x113e04u: goto label_113e04;
        case 0x113e10u: goto label_113e10;
        case 0x113e40u: goto label_113e40;
        default: break;
    }

    ctx->pc = 0x113d80u;

    // 0x113d80: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x113d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x113d84: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x113d84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x113d88: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x113d88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x113d8c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x113d8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x113d90: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x113d90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x113d94: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x113d94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x113d98: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x113d98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113d9c: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x113d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x113da0: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x113da0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x113da4: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x113da4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x113da8: 0x3053007f  andi        $s3, $v0, 0x7F
    ctx->pc = 0x113da8u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x113dac: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x113dacu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x113db0: 0x3063000f  andi        $v1, $v1, 0xF
    ctx->pc = 0x113db0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x113db4: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x113db4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x113db8: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x113db8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x113dbc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x113dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x113dc0: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x113dc0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x113dc4: 0x829021  addu        $s2, $a0, $v0
    ctx->pc = 0x113dc4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x113dc8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x113dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x113dcc: 0x10c0000d  beqz        $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x113DCCu;
    {
        const bool branch_taken_0x113dcc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x113DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113DCCu;
            // 0x113dd0: 0xa28823  subu        $s1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113dcc) {
            ctx->pc = 0x113E04u;
            goto label_113e04;
        }
    }
    ctx->pc = 0x113DD4u;
    // 0x113dd4: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x113dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x113dd8: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x113DD8u;
    {
        const bool branch_taken_0x113dd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x113DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113DD8u;
            // 0x113ddc: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113dd8) {
            ctx->pc = 0x113E04u;
            goto label_113e04;
        }
    }
    ctx->pc = 0x113DE0u;
    // 0x113de0: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x113de0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x113de4: 0x3442b010  ori         $v0, $v0, 0xB010
    ctx->pc = 0x113de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)45072);
    // 0x113de8: 0x3484b020  ori         $a0, $a0, 0xB020
    ctx->pc = 0x113de8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45088);
    // 0x113dec: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x113decu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6)); // MMIO: 0x10000000
    // 0x113df0: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x113df0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x113df4: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x113df4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x113df8: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x113df8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x113dfc: 0xc044eea  jal         func_113BA8
    ctx->pc = 0x113DFCu;
    SET_GPR_U32(ctx, 31, 0x113E04u);
    ctx->pc = 0x113E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113DFCu;
            // 0x113e00: 0x34840100  ori         $a0, $a0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
    ctx->pc = 0x113BA8u;
    if (runtime->hasFunction(0x113BA8u)) {
        auto targetFn = runtime->lookupFunction(0x113BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113E04u; }
        if (ctx->pc != 0x113E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113BA8_0x113ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113E04u; }
        if (ctx->pc != 0x113E04u) { return; }
    }
    ctx->pc = 0x113E04u;
label_113e04:
    // 0x113e04: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113e04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113e08: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x113e08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x113e0c: 0x0  nop
    ctx->pc = 0x113e0cu;
    // NOP
label_113e10:
    // 0x113e10: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x113e10u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113e14: 0x0  nop
    ctx->pc = 0x113e14u;
    // NOP
    // 0x113e18: 0x0  nop
    ctx->pc = 0x113e18u;
    // NOP
    // 0x113e1c: 0x0  nop
    ctx->pc = 0x113e1cu;
    // NOP
    // 0x113e20: 0x0  nop
    ctx->pc = 0x113e20u;
    // NOP
    // 0x113e24: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113E24u;
    {
        const bool branch_taken_0x113e24 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x113e24) {
            ctx->pc = 0x113E10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113e10;
        }
    }
    ctx->pc = 0x113E2Cu;
    // 0x113e2c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113e30: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113e30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113e34: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x113e34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x113e38: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x113e38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x113e3c: 0xac530000  sw          $s3, 0x0($v0)
    ctx->pc = 0x113e3cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 19)); // MMIO: 0x10000000
label_113e40:
    // 0x113e40: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x113e40u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113e44: 0x0  nop
    ctx->pc = 0x113e44u;
    // NOP
    // 0x113e48: 0x0  nop
    ctx->pc = 0x113e48u;
    // NOP
    // 0x113e4c: 0x0  nop
    ctx->pc = 0x113e4cu;
    // NOP
    // 0x113e50: 0x0  nop
    ctx->pc = 0x113e50u;
    // NOP
    // 0x113e54: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113E54u;
    {
        const bool branch_taken_0x113e54 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x113e54) {
            ctx->pc = 0x113E40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113e40;
        }
    }
    ctx->pc = 0x113E5Cu;
    // 0x113e5c: 0x12200016  beqz        $s1, . + 4 + (0x16 << 2)
    ctx->pc = 0x113E5Cu;
    {
        const bool branch_taken_0x113e5c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x113E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113E5Cu;
            // 0x113e60: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113e5c) {
            ctx->pc = 0x113EB8u;
            goto label_113eb8;
        }
    }
    ctx->pc = 0x113E64u;
    // 0x113e64: 0x12400015  beqz        $s2, . + 4 + (0x15 << 2)
    ctx->pc = 0x113E64u;
    {
        const bool branch_taken_0x113e64 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x113E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113E64u;
            // 0x113e68: 0xdfb30030  ld          $s3, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113e64) {
            ctx->pc = 0x113EBCu;
            goto label_113ebc;
        }
    }
    ctx->pc = 0x113E6Cu;
    // 0x113e6c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113e70: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x113e70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x113e74: 0x3442b410  ori         $v0, $v0, 0xB410
    ctx->pc = 0x113e74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46096);
    // 0x113e78: 0x3484b430  ori         $a0, $a0, 0xB430
    ctx->pc = 0x113e78u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46128);
    // 0x113e7c: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x113e7cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17)); // MMIO: 0x10000000
    // 0x113e80: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x113e80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113e84: 0x3463b420  ori         $v1, $v1, 0xB420
    ctx->pc = 0x113e84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46112);
    // 0x113e88: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x113e88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x113e8c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x113e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x113e90: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x113e90u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x113e94: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x113e94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x113e98: 0xac720000  sw          $s2, 0x0($v1)
    ctx->pc = 0x113e98u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 18));
    // 0x113e9c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x113e9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x113ea0: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x113ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x113ea4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x113ea4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x113ea8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x113ea8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113eac: 0x34840100  ori         $a0, $a0, 0x100
    ctx->pc = 0x113eacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)256);
    // 0x113eb0: 0x8044f08  j           func_113C20
    ctx->pc = 0x113EB0u;
    ctx->pc = 0x113EB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113EB0u;
            // 0x113eb4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113C20u;
    if (runtime->hasFunction(0x113C20u)) {
        auto targetFn = runtime->lookupFunction(0x113C20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00113C20_0x113c20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x113EB8u;
label_113eb8:
    // 0x113eb8: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x113eb8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_113ebc:
    // 0x113ebc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x113ebcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x113ec0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x113ec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x113ec4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x113ec4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113ec8: 0x3e00008  jr          $ra
    ctx->pc = 0x113EC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113EC8u;
            // 0x113ecc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113E04u: goto label_113e04;
            case 0x113E10u: goto label_113e10;
            case 0x113E40u: goto label_113e40;
            case 0x113EB8u: goto label_113eb8;
            case 0x113EBCu: goto label_113ebc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113ED0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
